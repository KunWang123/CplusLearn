#include <iostream>

using namespace std;
/********** part1 new *********/
// 1��new �����÷�
// �ڶ�����������
void func(){
    int *p = new int(10);
    delete p;
}
// 2���ڶ�������new��������
void test02(){
    int *aarr = new int[10];
    delete [] aarr; //�ͷ����� ����[]

}

/***********part2 ����************/
// 1�������Ǹ������������ָ����ͬ��ַ
void yinyong_test1(){
    int a = 10;
    int &b = a;
    b = 100;
    cout << a << endl;
}
// 2������ע�⣺ �����ʼ�������ɱ�
void yinyong_test2(){
    int a = 10;
    int &b = a;
    int c = 11;
    b = c; //��ֵ��������ȷ
    cout << "" <<b << endl;
    b = 15;
    cout << "c: " << c << endl;
    cout << "a: " << a << endl;
    // int &b=c; // ���󣬶������
    // &b=c; // ���󣬲����Ը�������
}
//3�����ô��κ͵�ַ����һ��,���޸�ԭʼֵ
void yinyong_test3(int &a, int&b){
    int c = a;
    a = b;
    b = c;
}
// 4��ָ��ı��ʣ�ָ�볣��
// int &p=a; ת��Ϊ int *const p =&a; ָ��ָ��̶��������޸�ֵ


/****************part3 ����*******************/
//1������ռλ����,�ֽ׶�ռλ�����ò���
// ռλ�������Ը�Ĭ��ֵfunction_test1(int a, int =10)
void function_test1(int a, int){
    cout << "" <<endl;
    return ;
}// function_test1(10, 11)
//2���������أ�������������ͬ����߸�����
// 1) ��ͬһ���������£�2) ����������ͬ 3)������������/����/˳��ͬ
void function_test2(){
    cout << "��������1" << endl;
}
void function_test2(int a){
    cout << "��������2" << endl;
}
void function_test2(double a){
    cout << "��������3" << endl;
}
void function_test2(double a, int b){
    cout << "��������4" << endl;
}
void function_test2(int a, double b){
    cout << "��������5" << endl;
}
// 3���������ص�ע������
// 1) ������Ϊ���ص�����
void function_test3(int &a){
    cout << "��������3" << endl;
}
void function_test3(const int &a){
    cout << "��������4" << endl;
}
// 2) ������������Ĭ�ϲ��� 
// function_test3_default(int a�� int b=10) ���ܺ����أ�����Ĭ��ֵ
void function_test3_default(int a){
    cout << " ������" << endl;
}
// function_test3_default(int a�� int b =10)


/******************part4 ��װ ************************/
//c++����������������Ϊ�� ��װ���̳С���̬
// ��װ�����壺�����Ժ���Ϊ��Ϊһ�����壬���������е���������Ժ���Ϊ����Ȩ������
// 1 ���һ��Բ�࣬����ܳ�
const double PI=3.1415926;
class Circle
{
// ����Ȩ��
private:
    /* data */
public:
    int m_r;//�뾶

    // ��Ϊ�� �����ܳ�
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
        cout << "������ " << name << endl;
        cout << "ѧ�ţ� " << number << endl;
        return;
    }
};

// 2 ��ķ���Ȩ�ޣ� 
// ����Ȩ��: ��Ա ���ڿ��Է��ʣ�������Է���
// ����Ȩ�ޣ���Ա ���ڿ��Է��ʣ����ⲻ���Է��ʣ� �̳��У��ӿ��Է���
// ˽��Ȩ�ޣ���Ա ���ڿ��Է��ʣ����ⲻ���Է��ʣ� �̳��У��Ӳ����Է���
class Person
{
private:
    int m_Password;
public:
    string m_Name;
protected:
    string car;
};

// 3 struct �� class ������ struct��Ĭ��Ȩ���ǹ����� class��Ĭ��Ȩ����˽��
class Test
{
    int m_A; // private, �ⲿ���ܷ���
};
struct Test1
{
    int m_A; // public, �ⲻ�ܷ���
};

