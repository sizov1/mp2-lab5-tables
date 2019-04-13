#ifndef __MULTITABLE_H
#define __MULTITABLE_H

#include "unsorttable.h"
#include "sorttable.h"
#include "hashtable.h"
#include <fstream>

extern ofstream fout;

void OpenFile(string file_name);

void CloseFile();

class Multitable 
{
    public:
        Multitable(size_t _sizeTab = MAX_SIZE) : 
            unsortTab(_sizeTab), sortTab(_sizeTab), hashTab(_sizeTab) {}
        
        size_t GetSizeTab();
        size_t GetCurrSize();
              
        void Insert(const string& name, const Polynomial& q);
        void Delete(const string& name);
        Polynomial& operator [] (const string& name);

        vector<string> GetPolynomialsList();
    private:
        Unsorttable unsortTab;
        Sorttable sortTab;
        Hashtable hashTab;
        size_t countOp[3]; // [0] - unsortTab, [1] - sortTab, [2] - hashTab

        void CountOperations();
        void WriteStatistic(string name_func, string name_polynomial);
};  

#endif