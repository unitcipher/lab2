#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double re;
    double im;

public:
    Complex();
    Complex(double x, double y);

    void   SetRe(double x);
    void   SetIm(double y);
    double GetRe() const;
    double GetIm() const;

    double Abs() const;
    double Arg() const;

    void Print()     const;
    void TrigPrint() const;
    void ExpPrint()  const;

    Complex Add(const Complex& z) const;
    Complex Sub(const Complex& z) const;
    Complex Mult(const Complex& z) const;
    Complex Div(const Complex& z) const;
};

#endif