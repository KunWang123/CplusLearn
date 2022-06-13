#include<iostream>
#include<string>
using namespace std;
/****************part11 模板****************/
// c++另一种编程思想成为 泛型编程， 主要利用的技术就是模板
// c++提供两种模板机制：函数模板和类模板
// 1、函数模板语法：
//    作用：简历一个通用函数，其函数的返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代替
//     （类型参数化）
//    语法：
//      template<typename T>//函数声明或定义
//      template --- 声明创建模板
//      typename --- 表明其后面的符号是一种数据类型，可以用class代替
//      T --- 通用的数据类型，名称可以替换，通常为大写字母
// 1) 函数模板
template<typename T>
void mySwap(T&a, T&b){
    T temp = a;
    a = b;
    b = temp;
}
void template_test1(){
    int a =  10;
    int b = 20;
    // 1、T 自动类型推导
    mySwap(a, b);

    // 2、显示指定类型
    mySwap<int>(a, b);
}

// 2、函数模板注意事项
//   1) 自动类型推导，必须推导出一致的数据类型T,才可以使用
//   2) 模板必须要确定出T的数据类型，才可以使用
template<typename T>
void template_func(){
    cout << "no fix parameters type " << endl;
}
void template_test2(){
    int a = 20;
    int b = 30;
    mySwap(a, b);//正确
    // 1) 不能推导类型
    char c = 'c';
    //mySwap(a, c);//错误，传参类型不一致，无法确定T类型
    // 2) 无参数类型，不能确定T的数据类型，需要指定
    template_func<int>();//必须<int/double...>
}

// 3、函数模板案例(通用的数据排序算法，选择排序，从大到小)
template<typename T>
void template_test3_mysort(T *arr, int length){
    for(int i=0;i < length;i++){
        int max = i;
        for(int j = i+1; j < length; j++){
            if(arr[max] < arr[j]){
                max = j;
            }
        }
        if(max != i){
            T temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
}
void template_test3_func1(){
    char arr[] = "abcdef";
    int num = sizeof(arr);
    template_test3_mysort(arr, num);
    for(int i = 0; i < num; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 4、普通函数和函数模板的区别
//  区别：
//     1) 普通函数调用时可以发生自动类型转换（隐式类型转换）
//     2) 函数模板调用时，如果利用自动类型推到，不会发生隐式类型转换
//     3) 函数模板如果利用显示指定类型的方式，可以发生隐式类型转换

// 5、普通函数和函数模板的调用规则
//   1) 如何函数模板和普通函数都可以调用，优先调用普通函数
//   2) 可以通过空模板参数列表，强制调用函数模板
//   3) 函数模板可以发生函数重载
//   4) 入伙函数模板可以产生更好的匹配，优先调用函数模板
void template5_func1(int a, int b){
    cout<< "函数" << endl;
}
template<typename T>
void template5_func1(T a, T b){
    cout<< "模板函数" << endl;
}
template<typename T>//3) 可以重载
void template5_func1(T a, T b, T c){
    cout<< "模板函数 重载" << endl;
}
void tempate_test5(){
    int a = 10;
    int b = 20;
    template5_func1(a, b);// 1)优先使用普通函数
    template5_func1<>(a, b);// 2)强制使用模板

    char c1 = 'a';
    char c2 = 'b';
    template5_func1(c1, c2);// 4) 调用模板函数，因为强制转换char2int,不如直接将T--char方便
    return ;
}

// 6、模板的局限性
//   模板不是万能的，模板具体化的数据类型，需要具体化的特殊实现
//   学习模板并不是为了写模板，而是在STL中运用系统提供的模板
// 对比两个数据是否相等
class Person
{
public:
    Person(string name, int age);
    string m_name;
    int m_age;
};
template<typename T>
bool template6_func1_mycompare(T&a, T&b){
    if(a==b){
        cout<<"a==b"<<endl;
    }
    else{
        cout << "a!=b" << endl;
    }
}
// 针对person具体化操作Template
template<> bool template6_func1_mycompare(Person&p1, Person&p2){
    if(p1.m_name==p2.m_name && p1.m_age==p1.m_age){
        return true;
    }
    else{
        return false;
    }
}

// 7、类模板
template<class NameType, class AgeType>
class T7_Person{
public:
    T7_Person(NameType name, AgeType age){
        this->m_Name = name;
        this->m_age = age;
    }
    NameType m_Name;
    AgeType m_age;
};
void template7_test1(){
    T7_Person<string, int>p1("Tom", 10);
}

// 8、类模板和函数模板的区别
//  1) 类模板没有自动类型推导的使用方式
//  2) 类模板在模板参数列表中可以默认参数
template<class NameType, class AgeType=int>
class T8_Person{
public:
    T8_Person(NameType name, AgeType age){
        this->m_Name = name;
        this->m_age = age;
    }
    NameType m_Name;
    AgeType m_age;
};
void template7_test2(){
    T7_Person<string, int>p1("Tom", 10);// 显式指定string 和 int
    // T7_Person p1("Tom", 110);//报错，不能

    T8_Person<string> p2("Tom2", 10);//第二个可以默认，不用给定，也可以给
}


// 9、类模板中成员函数创建时机
//   类模板中成员函数在调用时才被创建
template<class T>
class T9_Person{
public:
    T obj;
    // 两个成员函数，不调用就不会创建，不会报错
    void func1(){
        obj.show1();
    }
    void func2(){
        obj.show2();
    }
};

// 10、类模板对象做函数参数
//   类模板实例化出的对象，向函数传参的方式
//   1) 指定传入的类型 --- 直接显示对象的数据类型
//   2) 参数模板化 --- 将对象中的参数变为模板进行传递
//   3) 整个类模板化 -- 将这个对象类型 模板化传递
template<class T1, class T2>
class T10_Person{
public:
    T10_Person(T1 name, T2 age){
        this->m_Name = name;
        this->m_Age = age;
    }
    void show(){
        cout << this->m_Age << this->m_Name << endl;
    }
    T1 m_Name;
    T2 m_Age;
};
// 1)指定传入的类型; 使用广泛
void template10_test1(T10_Person<string, int>&p){
    p.show();
    return;
}
// 2)参数模板化
template<class T1, class T2>
void template10_test1(T10_Person<T1, T2>&p){
    p.show();
    return;
}
// 3)整个类模板化
template<typename T>
void template10_test1(T &p){
    p.show();
    return;
}

// 11、类模板与继承
//  1) 当儿子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
//  2) 如果不指定，编译器无法给子类分配内存
//  3) 如果想灵活指出父类中T的类型，子类也需变为类模板
template<class T>
class T11_Base{
public:
    T m_K;
};
//class T11_Son:public T11_Base//报错
class T11_Son:public T11_Base<int>
{
};
template<class T1, class T2>
class T11_Son2:public T11_Base<T2>{
public:
    T1 m_L;
};

// 12、类模板成员函数类外实现
template<class T1, class T2>
class T12_Person:{
public:
    T12_Person(T1 name, T2 age);
    T1 m_Name;
    T2 m_Age;
};
template<class T1, class T2>
T12_Person<T1,T2>::T12_Person(T1 name, T2 age){//T12_Person<T1,T2>加上模板的参数列表
    this->m_Age =age;
    this->m_Name = name;
}


// 13、类模板的分文件编写
//  .h 和 .cpp文件合并成.hpp

// 14、友元函数类内/外实现



int main(){
    template_test3_func1();
    return 0 ;
}