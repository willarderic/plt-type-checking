/*
	willarde.y

 	Example of a bison specification file.

	Grammar is:
      To create the syntax analyzer:

        flex example.l
        bison example.y
        g++ example.tab.c -o parser
        parser < inputFileName
 */

%{
#include <stdio.h>
#include <stack>
#include <cstring>
#include <sstream>
#include "SymbolTable.h"

int numLines = 1;
int exprListIndex = 0;
bool exprListInt = false;
std::stack<SymbolTable> scopeStack;

void printRule(const char *, const char *);
int yyerror(const char *s);
char* setText(string s);
void printTokenInfo(const char* tokenType, const char* lexeme);
void beginScope();
void endScope();
bool findEntryInAnyScope(const string entry);

extern "C"
{
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}

%}

%union{
    char op;
	char* text;
    TypeInfo typeInfo;
};

/* Token declarations */
%token T_LETSTAR T_LAMBDA T_INPUT T_PRINT T_IF
%token T_LPAREN T_RPAREN T_ADD T_MULT T_DIV T_SUB
%token T_AND T_OR T_NOT
%token T_LT T_GT T_LE T_GE T_EQ T_NE
%token T_IDENT T_INTCONST T_STRCONST T_T T_NIL T_UNKNOWN

%type <text> T_IDENT N_BIN_OP N_ARITH_OP N_LOG_OP N_REL_OP
%type <typeInfo> N_CONST N_EXPR N_PARENTHESIZED_EXPR N_IF_EXPR N_ARITHLOGIC_EXPR
%type <typeInfo> N_INPUT_EXPR N_EXPR_LIST N_LAMBDA_EXPR N_PRINT_EXPR
%type <typeInfo> N_LET_EXPR

/* Starting point */
%start N_START

/* Translation rules */
%%
N_START                 : N_EXPR
                            {
                                printRule("START", "EXPR");
                                printf("\n---- Completed parsing ----\n\n");
                                return 0;
                            }
