#include "multitable.h"
#include <locale.h>

ofstream fout;

void OpenFile(string file_name)
{
    fout.open(file_name);
}

void CloseFile()
{
    fout.close();
}

size_t Multitable::GetSizeTab()
{
    size_t utSize = unsortTab.GetSizeTab();
    size_t stSize = sortTab.GetSizeTab();
    size_t htSize = hashTab.GetSizeTab();
    if (( utSize == stSize ) && (utSize == htSize)) {
        return utSize;
    }
    else {
        throw Exception("multitable error: tables are of different sizes");
    }
}

size_t Multitable::GetCurrSize()
{
    size_t utCurrSize = unsortTab.GetCurrSize();
    size_t stSize = sortTab.GetCurrSize();
    size_t htSize = hashTab.GetCurrSize();
    if (( utCurrSize == stSize ) && (utCurrSize == htSize)) {
        return utCurrSize;
    }
    else {
        throw Exception("multitable error: tables are of different sizes");
    }
}

void Multitable::CountOperations()
{
    countOp[0] = unsortTab.GetNumberOperations();
    countOp[1] = sortTab.GetNumberOperations();
    countOp[2] = hashTab.GetNumberOperations();
}

void Multitable::WriteStatistic(string name_func, string name_polynomial)
{
    setlocale(LC_ALL, "Russian");
    fout << "--------------------------------------------------------------------------" << endl;
    fout << "Произведена операция " << name_func << " для полинома " << name_polynomial << endl;
    fout << "Неупорядоченная таблица: " << countOp[0] << " операций " << endl;
    fout << "Упорядоченая таблица: " << countOp[1] << " операций " << endl;
    fout << "Хэш-таблица: " << countOp[2] << " операций" << endl;
}

void Multitable::Insert(const string& name, const Polynomial& q)
{
    unsortTab.Insert(name, q);
    sortTab.Insert(name, q);
    hashTab.Insert(name, q);
    CountOperations();
    WriteStatistic("вставка", name);
}

void Multitable::Delete(const string& name)
{
    try {
	    unsortTab.Delete(name);
        sortTab.Delete(name);
        hashTab.Delete(name);
        CountOperations();
        WriteStatistic("удаление", name);
    }
    catch (Exception exc) {
        throw Exception(exc.GetNameError());
    }
}

Polynomial& Multitable::operator [] (const string& name)
{
    try {
        Polynomial& q = unsortTab[name];
        q = sortTab[name];
        q = hashTab[name];
        CountOperations();
        WriteStatistic("доступа", name);
        return q;
    }
    catch (Exception exc) {
        throw Exception(exc.GetNameError());
    }
}

vector<string> Multitable::GetPolynomialsList()
{
    return unsortTab.GetPolynomialsList();
}