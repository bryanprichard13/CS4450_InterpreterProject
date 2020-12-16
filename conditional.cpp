#include "symbolTable.h"
#include "conditional.h"

Number LessThan::check(const SymbolTable& st) const {
   return op1->check(st) < op2->check(st);
}

Number GreaterThan::check(const SymbolTable& st) const {
   return op1->check(st) > op2->check(st);
}

Number LessThanOrEqualTo::check(const SymbolTable& st) const {
   return op1->check(st) <= op2->check(st);
}

Number GreaterThanOrEqualTo::check(const SymbolTable& st) const {
   return op1->check(st) >= op2->check(st);
}

Number Equals::check(const SymbolTable& st) const {
   return op1->check(st) == op2->check(st);
}

Number NotEquals::check(const SymbolTable& st) const {
   return op1->check(st) != op2->check(st);
}