#ifndef __TABLE_H
#define __TABLE_H
#define MAX_SIZE 1024
#include "polynomial.h"
#include "record.h"

// Table - базовый абстрактный класс таблицы 

class Table
{
    public:
        size_t GetCurrSize() { return currSize; }
        size_t GetSizeTab() { return sizeTab; }

        bool isFull() { return currSize == sizeTab; }
        bool isEmpty() { return currSize == 0; }

        virtual void Insert(const string& name, const Polynomial& q) = 0;
        virtual void Delete(const string& name) = 0;
        virtual Polynomial& operator [] (const string& name) = 0;
    protected:
        Record* table;
        size_t currSize;
        size_t sizeTab;

        Table(size_t size = MAX_SIZE);
        virtual ~Table();
};

#endif