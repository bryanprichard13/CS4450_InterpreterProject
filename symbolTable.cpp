#include "symbolTable.h"
#include "number.h"

Number SymbolTable::operator[](const string& identity) const {
  if(symbolTable.count(identity) == 0) {
    return Number();
  }

  return symbolTable.find(identity)->second;
}

Number& SymbolTable::operator[](const string& identity) {
  return symbolTable[identity];
}
