#ifndef __SORTTABLE_H
#define __SORTTABLE_H

#include "table.h"


class Sorttable : public Table
{
    public:    
        void print()
        {
            for (size_t i = 0; i < currSize; i++) {
                table[i].print();
            }
        }
    
        Sorttable(size_t _sizeTab = MAX_SIZE) : Table(_sizeTab), countOp(0) {}

        size_t GetNumberOperations() { return countOp; }

        void Insert(const string& name, const Polynomial& q) override;
        void Delete(const string& name) override;
        Polynomial& operator [] (const string& name) override;
    private:
        size_t countOp;
        size_t search(const string& name, size_t left, size_t right);  // функция бинарного поиска
};

#endif