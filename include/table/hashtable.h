#ifndef __HASHTABLE_H
#define __HASHTABLE_H
#include "table.h"

class HashTable : public Table
{
    public:
        HashTable();
    
        void Insert(Polynomial q);
        void Delete(string name);
        Polynomial& operator [] (const string& name);
};

#endif
