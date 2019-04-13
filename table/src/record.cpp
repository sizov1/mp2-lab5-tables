#include "record.h"

void Record::init(string _key, Polynomial _data)
{
    key = _key;
    data = _data;
}

const Record& Record::operator = (const Record& rec)
{
    if (this != &rec) {
        key = rec.key;
        data = rec.data;
    }
    return *this;
}

void Record::print()
{
    cout << key << ": " << endl << data;
}