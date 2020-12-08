#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <list>
#include "number.h"

using std::string;
using std::list;

class SymbolTable;
class ExpressionList;
class Number;

class ArithmeticExpression {
public:
   virtual ~ArithmeticExpression() {};
   
   virtual Number check(const SymbolTable&) const = 0;

protected:
   ArithmeticExpression() { };
};


class Constant : public ArithmeticExpression {
public:
   Constant(const Number& n) : num(n) { }

   virtual Number check(const SymbolTable&) const;
private:
   Number num;
};


class Identity : public ArithmeticExpression {
public:
   Identity(const string& n) : name(n) { }

   virtual Number check(const SymbolTable&) const;
private:
   string name;
};


class Negative : public ArithmeticExpression {
public:
   Negative(ArithmeticExpression* e) : operand(e) { }
   ~Negative();
   
   virtual Number check(const SymbolTable&) const;

private:
   ArithmeticExpression* operand;
};

class BinaryExpression : public ArithmeticExpression {
public:
   ~BinaryExpression();

   virtual Number check(const SymbolTable&) const;

protected:
   BinaryExpression(ArithmeticExpression* e1, ArithmeticExpression* e2) : operand1(e1), operand2(e2) { }
   ArithmeticExpression* operand1;
   ArithmeticExpression* operand2;
};


class Add : public BinaryExpression {
public:
   Add(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};


class Subtract : public BinaryExpression {
public:
   Subtract(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};


class Multiply : public BinaryExpression {
public:
   Multiply(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};


class Divide : public BinaryExpression {
public:
   Divide(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};


class Mod : public BinaryExpression {
public:
   Mod(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};


class Exponent : public BinaryExpression {
public:
   Exponent(ArithmeticExpression* e1, ArithmeticExpression* e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};

#endif