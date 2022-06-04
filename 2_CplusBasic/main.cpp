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
    void setName(string name){
        p_Name = name;
    }
    void setLover(string name){
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

// 2、构造函数的分类及调用
// 1) 分类
//    按照参数分类： 无参构造（默认构造）和 有参构造
//    按照类型分类： 普通构造  和 拷贝构造
class duixiang_test2
{
private:
    int age;
public:
    // 普通构造----无参构造
    duixiang_test2(){
        cout << "无参构造函数" << endl;
    }
    // 普通构造----有参构造
    duixiang_test2(int a){
        cout << "有参构造函数" << endl;
        age = a;
        cout << "age: " << age << endl;
    }
    // 拷贝构造
    duixiang_test2(const duixiang_test2 &p){
        // 将传入类的所有属性都拷贝到我身上
        cout << "拷贝构造函数" << endl;
        age=p.age;
    }
    ~duixiang_test2(){}
};
// 2) 调用
void duixiang_test2_diaoyong(){
    // 1 括号法
    duixiang_test2 p1;//duixiang_test2 p1(); 错误，编译器理解为函数声明
    duixiang_test2 p2(10);
    duixiang_test2 p3(p2);

    // 2 显示法
    duixiang_test2 p4;
    duixiang_test2 p5 = duixiang_test2(10);//有参构造
    duixiang_test2 p6 = duixiang_test2(p5);//拷贝构造

    duixiang_test2(10);// 匿名对象
    //duixiang_test2(p5);// 编译器默认为 duxiang_test2 p5;

    // 隐式转换法
    duixiang_test2 p7 = 10;// 有参构造
    duixiang_test2 p8 = p7;// 拷贝构造
}

// 3、拷贝构造函数的调用时机
//   1) 使用一个已经创建完毕的对象来初始化一个新对象;
//   2) 值传递的方式给函数参数传值;//函数传参时候会调用
//   3) 值方式返回局部对象；// 函数返回一个类的对象时，做了拷贝
class duixiang_test3{
public:
    duixiang_test3(int age){
        m_Age = age;
        cout << "参数构造函数" << endl;
    };

private:
    int m_Age;
};

// 4、构造函数的调用规则
//  默认情况下，c++编译器会至少给一个类添加3个函数
//   1) 默认无参构造函数（无参， 函数体为空）
//   2) 默认无参析构函数（无参，函数体为空）
//   3) 默认拷贝构造函数，对属性进行值拷贝
// 但是，当
//   1) 如果用户定义有参构造函数，c++不在提供无参构造函数，但是会提供拷贝构造函数
//   2) 如果用户定义了拷贝构造函数，c++不在提供其他构造函数

// 5、深拷贝与浅拷贝
//   浅拷贝：简单的赋值拷贝操作
//   深拷贝：在堆区重新申请空间，进行拷贝操作
class duixiang_test5
{
public:
    int m_Age = 0;
    int * m_Height = NULL;
    duixiang_test5(){
        cout << "无参构造函数" << endl;
    };
    duixiang_test5(int age, int height){
        m_Age = age;
        m_Height = new int (height);
        cout << "有参构造函数" << endl;
    };
    duixiang_test5(const duixiang_test5 & p){
        // 默认的拷贝构造函数为
        // m_Age = p.m_Age;
        // m_Height = p.m_Height;
        // 当拷贝指针时候，会遇到析构函数对统一内存的两次delete问题

        // 自己实现深拷贝
        m_Age = p.m_Age;
        m_Height = new int(*p.m_Height);

        cout << "拷贝构造函数"<< endl;
    }
    ~duixiang_test5(){
        if(m_Height!=NULL){
            delete m_Height;
            m_Height = NULL;
        }
        cout << "析构函数" << endl;

    };
};

// 6、初始化列表
class duixiang_test6
{
private:
    /* data */
public:
    // 传统有参构造函数
    // duixiang_test6(int a, int b, int c){
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }

    // 初始化参数列表
    // 固定值初始化
    // duixiang_test6():m_A(10),m_B(20),m_C(30){
    // }
    // 带变量的初始化
    duixiang_test6(int a, int b, int c):m_A(a),m_B(b),m_C(c){
    }
    int m_A;
    int m_B;
    int m_C;
};

