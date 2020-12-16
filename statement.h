#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <list>

using std::string;
using std::list;

class SymbolTable;
class ExpressionList;
class Number; 

class IfElse : public Statement {
public:
   IfElse(Expression *cond, StatementList* tList, StatementList* fList) : condition(cond), trueList(tList), falseList(fList) { }
   IfElse(Expression *cond, StatementList* tList) : condition(cond), trueList(tList), falseList(new StatementList()) { }

   void check(SymbolTable&) const;

private:
   Expression*    condition;
   StatementList* trueList;
   StatementList* falseList;
};


class While : public Statement {
public:
   While(Expression* cond, StatementList* sList) : condition(cond), stmtList(sList) { }

   void check(SymbolTable&) const;

private:
   Expression*    condition;
   StatementList* stmtList;
};

class For : public Statement {
public:
   For(Expression* cond, Expression* state, Expression* action StatementList* sList) : condition(cond), condition(state), condition(action), stmtList(sList) { }

   void check(SymbolTable&) const;

private:
   Expression*    condition;
   StatementList* stmtList;
}

class Print : public Statement {
public:
   Print(Expression* e) : exp(e) { }

   void check(SymbolTable&, FunctionTable&) const;

private:
   Expression* exp;
};

#endif
