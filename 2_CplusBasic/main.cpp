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


/******************part4 封装 ************************/
//c++面向对象的三大特性为： 封装、继承、多态
// 封装的意义：将属性和行为作为一个整体，表现生活中的事物；将属性和行为加以权限限制
// 1 设计一个圆类，求解周长
const double PI=3.1415926;
class Circle
{
// 访问权限
private:
    /* data */
public:
    int m_r;//半径

    // 行为： 计算周长
    double calculateZC(){
        return 2 * PI * m_r;
    }
};

class Student
{
private:
    /* data */
public:
    string name = "";
    string number = "";
    void shownumberandname(){
        cout << "姓名： " << name << endl;
        cout << "学号： " << number << endl;
        return;
    }
};

// 2 类的访问权限： 
// 公共权限: 成员 类内可以访问，类外可以访问
// 保护权限：成员 类内可以访问，类外不可以访问； 继承中：子可以访问
// 私有权限：成员 类内可以访问，类外不可以访问； 继承中：子不可以访问
class Person
{
private:
    int m_Password;
public:
    string m_Name;
protected:
    string car;
};

// 3 struct 和 class 的区别； struct的默认权限是公共， class的默认权限是私有
class Test
{
    int m_A; // private, 外部不能访问
};
struct Test1
{
    int m_A; // public, 外不能访问
};

// 4 成员属性设置为私有化
// 1) 可以自己控制读取权限 2)对于写可以检测数据的有效性
class class_test4
{
private:
    int p_Age = 10;//读
    string p_Name = ""; // 读写
    string p_Lover = "";// 写
public:// 设置定义私有成员的权限
    string getName(){
        return p_Name;
    }
    string setName(string name){
        p_Name = name;
    }
    string setLover(string name){
        p_Lover = name;
    }
};

// 5 test example 设置立方体，并计算面积和体积
class class_5TestCube
{
private:
    double m_L=0;//长宽高
    double m_W=0;//长宽高
    double m_H=0;//长宽高
public:
    //设置值 
    void setLength(double length){
        m_L = length;
    }
    void setWidth(double width){
        m_W = width;
    }
    void setHeight(double height){
        m_H = height;
    }
    // 输出值
    double getLenght(){
        return m_L;
    }
    double getWidth(){
        return m_W;
    }
    double getHeight(){
        return m_H;
    }
    // 计算 面积体积
    double calculateV(){
        return m_L * m_W * m_H;
    }
    double calculateS(){
        return 2*m_L * m_W + 2 * m_L * m_H + 2 * m_H * m_W;
    }

    // 判断两个立方体是否相等
    bool isSameCube(class_5TestCube &c){
        if(m_L==c.getLenght() && m_H==c.getHeight() && m_W==c.getWidth()){
            return true;
        }
        return false;
    }
};

/******************part5 对象特性 ************************/
// 1 构造函数和析构函数: 不提供的时候，编译器会提供空函数
class duixiang_test1
{
private:
    /* data */
public:
    duixiang_test1(/* args */);
    ~duixiang_test1();
};

duixiang_test1::duixiang_test1(/* args */)
{
    cout << "duixiang_test1" << endl;
}

duixiang_test1::~duixiang_test1()
{
    cout << "duixiang_test1 destroyed" << endl;
}


int main(){

    // int *p = func();
    
    // cout << *p <<endl;
    // delete p;
    // yinyong_test2();
    // function_test2(10);
    /******************part4 封装 ************************/
    // Circle c1; // 实例化
    // c1.m_r = 10;
    // double zc = c1.calculateZC();
    // cout << "周长： " << zc << endl;
    // Student wangkun;
    // wangkun.name = "wangkun";
    // wangkun.number = "130418";
    // wangkun.shownumberandname();
    duixiang_test1 t1;

    return 0;
}