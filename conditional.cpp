#include "symbolTable.h"
#include "expression.h"

Number LessThan::check(const SymbolTable& st, const FunctionTable& ft) const {
   return op1->check(st, ft) < op2->check(st, ft);
}

Number GreaterThan::check(const SymbolTable& st, const FunctionTable& ft) const {
   return op1->check(st, ft) > op2->check(st, ft);
}

Number LessThanOrEqualTo::check(const SymbolTable& st, const FunctionTable& ft) const {
   return op1->check(st, ft) <= op2->check(st, ft);
}

Number GreaterThanOrEqualTo::check(const SymbolTable& st, const FunctionTable& ft) const {
   return op1->check(st, ft) >= op2->check(st, ft);
}

Number Equals::check(const SymbolTable& st, const FunctionTable& ft) const {
   return op1->check(st, ft) == op2->check(st, ft);
}

Number NotEquals::check(const SymbolTable& st, const FunctionTable& ft) const {
   return op1->check(st, ft) != op2->check(st, ft);
}