// 4 ��Ա��������Ϊ˽�л�
// 1) �����Լ����ƶ�ȡȨ�� 2)����д���Լ�����ݵ���Ч��
class class_test4
{
private:
    int p_Age = 10;//��
    string p_Name = ""; // ��д
    string p_Lover = "";// д
public:// ���ö���˽�г�Ա��Ȩ��
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

// 5 test example ���������壬��������������
class class_5TestCube
{
private:
    double m_L=0;//�����
    double m_W=0;//�����
    double m_H=0;//�����
public:
    //����ֵ 
    void setLength(double length){
        m_L = length;
    }
    void setWidth(double width){
        m_W = width;
    }
    void setHeight(double height){
        m_H = height;
    }
    // ���ֵ
    double getLenght(){
        return m_L;
    }
    double getWidth(){
        return m_W;
    }
    double getHeight(){
        return m_H;
    }
    // ���� ������
    double calculateV(){
        return m_L * m_W * m_H;
    }
    double calculateS(){
        return 2*m_L * m_W + 2 * m_L * m_H + 2 * m_H * m_W;
    }

    // �ж������������Ƿ����
    bool isSameCube(class_5TestCube &c){
        if(m_L==c.getLenght() && m_H==c.getHeight() && m_W==c.getWidth()){
            return true;
        }
        return false;
    }
};

/******************part5 �������� ************************/
// 1 ���캯������������: ���ṩ��ʱ�򣬱��������ṩ�պ���
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

// 2�����캯���ķ��༰����
// 1) ����
//    ���ղ������ࣺ �޲ι��죨Ĭ�Ϲ��죩�� �вι���
//    �������ͷ��ࣺ ��ͨ����  �� ��������
class duixiang_test2
{
private:
    int age;
public:
    // ��ͨ����----�޲ι���
    duixiang_test2(){
        cout << "�޲ι��캯��" << endl;
    }
    // ��ͨ����----�вι���
    duixiang_test2(int a){
        cout << "�вι��캯��" << endl;
        age = a;
        cout << "age: " << age << endl;
    }
    // ��������
    duixiang_test2(const duixiang_test2 &p){
        // ����������������Զ�������������
        cout << "�������캯��" << endl;
        age=p.age;
    }
    ~duixiang_test2(){}
};
// 2) ����
void duixiang_test2_diaoyong(){
    // 1 ���ŷ�
    duixiang_test2 p1;//duixiang_test2 p1(); ���󣬱��������Ϊ��������
    duixiang_test2 p2(10);
    duixiang_test2 p3(p2);

    // 2 ��ʾ��
    duixiang_test2 p4;
    duixiang_test2 p5 = duixiang_test2(10);//�вι���
    duixiang_test2 p6 = duixiang_test2(p5);//��������

    duixiang_test2(10);// ��������
    //duixiang_test2(p5);// ������Ĭ��Ϊ duxiang_test2 p5;

    // ��ʽת����
    duixiang_test2 p7 = 10;// �вι���
    duixiang_test2 p8 = p7;// ��������
}

// 3���������캯���ĵ���ʱ��
//   1) ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���;
//   2) ֵ���ݵķ�ʽ������������ֵ;//��������ʱ������
//   3) ֵ��ʽ���ؾֲ�����// ��������һ����Ķ���ʱ�����˿���
class duixiang_test3{
public:
    duixiang_test3(int age){
        m_Age = age;
        cout << "�������캯��" << endl;
    };

private:
    int m_Age;
};

// 4�����캯���ĵ��ù���
//  Ĭ������£�c++�����������ٸ�һ�������3������
//   1) Ĭ���޲ι��캯�����޲Σ� ������Ϊ�գ�
//   2) Ĭ���޲������������޲Σ�������Ϊ�գ�
//   3) Ĭ�Ͽ������캯���������Խ���ֵ����
// ���ǣ���
//   1) ����û������вι��캯����c++�����ṩ�޲ι��캯�������ǻ��ṩ�������캯��
//   2) ����û������˿������캯����c++�����ṩ�������캯��

// 5�������ǳ����
//   ǳ�������򵥵ĸ�ֵ��������
//   ������ڶ�����������ռ䣬���п�������
class duixiang_test5
{
public:
    int m_Age = 0;
    int * m_Height = NULL;
    duixiang_test5(){
        cout << "�޲ι��캯��" << endl;
    };
    duixiang_test5(int age, int height){
        m_Age = age;
        m_Height = new int (height);
        cout << "�вι��캯��" << endl;
    };
    duixiang_test5(const duixiang_test5 & p){
        // Ĭ�ϵĿ������캯��Ϊ
        // m_Age = p.m_Age;
        // m_Height = p.m_Height;
        // ������ָ��ʱ�򣬻���������������ͳһ�ڴ������delete����

        // �Լ�ʵ�����
        m_Age = p.m_Age;
        m_Height = new int(*p.m_Height);

        cout << "�������캯��"<< endl;
    }
    ~duixiang_test5(){
        if(m_Height!=NULL){
            delete m_Height;
            m_Height = NULL;
        }
        cout << "��������" << endl;

    };
};

// 6����ʼ���б�
class duixiang_test6
{
private:
    /* data */
public:
    // ��ͳ�вι��캯��
    // duixiang_test6(int a, int b, int c){
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }

