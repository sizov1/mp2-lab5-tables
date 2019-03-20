#ifndef __UNSORTTABLE_H
#define __UNSORTTABLE_H
#include "table.h"

class UnsortTable : public Table
{
    public:
        UnsortTable();

        void Insert(Polynomial q);
        void Delete(string name);
        Polynomial& operator [] (const string& name);
};

#endif
