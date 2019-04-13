#include "hashtable.h"

size_t Hashtable::Murmurhash2(const string& s_key)
{
    countOp = 0;
    size_t len = s_key.length() + 1;
    const size_t m = 0x5bd1e995;
    const size_t seed = 0;
    const int r = 24;
    size_t hash = seed ^ len;
    const char* key = s_key.c_str();
    const unsigned char* data = (const unsigned char*)key;
    size_t k;

    while (len >= 4) {
        countOp++;
        k = data[0];
        k |= data[1] << 8;
        k |= data[2] << 16;
        k |= data[3] << 24;
        k *= m;
        k ^= k >> r;
        k *= m;
        hash *= m;
        hash ^= k;
        data += 4;
        len -= 4;
    }

    switch (len) {
    case 3:
        hash ^= data[2] << 16;
    case 2:
        hash ^= data[1] << 8;
    case 1:
        hash ^= data[0];
    }

    hash ^= hash >> 3;
    hash *= m;
    hash ^= hash >> 15;

    return hash % sizeTab;
}

void Hashtable::Insert(const string& name, const Polynomial& q)
{
    if (isFull()) {
        throw Exception("cannot insert: table is full");
    }
        
    size_t hash = Murmurhash2(name);
    size_t i = 0;
    // ищем нужное место для вставки с помощью линейного пробирования
    while (!table[hash].isDefault()) {
        if (table[hash].key == name) {
            throw Exception("cannot insert: that polynomial already exist");
        }
        countOp++;
        hash = (hash + i) % sizeTab;
        i++;
    }

    // вставляем запись на найденное место
    countOp++; 
    table[hash].init(name, q);
    currSize++;
}

size_t Hashtable::find(const string& name)
{
    size_t hash = Murmurhash2(name);
    size_t i = 0;
    while (table[hash].key != name && i != sizeTab) {
        countOp++;
        hash = (hash + i) % sizeTab;
        i++;
    }

    if (i != sizeTab) {
        return hash;
    }
    else {
        return sizeTab;
    } 
}

void Hashtable::Delete(const string& name)
{
    if (isEmpty()) {
        throw Exception("cannot delete: table is empty");
    }

    // ищем номер записи, которую удаляем
    size_t ind = find(name);

    if (ind < sizeTab) {
        table[ind].SetDefault();
        currSize--;
    }
    else {
        throw Exception("cannot delete: polynomial not found");
    }
}

Polynomial& Hashtable::operator [] (const string& name)
{
    if (isEmpty()) {
        throw Exception("cannot []: table is empty");
    }

    // ищем номер нужной записи по ключю
    size_t ind = find(name);

    if (ind < sizeTab) {
        // запись с данным ключем есть => возращаем полином
        return table[ind].data;
    }
    else {
        throw Exception("cannot []: polynomial not found");
    }
}