#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H

#include <string>
using namespace std;

#define UNDEFINED -1
#define FUNCTION 0
#define INT 1 // 0001
#define STR 2 // 0010
#define INT_OR_STR 3 // 0011
#define BOOL 4 
#define INT_OR_BOOL 5
#define STR_OR_BOOL 6
#define INT_OR_STR_OR_BOOL 7

#define NOT_APPLICABLE -1

typedef struct {
  int type;
  int numParams;
  int returnType;
} TypeInfo;

class SymbolTableEntry 
{
private:
  // Member variables
  string name;
  TypeInfo typeInfo;  

public:
  // Constructors
  SymbolTableEntry( ) { name = ""; typeInfo.type = UNDEFINED; typeInfo.numParams = 0; typeInfo.returnType = NOT_APPLICABLE; }

  SymbolTableEntry(const string &name, TypeInfo typeInfo) { this->name = name; this->typeInfo = typeInfo; }

  // Accessors
  string getName() const { return name; }
  int getTypeCode() const { return typeInfo.type; }
  int getNumParams() const { return typeInfo.numParams; }
  int getReturnType() const { return typeInfo.returnType; }
  TypeInfo getTypeInfo() const { return typeInfo; }
};

#endif  // SYMBOL_TABLE_ENTRY_H
