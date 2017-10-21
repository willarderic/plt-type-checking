/*    example.l
 
 	Example of a lex specification file.
     
      To create the lexical analyzer:

      flex example.l
      g++ lex.yy.c -o lexer
      lexer < inputFileName
*/

%{

%}

/* Defintions of regular expressions go here */

WSPACE		    [ \t\v\r]+
NEWLINE         \n

DIGIT	        [0-9]
LETTER          [a-zA-Z]

IDENT			(_|{LETTER})({LETTER}|{DIGIT}|_)* 
INTCONST        (\+|-)?{DIGIT}+
DOUBLE_QUOTE    \"
STRCONST        {DOUBLE_QUOTE}[^\"\n]*{DOUBLE_QUOTE} 
COMMENT         ;(.)*

%%



"let*"      {
                printTokenInfo("LETSTAR", yytext);
				beginScope();
                return T_LETSTAR;
            }
"lambda"    {
                printTokenInfo("LAMBDA", yytext);
				beginScope();
                return T_LAMBDA;
            }
"input"     {
                printTokenInfo("INPUT", yytext);
                return T_INPUT;
            }
"print"     {
                printTokenInfo("PRINT", yytext);
                return T_PRINT;
            }
"if"        {
                printTokenInfo("IF", yytext);
                return T_IF;
            }
"and"       {
                printTokenInfo("AND", yytext);
                return T_AND;
            }
"or"        {
                printTokenInfo("OR", yytext);
                return T_OR;
            }
"not"       {
                printTokenInfo("NOT", yytext);
                return T_NOT;
            }
"t"         {
                printTokenInfo("T", yytext);
                return T_T;
            }
"nil"       {
                printTokenInfo("NIL", yytext);
                return T_NIL;
            }
{STRCONST}  {
                printTokenInfo("STRCONST", yytext);
				return T_STRCONST;
            }            
{INTCONST}	{
				printTokenInfo("INTCONST", yytext);
				return T_INTCONST;
			}
"<="        {
                printTokenInfo("LE", yytext);
                return T_LE;
            }
">="        {
                printTokenInfo("GE", yytext);
                return T_GE;
            }
"/="        {
                printTokenInfo("NE", yytext);
                return T_NE;
            }
"="         {
                printTokenInfo("EQ", yytext);
                return T_EQ;
            }
"+"         {
                printTokenInfo("ADD", yytext);
                return T_ADD;
            }
"-"         {
                printTokenInfo("SUB", yytext);
                return T_SUB;
            }
"*"         {
                printTokenInfo("MULT", yytext);
                return T_MULT;
            }
"/"         {
                printTokenInfo("DIV", yytext);
                return T_DIV;
            }
"<"         {
                printTokenInfo("LT", yytext);
                return T_LT;
            }
">"         {
                printTokenInfo("GT", yytext);
                return T_GT;
            }
"\("         {
                printTokenInfo("LPAREN", yytext);
                return T_LPAREN;
            }
"\)"         {
                printTokenInfo("RPAREN", yytext);
                return T_RPAREN;
            }
{IDENT}		{
				printTokenInfo("IDENT", yytext);
				yylval.text = strdup(yytext);
				return T_IDENT;
			}
{NEWLINE}	{ numLines++; }
{COMMENT}   { }
{WSPACE}	{ }
.			{
				printTokenInfo("UNKNOWN", yytext);
				return T_UNKNOWN;
			}

%%