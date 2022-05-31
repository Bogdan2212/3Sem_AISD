#ifndef Complex_H
#define Complex_H
#include <iostream>
#include "cmath"
using namespace std;

class Complex{
private:
    double Real;    //Реальная часть
    double Im;      //Мнимая часть
public:         //Конструкторы
    Complex();
    Complex(double x,double y);
    Complex(const Complex& comp);
public:
    double Get_Real(Complex complex);       //Получение реальной части
    double Get_Im(Complex complex);         //Получение мнимой части
    void Set_Real(double value);            //Присваивание значения реальной части
    void Set_Im(double value);               //Присваивание значения мнимой части
    Complex operator + (const Complex& complex);    //Перегрузка оператора сложения
    Complex operator - (const Complex& complex);    //Перегрузка оператора вычитания
    Complex operator * (const Complex& complex);    //Перегрузка оператора умножения
    Complex& operator = (Complex);                  //Перегрузки операторов...
    Complex& operator += (Complex);
    Complex& operator -= (Complex);
    Complex& operator *= (Complex);
    bool operator == (Complex com);
    bool operator != (Complex& com);
    bool operator > (Complex& com);
    bool operator < (Complex& com);


};



Complex Complex::operator - (const Complex& complex) {
    Complex res;
    res.Real=this->Real-complex.Real;
    res.Im= this->Im-complex.Im;
    return res;
}

Complex Complex::operator * (const Complex &complex) {
    Complex res;
    res.Real=(this->Real*complex.Real)-(this->Im*complex.Im);
    res.Im=(this->Real*complex.Im)+(this->Im*complex.Real);
    return res;

}

Complex Complex::operator + (const Complex& complex) {
    Complex res;
    res.Real=this->Real+complex.Real;
    res.Im= this->Im+complex.Im;
    return res;
}

bool Complex:: operator > (Complex& complex)
{
    if (this->Real > complex.Real)
        return 1;
    else if (this->Real == complex.Real && this->Im > complex.Im)
        return 1;
    else
        return 0;
}

bool Complex ::operator < (Complex& complex)
{
    if (this->Real < complex.Real)
        return 1;
    else if (this->Real == complex.Real && this->Im < complex.Im)
        return 1;
    else
        return 0;

}

bool Complex::operator != (Complex& complex)
{
    if (this->Real != complex.Real || this->Im != complex.Im)
        return 1;
    else
        return 0;
}

bool Complex::operator == (Complex complex)
{
    if (this->Real == complex.Real && this->Im == complex.Im)
        return 1;
    else
        return 0;
}




Complex& Complex::operator =(Complex complex)
{
    this->Real = complex.Real;
    this->Im = complex.Im;
    return *this;
}






Complex& Complex::operator+=(Complex a)
{
    Real += a.Real;
    Im += a.Im;
    return *this;
}

Complex& Complex::operator-=(Complex a)
{
    Real -= a.Real;
    Im -= a.Im;
    return *this;
}

Complex& Complex::operator*=(Complex a)
{
    Real *= a.Real;
    Im *= a.Im;
    return *this;
}


Complex::Complex() {
    Real=0;
    Im=0;
}

Complex::Complex(const Complex& comp) {
    Real = comp.Real;
    Im = comp.Im;
}

Complex::Complex(double x,double y) {
    Real=x;
    Im=y;
}

double Complex::Get_Im(Complex complex) {
    return complex.Im;
}

double Complex::Get_Real(Complex complex) {
    return complex.Real;
}

void Complex::Set_Real(double value) {
    Real=value;
}

void Complex::Set_Im(double value) {
    Im=value;
}

ostream & operator << (ostream & out, Complex complex){
    double Im,Real;
    Im=complex.Get_Im(complex);
    Real=complex.Get_Real(complex);
    if (Im>=0){
        out<<Real<<"+"<<Im<<"i";
    }
    else{
        out<<Real<<Im<<"i";
    }
    return out;
}
#endif //Complex_H
