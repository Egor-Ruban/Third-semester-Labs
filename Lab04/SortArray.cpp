//
// Created by old_g on 19.10.2019.
//

#include <chrono>
#include "Array.h"
using namespace std::chrono;



void Array::QuickSort(){
    int r = size-1, l = 0;
    QuickSort(l,r);
}



void Array::QuickSort(int l, int r){
    if(l>=r) return;
    int temp = arr[l+((r-l)/2)];
    int i = l, j = r;
    while(i<j){
        while(arr[i]<temp)   i++;
        while(arr[j]>temp)   j--;
        if(i<=j){
            int temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
            i++;
            j--;
        }
    }
    QuickSort(l,j);
    QuickSort(i,r);
}



void Array::RadixSort() {
    unsigned int max = 0;
    for (int i = 0; i < size; i++) if (arr[i] > max) max = arr[i];
    int k = 0, r = size - 1, l = 0;
    unsigned int tempmax = max;
    while (tempmax != 0) tempmax = max >> ++k;
    RadixSort(l, r, k);
}



void Array::RadixSort(int l, int r, int k){
    if(l>=r) return;
    if(k<=0) return;
    int i = l, j = r;
    while(i<=j){
        while(i<=j&&(arr[i]>>(k-1)&1)==0)    i++;
        while(i<=j&&(arr[j]>>(k-1)&1)==1)    j--;
        if(i<j){
            int temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
            i++;
            j--;
        }
    }
    int m = k-1;
    RadixSort(l,j,k-1);
    RadixSort(i,r,k-1);
}



void Array::CocktailSort(){
    int leftPoint = 0, rightPoint = size-1;
    while(leftPoint<rightPoint){
        int lastChanged = 0;
        for(int i=rightPoint;i>leftPoint;i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                lastChanged = i;
            }
        }
        leftPoint = lastChanged;
        lastChanged = 0;
        for(int i=leftPoint;i<rightPoint;i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                lastChanged = i;
            }
        }
        rightPoint = lastChanged;
    }
}



void Array::ShellSort(){
    for(int p = size/2;p>0;p/=2)    for(int i = 0;i<p;i++)  for(int j = i+p, k = j, temp = arr[k]; j<size;j+=p, arr[k] = temp)  for(;k-p>=0&&arr[k-p]>temp;k-=p)    arr[k] = arr[k-p];
}



void Array::HeapSort(){
    int n = size;
    for(int i = n/2-1;i>-1;i--){
        sift(i,n-1);
    }
    for(int i = n-1;i>0;i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        sift(0,i-1);
    }
}



void Array::sift(int i,int n) {
    int max; //max - индекс максимального дочернего элемента
    int x = arr[i];
    while((max = 2*i+1)<=n) {
        if(max+1<=n) {
            if(arr[max+1]>arr[max]) max+= 1;
        }
        if(x<arr[max]){
            arr[i] = arr[max];
            i=max;
        } else break;
    }
    arr[i]=x;
}


