#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <list>

using std::string;
using std::list;

extern int yylineno;

class SymbolTable;
class ArithmeticExpression;
class ExpressionList;
class Number;

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

class StatementList {
public:
   ~StatementList();

   void check(SymbolTable&) const;
   void add(Statement*);

private:
   list<Statement*> stmtList;
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


class IfElse : public Statement {
public:

   IfElse(ArithmeticExpression *cond, StatementList* tList, StatementList* fList) : condition(cond), trueList(tList), falseList(fList) { }
   IfElse(ArithmeticExpression *cond, StatementList* tList) : condition(cond), trueList(tList), falseList(new StatementList()) { }
   ~IfElse();

   void check(SymbolTable&) const;

private:
   ArithmeticExpression*    condition;
   StatementList* trueList;
   StatementList* falseList;
};


class While : public Statement {
public:

   While(ArithmeticExpression* cond, StatementList* sList) : condition(cond), stmtList(sList) { }
   ~While();

   void check(SymbolTable&) const;

private:
   ArithmeticExpression*    condition;
   StatementList* stmtList;
};

class For : public Statement {
public:

   For(ArithmeticExpression* cond, ArithmeticExpression* stat, ArithmeticExpression* act, StatementList* sList) : condition(cond), state(stat), action(act), stmtList(sList) { }

   void check(SymbolTable&) const;

private:
   ArithmeticExpression*    condition;
   ArithmeticExpression*    state;
   ArithmeticExpression*    action;
   StatementList* stmtList;
};

class Print : public Statement {
public:
   Print(ArithmeticExpression* e) : exp(e) { }
   ~Print();

   void check(SymbolTable&) const;

private:
   ArithmeticExpression* exp;
};

#endif
