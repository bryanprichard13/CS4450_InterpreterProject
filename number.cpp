#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
//#include "exception.h"
#include "number.h"

using std::ostream;
using std::fixed;

Number Number::operator+(const Number& number) {
    switch(type){
        case (INT):
            if (number.type == INT) { return Number(value.i + number.value.i); }
            else { return Number(value.i + number.value.d); }
            break;
        case (FLOAT):
            if (number.type == FLOAT) { return Number(value.d + number.value.d); }
            else {return Number(value.d + number.value.i);  }
            break;
        default:
            exit(EXIT_FAILURE);
    }
}

Number Number::operator-(const Number& number) {
    switch(type){
        case (INT):
            if (number.type == INT) { return Number(value.i - number.value.i); }
            else { return Number(value.i - number.value.d); }
            break;
        case (FLOAT):
            if (number.type == FLOAT) { return Number(value.d - number.value.d); }
            else {return Number(value.d - number.value.i);  }
            break;
        default:
            exit(EXIT_FAILURE);
    }
}

Number Number::operator*(const Number& number) {
    switch(type){
        case (INT):
            if (number.type == INT) { return Number(value.i * number.value.i); }
            else { return Number(value.i * number.value.d); }
            break;
        case (FLOAT):
            if (number.type == FLOAT) { return Number(value.d * number.value.d); }
            else {return Number(value.d * number.value.i);  }
            break;
        default:
            //throw UnknownType();
            exit(EXIT_FAILURE);
    }
}

Number Number::operator/(const Number& number) {
    switch(type){
        case (INT):
            if (number.type == INT) { return Number(value.i / number.value.i); }
            else { return Number(value.i / number.value.d); }
            break;
        case (FLOAT):
            if (number.type == FLOAT) { return Number(value.d / number.value.d); }
            else {return Number(value.d / number.value.i);  }
            break;
        default:
            //throw UnknownType();
            exit(EXIT_FAILURE);
    }
}

Number Number::operator%(const Number& number) {
    switch(type){
        case (INT):
            if (number.type == INT) {
                if (number.value.i == 0) { /*throw ModByZero();*/exit(EXIT_FAILURE);}
                return Number(value.i % number.value.i);
                }
            else { /*throw FloatingPointMod(); */exit(EXIT_FAILURE);}
            break;
        case (FLOAT):
            //throw FloatingPointMod();
            exit(EXIT_FAILURE);
            break;
        default:
          exit(EXIT_FAILURE);
            //throw UnknownType();
    }
}

ostream& operator<<(ostream& out, const Number& num) {
   if (num.type == INT) {
      return out << num.value.i;
   } else if (num.type == FLOAT) {
      return out << fixed << num.value.d;
   } else {
      // throw UnknownType();
      exit(EXIT_FAILURE);
   }
}

Number Number::operator^(const Number& number) {
    switch(type){
        case (INT):
            if (number.type == INT) { return Number(pow(value.i, number.value.i)); }
            else { return Number(pow(value.i, number.value.d)); }
            break;
        case (FLOAT):
            if (number.type == FLOAT) { return Number(pow(value.d, number.value.d)); }
            else {return Number(pow(value.d, number.value.i));  }
            break;
        default:
            //throw UnknownType();
            exit(EXIT_FAILURE);
    }
}


Number& Number::operator=(const Number& to_be_assigned) {
   type  = to_be_assigned.type;
   value = to_be_assigned.value;
   return *this;
}

Number& Number::operator+=(const Number& to_be_assigned) {
   *this = *this + to_be_assigned;
   return *this;
}

Number& Number::operator-=(const Number& to_be_assigned) {
   *this = *this - to_be_assigned;
   return *this;
}

Number& Number::operator*=(const Number& to_be_assigned) {
   *this = *this * to_be_assigned;
   return *this;
}

Number& Number::operator/=(const Number& to_be_assigned) {
   *this = *this / to_be_assigned;
   return *this;
}

Number& Number::operator%=(const Number& to_be_assigned) {
   *this = *this % to_be_assigned;
   return *this;
}

Number& Number::operator^=(const Number& to_be_assigned) {
   *this = *this ^ to_be_assigned;
   return *this;
}
bool operator==(const Number& lhs, const Number& rhs) {
   if (lhs.type == INT && rhs.type == INT) {
      return lhs.value.i == rhs.value.i;
   } else if (lhs.type == FLOAT && rhs.type == FLOAT) {
      return lhs.value.f == rhs.value.f;
   } else if (lhs.type == INT && rhs.type == FLOAT) {
      return lhs.value.i == rhs.value.f;
   } else if (lhs.type == FLOAT && rhs.type == INT) {
      return lhs.value.f == rhs.value.i;
   } else {
      //throw UnknownType();
   }
}

bool operator!=(const Number& lhs, const Number& rhs) {
   return !(lhs == rhs);
}

bool operator<(const Number& lhs, const Number& rhs) {
   if (lhs.type == INT && rhs.type == INT) {
      return lhs.value.i < rhs.value.i;
   } else if (lhs.type == FLOAT && rhs.type == FLOAT) {
      return lhs.value.f < rhs.value.f;
   } else if (lhs.type == INT && rhs.type == FLOAT) {
      return lhs.value.i < rhs.value.f;
   } else if (lhs.type == FLOAT && rhs.type == INT) {
      return lhs.value.f < rhs.value.i;
   } else {
      //throw UnknownType();
   }
}

bool operator>(const Number& lhs, const Number& rhs) {
   if (lhs.type == INT && rhs.type == INT) {
      return lhs.value.i > rhs.value.i;
   } else if (lhs.type == FLOAT && rhs.type == FLOAT) {
      return lhs.value.f > rhs.value.f;
   } else if (lhs.type == INT && rhs.type == FLOAT) {
      return lhs.value.i > rhs.value.f;
   } else if (lhs.type == FLOAT && rhs.type == INT) {
      return lhs.value.f > rhs.value.i;
   } else {
      //throw UnknownType();
   }
}

bool operator<=(const Number& lhs, const Number& rhs) {
   return !(lhs > rhs);
}

bool operator>=(const Number& lhs, const Number& rhs) {
   return !(lhs < rhs);
}
