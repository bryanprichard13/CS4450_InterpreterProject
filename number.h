#ifndef NUMBER_H
#define NUMBER_H

#include <iosfwd>

using std::ostream;

typedef enum Type {
   INT,
   FLOAT
} Type;

typedef union Value {
   Value(int    _int) : i(_int) { }
   Value(double _double) : d(_double) { }

   int    i;
   double d;
} Value;

class Number {
public:
   Number()                   : type(INT),   value(0)     { }
   Number(const int    input) : type(INT),   value(input) { }
   Number(const double input) : type(FLOAT), value(input) { }

   Number  operator+  (const Number&);
   Number  operator-  (const Number&);
   Number  operator*  (const Number&);
   Number  operator/  (const Number&);
   Number  operator%  (const Number&);
   Number  operator^  (const Number&);

   Number& operator=  (const Number&);
   Number& operator+= (const Number&);
   Number& operator-= (const Number&);
   Number& operator*= (const Number&);
   Number& operator/= (const Number&);
   Number& operator^= (const Number&);
   Number& operator%= (const Number&);

   friend bool     operator<  (Number&, Number&);
   friend bool     operator<= (Number&, Number&);
   friend bool     operator>  (Number&, Number&);
   friend bool     operator>= (Number&, Number&);
   friend bool     operator== (Number&, Number&);
   friend bool     operator!= (Number&, Number&);



private:
   Type  type;
   Value value;
};

#endif
