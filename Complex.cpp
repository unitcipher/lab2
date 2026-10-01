#include "Complex.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Complex::Complex() : re(0.0), im(0.0) {}
Complex::Complex(double x, double y) : re(x), im(y) {}

void   Complex::SetRe(double x) { re = x; }
void   Complex::SetIm(double y) { im = y; }
double Complex::GetRe() const { return re; }
double Complex::GetIm() const { return im; }

double Complex::Abs() const { return std::sqrt(re * re + im * im); }
double Complex::Arg() const { return std::atan2(im, re); }

void Complex::Print() const {
    std::cout << re << (im < 0 ? " - i*" : " + i*") << std::fabs(im);
}

void Complex::TrigPrint() const {
    double rho = Abs(), phi = Arg();
    std::cout << rho << "*(cos(" << phi << ") + i*sin(" << phi << "))";
}

void Complex::ExpPrint() const {
    double rho = Abs(), phi = Arg();
    std::cout << rho << "*e^(i*" << phi << ")";
}

Complex Complex::Add(const Complex& z) const {
    return Complex(re + z.re, im + z.im);
}

Complex Complex::Sub(const Complex& z) const {
    return Complex(re - z.re, im - z.im);
}

Complex Complex::Mult(const Complex& z) const {
    return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
}

Complex Complex::Div(const Complex& z) const {
    double denom = z.re * z.re + z.im * z.im;
    if (std::fabs(denom) < 1e-15)
        throw std::runtime_error("деление на ноль");
    return Complex((re * z.re + im * z.im) / denom,
        (im * z.re - re * z.im) / denom);
}