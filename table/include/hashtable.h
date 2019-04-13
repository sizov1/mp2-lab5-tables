#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include "table.h"


class Hashtable : public Table
{
    public:    
        void print() 
        {
            for (size_t i = 0; i < sizeTab; i++) {
                if (!table[i].isDefault()) {
                    table[i].print();
                }
            }
        }

        Hashtable(size_t _sizeTab = MAX_SIZE) : Table(_sizeTab), countOp(0) {}
   
        size_t GetNumberOperations() { return countOp; }

        void Insert(const string& name, const Polynomial& q) override;
        void Delete(const string& name) override;
        Polynomial& operator [] (const string& name) override;
    private:
        size_t countOp;
       
        size_t Murmurhash2(const string& s_key);  // hash function
        size_t find(const string& name);  
};

#endif