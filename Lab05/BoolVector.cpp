//
// Created by old_g on 19.10.2019.
//

#include "BoolVector.h"

BoolVector& BoolVector::operator = (const BoolVector& obj){
    if(this!=&obj) {
        this->lenb = obj.lenb;
        this->lenw = obj.lenw;
        delete[](arr);
        this->arr = new unsigned int[this->lenw];
        for (int i = 0; i < this->lenw; i++) {
            this->arr[i] = obj.arr[i];
        }
    }
    return *this;
}
bool BoolVector::operator==(const BoolVector &obj) {
    if ((lenb) != (obj.lenb))  return false;
    else {
        for (int i = 0; i < lenb; i++) {
            if (this->TakeBool(i) != obj.TakeBool(i)) return false;
        }
        return true;
    }
}

bool BoolVector::operator!=(const BoolVector &obj) {
    if ((lenb) != (obj.lenb))  return true;
    else {
        for (int i = 0; i < lenb; i++) {
            if (this->TakeBool(i) != obj.TakeBool(i)) return true;
        }
        return false;
    }
}

std::istream &operator>>(std::istream &in, BoolVector &obj) {
    std::cout << "== enter your vector: " << std::endl;
    std::string str;
    in >> str;
    if (str.size() != obj.lenb) {
        obj.lenb = str.size();
        obj.lenw = (obj.lenb % 32) ? (obj.lenb / 32 + 1) : (obj.lenb / 32);
        delete[](obj.arr);
        obj.arr = new unsigned int[obj.lenw];
    }
    for (int i = 0; i < obj.lenb; i++) {
        int base = i / 32;
        int pos = i % 32;
        int h = (((int) str[i] - '0') << (31 - pos));
        (obj.arr)[base] = (obj.arr)[base] | h;
    }
    return in;
}

std::ostream &operator<<(std::ostream &out,const BoolVector &obj) {
    for (int i = 0; i < obj.lenb; i++) {
        out << obj.TakeBool(i);
    }
    out << std::endl;
    return out;
}

BoolVector::BoolVector() {
    arr = nullptr;
    lenb = 0;
    lenw = 0;
}

BoolVector::BoolVector(int len) {
    lenb = len;
    lenw = (lenb % 32) ? (lenb / 32 + 1) : (lenb / 32);
    arr = new unsigned int[lenw];

    for (int i = 0; i < lenw; i++) {
        int base = i / 32;
        (arr)[base] = 0;
    }

}

BoolVector::BoolVector(BoolVector& sample){
    lenb = sample.lenb;
    lenw = sample.lenw;
    arr = new unsigned int[lenw];

    for (int i = 0; i < lenw; i++) {
        int base = i / 32;
        (arr)[base] = sample.arr[base];
    }
}

void BoolVector::fillRandomly() {
    for (int i = 0; i < lenw; i++) {
        int base = i / 32;
        (arr)[base] = 0;
    }
    for (int i = 0; i < lenb; i++) {
        int base = i / 32;
        int pos = i % 32;
        int h = ((rand() % 2) << (31 - pos));
        (arr)[base] = (arr)[base] | h;
    }
}

BoolVector::BoolVector(std::string S) {
    lenb = S.size();
    lenw = (lenb % 32) ? (lenb / 32 + 1) : (lenb / 32);
    arr = new unsigned int[lenw];

    for (int i = 0; i < lenw; i++) {
        //int base = i / 32;
        arr[i] = 0;
    }
    for (int i = 0; i < lenb; i++) {
        int base = i / 32;
        int pos = i % 32;
        unsigned int h = (((unsigned int) S[i] - '0') << (31 - pos));
        (arr)[base] = (arr)[base] | h;
       // std::cout<<arr[base]<<std::endl;
    }
}


BoolVector::~BoolVector() {
    if (arr != NULL) {
        delete[](arr);
        arr = NULL;
    }
}

void BoolVector::Log() {
    for (int i = 0; i < lenb; i++) {
        int base = i / 32;
        int pos = i % 32;
        std::cout << TakeBool(base, pos);
    }
    std::cout << std::endl;
}

