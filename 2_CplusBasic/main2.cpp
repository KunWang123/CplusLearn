// 学习继承和多态
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/******************part8 继承 ************************/
// 1、继承的基础语法
//    继承是面向对象的三大特性之一
//    继承的好处，减少重复的代码
//    语法：class 子类: 继承方式 父类
//         子类：派生类
//         父类：基类
// 派生类的成分：一类从基类获得，一类自己的特性
class jicheng_BasePage1{
public:
    void header(){
        cout << "首页公开课、注册...（公共头部）" << endl;
    }
    void footer(){
        cout << "帮助中心、交流合作...（公共底部）" << endl;
    }
    void left(){
        cout << "Java、Python、c++....(学科列表))" << endl;
    }
};
class jicheng_Java:public jicheng_BasePage1{
public:
    void content(){
        cout << "java 学习视频" << endl;
    }
};
class jicheng_Python:public jicheng_BasePage1{
public:
    void content(){
        cout << "python 学习视频" << endl;
    }
};
void func_test1(){
    jicheng_Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "----------------------------" <<endl;
    jicheng_Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
}

// 2、继承方式
//  class 子类：继承方式 父类
//  继承方式:(不论是哪种继承，父类中私有权限的成员不能访问)
//  1) 公共继承：父类中public和protected不变
//  2) 保护继承：父类中public和protected变为protected
//  3) 私有继承：父类中public和protected变为private
class jicheng_test2_Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class jicheng_test2_son1:public jicheng_test2_Base{
public:
    void func(){
        m_A = 10;
        m_B = 10;
        // m_C = 10;
    }
};
class jicheng_test2_son2:protected jicheng_test2_Base{
public:
    void func(){
        m_A = 100;//保护权限
        m_B = 100;//保护权限
        // m_C = 100;
    }
};
void func1_jicheng_test2(){
    jicheng_test2_son2 son2;
    // son2.m_A = 10; //protected 类内可以访问，类外不能
}
class jicheng_test2_son3:private jicheng_test2_Base{
public:
    void func(){
        m_A = 10;//现阶段是私有的，类外不能访问
        m_B = 10;//现阶段是私有的，类外不能访问
        // m_C = 10;
    }
};

// 3、继承中的对象模型
class jicheng_test3_Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class jicheng_test3_Son:public jicheng_test3_Base{
public:
    int m_D;
};// sizeof(jicheng_test3_Son)=16,所有都被继承下来了，私有成员也继承下去了，只是被编译器隐藏，访问不到

// 4、继承中的构造和析构顺序
//  Base构造函数；Son构造函数；Son析构函数；Base析构函数

// 5、继承中同名成员的处理方式
//    访问子类同名成员，直接访问即可
//    访问父类同名成员，需要加作用域
//    当子类与父类拥有同名的成员函数，子类会隐藏弗雷中同名成员函数，加作用域可以访问到父类中同名函数
class jicheng_test5_Base{
public:
    jicheng_test5_Base(){
        m_A = 10;
    }
    void func(){
        cout << "父类成员函数" << endl;
    }
    void func(int a){
        cout << "父类成员函数 func(int)" << endl;
    }
    int m_A;
};
class jicheng_test5_Son:public jicheng_test5_Base{
public:
    jicheng_test5_Son(){
        m_A = 100;
    }
    void func(){
        cout << "子类成员函数" << endl;
    }
    int m_A;
};
// 同名成员变量处理
void func1_jicheng_test5(){
    jicheng_test5_Son son;
    cout << "son 类成员访问： " << son.m_A << endl;
    cout << "Base 类成员访问： " << son.jicheng_test5_Base::m_A << endl;
}
void func2_jicheng_test5(){
    jicheng_test5_Son son;
    son.func();//son 类成员函数访问： 
    son.jicheng_test5_Base::func();//base类成员函数访问
    // 如果子类中出现和父类同名的成员函数，子类同名函数会隐藏掉父类中所有的同名成员函数
    // 如果想访问到父类被隐藏的同名成员函数，需要加作用域
    son.jicheng_test5_Base::func(10);//base类成员函数访问： 
}