N_EXPR                  : N_CONST
                            {
                                printRule("EXPR", "CONST");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | T_IDENT
                            {
                                printRule("EXPR", "IDENT");
								bool found = findEntryInAnyScope(string($1));
								if (!found) {
									yyerror("Undefined identifier");
                                    return 1;
								}
                                $$ = scopeStack.top().getEntryType(string($1));
                            }
                        | T_LPAREN N_PARENTHESIZED_EXPR T_RPAREN
                            {
                                printRule("EXPR", "( PARENTHESIZED_EXPR )");
                                $$.type = $2.type;
                                $$.numParams = $2.numParams;
                                $$.returnType = $2.returnType;
                            }
N_CONST                 : T_INTCONST
                            {
                                printRule("CONST", "INTCONST");
                                $$.type = INT;
                                $$.numParams = NOT_APPLICABLE;
                                $$.returnType = NOT_APPLICABLE;
                            }
                        | T_STRCONST
                            {
                                printRule("CONST", "STRCONST");
                                $$.type = STR;
                                $$.numParams = NOT_APPLICABLE;
                                $$.returnType = NOT_APPLICABLE;
                            }
                        | T_T
                            {
                                printRule("CONST", "t");
                                $$.type = BOOL;
                                $$.numParams = NOT_APPLICABLE;
                                $$.returnType = NOT_APPLICABLE;
                            }
                        | T_NIL
                            {
                                printRule("CONST", "nil");
                                $$.type = BOOL;
                                $$.numParams = NOT_APPLICABLE;
                                $$.returnType = NOT_APPLICABLE;
                            }
N_PARENTHESIZED_EXPR    : N_ARITHLOGIC_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "ARITHLOGIC_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_IF_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "IF_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_LET_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "LET_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_LAMBDA_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "LAMBDA_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_PRINT_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "PRINT_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_INPUT_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "INPUT_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_EXPR_LIST
                            {
                                printRule("PARENTHESIZED_EXPR", "EXPR_LIST");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
N_ARITHLOGIC_EXPR       : N_UN_OP N_EXPR
                            {
                                printRule("ARITHLOGIC_EXPR", "UN_OP EXPR");
                                if ($2.type == FUNCTION) {
                                    yyerror("Arg 1 cannot be function");
                                    return(1);
                                }
                                $$.type = BOOL;
                                $$.numParams = NOT_APPLICABLE;
                                $$.returnType = NOT_APPLICABLE;
                            }
                        | N_BIN_OP N_EXPR N_EXPR
                            {
                                // add text attribute to N_BIN_OP
                                printRule("ARITHLOGIC_EXPR", "BIN_OP EXPR EXPR");
                                if (strcmp($1, "*") == 0 || strcmp($1, "/") == 0 ||
                                    strcmp($1, "+") == 0 || strcmp($1, "-") == 0)
                                {
									int intReducedTypeArg1 = INT & $2.type;
									int intReducedTypeArg2 = INT & $3.type;
                                    if (intReducedTypeArg1 != INT) {
                                        yyerror("Arg 1 must be integer");
                                        return 1;
                                    } else if (intReducedTypeArg2 != INT) {
                                        yyerror("Arg 2 must be integer");
                                        return 1;
                                    }
                                    $$.type = INT;
                                    $$.numParams = NOT_APPLICABLE;
                                    $$.returnType = NOT_APPLICABLE;
                                } else if (strcmp($1, "and") == 0 || strcmp($1, "or") == 0) {
                                    if ($2.type == FUNCTION) {
                                        yyerror("Arg 1 cannot be function");
                                        return 1;
                                    }
									int intReducedType = INT & $2.type;
									int strReducedType = STR & $2.type;
									int boolReducedType = BOOL & $2.type;
                                    if (intReducedType == INT) {
                                        if ($3.type == FUNCTION) {
                                            yyerror("Arg 2 cannot be function");
                                            return 1;
                                        }
                                        $$.type = BOOL;
                                        $$.numParams = NOT_APPLICABLE;
                                        $$.returnType = NOT_APPLICABLE;
                                    } else if (strReducedType == STR) {
                                        if ($3.type == FUNCTION) {
                                            yyerror("Arg 2 cannot be function");
                                            return 1;
                                        }
                                        $$.type = BOOL;
                                        $$.numParams = NOT_APPLICABLE;
                                        $$.returnType = NOT_APPLICABLE;
                                    } else if (boolReducedType == BOOL) {
                                        if ($3.type == FUNCTION) {
                                            yyerror("Arg 2 cannot be function");
                                            return 1;
                                        }
                                        $$.type = BOOL;
                                        $$.numParams = NOT_APPLICABLE;
                                        $$.returnType = NOT_APPLICABLE;
                                    }
                                } else if (strcmp($1, "<") || strcmp($1, ">") ||
                                           strcmp($1, ">=") || strcmp($1, "<=") ||
                                           strcmp($1, "=") || strcmp($1, "/=")) {
                                    if ($2.type == FUNCTION) {
                                        yyerror("Arg 1 must be integer or string");
                                        return 1;
                                    } else if ($2.type == BOOL) {
                                        yyerror("Arg 1 must be integer or string");
                                        return 1;
                                    }
									int intReducedTypeArg1 = INT & $2.type;
									int strReducedTypeArg1 = STR & $2.type;
                                    if (intReducedTypeArg1 == INT) {
										int intReducedTypeArg2 = INT & $3.type;
                                        if (intReducedTypeArg2 != INT) {
                                            yyerror("Arg 2 must be integer or string");
                                            return 1;
                                        }
                                        $$.type = BOOL;
                                        $$.numParams = NOT_APPLICABLE;
                                        $$.returnType = NOT_APPLICABLE;
                                    } else if (strReducedTypeArg1 == STR) {
										int strReducedTypeArg2 = STR & $3.type;
                                        if (strReducedTypeArg2 != STR) {
                                            yyerror("Arg 2 must be integer or string");
                                            return 1;
                                        }
                                        $$.type = BOOL;
                                        $$.numParams = NOT_APPLICABLE;
                                        $$.returnType = NOT_APPLICABLE;
                                    }
                                }
                            }
N_IF_EXPR               : T_IF N_EXPR N_EXPR N_EXPR
                            {
                                printRule("IF_EXPR", "IF EXPR EXPR EXPR");

                                if ($2.type == FUNCTION) {
                                    yyerror("Arg 1 cannot be function");
                                    return(1);
                                } else if ($3.type == FUNCTION) {
                                    yyerror("Arg 2 cannot be function");
                                    return(1);
                                } else if ($4.type == FUNCTION) {
                                    yyerror("Arg 3 cannot be function");
                                    return 1;
                                }
                                $$.type = $3.type | $4.type;
                                $$.numParams = NOT_APPLICABLE;
                                $$.returnType = NOT_APPLICABLE;
                            }
N_LET_EXPR              : T_LETSTAR T_LPAREN N_ID_EXPR_LIST T_RPAREN N_EXPR
                            {
                                printRule("LET_EXPR", "let* ( ID_EXPR_LIST ) EXPR");
								endScope();
                                if ($5.type == FUNCTION) {
                                    yyerror("Arg 2 cannot be function");
                                    return 1;
                                }
                                $$.type = $5.type;
                                $$.numParams = $5.numParams;
                                $$.returnType = $5.returnType;
                            }
N_ID_EXPR_LIST          : /* epsilon */
                            {
                                printRule("ID_EXPR_LIST", "epsilon");
                            }
                        | N_ID_EXPR_LIST T_LPAREN T_IDENT N_EXPR T_RPAREN
                            {
                                printRule("ID_EXPR_LIST", "ID_EXPR_LIST ( IDENT EXPR )");
								bool found = scopeStack.top().findEntry(string($3));
								printf("___Adding %s to symbol table\n", $3);
								if (found) {
									yyerror("Multiply defined identifier");
                                    return 1;
								} else {
									scopeStack.top().addEntry(SymbolTableEntry(string($3), $4));
								}
                            }
N_LAMBDA_EXPR           : T_LAMBDA T_LPAREN N_ID_LIST T_RPAREN N_EXPR
                            {
                                printRule("LAMBDA_EXPR", "lambda ( ID_LIST ) EXPR");
                                $$.numParams = scopeStack.top().getNumParams();
                                endScope();
                                if ($5.type == FUNCTION) {
                                    yyerror("Arg 2 cannot be function");
                                    return 1;
                                }
                                $$.type = FUNCTION;
                                $$.returnType = $5.type;
                            }
N_ID_LIST               : /* epsilon */
                            {
                                printRule("ID_LIST", "epsilon");
                            }
                        | N_ID_LIST T_IDENT
                            {
                                printRule("ID_LIST", "ID_LIST IDENT");
								bool found = scopeStack.top().findEntry(string($2));
                                printf("___Adding %s to symbol table\n", $2);
								if (found) {
									yyerror("Multiply defined identifier");
                                    return 1;
								} else {
									scopeStack.top().addEntry(SymbolTableEntry(string($2), INT));
								}
                            }
N_PRINT_EXPR            : T_PRINT N_EXPR
                            {
                                printRule("PRINT_EXPR", "print EXPR");
                                if ($2.type == FUNCTION) {
                                    yyerror("Arg 1 cannot be function");
                                    return(1);
                                }
                                $$.type = $2.type;
                                $$.numParams = $2.numParams;
                                $$.returnType = $2.returnType;
                            }
N_INPUT_EXPR            : T_INPUT
                            {
                                printRule("INPUT_EXPR", "input");
                                $$.type = INT_OR_STR;
                                $$.numParams = NOT_APPLICABLE;
                                $$.returnType = NOT_APPLICABLE;
                            }
N_EXPR_LIST             : N_EXPR N_EXPR_LIST
                            {
                                printRule("EXPR_LIST", "EXPR EXPR_LIST");
                                if ($1.type == FUNCTION) {
                                    if (exprListInt == false) {
                                        std::string s;
                                        std::stringstream out;
                                        out << "Arg " << ($1.numParams - exprListIndex) << " must be integer";
                                        s = out.str();
                                        yyerror(s.c_str());
                                        return 1;
                                    }
                                    if ($1.numParams > $2.numParams) {
                                        yyerror("Too few parameters in function call");
                                        return 1;
                                    } else if ($1.numParams < $2.numParams) {
                                        yyerror("Too many parameters in function call");
                                        return 1;
                                    } else {
                                        $$.type == $1.returnType;
                                    }
                                } else if ($1.type == INT) {
                                    $$.numParams = $2.numParams + 1;
                                } else if ($1.type != INT) {
                                    $$.numParams = $2.numParams + 1;
                                    exprListInt = false;
                                    exprListIndex = $$.numParams;
                                }
                            }
                        | N_EXPR
                            {
                                printRule("EXPR_LIST", "EXPR");
                                int intReducedType = INT & $1.type;
                                if ($1.type == FUNCTION) {
                                    $$.type = $1.returnType;
                                } else if (intReducedType == INT) {
                                    $$.type = $1.type;
                                    exprListInt = true;
                                } else  {
                                    exprListInt = false;
                                    exprListIndex = 1;
                                }
                                $$.numParams = 1;
                            }
N_BIN_OP                : N_ARITH_OP
                            {
                                printRule("BIN_OP", "ARITH_OP");
                                $$ = $1;
                            }
                        | N_LOG_OP
                            {
                                printRule("BIN_OP", "LOG_OP");
                                $$ = $1;
                            }
                        | N_REL_OP
                            {
                                printRule("BIN_OP", "REL_OP");
                                $$ = $1;
                            }
N_ARITH_OP              : T_MULT
                            {
                                printRule("ARITH_OP", "*");
                                $$ = setText("*");
                            }
                        | T_SUB
                            {
                                printRule("ARITH_OP", "-");
                                $$ = setText("-");
                            }
                        | T_DIV
                            {
                                printRule("ARITH_OP", "/");
                                $$ = setText("/");
                            }
                        | T_ADD
                            {
                                printRule("ARITH_OP", "+");
                                $$ = setText("+");
                            }
N_LOG_OP                : T_AND
                            {
                                printRule("LOG_OP", "and");
                                $$ = setText("and");
                            }
                        | T_OR
                            {
                                printRule("LOG_OP", "or");
                                $$ = setText("or");
                            }
N_REL_OP                : T_LT
                            {
                                printRule("REL_OP", "<");
                                $$ = setText("<");
                            }
                        | T_GT
                            {
                                printRule("REL_OP", ">");
                                $$ = setText(">");
                            }
                        | T_LE
                            {
                                printRule("REL_OP", "<=");
                                $$ = setText("<=");
                            }
                        | T_GE
                            {
                                printRule("REL_OP", ">=");
                                $$ = setText(">=");
                            }
                        | T_EQ
                            {
                                printRule("REL_OP", "=");
                                $$ = setText("=");
                            }
                        | T_NE
                            {
                                printRule("REL_OP", "/=");
                                $$ = setText("/=");
                            }
N_UN_OP                 : T_NOT
                            {
                                printRule("UN_OP", "not");
                            }
%%

#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char *lhs, const char *rhs)
{
  printf("%s -> %s\n", lhs, rhs);
  return;
}

int yyerror(const char *s)
{
  printf("Line %d: %s\n", numLines, s);
  return(1);
}

void printTokenInfo(const char* tokenType, const char* lexeme)
{
  printf("TOKEN: %s  LEXEME: %s\n", tokenType, lexeme);
}

char* setText(string s) {
    char* cstr = new char[s.length() + 1];
    strcpy(cstr, s.c_str());
    return cstr;
}

void beginScope() {
	scopeStack.push(SymbolTable());
	printf("\n___Entering new scope... \n\n");
}

void endScope() {
	scopeStack.pop();
	printf("\n___Exiting scope...\n\n");
}

bool findEntryInAnyScope(const string entry) {
	if (scopeStack.empty()) return false;
	bool found = scopeStack.top().findEntry(entry);
	if (found) {
		return true;
	} else {
		SymbolTable symbolTable = scopeStack.top();
		scopeStack.pop();
		found = findEntryInAnyScope(entry);
		scopeStack.push(symbolTable);
		return found;
	}
}

int main()
{
  do
  {
	yyparse();
  } while (!feof(yyin));

  return(0);
}
