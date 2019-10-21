//
// Created by old_g on 19.10.2019.
//

#include "BoolMatrix.h"

BoolMatrix::~BoolMatrix() {
    if (vectors!= NULL) {
        delete[](vectors);
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
    int* result = new int[this->sizeX];
    int finished = 0;
    int checker = 0;
    int* A = new int[this->sizeX];
    for(int i = 0; i<sizeX;i++) A[i] = 0;
    while(finished<sizeX){
        int checker1 = 0;
        for(int i = 0; i<sizeX;i++){
            if(A[i]==0){
                checker = 0;
                for(int j = 0;j<sizeX;j++){
                    if(vectors[j].TakeBool(i)) checker++;
                }
                if(checker==0){
                    checker1++;
                    A[i]++;
                    vectors[i].setEmpty();
                    result[finished]=i;
                    finished++;
                }
            }
        }
        if(checker1==0){
            std::cout<<"Not Found"<<std::endl;
            return result;
        }
    }
    for(int i = 0; i<sizeX;i++) std::cout<<result[i];
    return result;
}