// 6、继承同名静态成员处理方式
//    访问子类同名成员，直接访问即可
//    访问父类同名成员，需要加作用域
//    子类和父类出现同名静态成员函数，子类同名函数会隐藏掉父类所有同名成员函数
class jicheng_test6_Base{
public:
    static int m_A;
};
int jicheng_test6_Base::m_A = 100;
class jicheng_test6_Son:public jicheng_test6_Base{
public:
    static int m_A;
};
int jicheng_test6_Son::m_A = 200;
//  访问成员变量和成员函数相同方法
void func1_jicheng_test6(){
    // 1 通过对象访问
    cout << "通过对象访问" << endl;
    jicheng_test6_Son s;
    cout << "Son 下 m_A: " << s.m_A << endl;
    cout << "Base 下 m_A: " << s.jicheng_test6_Base::m_A << endl;

    // 2 通过类名访问
    cout << "通过类名访问" << endl;
    cout << "Son 下 m_A: " << jicheng_test6_Son::m_A << endl;
    // 第一个::代表通过类名方式访问，  第二个:: 代表访问父类作用域下
    cout << "Base 下 m_A: " << jicheng_test6_Son::jicheng_test6_Base::m_A << endl;
}

// 7、多继承语法 (实际使用中不建议)
//    语法： class 子类： 继承方式 父类1, 继承方式 父类2....
class jicheng_test7_Base1{
public:
    jicheng_test7_Base1(){
        m_A = 100;
    }
    int m_A;
};
class jicheng_test7_Base2{
public:
    jicheng_test7_Base2(){
        m_A = 200;
        m_B = 201;
    }
    int m_A;
    int m_B;
};
class jicheng_test7_Son:public jicheng_test7_Base1, public jicheng_test7_Base2{
public:
    int m_C;
};
void func1_test7(){
    jicheng_test7_Son son;
    //  访问不同父类中的同名变量，需要加作用域
    cout << "base1 m_A = " << son.jicheng_test7_Base1::m_A << endl;
    cout << "base2 m_A = " << son.jicheng_test7_Base2::m_A << endl;
    // 访问不同名的不需要加入作用域
     cout << "base2 m_B = " << son.m_B << endl;
}

// 8、菱形继承
//  概念： 两个派生类继承同一个基类， 又有某个类同时继承两个派生类，这种继承被称为菱形继承(钻石继承)
//  后果：菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
//  措施：利用虚继承可以解决菱形继承问题
class jicheng_test8_Base{
public:
    jicheng_test8_Base(){
        m_Age = 18;
    }
    int m_Age;
};
class jicheng_test8_Son1: virtual public jicheng_test8_Base{
};
class jicheng_test8_Son2: virtual public jicheng_test8_Base{
};
// 继承了两份Base, 为了解决这个问题，引入关键字virtual，虚继承
// Base类称为 虚基类
class jicheng_test8_GrandSon:public jicheng_test8_Son1, public jicheng_test8_Son2{
};
void func1_test8(){
    jicheng_test8_GrandSon grandson;// 继承了两份Base
    grandson.jicheng_test8_Son1::m_Age = 10;
    grandson.jicheng_test8_Son2::m_Age = 20;
    cout << "son1 age: " << grandson.jicheng_test8_Son1::m_Age << endl;// 加virtual之前是10，之后是20
    cout << "son2 age: " << grandson.jicheng_test8_Son2::m_Age << endl;// 加virtual之前是20，之后是20
    // 虚继承后可以直接访问
    //  引入virtual后，两次继承的基类会变成两个虚基类指针(vbptr)指向虚基类表(vbtable)
    //  两次继承的基类数据会变成一份，不论那边改动，输出的结果只有一个
    cout << "grand_son age:" << grandson.m_Age << endl;// 输出20,保留最后一次改动； 加virtual之前不能直接调用grandson.m_Age
}


