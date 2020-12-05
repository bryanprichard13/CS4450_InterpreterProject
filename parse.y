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

%token <int_value> TOKEN_INT
%token <float_value> TOKEN_float
%token TOKEN_ADD         "+"
%token TOKEN_MINUS       "-"
%token TOKEN_MULTIPLY    "*"
%token TOKEN_DIVIDE      "/"
%token TOKEN_MOD         "%"
%token TOKEN_EXPO        "^"
%token TOKEN_LEFT
%token TOKEN_RIGHT

%left TOKEN_ADD TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_DIVIDE TOKEN_MOD TOKEN_EXPO
%

%%
