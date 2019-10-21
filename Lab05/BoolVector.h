//
// Created by old_g on 19.10.2019.
//

#ifndef LAB05_BOOLVECTOR_H
#define LAB05_BOOLVECTOR_H


#include <xstring>
#include <iostream>

class BoolVector {
    friend class BoolMatrix;
private:
    int* arr;
    int lenw;
    int lenb;
public:
    BoolVector(std::string S);
    explicit BoolVector(int len);
    BoolVector();

    ~BoolVector();

    virtual void Log();
    int TakeBool(int i) const;
    void setEmpty();
    int operator [] (int index);
    BoolVector& operator = (const BoolVector& obj);
    bool operator == (const BoolVector &obj);
    bool operator != (const BoolVector &obj);
    friend std::istream& operator >> (std::istream &in, BoolVector& obj);
    friend std::ostream& operator<<(std::ostream &out,const BoolVector &obj);

private:
    int TakeBool(int base, int pos);

};


#endif //LAB05_BOOLVECTOR_H
