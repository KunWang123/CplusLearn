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
    string setName(string name){
        p_Name = name;
    }
    string setLover(string name){
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
    duixiang_test1 t1;

    return 0;
}