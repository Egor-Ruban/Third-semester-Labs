//
// Created by old_g on 19.10.2019.
//

#include "BoolVector.h"

BoolVector& BoolVector::operator = (const BoolVector& obj){
    if(this!=&obj) {
        this->lenb = obj.lenb;
        this->lenw = obj.lenw;
        delete[](arr);
        this->arr = new int[this->lenw];
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
        obj.arr = new int[obj.lenw];
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
    arr = new int[lenw];

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
    arr = new int[lenw];

    for (int i = 0; i < lenw; i++) {
        int base = i / 32;
        (arr)[base] = 0;
    }
    for (int i = 0; i < lenb; i++) {
        int base = i / 32;
        int pos = i % 32;
        int h = (((int) S[i] - '0') << (31 - pos));
        (arr)[base] = (arr)[base] | h;
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



