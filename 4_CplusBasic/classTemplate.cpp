#include<iostream>
#include<string>
#include"myclass.hpp"
using namespace std;

int main(){

    MyArray <int> arr1(5);
    MyArray<int> arr2(arr1);
    arr2 = arr1;
    return 0;
}