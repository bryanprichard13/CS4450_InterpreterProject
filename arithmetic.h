#ifndef ArithmeticExpression_H
#define ArithmeticExpression_H

#include <string>
#include <list>
#include "number.h"

using std::string;
using std::list;

class SymbolTable;
class ExpressionList;
class Number; 

class ArithmeticExpression {
    virtual Number check(const SymbolTable&) const;
};

class Constant : public ArithmeticExpression {
public:
   Constant(const Number& n) : num(n) { }

private:
   Number num;
};

class Identity : public ArithmeticExpression {
public:
   Identity(const string& n) : name(n) { }

private:
   string name;
};

class Negative : public ArithmeticExpression {
public:
   Negative(ArithmeticExpression* e) : negative(e) { }

private:
   ArithmeticExpression* negative;
};

class BinaryExpression : public ArithmeticExpression {
protected:
   BinaryExpression(Expression* e1, Expression* e2) : op1(e1), op2(e2) { }
   Expression* op1;
   Expression* op2;
};

class Add : public BinaryExpression {
public:
   Add(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }
};

class Subtract : public BinaryExpression {
public:
   Subtract(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }
};

class Multiply : public BinaryExpression {
public:
   Multiply(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }
};

class Divide : public BinaryExpression {
public:
   Divide(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }
};

class Mod : public BinaryExpression {
public:
   Mod(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }
};

class Exponent : public BinaryExpressionn {
public:
   Exponent(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }
};


#endif