    // ��ʼ�������б�
    // �̶�ֵ��ʼ��
    // duixiang_test6():m_A(10),m_B(20),m_C(30){
    // }
    // �������ĳ�ʼ��
    duixiang_test6(int a, int b, int c):m_A(a),m_B(b),m_C(c){
    }
    int m_A;
    int m_B;
    int m_C;
};

// 7���������Ϊ���Ա
// c++���еĳ�Ա��������һ����Ķ������ǳƸó�ԱΪ�����Ա
// �������������Ϊ�����Աʱ������ʱ���ȹ���������ٹ�������������˳���෴
class duixiang_test7_1{
};
class duixiang_test7_2{
    duixiang_test7_1 a;// �����
};

// 8����̬��Ա
// ��̬��Ա������ ��Ա���� �� ��Ա���� ǰ���Ϲؼ���static,��Ϊ��̬��Ա
//   ��̬��Ա�����ص㣺1) ���ж�����ͬһ�����ݣ�2)�ڱ���׶η����ڴ棻 3) ���������������ʼ��
//   ��̬��Ա�����ص㣺1) ���ж�����ͬһ�������� 2) ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class duixiang_test8{
public:
    static int duixiang_test8_A;//��������
};
int duixiang_test8::duixiang_test8_A=100;//�����ʼ��
//   1) ��̬��Ա��������
//     1��ͨ��������з���: duixiang_test8 P; cout<< P.duixiang_test8_A;
//     2��ͨ���������з��ʣ� cout<< duixiang_test8::duixiang_test8_A;
//   2) ��̬��Ա����---����
class duixiang_test8_2{
public:
    static void func(){
        duixiang_test8_2_a = 200;
        // duixiang_test8_2_b = 100; // ������̬��Ա�������ܷ��ʷǾ�̬��Ա����
        cout << "��̬��Ա����" << endl;
    }
    static int duixiang_test8_2_a;
    int duixiang_test8_2_b;
};
int duixiang_test8_2::duixiang_test8_2_a=100;
//    2) ��̬��Ա����---����
void function_duixiang_test8_2(){
    // 1��ͨ�����߷���
    duixiang_test8_2 P;
    P.func();

    // 2��ͨ���������з���
    duixiang_test8_2::func();
    return;
}

//  9����Ա�����ͳ�Ա�����ֿ��洢
//  ֻ�зǾ�̬��Ա������������Ķ�����
class duixiang_test9{
};
void fun_duixiang_test9(){
    duixiang_test9 P;
    cout << "�ն���ռ�ÿռ䣺" << sizeof(P) << endl;
    //sizeof(P) Ϊ 1
    // c++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
    // ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
}
class duixiang_test9_2{
public: 
    int a;// 4�ֽ� �Ǿ�̬��Ա���� ������Ķ�����
    static int duixiang_test9_2_a;// ��̬��Ա���� ��������Ķ�����
    void func(){}; // �Ǿ�̬��Ա����  ��������Ķ�����
    static void func2(){};// ��̬��Ա���� ��������Ķ�����
};
int duixiang_test9_2::duixiang_test9_2_a=10;
void fun_duixiang_test9_2(){
    duixiang_test9_2 P;
    cout << "����ռ�ÿռ䣺" << sizeof(P) << endl;
    //sizeof(P) Ϊ 4
    // ֻ�зǾ�̬��Ա����������Ķ�����
}

