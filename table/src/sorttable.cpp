#include "sorttable.h"

void Sorttable::Insert(const string& name, const Polynomial& q)
{
    countOp = 0;
    
    if (isEmpty()) {
        // таблица пустая => вставляем запись на первое место
        countOp++;
        table[currSize++].init(name, q);
        return;
    }
    else if (isFull()) {
        // вставка в заполненную таблицу невозможна
        throw Exception("cannot insert: table is full");
    }

    size_t ind = 0;  // индекс по которому будем вставлять новую запись

    // ищем место на которое нужно вставить новую запись
    // в порядке возрастания по ключу
    for (size_t i = 0; i < currSize; i++) {
        countOp++;
        if (table[i].key == name) {
            // запись с данным ключем уже есть => 
            // => повторная вставка не производится 
            throw Exception("cannot insert: that polynomial already exist");
        }
        else if (table[i].key > name) {
            break;
        }
        ind++;
    }

    // реалоцируем массив записей для вставки
    countOp++;
    Record* tmp = new Record[sizeTab];   

    // копируем таблицу вставляя на нужное место новую запись
    for (size_t i = 0; i < currSize + 1; i++) {
        countOp++;
        if (i < ind) {
            tmp[i] = table[i];
        }
        else if (i > ind) {
            tmp[i] = table[i - 1];
        }
        else {
            tmp[i].init(name, q);
        }
    }

    delete[] table;
    // сохраняем изменения для данной таблицы
    table = &tmp[0];
    currSize++;
}

size_t Sorttable::search(const string& name, size_t left, size_t right)
{
    countOp = 0;
    size_t mid;
    while (left <= right) {
        countOp++;
        mid = (right&left) + ((right^left) >> 1);

        if (table[mid].key > name) {
            right = mid - 1;
        }
        else if (table[mid].key < name) {
            left = mid + 1;
        }
        else {
            return mid;
        }
    }
    return sizeTab + 1;
}

void Sorttable::Delete(const string& name)
{
    if (isEmpty()) {
        throw Exception("cannot delete: table is empty");
    }

    // ищем номер записи, которую надо удалить
    size_t ind = search(name, 0, currSize - 1);

    if (ind >= sizeTab) {
        throw Exception("cannot delete: polynomial not found");
    }
    // запись с данным ключем существует => удаляем запись
    // реалоцируем массив записей для удаления
    countOp++;
    Record* tmp = new Record[sizeTab];

    // копируем таблицу, удаляя нужную запись
    for (size_t i = 0; i < currSize; i++) {
        countOp++;
        if (i < ind) {
            tmp[i] = table[i];
        }
        else if (i > ind) {
            tmp[i - 1] = table[i];
        }
    }

    delete[] table;
    // сохраняем изменения для данной таблицы
    table = &tmp[0];
    currSize--;
}

Polynomial& Sorttable::operator [] (const string& name)
{
    if (isEmpty()) {
        throw Exception("cannot []: table is empty");
    }

    // ищем номер записи с заданным ключем
    size_t ind = search(name, 0, currSize - 1);

    if (ind < sizeTab) {
        // запись с данным ключем существует => возращаем полином
        return table[ind].data;
    }
    else {
        // запись не найдена => ошибка 
        throw Exception("cannot []: polynomial not found");
    }
}