// 7、类对象作为类成员
// c++类中的成员可以是另一个类的对象，我们称该成员为对象成员
// 当其他类对象作为本类成员时，构造时候先构造类对象，再构造自身；析构的顺序相反
class duixiang_test7_1{
};
class duixiang_test7_2{
    duixiang_test7_1 a;// 类对象
};

// 8、静态成员
// 静态成员就是在 成员变量 和 成员函数 前加上关键字static,称为静态成员
//   静态成员变量特点：1) 所有对象共享同一份数据；2)在编译阶段分配内存； 3) 类内声明，类外初始化
//   静态成员函数特点：1) 所有对象共享同一个函数； 2) 静态成员函数只能访问静态成员变量
class duixiang_test8{
public:
    static int duixiang_test8_A;//类内声明
};
int duixiang_test8::duixiang_test8_A=100;//类外初始化
//   1) 静态成员变量访问
//     1、通过对象进行访问: duixiang_test8 P; cout<< P.duixiang_test8_A;
//     2、通过类名进行访问： cout<< duixiang_test8::duixiang_test8_A;
//   2) 静态成员函数---创建
class duixiang_test8_2{
public:
    static void func(){
        duixiang_test8_2_a = 200;
        // duixiang_test8_2_b = 100; // 报错，静态成员函数不能访问非静态成员变量
        cout << "静态成员函数" << endl;
    }
    static int duixiang_test8_2_a;
    int duixiang_test8_2_b;
};
int duixiang_test8_2::duixiang_test8_2_a=100;
//    2) 静态成员函数---访问
void function_duixiang_test8_2(){
    // 1、通过对线访问
    duixiang_test8_2 P;
    P.func();

    // 2、通过类名进行访问
    duixiang_test8_2::func();
    return;
}

//  9、成员变量和成员函数分开存储
//  只有非静态成员变量才属于类的对象上
class duixiang_test9{
};
void fun_duixiang_test9(){
    duixiang_test9 P;
    cout << "空对象占用空间：" << sizeof(P) << endl;
    //sizeof(P) 为 1
    // c++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
}
class duixiang_test9_2{
public: 
    int a;// 4字节 非静态成员变量 属于类的对象上
    static int duixiang_test9_2_a;// 静态成员变量 不属于类的对象上
    void func(){}; // 非静态成员函数  不属于类的对象上
    static void func2(){};// 静态成员函数 不属于类的对象上
};
int duixiang_test9_2::duixiang_test9_2_a=10;
void fun_duixiang_test9_2(){
    duixiang_test9_2 P;
    cout << "对象占用空间：" << sizeof(P) << endl;
    //sizeof(P) 为 4
    // 只有非静态成员变量属于类的对象上
}

// 10、this指针
//    背景1)成员变量和成员函数是分开存储的，
//    背景2)每一个非静态成员函数只会诞生一份函数实例，多个同类型的对象会共用一块代码
//    问题： 这一块代码是如何区分哪个对象调用自己？ this指针
//   this指针指向被调用的成员函数所属对象；this指针隐含在每一个非静态成员函数内的指针；不需要定义，直接使用
//    用途
//      1) 当形参和成员变量同名时，可用this指针来区分
//      2) 在类的非静态成员函数中返回对象本身，可以使用return *this;
class duixiang_test10{
public:
    // 解决名称冲突
    duixiang_test10(int age){
        // age = age;//左边age无法识别，不确定是否为类内成员age还是参数age
        this->age = age;
    }
    // 返回对象本身
    duixiang_test10& AddAge(duixiang_test10 P){
        this->age += P.age;
        return *this;
    }
    int age;
};
void func_duixiant_test10(){
    duixiang_test10 p1(10);
    duixiang_test10 p2(10);
    // 链式编程
    p2.AddAge(p1).AddAge(p1).AddAge(p1);// 每次返回的是p2，可以重复实现年龄+
    cout << "p2.age: " << p2.age << endl;
}

// 11、空指针访问成员函数
//  c++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
//  如果用到this指针，需要加以判断保证代码的健壮性
class duixiang_test11{
public:
    void showname(){
        cout << "无内部成员的函数" <<endl;
    }
    void showage(){
        if(this ==NULL){
            return;
        }
        cout << "有内部成员函数" << m_Age << endl;
        // 调用成员变量时，实际为this->m_Age,
        // 当没有对象时，this=NULL, this->m_Age不存在,所以会出错,需要加以判断
    }
    int m_Age=10;
};
void func_duixiang_test11(){
    duixiang_test11* P = NULL;
    P->showname();// 空指针可以调用
    P->showage(); // this 为空的时候
}

