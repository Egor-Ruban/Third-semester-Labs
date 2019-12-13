#include <iostream>
#include "ChString.h"
#include <string>
class Complex{
private:

    double a ;
    double b ;

public:
    static int k;
    Complex(double a=0, double b=0){
        this->a=a;
        this->b=b;
    }


    void Out() {
        std::cout<<this->a<<" + "<<this->b<<"i"<<std::endl;
    }

    static Complex Add(Complex z1, Complex z2){
        Complex res;
        res.a = z1.a+z2.a;
        res.b = z1.b+z2.b;
        return res;
    }

    Complex& operator=(const Complex& obj){
        a = obj.a;
        b = obj.b;
        return *this;
    }

    Complex& operator+=(const Complex& obj){
        a = a + obj.a;
        b = b + obj.b;
        return *this;
    }

    Complex operator+(const Complex& obj){
        Complex res(a + obj.a, b + obj.b);
        return res;
    }

    Complex& operator-=(const Complex& obj){
        a = a - obj.a;
        b = b - obj.b;
        return *this;
    }

    Complex operator-(const Complex& obj){
        Complex res(a - obj.a, b - obj.b);
        return res;
    }

    friend std::istream& operator >> (std::istream &in, Complex& obj){
        std::cout<<"== enter a: "<<std::endl;
        in>>obj.a;
        std::cout<<"== enter b: "<<std::endl;
        in>>obj.b;
        return in;
    }

    friend std::ostream& operator<<(std::ostream &out, const Complex &obj){
        out<<obj.a<<"+"<<obj.b<<"i"<<std::endl;
        return out;
    }


    static Complex Sub(Complex z1, Complex z2){
        Complex res;
        res.a = z1.a-z2.a;
        res.b = z1.b-z2.b;
        return res;
    }

    static Complex Mul(Complex z1, Complex z2){
        Complex res;
        res.a = z1.a*z2.a-z1.b*z2.b;
        res.b = z1.a*z2.b+z1.b*z2.a;
        return res;
    }

    double Abs(){
        return sqrt(this->a*this->a+pow(this->b,2));
    }

    static bool IsEqual(Complex z1, Complex z2) {
        return z1.a == z2.a && z1.b == z2.b;
    }

    std::string toString(){
        std::string str;
        str+=std::to_string(this->a);
        str+="+";
        str+=std::to_string(this->b);
        str+="i";

        return str;
    }
};