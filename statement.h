#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <list>

using std::string;
using std::list;

extern int yylineno;

class SymbolTable;
class ArithmeticExpression;

class Statement {
public:
  virtual ~Statement() {};

  virtual void check(SymbolTable&) const = 0;
  virtual int getLine() const;

protected:
  Statement()      : line(yylineno-1) {}
  Statement(int i) : line(i) {}
  int line;
};

class Assignment : public Statement {
public:
  Assignment(const string& str, ArithmeticExpression *e) : name(str), arithExp(e) {}
  ~Assignment();

  void check(SymbolTable&) const;

private:
  string name;
  ArithmeticExpression* arithExp;

};
#endif
