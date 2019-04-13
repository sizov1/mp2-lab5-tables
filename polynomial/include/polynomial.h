#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H

#include <iostream>

using namespace std;

#include "tlist.h"
#include "monom.h"

class Polynomial : public TList<Monom>
{
    public:
        Polynomial(Monom* monoms = nullptr, int km = 0);  // monoms - массив мономов
                                                          // km - количество мономов в полиноме

        void CombineLikeTerms();     // привести подобные и убрать нулевые
        void Insert(const Monom& q);   // вставить на нужное место и привести подобные
        void Insert(double coeff, int index);

        bool operator == (const Polynomial& q) const;
        const Polynomial& operator = (const Polynomial& q);

        const Polynomial operator + (const Polynomial& q) const;
        const Polynomial operator - (const Polynomial& q) const;
        Polynomial& operator += (const Polynomial& q);
        Polynomial& operator -= (const Polynomial& q);
        Polynomial& operator *= (const Polynomial& q);
        Polynomial operator * (double d) const;
        Polynomial operator * (const Monom& m) const;
        Polynomial operator * (const Polynomial& q) const;

        friend istream& operator >> (istream& in, Polynomial& p);
        friend ostream& operator << (ostream& os, const Polynomial& p);

};



#endif
