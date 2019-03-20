#include <iostream>
#include <locale>
#include <chrono>
#include <thread>
#include "polynomial.h"
#include "parser.h"

using namespace std;

void outDelay(const string& s, int ms)
{
    for (auto c : s)
    {
        cout << c;
        this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    while (cin) {
        get_token();
    }
    

    system("pause");
    return 0;
}