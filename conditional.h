#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <list>
#include "number.h"

using std::string;
using std::list;

class FunctionTable;
class SymbolTable;
class ExpressionList;
class Number;

class Expression {
public:
   virtual ~Expression() {};
   
   virtual Number eval(const SymbolTable&, const FunctionTable&) const = 0;

protected:
   Expression() { };
};

class BinaryExpression : public Expression {
public:
   ~BinaryExpression();
   
   virtual Number eval(const SymbolTable&, const FunctionTable&) const = 0;

protected:
   BinaryExpression(Expression* e1, Expression* e2) : op1(e1), op2(e2) { }
   Expression* op1;
   Expression* op2;
};

class LessThan : public BinaryExpression {
public:
   LessThan(Expression* e1, Expression *e2) : BinaryExpression(e1, e2) { }
   
   virtual Number eval(const SymbolTable&, const FunctionTable&) const;
};


class GreaterThan : public BinaryExpression {
public:
   GreaterThan(Expression* e1, Expression *e2) : BinaryExpression(e1, e2) { }
   
   virtual Number eval(const SymbolTable&, const FunctionTable&) const;
   
};


class LessThanOrEqualTo : public BinaryExpression {
public:
   LessThanOrEqualTo(Expression* e1, Expression *e2) : BinaryExpression(e1, e2) { }
   
   virtual Number eval(const SymbolTable&, const FunctionTable&) const;
};


class GreaterThanOrEqualTo : public BinaryExpression {
public:
   GreaterThanOrEqualTo(Expression* e1, Expression *e2) : BinaryExpression(e1, e2) { }
   
   virtual Number eval(const SymbolTable&, const FunctionTable&) const;
};


class Equals : public BinaryExpression {
public:
   Equals(Expression* e1, Expression *e2) : BinaryExpression(e1, e2) { }
   
   virtual Number eval(const SymbolTable&, const FunctionTable&) const;
};


class NotEquals : public BinaryExpression {
public:
   NotEquals(Expression* e1, Expression *e2) : BinaryExpression(e1, e2) { }
   
   virtual Number eval(const SymbolTable&, const FunctionTable&) const;
};

#endif