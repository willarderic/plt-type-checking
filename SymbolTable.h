#ifndef SYMBOL_TABLE_H

#define SYMBOL_TABLE_H

#include <map>
#include <string>
#include "SymbolTableEntry.h"
using namespace std;

class SymbolTable
{
private:
  std::map<string, SymbolTableEntry> hashTable;

public:
  //Constructor
  SymbolTable( ) { }

  // Add SYMBOL_TABLE_ENTRY x to this symbol table.
  // If successful, return true; otherwise, return false.
  bool addEntry(SymbolTableEntry x)
  {
    // Make sure there isn't already an entry with the same name
    map<string, SymbolTableEntry>::iterator itr;
    if ((itr = hashTable.find(x.getName())) == hashTable.end())
    {
      hashTable.insert(make_pair(x.getName(), x));
      return(true);
    }
    else return(false);
  }

  // If a SYMBOL_TABLE_ENTRY with name theName is
  // found in this symbol table, then return true;
  // otherwise, return false.
  bool findEntry(string theName)
  {
    map<string, SymbolTableEntry>::iterator itr;
    if ((itr = hashTable.find(theName)) == hashTable.end())
      return(false);
    else return(true);
  }

  TypeInfo getEntryType(string entry) {
    return hashTable.find(entry)->second.getTypeInfo();
  }

  // returns the number of entries in the current scope
  int getNumParams() {
    return hashTable.size();
  }

};

#endif  // SYMBOL_TABLE_H
