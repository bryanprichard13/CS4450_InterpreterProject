%{

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

extern int yylineno;
extern int yylex();
extern int yyparse();

%}

%union {
     int       int_value;
     float     float_value;
}

%token <int_value> TOKEN-INT
%token <float_value> TOKEN-float
%token TOKEN-ADD         "+"
%token TOKEN-MINUS       "-"
%token TOKEN-MULTIPLY    "*"
%token TOKEN-DIVIDE      "/"
%token TOKEN-MOD         "%"
%token TOKEN-EXPO        "^"
%token TOKEN-LEFT
%token TOKEN-RIGHT

%left TOKEN-ADD TOKEN-MINUS
%left TOKEN-MULTIPLY TOKEN-DIVIDE TOKEN-MOD TOKEN-EXPO
%

%%
