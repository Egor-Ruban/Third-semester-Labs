
#include "Array.h"
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std::chrono;

int main() {
    srand(time(nullptr));

    int arr1[10] = {9,6,7,3,5,1,4,2,8,10};

    //Array nums1(arr1,10);
    Array nums1(5000,Array::DISORD,1000);
    //std::cout<<nums1<<std::endl;
    //Array nums(arr,8);
    //nums;
    //nums.Sort(SortType::Shell);
    Array nums = nums1;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    if(nums.Sort(SortType::Heap).isOrdered()&&nums==nums1) std::cout<<"Shell: sorted successful"<<std::endl;
    else std::cout<<"Shell: sorted unsuccessful"<<std::endl;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();
    std::cout <<"\tTime: "<< duration <<" milliseconds"<<std::endl;
/*
    nums = nums1;
    t1 = high_resolution_clock::now();
    if(nums.Sort(SortType::Cocktail).isOrdered()&&nums==nums1) std::cout<<"Cocktail: sorted successful"<<std::endl;
    else std::cout<<"Cocktail: sorted unsuccessful"<<std::endl;
    t2 = high_resolution_clock::now();
    duration = duration_cast<milliseconds>( t2 - t1 ).count();
    std::cout <<"\tTime: "<< duration <<" milliseconds"<<std::endl;

    nums = nums1;
    t1 = high_resolution_clock::now();
    if(nums.Sort(SortType::Heap).isOrdered()&&nums==nums1) std::cout<<"Heap: sorted successful"<<std::endl;
    else std::cout<<"Heap: sorted unsuccessful"<<std::endl;
    t2 = high_resolution_clock::now();
    duration = duration_cast<milliseconds>( t2 - t1 ).count();
    std::cout <<"\tTime: "<< duration <<" milliseconds"<<std::endl;

    nums = nums1;
    t1 = high_resolution_clock::now();
    if(nums.Sort(SortType::Quick).isOrdered()&&nums==nums1) std::cout<<"Quick: sorted successful"<<std::endl;
    else std::cout<<"Quick: sorted unsuccessful"<<std::endl;
    t2 = high_resolution_clock::now();
    duration = duration_cast<milliseconds>( t2 - t1 ).count();
    std::cout <<"\tTime: "<< duration <<" milliseconds"<<std::endl;

    nums = nums1;
    t1 = high_resolution_clock::now();
    if(nums.Sort(SortType::Radix).isOrdered()&&nums==nums1) std::cout<<"Radix: sorted successful"<<std::endl;
    else std::cout<<"Radix: sorted unsuccessful"<<std::endl;
    t2 = high_resolution_clock::now();
    duration = duration_cast<milliseconds>( t2 - t1 ).count();
    std::cout <<"\tTime: "<< duration <<" milliseconds"<<std::endl;
*/
    return 0;
}