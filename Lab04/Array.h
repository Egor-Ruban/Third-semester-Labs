//
// Created by egor-ruban on 13.10.2019.
//

#ifndef LAB04_ARRAY_H
#define LAB04_ARRAY_H

#include <stdlib.h>
#include <iostream>
enum class SortType{
    Shell,
    Cocktail,
    Heap,
    Quick,
    Radix
};

class Array {
    friend class Sort;
private:
    int size;
    int *arr;

    void sift(int i, int n);
    void heapChangeNums(int a,int n);
    void QuickSort(int l, int r);
    void RadixSort(int l, int r, int k);

public:

    static const int DISORD = 1;
    static const int ORD_BY_DEC = 2;
    static const int ORD_BY_INC = 3;

    Array(int size = 1, int type = DISORD, int max = 10);
    Array(const int* arr, int size);
    Array(const Array& obj);

    ~Array();

    int& operator [] (int index);
    Array& operator= (const Array& obj);
    bool operator == (const Array& obj);
    friend std::istream& operator >> (std::istream &in, Array& obj);
    friend std::ostream& operator<<(std::ostream &out, const Array &obj);

    bool isOrdered(int type = ORD_BY_INC);
    Array& Log();

    Array& Sort(SortType TypeOfSort = SortType::Cocktail);
    void CocktailSort();
    void HeapSort();
    void QuickSort();
    void RadixSort();
    void ShellSort();
};


#endif //LAB04_ARRAY_H