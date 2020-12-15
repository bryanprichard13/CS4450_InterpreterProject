#include "symbolTable.h"

Number SymbolTable::operator[](const string& identity) const {
  if(symbolTable.count(identity) == 0) {
    return new Number(-1);
  }

  return symbolTable.find(ident)->second;
}

Number& SymbolTable::operator[](const string& identity) {
  return symbolTable[identity];
}
