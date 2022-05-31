#include<iostream>
#include"function_bywk.h"

using namespace std;

int main(int argc, char**argv){
    
    // int a = 0, b =1;
    // int sum = sum_bywk(a, b);
    // cout << "数字a: " << a << " 数字b: " << b << " 和为：" << sum << endl;
    int a[] = {6,1,4,5,10,4};
    int length = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, length);
    for(int i=0; i<length;i++){
        cout << a[i] << "  ";
    }
    cout << endl;
    // 结构体 
    struct Student s1;
    s1.name="kk";
    s1.age = 1;
    s1.scorce = 90;
    struct Student s2 = {"jingjing", 10, 91};

    // 结构体指针
    Student *p = &s1;
    p->age = 15;
    

    return 0;
}

/*----  指针 ----*/ 
// 常量指针: 指针的指向可以修改，指针指向的值不可以修改
// const int *p = &a; p = &b;

// 指针常量: 指针的指向不可以修改，指针指向的值可以修改
// int * const p = &a; *p = 20; 

// const 修饰指针和常量
// const *const p=&a;