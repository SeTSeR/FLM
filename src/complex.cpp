#include "complex.h"
#include <cmath>

long double Complex::abs() const 
{
    if (!isInf)
        return hypot(Re,Im);
    else
        return 0;
}

Complex Complex::conjugate() const 
{
    return Complex(Re,Im);
}

const Complex operator + (const Complex &l, const Complex &r)
{
    return Complex(l.Re + r.Re,l.Im + r.Im);
}

const Complex operator - (const Complex &l, const Complex &r)
{
    return Complex(l.Re - r.Re,l.Im - r.Im);
}

const Complex operator * (const Complex &l, const Complex &r)
{
    return Complex(l.Re * r.Re - l.Im * r.Im,l.Re * r.Im + l.Im * r.Re);
}

const Complex operator / (const Complex &l, const Complex &r)
{
    if (r.abs() == 0)
        return Complex(0,0,1);
    Complex up = l * r.conjugate();
    return Complex(up.Re / (r.abs() * r.abs()),up.Im / (r.abs() * r.abs()));
}
