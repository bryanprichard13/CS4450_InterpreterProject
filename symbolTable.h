#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <string>

using std::map;
using std::string;

class Number;

class SymbolTable {
public:
  Number operator[](const string&) const;
  Number& operator[](const string&);

private:
  map<string,Number> symbolTable;
};

#endif
