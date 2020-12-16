%{

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "arithmetic.h"
#include "conditional.h"
#include "statement.h"

using std::cout;
using std::cerr;
using std::endl;

extern int yylineno;
extern int yylex();
extern int yyparse();

bool error = false;

void yyerror(const char* s) {
   // bision seems to call both versions of yyerror, check a flag to supress the duplicate message
   if (!error) {
      cerr << "error (line " << yylineno << "): " << s << endl;
   }
}

void yyerror(const char* s, char c) {
   cerr << "error (line " << yylineno << "): " << s << " \"" << c << "\"" << endl;
   error = true;
}
%}

%union {
     int                       int_value;
     float                   float_value;
     char*                        string;
     ArithmeticExpression*    expression;
     Statement*                statement;
     StatementList*       statement_list;
     ExpressionList*            exp_list;
}

%token <int_value>       TOKEN_INT
%token <float_value>     TOKEN_FLOAT
%token <string>    TOKEN_STRING
%token PLUSEQ  "+="
%token MINUSEQ "-="
%token TIMESEQ  "*="
%token DIVEQ   "/="
%token POWEQ   "^="
%token MODEQ   "%="
%token LE      "<="
%token GE      ">="
%token EQ      "=="
%token NE      "!="
%token PRINT   "print"


%left '+' '-'
%left '*' '/' '%' '^'
%nonassoc UMINUS

%type <expression> exp
%type <statement> statement
%type <statement> assign
%type <statement> print
%type <statement_list> statement_list
%type <exp_list> exp_list

%%

statement : assign
          | print
          ;

statement_list  : statement_list statement
                     {
                     $1->add($2);
                     $$ = $1;
                     }
                | statement
                     {
                     StatementList* sl = new StatementList;
                     sl->add($1);
                     $$ = sl;
                     }
                ;

assign    : TOKEN_STRING '=' exp
            {
              $$ = new Assignment($1, $3);
              delete [] $1;
            }

          | TOKEN_STRING PLUSEQ exp
            {
              $$ = new Assignment($1, new Add(new Identity($1), $3));
              delete [] $1;
            }

          | TOKEN_STRING MINUSEQ exp
            {
              $$ = new Assignment($1, new Subtract(new Identity($1), $3));
              delete [] $1;
            }

          | TOKEN_STRING TIMESEQ exp
            {
              $$ = new Assignment($1, new Multiply(new Identity($1), $3));
              delete [] $1;
            }

          | TOKEN_STRING DIVEQ exp
            {
              $$ = new Assignment($1, new Divide(new Identity($1), $3));
              delete [] $1;
            }

          | TOKEN_STRING POWEQ exp
            {
              $$ = new Assignment($1, new Exponent(new Identity($1), $3));
              delete [] $1;
            }

          | TOKEN_STRING MODEQ exp
            {
              $$ = new Assignment($1, new Mod(new Identity($1), $3));
              delete [] $1;
            };

exp       :
            '(' exp ')'          { $$ = $2; }
          | TOKEN_INT            { $$ = new Constant($1); }
          | TOKEN_FLOAT          { $$ = new Constant($1); }
          | TOKEN_STRING         { $$ = new Identity($1); delete [] $1; }
          | exp '+' exp          { $$ = new Add($1, $3); }
          | exp '-' exp          { $$ = new Subtract($1, $3); }
          | exp '*' exp          { $$ = new Multiply($1, $3); }
          | exp '/' exp          { $$ = new Divide($1, $3); }
          | exp '%' exp          { $$ = new Mod($1, $3); }
          | exp '^' exp          { $$ = new Exponent($1, $3); }
          | exp '<' exp          { $$ = new LessThan($1, $3); }
          | exp '>' exp          { $$ = new GreaterThan($1, $3); }
          | exp LE exp           { $$ = new LessThanOrEqualTo($1, $3); }
          | exp GE exp           { $$ = new GreaterThanOrEqualTo($1, $3); }
          | exp EQ exp           { $$ = new Equals($1, $3); }
          | exp NE exp           { $$ = new NotEquals($1, $3); }
          | '-' exp %prec UMINUS { $$ = new Negative($2); };

print     : PRINT exp
              {
              cout << "HEY";
              $$ = new Print($2); }
          ;

exp_list : /* empty*/
                     { $$ = new ExpressionList(); }
                | exp_list ',' exp
                     { $1->add($3);
                       $$ = $1;
                     }
                | exp
                     { ExpressionList* el = new ExpressionList();
                       el->add($1);
                       $$ = el;
                     }
                ;


%%
