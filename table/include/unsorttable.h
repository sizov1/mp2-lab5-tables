#ifndef __UNSORTTABLE_H
#define __UNSORTTABLE_H

#include "table.h"
#include <vector>

// Unsorttable - класс неупорядоченной таблицы 

class Unsorttable : public Table
{
    public:
        void print()
        {
            for (size_t i = 0; i < sizeTab; i++) {
                if (flags[i] == '1') {
                    table[i].print();
                }
            }
        }
    
        Unsorttable(size_t _sizeTab = MAX_SIZE);
        ~Unsorttable();

        size_t GetNumberOperations() { return countOp; }

        void Insert(const string& name, const Polynomial& q) override;
        void Delete(const string& name) override;
        Polynomial& operator [] (const string& name) override;

        vector<string> GetPolynomialsList();
    private:
        char* flags;     // '0' - запись свободна; '1' - занята
        size_t countOp;  // счетчик операций произведенных при 
                         // выполнении последне вызванной фукнции
        
        size_t Find(const string& name);  // функция возращает индекс записи по ключу name 
};

#endif