#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H

#include <string>
using namespace std;

#define UNDEFINED -1
#define FUNCTION 0
#define INT 1
#define STR 2
#define INT_OR_STR 3
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
  SymbolTableEntry( ) { name = ""; typeInfo.type = UNDEFINED; }

  SymbolTableEntry(const string &name, const int type) { makeTableEntry(name, type, 0, NOT_APPLICABLE); }

  SymbolTableEntry(const string &name, const int type, const int numParams, const int returnType) { makeTableEntry(name, type, numParams, returnType); }

  void makeTableEntry(const string &name, const int type, const int numParams, const int returnType) {
    this->name = name;
    this->typeInfo.type = type;
    this->typeInfo.numParams = numParams;
    this->typeInfo.returnType = returnType;
  }

  // Accessors
  string getName() const { return name; }
  int getTypeCode() const { return typeInfo.type; }
  int getNumParams() const { return typeInfo.numParams; }
  int getReturnType() const { return typeInfo.returnType; }
  TypeInfo getTypeInfo() const { return typeInfo; }
};

#endif  // SYMBOL_TABLE_ENTRY_H
