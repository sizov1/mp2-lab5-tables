#include "interface.h"

Multitable table;

string EnterName()
{
    string str;
    cin >> str;
    return str;
}

void PrintLogFile(string str)
{
    fout << str;
}

int YesNoMessage(string msg)
{
    cout << msg << " 1 - Да; 2 - нет |" << endl;
    string sAct;
    cin >> sAct;
    try {
        int act = stoi(sAct);
        if (act == 2) {
            return 2;
        }
    }
    catch (Exception exc) {
        cout << "| Некорректный ввод " << endl;
        return -1;
    }
    return 1;
}

vector<string> ArgumentsList()
{
    vector<string> argumentsList;
    char ch = cin.get();
    while ((ch = cin.get()) != '\n') {
        cin.putback(ch);
        argumentsList.push_back(EnterName());
    }
    return argumentsList;
}

void PrintRules()
{
    setlocale(LC_ALL, "Russian");
    cout << "| Выполнение арифметических действий над полиномами трех переменных  |" << endl;
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "|  Данная прогрмма предоствляет пользователю следующий функционал:   |" << endl;
    cout << "|   * задать полином и положить его в таблицу                        |" << endl;
    cout << "|   * удалить полином из таблицы                                     |" << endl;
    cout << "|   * вывести полином (по имени)                                     |" << endl;
    cout << "|   * складывать/вычитать полиномы                                   |" << endl;
    cout << "|   * перемножать полиномы                                           |" << endl;
    cout << "|   * умножать полиномы на константу                                 |" << endl;
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Все полиномы задаются в следующем формате:                         |" << endl;
    cout << "|    <имя полинома>                                                  |" << endl;
    cout << "|    <количество мономов в полиноме>                                 |" << endl;
    cout << "|    <мономы>                                                        |" << endl;
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Формат задания мономов:                                            |" << endl;
    cout << "|    <коэфициент> <свертка степени>,                                 |" << endl;
    cout << "| свертка степени - трехзначное число вида 'abc',                    |" << endl;
    cout << "| где a, b, c - показатели степени переменных  x, y, z соответсвенно |" << endl;
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Все полиномы хранятся одновременно в трех таблицах:                |" << endl;
    cout << "|    * неупорядоченная таблица                                       |" << endl;
    cout << "|    * упорядоченная таблица                                         |" << endl;
    cout << "|    * хэш-таблица                                                   |" << endl;
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| В файл statistics.txt записываются данные о колличестве операций   |" << endl;
    cout << "| произведенных при выполнении различных действий с каждой из трех   |" << endl;
    cout << "| таблиц                                                             |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                                                                    |" << endl;
}

void PrintAction()
{
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Выберите действие: 0 - выход                                       |" << endl;
    cout << "|                    1 - задать полином и положить его в таблицу     |" << endl;
    cout << "|                    2 - удалить полином из таблицы                  |" << endl;
    cout << "|                    3 - вывести полином                             |" << endl;
    cout << "|                    4 - сложить полиномы                            |" << endl;
    cout << "|                    5 - вычесть один полином из другого             |" << endl;
    cout << "|                    6 - перемножить полиномы                        |" << endl;
    cout << "|                    7 - умножить полином на константу               |" << endl;
    cout << "|                    8 - вывести все доступные полиномы              |" << endl;
    cout << "|                    9 - считать таблицу из файла table.txt          |" << endl;
}

void InterFace()
{
    PrintRules();
    while (true) {
        PrintAction();
        string str;
        cin >> str;
        try {
            int act = stoi(str);
            switch (act) {
                case 0:
                    return;
                case 1:
                    InsertRecord(); //done
                    break;
                case 2:
                    DeleteRecord(); //done
                    break;
                case 3:
                    PrintRecord(); //done
                    break;
                case 4:
                    AddPolynomial(); //done
                    break;
                case 5:
                    SubPolynomial(); //done
                    break;
                case 6:
                    MulPolynomial(); //done
                    break;
                case 7:
                    CMulPolynomial();
                    break;
                case 8:
                    PrintTable(); // done
                    break;
                case 9:
                    ReadTableFromFile(); //done
                    break;
                default:
                    Incorrect();
                    break;
            }
        }
        catch (invalid_argument exc) {
            cerr << "| Некорректный ввод" << endl;
            cerr << "| Пожалуйста повторите ввод" << endl;
        }
    }
}

void InsertRecord()
{
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Введите имя нового полинома:                                       |" << endl;
    string name = EnterName();
    cout << "| Задайте полином " << name << endl;
    Polynomial q;
    try {
        cin >> q;
        table.Insert(name, q);
        cout << "| Полином " << name  << endl << q <<  "| помещен в таблицу " << endl;
    }
    catch (Exception exc) {
        cerr << exc.GetNameError() << endl;
    }
}

void DeleteRecord()
{
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Введите имя полинома, который нужно удалить:                       |" << endl;
    string name = EnterName();
    try {
        table.Delete(name);
        return;
    }
    catch (Exception exc) {
        cerr << "| Полином с таким именем в таблице отсутсвует                        |" << endl;
    }
}