// 10��thisָ��
//    ����1)��Ա�����ͳ�Ա�����Ƿֿ��洢�ģ�
//    ����2)ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ�������ͬ���͵Ķ���Ṳ��һ�����
//    ���⣺ ��һ���������������ĸ���������Լ��� thisָ��
//   thisָ��ָ�򱻵��õĳ�Ա������������thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�ָ�룻����Ҫ���壬ֱ��ʹ��
//    ��;
//      1) ���βκͳ�Ա����ͬ��ʱ������thisָ��������
//      2) ����ķǾ�̬��Ա�����з��ض���������ʹ��return *this;
class duixiang_test10{
public:
    // ������Ƴ�ͻ
    duixiang_test10(int age){
        // age = age;//���age�޷�ʶ�𣬲�ȷ���Ƿ�Ϊ���ڳ�Աage���ǲ���age
        this->age = age;
    }
    // ���ض�����
    duixiang_test10& AddAge(duixiang_test10 P){
        this->age += P.age;
        return *this;
    }
    int age;
};
void func_duixiant_test10(){
    duixiang_test10 p1(10);
    duixiang_test10 p2(10);
    // ��ʽ���
    p2.AddAge(p1).AddAge(p1).AddAge(p1);// ÿ�η��ص���p2�������ظ�ʵ������+
    cout << "p2.age: " << p2.age << endl;
}

// 11����ָ����ʳ�Ա����
//  c++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��
//  ����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��
class duixiang_test11{
public:
    void showname(){
        cout << "���ڲ���Ա�ĺ���" <<endl;
    }
    void showage(){
        if(this ==NULL){
            return;
        }
        cout << "���ڲ���Ա����" << m_Age << endl;
        // ���ó�Ա����ʱ��ʵ��Ϊthis->m_Age,
        // ��û�ж���ʱ��this=NULL, this->m_Age������,���Ի����,��Ҫ�����ж�
    }
    int m_Age=10;
};
void func_duixiang_test11(){
    duixiang_test11* P = NULL;
    P->showname();// ��ָ����Ե���
    P->showage(); // this Ϊ�յ�ʱ��
}

