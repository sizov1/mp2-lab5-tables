#ifndef __TABLE_H
#define __TABLE_H
#define MAX_SIZE 1024
#include "polynomial.h"

class Table
{
    private:
        TList<Polynomial>* table[MAX_SIZE];
    public:
        virtual void Insert(Polynomial q) = 0;
        virtual void Delete(string name) = 0;
        virtual Polynomial& operator [] (const string& name) = 0;
};


#endif
