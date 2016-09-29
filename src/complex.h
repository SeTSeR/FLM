#ifndef COMPLEX_H
#define COMPLEX_H


struct Complex
{
public:
    Complex(long double Re = 0, long double Im = 0, bool isInf = 0):Re(Re),Im(Im),isInf(isInf){}
    bool isInf;
    long double Re,Im;
    long double abs() const ;
    Complex conjugate() const;
};


const Complex operator * (const Complex &l, const Complex &r);

const Complex operator + (const Complex &l, const Complex &r);

const Complex operator - (const Complex &l, const Complex &r);

const Complex operator / (const Complex &l, const Complex &r);

#endif // COMPLEX_H