// 12、const 修饰成员函数
//  常函数:
//     成员函数后加const后我们称这个函数为常函数
//     常函数内不可以修改成员属性
//     成员属性声明时加关键字muttable后，在常函数中依然可以修改
//  常对象:
//     声明对象前加const称该对象为常对象
//     常对象只能调用常函数
class duixiang_test12{
public:
    duixiang_test12(){};
    // this指针的本质 是指针常量  指针的指向不可以修改
    // const clasname * const this
    // 在成员函数后面加const，修饰的是this指向，让指针指向的值不可以修改
    void function1() const {
        // this->m_A=100; // 不可以修改
        this->m_B = 100; //加入关键词mutable 就可以修改成员属性了
    }
    void function2(){

    }
    int m_A;
    mutable int m_B;
};
void func_duixianig_test12(){
    // const duixiang_test12 p1;
    const duixiang_test12 p1;
    // P.m_A = 100; //
    p1.m_B = 200;
    // p1.function2();//常对象只能调用常函数
    p1.function1();
    return;
}


/******************part6 友元 ************************/
// 1、友元定义： 让类外特殊的一些函数或者类访问本类内的私有属性
//        目的：让一个函数或者类访问另一个类中私有成员
//        关键字： friend
//       实现：1)全局函数做友元  2)类做友元  3)成员函数做友元
// 1) 全局函数做友元
class Building
{
//全局函数前面加一个friend，告诉类，这个是友元函数
friend void GoodGay(Building * building);
public:
    Building(){
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    };
public:
    string m_SittingRoom;//客厅
private:
    string m_BedRoom;
};
// 全局函数
void GoodGay(Building * building){
    cout << "好基友全局函数 正在访问："<< building->m_SittingRoom << endl;
    cout << "好基友全局函数 正在访问："<< building->m_BedRoom << endl;
}
// 2) 类做友元
class Building2{
    friend class GoodGay2;
public:
    Building2(){
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    };
public:
    string m_SittingRoom;//客厅
private:
    string m_BedRoom;
};
class GoodGay2{
public:
    GoodGay2(){
        building = new Building2;
    };
    void visit(){
        cout << "好基友类 正在访问："<< building->m_SittingRoom << endl;
        cout << "好基友类 正在访问："<< building->m_BedRoom << endl;
    }
    Building2 * building;
};
void func_friend_test1(){
    GoodGay2 gg;
    gg.visit();
    return;
}
// 3) 成员函数做友元; 先声明类和函数，两个都声明完之后进行构造和析构函数的实现
class Building3;
class GoodGay3{
public:
    GoodGay3();
    void visit();
    void visit2();
    Building3 * building;
};
class Building3{
friend void GoodGay3::visit();
public:
    Building3();
public:
    string m_SittingRoom;//客厅
private:
    string m_BedRoom;
};
Building3::Building3(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
};
GoodGay3::GoodGay3(){
    building = new Building3;
};
void GoodGay3::visit(){
    cout << "好基友visit 正在访问："<< building->m_SittingRoom << endl;
    cout << "好基友visit 正在访问："<< building->m_BedRoom << endl;
}
void GoodGay3::visit2(){
    cout << "好基友visit2 正在访问："<< building->m_SittingRoom << endl;
    // cout << "好基友类 正在访问："<< building->m_BedRoom << endl;
}

void func_friend_test2(){
    GoodGay3 gg;
    gg.visit();
    gg.visit2();
    // // gg.visit2();
    // system("pause");
    // Building3 building;
    // cout << building.m_SittingRoom;
}