// 12��const ���γ�Ա����
//  ������:
//     ��Ա�������const�����ǳ��������Ϊ������
//     �������ڲ������޸ĳ�Ա����
//     ��Ա��������ʱ�ӹؼ���muttable���ڳ���������Ȼ�����޸�
//  ������:
//     ��������ǰ��const�Ƹö���Ϊ������
//     ������ֻ�ܵ��ó�����
class duixiang_test12{
public:
    duixiang_test12(){};
    // thisָ��ı��� ��ָ�볣��  ָ���ָ�򲻿����޸�
    // const clasname * const this
    // �ڳ�Ա���������const�����ε���thisָ����ָ��ָ���ֵ�������޸�
    void function1() const {
        // this->m_A=100; // �������޸�
        this->m_B = 100; //����ؼ���mutable �Ϳ����޸ĳ�Ա������
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
    // p1.function2();//������ֻ�ܵ��ó�����
    p1.function1();
    return;
}


/******************part6 ��Ԫ ************************/
// 1����Ԫ���壺 �����������һЩ������������ʱ����ڵ�˽������
//        Ŀ�ģ���һ�����������������һ������˽�г�Ա
//        �ؼ��֣� friend
//       ʵ�֣�1)ȫ�ֺ�������Ԫ  2)������Ԫ  3)��Ա��������Ԫ
// 1) ȫ�ֺ�������Ԫ
class Building
{
//ȫ�ֺ���ǰ���һ��friend�������࣬�������Ԫ����
friend void GoodGay(Building * building);
public:
    Building(){
        m_SittingRoom = "����";
        m_BedRoom = "����";
    };
public:
    string m_SittingRoom;//����
private:
    string m_BedRoom;
};
// ȫ�ֺ���
void GoodGay(Building * building){
    cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�"<< building->m_SittingRoom << endl;
    cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�"<< building->m_BedRoom << endl;
}
// 2) ������Ԫ
class Building2{
    friend class GoodGay2;
public:
    Building2(){
        m_SittingRoom = "����";
        m_BedRoom = "����";
    };
public:
    string m_SittingRoom;//����
private:
    string m_BedRoom;
};
class GoodGay2{
public:
    GoodGay2(){
        building = new Building2;
    };
    void visit(){
        cout << "�û����� ���ڷ��ʣ�"<< building->m_SittingRoom << endl;
        cout << "�û����� ���ڷ��ʣ�"<< building->m_BedRoom << endl;
    }
    Building2 * building;
};
void func_friend_test1(){
    GoodGay2 gg;
    gg.visit();
    return;
}
// 3) ��Ա��������Ԫ; ��������ͺ�����������������֮����й��������������ʵ��
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
    string m_SittingRoom;//����
private:
    string m_BedRoom;
};
Building3::Building3(){
    m_SittingRoom = "����";
    m_BedRoom = "����";
};
GoodGay3::GoodGay3(){
    building = new Building3;
};
void GoodGay3::visit(){
    cout << "�û���visit ���ڷ��ʣ�"<< building->m_SittingRoom << endl;
    cout << "�û���visit ���ڷ��ʣ�"<< building->m_BedRoom << endl;
}
void GoodGay3::visit2(){
    cout << "�û���visit2 ���ڷ��ʣ�"<< building->m_SittingRoom << endl;
    // cout << "�û����� ���ڷ��ʣ�"<< building->m_BedRoom << endl;
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


/******************part7 c++��������� ************************/
// ��������صĸ�������е�������������¶��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
// 1���Ӻ����������
//   ���ڲ������õ��������ͣ����¶���ӷ����㷨��
//  1)ͨ����Ա��������
//  2)ͨ��ȫ�ֺ�������
//  1)����---��Ա����
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
    // ����Ϊ
    // Operate_test1 p3 = p1.operator+(p2);
    Operate_test1 p3 = p1 + p2;
    cout << "p3.m_A : " << p3.m_A << "  p3.m_B: " << p3.m_B << endl;
    return;
}
///  2)����---ȫ�ֺ���
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
    // ����Ϊ
    // Operate_test1 p3=operator+(p1, p2);
    Operate_test1 p3 = p1 + p2;
    cout << "p3.m_A : " << p3.m_A << "  p3.m_B: " << p3.m_B << endl;
    return;
}

// 2���������������
class Operate_test3{
public:
    // ��Ա���� �޷�ʵ�� cout�����
    // void operator<<(){
    // }
    int m_A=10;
    int m_B=11;
};
ostream&  operator<<(ostream& cout, Operate_test3 p){
    cout << "m_A = " << p.m_A << "  m_B = " << p.m_B <<" ";
    return cout;
}// return cout Ϊʵ����ʽ��̣����޵���
void func_Operate_test3(){
    Operate_test3 p1;
    p1.m_A = 10;
    p1.m_B = 11;
    cout << p1 << "hello world" << endl;
    return;
}

// 3���������������
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

// 4����ֵ���������
// c++�����ṩ4������������+����+����+operator=
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
    // �Լ����帳ֵ������Ϊ�˱����ж�����ֵ����ʱ��������⣬��������ͬһ�������ͷ�
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

// 5����ϵ���������
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

// 6�������������������
//    �������������() Ҳ��������
//    �������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
//    �º���û�й̶�д�����ǳ����
class Operator_test7{
public:
    void operator()(string text){
        cout <<  text << endl;
    }
};
void func_Operator_test7(){
    Operator_test7 myprint;
    myprint("hello world");//ʹ�������������������ã��зº���
}

int main(){

    // int *p = func();
    
    // cout << *p <<endl;
    // delete p;
    // yinyong_test2();
    // function_test2(10);
    /******************part4 ��װ ************************/
    // Circle c1; // ʵ����
    // c1.m_r = 10;
    // double zc = c1.calculateZC();
    // cout << "�ܳ��� " << zc << endl;
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