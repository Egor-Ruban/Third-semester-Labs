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
    unsigned int* arr;
    int lenw;
    int lenb;
public:
    BoolVector(std::string S);
    explicit BoolVector(int len);
    BoolVector();
    BoolVector(BoolVector& sample);


    ~BoolVector();

    virtual void Log();
    int TakeBool(int i) const;
    void setBool(int i, int bit);
    void setEmpty();
    void fillRandomly();
    int getWeight();
    int operator [] (int index);
    BoolVector& operator = (const BoolVector& obj);
    bool operator == (const BoolVector &obj);
    bool operator != (const BoolVector &obj);
    friend std::istream& operator >> (std::istream &in, BoolVector& obj);
    friend std::ostream& operator<<(std::ostream &out,const BoolVector &obj);

    BoolVector operator & (BoolVector& obj);
    BoolVector operator | (BoolVector& obj);
    BoolVector operator ~ ();


    void operator |=(BoolVector& obj);
    void operator &=(BoolVector& obj);

    BoolVector operator << (int i);
    BoolVector operator >> (int i);


private:
    int TakeBool(int base, int pos);

};


#endif //LAB05_BOOLVECTOR_H
