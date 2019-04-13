#include "unsorttable.h"

Unsorttable::Unsorttable(size_t _maxSize) : Table(_maxSize), countOp(0)
{
    flags = new char[sizeTab];
    for (size_t i = 0; i < sizeTab; i++) {
        flags[i] = '0';
    }
}

Unsorttable::~Unsorttable()
{
    if (flags) {
        delete[] flags;
    }
}

void Unsorttable::Insert(const string& name, const Polynomial& q)
{
    countOp = 0;

    // таблица заполнена => вставка невозможна
    if (isFull()) {
        throw Exception("cannot insert: table is full");
    }

    for (size_t i = 0; i < sizeTab; i++) {
        // ищем свободное место 
        countOp++;
        // полином с таким именем уже есть => вставка не производится
        if (table[i].key == name) {
            throw Exception("cannot insert: that polynomial already exist");
        }
        if (flags[i] == '0') {
            // если место свободно инициализируем запись на этом месте
            table[i].init(name, q);
            // помечаем данное место как занятое
            flags[i] = '1';
            // увеличиваем текущий размер таблицы
            currSize++;
            return;
        }
    }
}

size_t Unsorttable::Find(const string& name)
{
    // ищем запись с заданным ключом name
    for (size_t i = 0; i < sizeTab; i++) {
        countOp++;
        if (name == table[i].key && flags[i] == '1') {
            // нашли нужную запись => возрашаем её номер в таблице
            return i;
        }
    }
    // запись по ключу отсутсвует => возращаем некорретное значение 
    return sizeTab + 1;
}

void Unsorttable::Delete(const string& name)
{
    countOp = 0;

    // таблица пуста => удаление невозможно
    if (isEmpty()) {
        throw Exception("cannot delete: table is empty");
    }

    // ищем номер записи, которую надо удалить
    size_t ind = Find(name);
    
    if (ind < sizeTab) {
        // нашли нужную запись помечаем её как свободную
        flags[ind] = '0';
        // уменьшаем текущий размер
        currSize--;
        return;
    }
    else {
        // нужной записи нет => ошибка
        throw Exception("cannot delete: polynomial not found");
    }

}

Polynomial& Unsorttable::operator [] (const string& name)
{
    if (isEmpty()) {
        throw Exception("cannot []: table is empty");
    }

    countOp = 0;
    // ищем номер нужной записи по ключу
    size_t ind = Find(name);
    
    if (ind < sizeTab) {
        // нужная запись есть в таблице => возращаем полином
        return table[ind].data;
    }
    else {
        // нужная запись отсутсвует в таблице => ошибка
        throw Exception("cannot []: record not found");
    }
    
	return table[0].data;
}

vector<string> Unsorttable::GetPolynomialsList()
{
    vector<string> polynomialsList;
    for (size_t i = 0; i < sizeTab; i++) {
        if (flags[i] == '1') {
            polynomialsList.push_back(table[i].key);
        }
    }
    return polynomialsList;
}

// я закончил вроде как писать