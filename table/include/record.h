#ifndef __RECORD_H
#define __RECORD_H

#include <string>
#include <iostream>
#include "polynomial.h"

using std::string;
using std::cout;
using std::endl;

// Record - класс записи в таблице

class Record
{
    public:
        Record(string _key, Polynomial _data) : key(_key), data(_data) {}
        Record() : key("&&&"), data() {}

        void init(string _key, Polynomial _data);
        void print();
        void SetDefault() { key = "&&&"; }

        const Record& operator = (const Record& rec);
    
        bool operator > (const Record& rec) const { return key > rec.key; }
        bool operator < (const Record& rec) const { return key < rec.key; }
        bool operator == (const Record& rec) const { return key == rec.key; }
        bool isDefault() { return key == "&&&"; }

        friend class Unsorttable;
        friend class Sorttable;
        friend class Hashtable;

    private:
        Polynomial data;
        string key;
};

#endif