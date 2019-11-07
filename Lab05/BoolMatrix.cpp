//
// Created by old_g on 19.10.2019.
//

#include "BoolMatrix.h"

BoolMatrix::~BoolMatrix() {
    if (vectors!= NULL) {
        delete[](vectors);
        vectors = NULL;
    }
}

BoolMatrix::BoolMatrix() {
    std::cout<<"Enter number of rows"<<std::endl;
    std::cin>>sizeZ;
    std::cout<<"Enter Vectors"<<std::endl;
    std::string str;
    std::cin>>str;
    sizeX = str.length();
    BoolVector vec(str);
    vectors = new BoolVector[sizeZ];
    vectors[0] = vec;
    for(int i = 1; i<sizeZ;i++){
        std::cin>>str;
        vectors[i] = str;
    }
}

BoolMatrix::BoolMatrix(int size) {
    BoolVector vec(size);
    vectors = new BoolVector[sizeX = size];
    vectors[0] = vec;
    sizeZ = size;
    for(int i = 1; i<size;i++){
        BoolVector vec1(size);
        vectors[i] = vec1;
    }
}

BoolMatrix::BoolMatrix(int sizeX,int sizeZ) {
    BoolVector vec(this-> sizeX = sizeX);
    vectors = new BoolVector[this->sizeZ = sizeZ];
    vectors[0] = vec;
    for(int i = 1; i<sizeZ;i++){
        BoolVector vec1(sizeX);
        vectors[i] = vec1;
    }
}

BoolMatrix::BoolMatrix(int sizeX,int sizeZ,bool isEmpty) {
    if(!isEmpty){
        BoolMatrix(sizeX,sizeZ);
    } else {
        BoolVector vec(this-> sizeX = sizeX);
        vectors = new BoolVector[this->sizeZ = sizeZ];
        vectors[0] = vec;
        vectors[0].setEmpty();
        for(int i = 1; i<sizeZ;i++){
            BoolVector vec1(sizeX);
            vectors[i] = vec1;
            vectors[i].setEmpty();
        }
    }
}


BoolMatrix& BoolMatrix::operator = (const BoolMatrix& obj){
    if(this!=&obj) {
        this->sizeX = obj.sizeX;
        this->sizeZ = obj.sizeZ;
        delete[](vectors);
        this->vectors = new BoolVector[this->sizeZ];
        for (int i = 0; i < this->sizeZ; i++) {
            this->vectors[i] = obj.vectors[i];
        }
    }
    return *this;
}
bool BoolMatrix::operator==(const BoolMatrix &obj) {
    if (((sizeZ) != (obj.sizeZ)) || (sizeX!=obj.sizeX))  return false;
    else {
        for (int i = 0; i < sizeZ; i++) {
            if (vectors[i] != obj.vectors[i]) return false;
        }
        return true;
    }
}

bool BoolMatrix::operator!=(const BoolMatrix &obj) {
    if ((sizeZ) != (obj.sizeZ) || sizeX!=obj.sizeX)  return true;
    else {
        for (int i = 0; i < sizeZ; i++) {
            if (vectors[i] != obj.vectors[i]) return true;
        }
        return false;
    }
}

std::istream &operator>>(std::istream &in, BoolMatrix &obj) {
    std::cout<<"enter your sizeZ"<<std::endl;
    in>>obj.sizeZ;
    std::cout << "== enter your vector: " << std::endl;
    std::string str;
    in >> str;
    if (str.size() != obj.sizeX) {
        obj.sizeX = str.size();
        delete[](obj.vectors);
        obj.vectors = new BoolVector[obj.sizeZ];
    }
    obj.vectors[0] = str;
    for (int i = 1; i < obj.sizeZ; i++) {
        in>>obj.vectors[i];
    }
    return in;
}

std::ostream &operator<<(std::ostream &out,const BoolMatrix &obj) {
    for (int i = 0; i < obj.sizeZ; i++) {
        out << obj.vectors[i];
    }
    return out;
}

void BoolMatrix::Log(){
    for(int i = 0;i<sizeZ;i++){
        vectors[i].Log();
    }
    std::cout<<std::endl;
}

int* BoolMatrix::topologicalSort(){
    int* result = new int[this->sizeX]; //result - результирующий массив
    int workingIndex = 0;

    BoolVector isColumnDeleted(this->sizeX);

    BoolVector disVectors(this->sizeX);
    for(int i = 0; i<sizeZ;i++){
        disVectors|=vectors[i];
    }

    while(workingIndex<sizeX){
        int isColumnFounded = 0;

        BoolVector emptyColumns(this->sizeX);
        emptyColumns = (~disVectors)&(~isColumnDeleted);

        for(int i = 0; i<sizeX;i++){
            if(emptyColumns[i]==1){
                isColumnFounded++;
                isColumnDeleted.setBool(i,1);
                vectors[i].setEmpty();
                result[workingIndex]=i;
                workingIndex++;
            }
        }

        if(isColumnFounded==0){
            std::cout<<"Not Found"<<std::endl;
            return result;
        }

    }
    return result;
}

BoolMatrix& BoolMatrix::parsePairs(int **Pairs,int n, int size) {
    //считается, что вершины нумеруются с единицы
    for(int i = 0;i<size;i++){
        vectors[i].setEmpty();
    }
    //Log();
    for(int i = 0;i<n;i++){
        vectors[Pairs[i][0]-1].setBool(Pairs[i][1] - 1,1);
        //BM.vectors[Pairs[i][0] - 1].Log();
    }
   // Log();
    return *this;
}

BoolVector& BoolMatrix::operator [] (int i){
    if(i>sizeZ||i<0){
        std::cout<<"throw ex \"out of border\""<<std::endl;
        return vectors[0];
    }
    return vectors[i];
}