void PrintRecord()
{
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Введите имя полинома, который нужно вывести:                       |" << endl;
    string name = EnterName();
    try {
        cout << table[name];
        return;
    }
    catch (Exception exc) {
        cerr << "| Полином с таким именем в таблице отсутсвует                        |" << endl;
    }
}

void AddPolynomial()
{
    PrintLogFile("--------------------------------------------------------------------------\n");
    PrintLogFile("Для сложения были произведенны следующие операции\n"); 
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Введите имена полиномов (через пробел), которые нужно сложить      |" << endl;
    vector<string> args = ArgumentsList();
    Polynomial res;
    size_t sz = args.size();
    try {
        for (size_t i = 0; i < sz; i++) {
            res += table[args[i]];
        }
        cout << "| Результат сложения:                                                |" << endl;
        cout << res;
        if (YesNoMessage("| Сохранить результат сложения в таблицу?") == 2) {
            return;
        }
        PrintLogFile("--------------------------------------------------------------------------\n");
        cout << "| Введите имя для результата сложения                                |"  << endl;
        table.Insert(EnterName(), res);
    } catch (Exception exc) {
        cout << exc.GetNameError() << endl;
    }
}

void SubPolynomial()
{
    PrintLogFile("--------------------------------------------------------------------------\n");
    PrintLogFile("Для вычитания были произведенны следующие операции\n");
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Введите имена полиномов (через пробел), которые нужно вычесть      |" << endl;
    vector<string> args = ArgumentsList();
    Polynomial res = table[args[0]];
    size_t sz = args.size();
    try {
        for (size_t i = 1; i < sz; i++) {
            res -= table[args[i]];
        }
        cout << "| Результат вычитания:                                               |" << endl;
        cout << res;
        if (YesNoMessage("| Сохранить результат вычитания в таблицу?") == 2) {
            return;
        }
        PrintLogFile("--------------------------------------------------------------------------\n");
        cout << "| Введите имя для результата вычитания                               |" << endl;
        table.Insert(EnterName(), res);
    } catch (Exception exc) {
        cout << exc.GetNameError() << endl;
    }
}

void MulPolynomial()
{
    PrintLogFile("--------------------------------------------------------------------------\n");
    PrintLogFile("Для умножения были произведенны следующие операции\n");
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Введите имена полиномов (через пробел), которые нужно умножить     |" << endl;
    vector<string> args = ArgumentsList();
    Polynomial res = table[args[0]];
    size_t sz = args.size();
    try {
        for (size_t i = 1; i < sz; i++) {
            res *= table[args[i]];
        }
    }
    catch (Exception exc) {
        cout << exc.GetNameError() << endl;
        return;
    }
    cout << "| Результат умножения:                                               |" << endl;
    cout << res;
    if (YesNoMessage("| Сохранить результат умножения в таблицу?") == 2) {
        return;
    }
    PrintLogFile("--------------------------------------------------------------------------\n");
    cout << "| Введите имя для результата умножения                               |" << endl;
    try {
        table.Insert(EnterName(), res);
    }
    catch (Exception exc) {
        cout << exc.GetNameError() << endl;
    }
}

void CMulPolynomial()
{
    PrintLogFile("--------------------------------------------------------------------------\n");
    PrintLogFile("Для умножения на скаляр были произведенны следующие операции\n");
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "| Введите имя полинома, которого нужно умножить на скаляр         |" << endl;
    string name = EnterName();
    cout << "| Введите значени константы на которое нужно умножить полином        |" << endl;
    string str;
    cin >> str;
    try {
        double scalar = stod(str);
        Polynomial res = table[name] * scalar;
        cout << "| Результат умножения на скаляр:                                     |" << endl;
        cout << res;
        if (YesNoMessage("| Сохранить результат умножения на скаляр в таблицу?") == 2) {
            return;
        }
        PrintLogFile("--------------------------------------------------------------------------\n");
        cout << "| Введите имя для результата умножения                               |" << endl;
        try {
            table.Insert(EnterName(), res);
        }
        catch (Exception exc) {
            cout << exc.GetNameError() << endl;
        }
    }
    catch (invalid_argument exc) {
        cerr << "| Некорректный ввод" << endl;
    }
    
}

void PrintTable()
{
    cout << "| Список доступных полиномов:                                        |" << endl;
    vector<string> poltnomialsList;
    poltnomialsList = table.GetPolynomialsList();
    size_t sz = poltnomialsList.size();
    for (size_t i = 0; i < sz; i++) {
        if (i != 0 && !(i % 8)) {
            if (YesNoMessage("| Вывести ещё ?") == 2) {
                return;
            }
        }
        cout << "| " << i << ") " << poltnomialsList[i] << endl;
    }
}

void ReadTableFromFile()
{
    ifstream fin("table.txt");
    if (fin.is_open()) {
        while (fin) {
            string name;
            fin >> name;
            if (!name.empty()) {
                Polynomial q;
                fin >> q;
                try {
                    table.Insert(name, q);
                }
                catch (Exception exc) {
                    cout << exc.GetNameError() << endl;
                    return;
                }
            }
        }
    }
    else {
        cerr << "| Не удалось открыть файл table.txt" << endl;
    }
    fin.close();
}

void Incorrect()
{
    cout << "| Выберите один из предложенных вариантов                            |" << endl;
}

