#ifndef __MONOM_H
#define __MONOM_H

#define EPS 0.0000000001
#include "exception.h"

class Monom
{
    private:
        double coeff_;
        int index_;
        int sum_;
    public:
        Monom(double coeff = 0.0, int index = -1);
        Monom(const Monom& q);

        double GetCoeff();
        int GetIndex();
        int GetSum();

        void SetCoeff(double coeff);
        void SetIndex(int index);

        bool operator != (const Monom& q) const;
        bool operator == (const Monom& q) const;
        bool operator < (const Monom& q) const;
        bool operator > (const Monom& q) const;

        const Monom& operator = (const Monom& q);
        Monom& operator += (const Monom& q);
        const Monom operator + (const Monom& q) const;
        Monom operator * (double d) const;
        Monom operator * (int i) const;
        Monom& operator -= (const Monom& q);
        const Monom operator - (const Monom& q) const;
        Monom& operator *= (const Monom& q);
        const Monom operator * (const Monom& q) const;

        friend ostream& operator << (ostream& os, const Monom& m);
        friend istream& operator >> (istream& is, Monom& m);

};

#endif
