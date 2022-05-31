#include <iostream>

using namespace std;
/********** part1 new *********/
// 1、new 基本用法
// 在堆区创建数据
void func(){
    int *p = new int(10);
    delete p;
}

// 2、在堆区利用new开辟数组
void test02(){
    int *aarr = new int[10];
    delete [] aarr; //释放数组 加上[]

}

/***********part2 引用************/
// 1、引用是给变量起别名，指向相同地址
void yinyong_test1(){
    int a = 10;
    int &b = a;
    b = 100;
    cout << a << endl;
}
// 2、引用注意： 必须初始化，不可变
void yinyong_test2(){
    int a = 10;
    int &b = a;
    int c = 11;
    b = c; //赋值操作，正确
    cout << "" <<b << endl;
    b = 15;
    cout << "c: " << c << endl;
    cout << "a: " << a << endl;
    // int &b=c; // 错误，多次命名
    // &b=c; // 错误，不可以更改引用
}
//3、引用传参和地址传参一样,会修改原始值
void yinyong_test3(int &a, int&b){
    int c = a;
    a = b;
    b = c;
}
// 4、指针的本质，指针常量
// int &p=a; 转换为 int *const p =&a; 指针指向固定，可以修改值

int main(){

    // int *p = func();
    
    // cout << *p <<endl;
    // delete p;
    yinyong_test2();
    return 0;
}