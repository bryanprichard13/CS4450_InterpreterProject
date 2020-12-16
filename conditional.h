#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include <string>
#include <list>
#include "number.h"
#include "arithmetic.h"

using std::string;
using std::list;

class BinaryExpression;
class SymbolTable;
class Number;

class LessThan : public BinaryExpression {
public:
   LessThan(ArithmeticExpression* e1, ArithmeticExpression *e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};


class GreaterThan : public BinaryExpression {
public:
   GreaterThan(ArithmeticExpression* e1, ArithmeticExpression *e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;

};


class LessThanOrEqualTo : public BinaryExpression {
public:
   LessThanOrEqualTo(ArithmeticExpression* e1, ArithmeticExpression *e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};


class GreaterThanOrEqualTo : public BinaryExpression {
public:
   GreaterThanOrEqualTo(ArithmeticExpression* e1, ArithmeticExpression *e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};


class Equals : public BinaryExpression {
public:
   Equals(ArithmeticExpression* e1, ArithmeticExpression *e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};


class NotEquals : public BinaryExpression {
public:
   NotEquals(ArithmeticExpression* e1, ArithmeticExpression *e2) : BinaryExpression(e1, e2) { }

   virtual Number check(const SymbolTable&) const;
};

#endif
