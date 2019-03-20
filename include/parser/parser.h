#ifndef __PARSER_H
#define __PARSER_H
#include <iostream>
#include <string>
#include "multitable.h"
using namespace std;

enum Token_value 
{
    PRINT, END, NAME,
    LP = '(', RP = ')',
    PLUS = '+', MINUS = '-', MUL = '*',
};

struct Token
{
    Token_value tok_value;
    string string_value;
};

extern Token curr;
extern MultiTable tablePolinoms;

double error(const string& s);

Token_value get_token();
Polynomial expr(bool get);
Polynomial term(bool get);
Polynomial prim(bool get);

#endif
