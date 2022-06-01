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


/****************part3 函数*******************/
//1、函数占位参数,现阶段占位参数用不到
// 占位参数可以给默认值function_test1(int a, int =10)
void function_test1(int a, int){
    cout << "" <<endl;
    return ;
}// function_test1(10, 11)
//2、函数重载，函数名可以相同，提高复用性
// 1) 在同一个作用域下，2) 函数名称相同 3)函数参数类型/个数/顺序不同
void function_test2(){
    cout << "函数重载1" << endl;
}
void function_test2(int a){
    cout << "函数重载2" << endl;
}
void function_test2(double a){
    cout << "函数重载3" << endl;
}
void function_test2(double a, int b){
    cout << "函数重载4" << endl;
}
void function_test2(int a, double b){
    cout << "函数重载5" << endl;
}
// 3、函数重载的注意事项
// 1) 引用作为重载的条件
void function_test3(int &a){
    cout << "函数重载3" << endl;
}
void function_test3(const int &a){
    cout << "函数重载4" << endl;
}
// 2) 函数重载碰到默认参数 
// function_test3_default(int a， int b=10) 不能和重载，避免默认值
void function_test3_default(int a){
    cout << " 能运行" << endl;
}
// function_test3_default(int a， int b =10)

int main(){

    // int *p = func();
    
    // cout << *p <<endl;
    // delete p;
    // yinyong_test2();
    function_test2(10);
    return 0;
}