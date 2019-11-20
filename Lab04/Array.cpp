//
// Created by egor-ruban on 13.10.2019.
//

#include "Array.h"



Array::Array(int size, int type, int max){
    switch (type){
        case DISORD:
            this->size = size;
            arr = new int [size];
            for(int i = 0; i<size; i++) {
                arr[i] = rand() % max;
            }
            break;
        case ORD_BY_DEC:
            this->size = size;
            arr = new int [size];
            arr[size-1] = rand() % max;
            for(int i = size-2; i>=0; i--) {
                arr[i] = arr[i+1] + (rand() % 5);
            }
            break;
        case ORD_BY_INC:
            this->size = size;
            arr = new int [size];
            arr[0] = rand() % max;
            for(int i = 1; i<size; i++) {
                arr[i] = arr[i-1] + (rand() % 5);
            }
            break;
        default:
            break;
    }
}

Array::Array(const int* arr, int size){
    this->size = size;
    this->arr = new int[size];

    for(int i = 0; i<size; i++){
        this->arr[i] = arr[i];
    }
}

Array::Array(const Array& obj){
    this->size = obj.size;
    this->arr = new int[this->size];

    for(int i = 0; i<this->size; i++){
        this->arr[i] = obj.arr[i];
    }
}

Array::~Array(){
    if(arr!=NULL) {
        delete[](arr);
        arr = NULL;
    }
}

Array& Array::operator= (const Array& obj){
    if(this!=&obj) {
        this->size = obj.size;
        delete[](arr);
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = obj.arr[i];
        }
    }
    return *this;
}

int& Array::operator [] (int index){
    if (index < 0 || index >= size) {
        std::cout << "=== Выход за пределы массива ===";
        return arr[0];
    }
    return arr[index];
}

bool Array::operator == (const Array& obj){

    if(obj.size==this->size){
        Array copiedObj(obj);
        bool* isTaken = new bool[obj.size];
        for(int i = 0; i<obj.size; i++){
            isTaken[i] = false;
         }
        for(int i = 0; i<size; i++){
            bool isItemFound = false;
            for(int j = 0; j<copiedObj.size;j++){
                if(this->arr[i]==copiedObj.arr[j] && !isTaken[j]){
                    isItemFound = true;
                    isTaken[j] = true;
                    break;
                }
            }
            if(!isItemFound) {
                return false;
            }
        }
        return true;
    } else return false;
}

std::istream& operator >> (std::istream &in, Array& obj) {
    std::cout<<"== enter size of Array: "<<std::endl;
    int temp;
    in>>temp;
    if(temp!=obj.size){
        obj.size=temp;
        delete[](obj.arr);
        obj.arr = new int[obj.size];
    }
    std::cout<<"== enter your Array: "<<std::endl;
    for (int i = 0; i < obj.size; i++) {
        in >> obj.arr[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream &out, const Array &obj){
    for(int i = 0; i<obj.size-1;i++) {
        out << obj.arr[i]<<",";
    }
    out<<obj.arr[obj.size-1]<<std::endl;
    return out;
}

bool Array::isOrdered(int type){
    //int counter = 0;
    switch(type){
        case ORD_BY_INC:
            for(int i = 0; i<size-1; i++){
                if(arr[i]>arr[i+1]){
                    //std::cout << i << " is i, " << i + 1 << " is i+1, " << arr[i] << " is arr[i], " << arr[i + 1] <<" is arr[i+1], "<< std::endl;
                    return false;
                }
            }
            break;
        case ORD_BY_DEC:
            for(int i = 0; i<size-1; i++) {
                if (arr[i] < arr[i + 1]) {
                    //std::cout << i << " " << i + 1 << " " << arr[i] << " " << arr[i + 1] << std::endl;
                    return false;
                }
                break;
            }
    }
    return true;
}

Array& Array::Log(){
    std::cout<<"========"<<std::endl;
    std::cout<<"Array has "<<size<<" elements"<<std::endl;
    std::cout<<"Array: ";
    for(int i = 0; i<size-1; i++){
        std::cout<<arr[i]<<", ";
    }
    std::cout<<arr[size-1]<<std::endl;
    return *this;
}

Array& Array::Sort(SortType typeOfSort) {
    switch (typeOfSort) {
        case SortType::Cocktail:
            this->CocktailSort();
            break;
        case SortType::Heap:
            this->HeapSort();
            break;
        case SortType::Quick:
            this->QuickSort();
            break;
        case SortType::Radix:
            this->RadixSort();
            break;
        case SortType::Shell:
            this->ShellSort();
            break;
    }
    return *this;
}










