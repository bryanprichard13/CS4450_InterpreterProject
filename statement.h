#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <list>

using std::string;
using std::list;

<<<<<<< HEAD
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
=======
class SymbolTable;
class ExpressionList;
class Number; 

class IfElse : public Statement {
public:
   IfElse(Expression *cond, StatementList* tList, StatementList* fList) : condition(cond), trueList(tList), falseList(fList) { }
   IfElse(Expression *cond, StatementList* tList) : condition(cond), trueList(tList), falseList(new StatementList()) { }
   ~IfElse();

   void check(SymbolTable&, FunctionTable&) const;

private:
   Expression*    condition;
   StatementList* trueList;
   StatementList* falseList;
};


class While : public Statement {
public:
   While(Expression* cond, StatementList* sList) : condition(cond), stmtList(sList) { }
   ~While();

   void check(SymbolTable&, FunctionTable&) const;

private:
   Expression*    condition;
   StatementList* stmtList;
};


class Print : public Statement {
public:
   Print(Expression* e) : exp(e) { }
   ~Print();

   void check(SymbolTable&, FunctionTable&) const;

private:
   Expression* exp;
};

class Comment : public Statement {
public:
   Comment(Expression* e) : exp(e) { }
   ~Comment();

   void check(SymbolTable&, FunctionTable&) const;

private:
   Expression* exp;
};

>>>>>>> 0b6cd257b414dd0560932edb846f961a0d763a3b
#endif