/******************part9 多态 ************************/
// 1、多态的基本概念
//  多态分为两类：
//     静态多态：函数重载 运算符重载 属于静态多态，复用函数名
//     动态多态：派生类和虚函数实现运行时多态
//  静态多态和动态多态的区别：
//     静态多态的函数地址早绑定 -- 编译阶段确定函数地址
//     动态多态的函数地址晚绑定 -- 运行阶段确定函数地址
//  动态多态的满足条件
//     1) 存在继承关系
//     2) 子类重写父类的虚函数(重写：返回值一致，参数列表一致； 子类重写函数virtual关键字可写可不写)
//  动态多态的使用
//     父类的指针或者引用指向子类对象
class duotai_1_Animal{
public:
    virtual void speak(){
        cout << "动物在说话" << endl;
    }
};
class duotai_1_Cat:public duotai_1_Animal{
public:
    //virtural void speak(){//同下,子类中virtual关键字可写可不写
    void speak(){
        cout << "小猫在说话" << endl;
    }
};
// 父类的指针可以直接指向子类的对象
// Animal & animal = cat;//允许
void func1_duotai_dospeak(duotai_1_Animal & animal){
    animal.speak();
}
void func_duotai_test1(){
    duotai_1_Cat cat;
    // 当animal中speak不是虚函数时，调用的是animal的speak
    // 当animal中的speak是虚函数时，传入的参数是什么，就调用哪个对象的speak
    func1_duotai_dospeak(cat);
}

// 2、动态多态的剖析
// 函数多态子类继承父类的vfptr指向vftable,然后子类重写虚函数后替换vftable中的虚函数
// 所以父类引用或者指针指向子类的对象时，再调用函数便使用的是子类实现的函数
// 子类只修改了，子类继承后的vftable中的函数实现；父类中本身的vftable并没有改变

// 3、多态实现计算器
//  多态好处：
//    1) 组织结构清晰
//    2) 可读性很强
//    3) 利于前期和后期的扩展以及维护
class duotai_3_AbstractCal{
public:
    virtual int getresult(){
        return 0;
    }
    int m_Num1;
    int m_Num2;
};
class duotai_3_AddCal:public duotai_3_AbstractCal{
public:
    int getresult(){
        return m_Num1 + m_Num2;
    }
};
class duotai_3_SubCal:public duotai_3_AbstractCal{
public:
    int getresult(){
        return m_Num1 - m_Num2;
    }
};
void func_duotai_test3(){
    duotai_3_AbstractCal * abs=NULL;
    // 计算加法
    abs = new duotai_3_AddCal;
    abs->m_Num1 = 10;
    abs->m_Num2 = 10;
    cout << abs->m_Num1 << " + " << abs->m_Num2 << " = " << abs->getresult() << endl;
    delete abs;
    abs = NULL;

    // 计算减法
    abs = new duotai_3_SubCal;
    abs->m_Num1 = 10;
    abs->m_Num2 = 10;
    cout << abs->m_Num1 << " - " << abs->m_Num2 << " = " << abs->getresult() << endl;
    delete abs;
    abs = NULL;
}

// 4、纯虚函数和抽象类
//    多态中，通常父类中的虚函数的实现是毫无意义的，主要都是调用子类重写的内容
//    因此可以将虚函数改为纯虚函数
//    纯虚函数语法： virtual 返回值类型 函数名 (参数列表) = 0；
//    当类中有了纯虚函数，这个类也成为抽象类
//    抽象类特点：
//      1) 无法实例化对象
//      2) 子类必须重写抽象类中的纯函数，否则也是属于抽象类
class duotai_4_Base{
public:
    virtual void func() = 0;
};

