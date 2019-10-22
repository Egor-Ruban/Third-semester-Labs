//
// Created by old_g on 19.10.2019.
//

#include "Array.h"

void Array::heapChangeNums(int a, int n){
    if(arr[a]>arr[(a-1)/2]){
        int temp = arr[a];
        arr[a] = arr[(a-1)/2];
        arr[(a-1)/2] = temp;
        if((a-1)/2>0) heapChangeNums((a-1)/2,n);
    }
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
    for(int p = size/2;p>0;p/=2){
        for(int i = 0;i<p;i++){
            for(int j = i+p; j<size;j+=p){
                int k=j;
                int temp = arr[k];
                for(;k-p>=0&&arr[k-p]>temp;k-=p){
                    arr[k] = arr[k-p];
                }
                arr[k] = temp;
            }
        }
    }
}

void Array::RadixSort() {
    unsigned int max = 0;
    for (int i = 0; i < size; i++) if (arr[i] > max) max = arr[i];
    int k = 0, r = size - 1, l = 0;
    unsigned int tempmax = max;
    while (tempmax != 0) tempmax = max >> ++k;
    RadixSort(l, r, k);
}

void Array::QuickSort(){
    int r = size-1, l = 0;
    QuickSort(l,r);
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
    int max;
    while((2*i+1)<=n) {
        if(i*2+1==n)  max = i*2+1;
        else if(arr[i*2+1]>arr[i*2+2]) max = i*2+1;
        else max = i*2+2;
        if(arr[i]<arr[max]){
            int temp = arr[i];
            arr[i]=arr[max];
            arr[max]=temp;
            i=max;
        } else return;
    }
}