/******************part7 c++运算符重载 ************************/
// 运算符重载的概念：对已有的运算符进行重新定义，赋予其另一种功能，以适应不同的数据类型
// 1、加号运算符重载
//   对于不是内置的数据类型，重新定义加法运算法则
//  1)通过成员函数重载
//  2)通过全局函数重载
//  1)重载---成员函数
class Operate_test1{
public:
    Operate_test1 operator+(Operate_test1 &p){
        Operate_test1 temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
    int m_A=10;
    int m_B=11;
};
void func_Operate_test1(){
    Operate_test1 p1;
    p1.m_A = 10;
    p1.m_B = 11;
    Operate_test1 p2;
    p2.m_A = 20;
    p2.m_B = 21;
    // 本质为
    // Operate_test1 p3 = p1.operator+(p2);
    Operate_test1 p3 = p1 + p2;
    cout << "p3.m_A : " << p3.m_A << "  p3.m_B: " << p3.m_B << endl;
    return;
}
///  2)重载---全局函数
class Operate_test2{
public:
    int m_A=10;
    int m_B=11;
};
Operate_test2 operator+(Operate_test2&p1, Operate_test2&p2){
    Operate_test2 p3;
    p3.m_A = p1.m_A + p2.m_A;
    p3.m_B = p1.m_B + p2.m_B;
    return p3;
}
void func_Operate_test2(){
    Operate_test1 p1;
    p1.m_A = 10;
    p1.m_B = 11;
    Operate_test1 p2;
    p2.m_A = 20;
    p2.m_B = 21;
    // 本质为
    // Operate_test1 p3=operator+(p1, p2);
    Operate_test1 p3 = p1 + p2;
    cout << "p3.m_A : " << p3.m_A << "  p3.m_B: " << p3.m_B << endl;
    return;
}

// 2、左移运算符重载
class Operate_test3{
public:
    // 成员函数 无法实现 cout在左边
    // void operator<<(){
    // }
    int m_A=10;
    int m_B=11;
};
ostream&  operator<<(ostream& cout, Operate_test3 p){
    cout << "m_A = " << p.m_A << "  m_B = " << p.m_B <<" ";
    return cout;
}// return cout 为实现链式编程，无限调用
void func_Operate_test3(){
    Operate_test3 p1;
    p1.m_A = 10;
    p1.m_B = 11;
    cout << p1 << "hello world" << endl;
    return;
}

// 3、递增运算符重载
class Operate_test4{
    friend ostream& operator<<(ostream&cout, Operate_test4 p);
public:
    Operate_test4(){
        m_num = 0;
    }
    Operate_test4& operator++(){
        m_num++;
        return *this;
    }
    Operate_test4 operator++(int){
        Operate_test4 temp = *this;
        m_num++;
        return temp;
    }
private:
    int m_num;
};
ostream& operator<<(ostream&cout, Operate_test4 p){
    cout << p.m_num;
    return cout;
}
void func_Operate_test4(){
    Operate_test4 p1;
    cout << (++p1)<<endl;
    cout << p1++<<endl;
    cout << p1<<endl;
    return;
}

// 4、赋值运算符重载
// c++至少提供4个函数：构造+析构+拷贝+operator=
class Operator_test5{
public:
    Operator_test5(int age){
        m_age = new int(age);
    }
    ~Operator_test5(){
        if(m_age!=NULL){
            delete m_age;
        }
    }
    // 自己定义赋值操作是为了避免有堆区数值复制时候出现问题，多个对象对同一区域多次释放
    Operator_test5& operator=(Operator_test5 &p){
        if(m_age!=NULL){
            delete m_age;
        }
        m_age = new int(*p.m_age);
        return*this;
    }
private:
    int *m_age;
};

// 5、关系运算符重载
class Operator_test6{  
public:
    Operator_test6(string name, int age){
        m_Name = name;
        m_Age = age;
    }
    bool operator==(Operator_test6&p){
        if(p.m_Name == m_Name && p.m_Age == m_Age){
            return true;
        }
        return false;
    }
    bool operator!=(Operator_test6&p){
        if(p.m_Name == m_Name && p.m_Age == m_Age){
            return false;
        }
        return true;
    }
    string m_Name;
    int m_Age;
    
};

// 6、函数调用运算符重载
//    函数调用运算符() 也可以重载
//    由于重载后使用的方式非常像函数的调用，因此成为仿函数
//    仿函数没有固定写法，非常灵活
class Operator_test7{
public:
    void operator()(string text){
        cout <<  text << endl;
    }
};
void func_Operator_test7(){
    Operator_test7 myprint;
    myprint("hello world");//使用起来像正常函数调用，叫仿函数
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
    // duixiang_test1 t1;
    // duixiang_test2_diaoyong();
    // func_duixiant_test10();
    // func_friend_test2();
    // func_Operate_test2();
    func_Operate_test4();

    return 0;
}