// 5、虚析构和纯虚析构
//   多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
//   解决方式：将父类的析构函数改为 虚析构 或者 纯虚析构
//   虚析构和纯虚析构 作用：利用虚析构可以解决父类指针释放子类对象不干净的问题
//   纯虚析构：需要声明也需要实现
//   如果子类中没有堆区数据，可以不写虚析构或者纯虚析构
//   拥有纯虚析构的函数的类也属于抽象类
class duotai_5_Animal{
public:
    duotai_5_Animal(){
        cout << "animal 构造" << endl;
    }
    virtual void speak() = 0;
    virtual ~duotai_5_Animal(){// 虚析构
        cout << "animal 析构" << endl;
    }
    // virtual ~duotai_5_Animal()=0;//纯虚析构声明
};
// duotai_5_Animal::~duotai_5_Animal(){// 纯虚析构实现
//     cout << "animal 析构" << endl;
// }
class duotai_5_Cat:public duotai_5_Animal{
public:
    duotai_5_Cat(string name){
        cout << "cat 构造" << endl;
        m_Name = new string(name);
    }
    void speak(){
        cout << "小猫在说话" << endl;
    }
    ~duotai_5_Cat(){
        cout << "cat 析构" << endl;
        if(m_Name!=NULL){delete m_Name; m_Name=NULL;}
    }
    string *m_Name;
};
void func_duotai_test5(){
    duotai_5_Animal * animal = new duotai_5_Cat("Tom");
    animal->speak();
    // 父类指针释放子类对象事不干净，不执行子类的析构函数，需要加虚析构
    delete animal; // 不是虚析构的时候，此时不能执行Cat的析构函数

}

/******************part10 文件操作 ************************/
// c++中对文件操作需要包含头文件<fstream>
// 文件类型两类：
//    1) 文本文件 -- 文件以文本的ASCII码的形式存储在计算机中
//    2) 二进制文件 -- 文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂他们
// 操作文件的三大类
//   1) ofstream: 写操作
//   2) ifstream: 读操作
//   3) fstream: 读写操作
// 1、文本文件---写
void file_1_wirte(){
    ofstream ofs;
    ofs.open("./file_1_write.txt", ios::out);
    ofs << "name: zhangsan"<<endl;// 中文写入文件存在问题
    ofs.close();
}
// 2、文本文件---读
void file_2_read(){
    ifstream ifs;
    ifs.open("file_1_write.txt", ios::in);
    if (!ifs.is_open()){
        cout << "file open failed!" << endl;
        return ;
    }
    // // 第一种
    // char buff[1024] = {0};
    // while (ifs >> buff)
    // {
    //     cout << buff << endl;
    // }

    // // 第二种
    // char buff[1024] = {0};
    // while (ifs.getline(buff, sizeof(buff)))
    // {
    //     cout << buff << endl;
    // }

    // // 第三种
    // string buff;
    // while (getline(ifs, buff))
    // {
    //     cout << buff << endl;
    // }

    // 第四种
    char c;
    while ((c=ifs.get())!=EOF)
    {
        cout << c << endl;
    }

    ifs.close();
    return;
}
// 3、二进制文件-写
void file_3_writeb(){
    ofstream ofs("file_3_binay.txt", ios::out | ios::binary);
    char arr[] = {'1','2','3','4'};
    // char arr = '1';
    cout << sizeof(arr)<< endl;
    ofs.write(arr, sizeof(arr));
    ofs.close();
}
// 4、二进制文件-读
void file_3_readb(){
    ifstream ifs("file_3_binay.txt", ios::in | ios::binary);
    if(!ifs.is_open()){
        cout << "file open failed" << endl;
        return;
    }
    char arr[5] = {};//多的一个字符是什么？
    // char arr='5';
    cout << sizeof(arr) << endl;
    ifs.read(arr, sizeof(arr));
    ifs.close();
    cout << arr << endl;
}

int main(){
    // func_test1();
    // func1_jicheng_test5();
    // func1_test8();
    // func_duotai_test1();
    // func_duotai_test3();
    // file_1_wirte();
    // file_2_read();
    file_3_writeb();
    file_3_readb();
    return 0;
}