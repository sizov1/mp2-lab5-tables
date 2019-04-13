#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#include <string>

using namespace std;

class Exception
{
    protected:
        string msg;
    public:
        Exception(string _msg) : msg(_msg) {};

        string GetNameError()
        {
            return msg;
        }
};

#endif 