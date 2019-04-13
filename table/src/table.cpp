#include "table.h"

Table::Table(size_t _sizeTab) : sizeTab(_sizeTab), currSize(0)
{
    table = new Record[_sizeTab];
}

Table::~Table()
{
    if (table) {
        delete[] table;
    }
}