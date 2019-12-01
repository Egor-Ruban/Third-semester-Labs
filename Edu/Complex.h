#include <iostream>
#include "ChString.h"
#include <string>
class Complex{
private:

    double a = 0;
    double b = 0;

public:
    static int k;
    Complex(double a, double b){
        this->a=a;
        this->b=b;
    }

    Complex() {

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