int BoolVector::TakeBool(int base, int pos) {
    return arr[base] >> (31 - pos) & (int) 1;
}

int BoolVector::TakeBool(int i) const {
    int base = i / 32;
    int pos = i % 32;
    return arr[base] >> (31 - pos) & (int) 1;
}

int BoolVector::operator[](int i) {
    int base = i / 32;
    int pos = i % 32;
    return arr[base] >> (31 - pos) & (int) 1;
}

void BoolVector::setEmpty() {
    for(int i = 0; i<lenw;i++){
        arr[i] = 0;
    }
}

int BoolVector::getWeight() {
    int weight = 0;
    for(int i=0;i<lenb;i++){
        if(TakeBool(i)==1){
            weight++;
        }
    }
    return weight;
}

void BoolVector::setBool(int i, int bit){
    int base = i / 32;
    int pos = i % 32;
    if(bit){
        unsigned int mask = 1 << (31-pos);
         arr[base]|=mask;
    } else {
        unsigned int mask = -2;
        for(int j = 0;j<(31-pos);j++){
            mask = mask<<1;
            mask|=1;
        }
        arr[base] = arr[base]&mask;
    }
}


BoolVector BoolVector::operator&(BoolVector &obj) {
    if(lenb!=obj.lenb) {
        std::cout << "error" << std::endl;
        return *this;
    }
    //Log();
    //obj.Log();
    BoolVector res(lenb);
    for(int i = 0;i<lenb;i++){
        int base = i/32;
        int pos = i%32;
        //std::cout<<(TakeBool(base,pos)&obj.TakeBool(base,pos));
        res.arr[base]|=(TakeBool(base,pos)&obj.TakeBool(base,pos))<<(31-pos);
    }
    //res.Log();
    return res;
}

void BoolVector::operator &= (BoolVector& obj) {
    if ((this->lenb) != (obj.lenb)){
        std::cout<<"throw ex"<<std::endl;
        return;
        //return BoolVector();
    }
    //BoolVector temp(lenb);
    for (int i = 0; i < lenw-1; i++) {
        //int base = i / 32;
        //int pos = i % 32;
        arr[i] &= obj.arr[i];
    }
    //return temp;
}

BoolVector BoolVector::operator | (BoolVector& obj) {
    if ((this->lenb) != (obj.lenb)){
        std::cout<<"throw ex"<<std::endl;
        BoolVector BV;
        return BV;
    }
    BoolVector temp(lenb);
    for (int i = 0; i < lenw; i++) {
        (temp.arr)[i] = (this->arr[i] | obj.arr[i]);
    }
    return temp;
}

void BoolVector::operator |= (BoolVector& obj) {
    if ((this->lenb) != (obj.lenb)){
        std::cout<<"throw ex"<<std::endl;
        //return *this;
    }
    BoolVector temp(lenb);
    for (int i = 0; i < lenb; i++) {
        int base = i/32;
        int pos = i%32;
        temp.arr[base]|=(TakeBool(base,pos)|obj.TakeBool(base,pos))<<(31-pos);

    }
    *this=temp;
    //return *this;
}

BoolVector BoolVector::operator ~ (){
    BoolVector temp(lenb);
    for(int i = 0; i<lenw; i++){
        int base = i/32;
        int pos = i%32;
        (temp.arr)[base]|=((TakeBool(base,pos)?(0<<(31-pos)):1<<(31-pos)));
    }
    return temp;
}

BoolVector BoolVector::operator << (int i){
    BoolVector temp(lenb);
    for(int j = i;j<lenb;j++){
        temp.setBool(j-i,TakeBool(j));
    }
    for(int j = lenb-i; j<lenb;j++){
        temp.setBool(j,0);
    }
    return  temp;
}

BoolVector BoolVector::operator >> (int i){
    BoolVector temp(lenb);
    for(int j = i; j<lenb;j++){
        temp.setBool(j,TakeBool(j-i));
    }
    for(int j = 0;j<i;j++){
        temp.setBool(j,0);
    }
    return  temp;
}

