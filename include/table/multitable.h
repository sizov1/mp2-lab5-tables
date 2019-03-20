#ifndef __MULTITABLE_H
#define __MULTITABLE_H

#include "unsorttable.h"
#include "sorttable.h"
#include "hashtable.h"

class MultiTable
{
    private:
        UnsortTable unsort_table;
        SortTable sort_table;
        HashTable hash_table;
        unsigned countOperations[3];
    public:
        MultiTable();
    
        void Insert(Polynomial q);
        void Delete(string name);
        Polynomial& operator [] (const string& name);
};

#endif 
