//
// Created by old_g on 19.10.2019.
//

#ifndef LAB05_BOOLMATRIX_H
#define LAB05_BOOLMATRIX_H

#include "BoolVector.h"

class BoolMatrix{
private:
    BoolVector *vectors;
    int sizeX;
    int sizeZ;
public:
    BoolMatrix();
    explicit BoolMatrix(int size);
    BoolMatrix(int sizeX, int sizeZ);
    BoolMatrix(int sizeX, int sizeZ, bool isEmpty);
    ~BoolMatrix();

    BoolMatrix& operator = (const BoolMatrix& obj);
    bool operator == (const BoolMatrix &obj);
    bool operator != (const BoolMatrix &obj);
    BoolVector& operator [] (int i);

    friend std::istream& operator >> (std::istream &in, BoolMatrix& obj);
    friend std::ostream& operator<<(std::ostream &out,const BoolMatrix &obj);
    void Log();
    BoolMatrix& parsePairs(int **Pairs, int n, int size);

    int* topologicalSort();
private:


};


#endif //LAB05_BOOLMATRIX_H
