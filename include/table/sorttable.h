#ifndef __SORTTABLE_H
#define __SORTTABLE_H

#include "table.h"

class SortTable : public Table
{
    public:
        SortTable();

        void Insert(Polynomial q);
        void Delete(string name);
        Polynomial& operator [] (const string& name);
};

#endif
