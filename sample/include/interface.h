#ifndef __INTERFACE_H
#define __INTERFACE_H

#include <iostream>
#include "multitable.h"

using namespace std;

extern Multitable table;

enum Action
{
    EXIT, INCORRECT,
    INS, DEL, GET, SET,
    ADD, SUB, MUL, CMUL
};

void InterFace();

void PrintRules();
void PrintAction();

void InsertRecord();
void DeleteRecord();
void PrintRecord();
void AddPolynomial();
void SubPolynomial();
void MulPolynomial();
void CMulPolynomial();
void PrintTable();
void ReadTableFromFile();
void Incorrect();

string EnterName();

#endif