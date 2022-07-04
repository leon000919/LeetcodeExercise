#include<bits/stdc++.h>
using namespace std;
class Complex {
public:
    Complex(double x, double y) : re(x), im(y){}
    Complex() : re(0), im(0){}
    double real() const { return re; }
    double imag() const { return im; }
    Complex &operator+=(const Complex &c);
    template <typename T>
    Complex &operator+=(const T num);

    Complex &operator-=(const Complex &c);
    template <typename T>
    Complex &operator-=(const T num);

    Complex &operator*=(const Complex &c);
    template <typename T>
    Complex &operator*=(const T num);

    Complex conj() {
        return Complex(this->re, -this->im);
    }

    double length() {
        return pow(this->re * this->re + this->im * this->im, 0.5);
    }

private:
    double re, im;
    friend Complex &_plus(Complex *, const Complex &);
    friend Complex &_minus(Complex *, const Complex &);
    friend Complex &_times(Complex *, const Complex &);
};
//  + 
inline Complex &_plus(Complex *ths, const Complex &c) {
    ths->re += c.re;
    ths->im += c.im;
    return *ths;
}
//  - 
inline Complex &_minus (Complex *ths, const Complex &c) {
    ths->re -= c.re;
    ths->im -= c.im;
    return *ths;
}
//  * 
inline Complex &_times(Complex *ths, const Complex &c) {
    ths->re = ths->re * c.re - ths->im * c.im;
    ths->im = ths->re * c.im + ths->im * c.re;
    return *ths;
}
// += Complex
inline Complex & Complex::operator += (const Complex & c) {
    return _plus(this, c);
}
// += number
template <typename T>
inline Complex & Complex::operator += (const T num) {
    this->re += num;
    return *this;
}

// -= Complex
inline Complex & Complex::operator -= (const Complex & c) {
    return _minus(this, c);
}
// -= number
template <typename T>
inline Complex & Complex::operator -= (const T num) {
    this->re -= num;
    return *this;
}
// *= Complex
inline Complex & Complex::operator*=(const Complex & c) {
    return _times(this, c);
}
// *=number
template <typename T>
inline Complex & Complex::operator *= (const T num) {
    this->re *= num;
    this->im *= num;
    return *this;
}
//Complex + Complex
inline Complex  operator+ (const Complex & x,const Complex & y) {
    return Complex(x.real() + y.real(), x.imag() + y.imag());
}
// Complex + number
template <typename T>
inline Complex operator+(const Complex &c, T num) {
    return Complex(c.real() + num, c.imag());
}
// number + Complex
template <typename T>
inline Complex operator+(T num, const Complex &c) {
    return Complex(c.real() + num, c.imag());
}
//Complex - Complex
inline Complex operator-(const Complex &x, const Complex &y) {
    return Complex(x.real() - y.real(), x.imag() - y.imag());
}
// Complex - number
template <typename T>
inline Complex operator-(const Complex &c, T num) {
    return Complex(c.real() - num, c.imag());
}
// number - Complex
template <typename T>
inline Complex operator-(T num, const Complex &c) {
    return Complex(num - c.real(), -c.imag());
}
// -Complex
inline Complex operator-(const Complex &c) {
    return Complex(-c.real(), -c.imag());
}
// Complex * Complex
inline Complex operator*(const Complex &x, const Complex &y) {
    return Complex(x.real() * y.real() - x.imag() * y.imag(), x.real() * y.imag() + x.imag() * y.real());

}
// Complex * number
template <typename T>
inline Complex operator*(const Complex &c, T num) {
    return Complex(c.real() * num, c.imag() * num);
}
// number * Complex
template <typename T>
inline Complex operator*(T num, const Complex &c) {
    return Complex(c.real() * num, c.imag() * num);
}
inline ostream& operator <<(ostream& os,const Complex & c) {
    if (c.real() && c.imag()) {
        if (c.imag() >0) {
            return os << c.real() << "+" << c.imag() << "i";
        } else {
            return os << c.real() << c.imag() << "i";
        }
    } else if (c.real()) {
        return os << c.real();
    } else {
        return os << c.imag() << "i";
    }
}
// ==
inline bool operator==(const Complex &x, const Complex &y) {
    return (x.real() == y.real()) && (x.imag() == y.imag());
}
// !=
inline bool operator!=(const Complex &x, const Complex &y) {
    // return !(x == y);   //不是相同则为不同
    return (x.real() != y.real()) || (x.imag() != y.imag());
}

int main() {
    Complex x(3,4);
    Complex y(3, -4);
    cout << sizeof(x) << endl;
    cout << x.length() << endl;
    cout << x * y << endl;
    x += 2;
    cout << x << endl;
    cout << -x << endl;
    cout << (x == y.conj())<<endl;
    cout << (x.conj() != y) << endl;
    cout << x + y << endl;
    cout << 1 + x << endl;
    cout << y + 3 << endl;
    cout << 2 * x << endl;
    return 0;
}