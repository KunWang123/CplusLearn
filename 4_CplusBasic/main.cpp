#include<iostream>
#include<string>
using namespace std;
/****************part11 ģ��****************/
// c++��һ�ֱ��˼���Ϊ ���ͱ�̣� ��Ҫ���õļ�������ģ��
// c++�ṩ����ģ����ƣ�����ģ�����ģ��
// 1������ģ���﷨��
//    ���ã�����һ��ͨ�ú������亯���ķ���ֵ���ͺ��β����Ϳ��Բ�����ָ������һ�����������������
//     �����Ͳ�������
//    �﷨��
//      template<typename T>//������������
//      template --- ��������ģ��
//      typename --- ���������ķ�����һ���������ͣ�������class����
//      T --- ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
// 1) ����ģ��
template<typename T>
void mySwap(T&a, T&b){
    T temp = a;
    a = b;
    b = temp;
}
void template_test1(){
    int a =  10;
    int b = 20;
    // 1��T �Զ������Ƶ�
    mySwap(a, b);

    // 2����ʾָ������
    mySwap<int>(a, b);
}

// 2������ģ��ע������
//   1) �Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
//   2) ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<typename T>
void template_func(){
    cout << "no fix parameters type " << endl;
}
void template_test2(){
    int a = 20;
    int b = 30;
    mySwap(a, b);//��ȷ
    // 1) �����Ƶ�����
    char c = 'c';
    //mySwap(a, c);//���󣬴������Ͳ�һ�£��޷�ȷ��T����
    // 2) �޲������ͣ�����ȷ��T���������ͣ���Ҫָ��
    template_func<int>();//����<int/double...>
}

// 3������ģ�尸��(ͨ�õ����������㷨��ѡ�����򣬴Ӵ�С)
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

// 4����ͨ�����ͺ���ģ�������
//  ����
//     1) ��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
//     2) ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
//     3) ����ģ�����������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��

// 5����ͨ�����ͺ���ģ��ĵ��ù���
//   1) ��κ���ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
//   2) ����ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
//   3) ����ģ����Է�����������
//   4) ��ﺯ��ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
void template5_func1(int a, int b){
    cout<< "����" << endl;
}
template<typename T>
void template5_func1(T a, T b){
    cout<< "ģ�庯��" << endl;
}
template<typename T>//3) ��������
void template5_func1(T a, T b, T c){
    cout<< "ģ�庯�� ����" << endl;
}
void tempate_test5(){
    int a = 10;
    int b = 20;
    template5_func1(a, b);// 1)����ʹ����ͨ����
    template5_func1<>(a, b);// 2)ǿ��ʹ��ģ��

    char c1 = 'a';
    char c2 = 'b';
    template5_func1(c1, c2);// 4) ����ģ�庯������Ϊǿ��ת��char2int,����ֱ�ӽ�T--char����
    return ;
}

// 6��ģ��ľ�����
//   ģ�岻�����ܵģ�ģ����廯���������ͣ���Ҫ���廯������ʵ��
//   ѧϰģ�岢����Ϊ��дģ�壬������STL������ϵͳ�ṩ��ģ��
// �Ա����������Ƿ����
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
// ���person���廯����Template
template<> bool template6_func1_mycompare(Person&p1, Person&p2){
    if(p1.m_name==p2.m_name && p1.m_age==p1.m_age){
        return true;
    }
    else{
        return false;
    }
}

// 7����ģ��
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

// 8����ģ��ͺ���ģ�������
//  1) ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//  2) ��ģ����ģ������б��п���Ĭ�ϲ���
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
    T7_Person<string, int>p1("Tom", 10);// ��ʽָ��string �� int
    // T7_Person p1("Tom", 110);//��������

    T8_Person<string> p2("Tom2", 10);//�ڶ�������Ĭ�ϣ����ø�����Ҳ���Ը�
}


// 9����ģ���г�Ա��������ʱ��
//   ��ģ���г�Ա�����ڵ���ʱ�ű�����
template<class T>
class T9_Person{
public:
    T obj;
    // ������Ա�����������þͲ��ᴴ�������ᱨ��
    void func1(){
        obj.show1();
    }
    void func2(){
        obj.show2();
    }
};

// 10����ģ���������������
//   ��ģ��ʵ�������Ķ����������εķ�ʽ
//   1) ָ����������� --- ֱ����ʾ�������������
//   2) ����ģ�廯 --- �������еĲ�����Ϊģ����д���
//   3) ������ģ�廯 -- ������������� ģ�廯����
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
// 1)ָ�����������; ʹ�ù㷺
void template10_test1(T10_Person<string, int>&p){
    p.show();
    return;
}
// 2)����ģ�廯
template<class T1, class T2>
void template10_test1(T10_Person<T1, T2>&p){
    p.show();
    return;
}
// 3)������ģ�廯
template<typename T>
void template10_test1(T &p){
    p.show();
    return;
}

// 11����ģ����̳�
//  1) ��������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
//  2) �����ָ�����������޷�����������ڴ�
//  3) ��������ָ��������T�����ͣ�����Ҳ���Ϊ��ģ��
template<class T>
class T11_Base{
public:
    T m_K;
};
//class T11_Son:public T11_Base//����
class T11_Son:public T11_Base<int>
{
};
template<class T1, class T2>
class T11_Son2:public T11_Base<T2>{
public:
    T1 m_L;
};

// 12����ģ���Ա��������ʵ��
template<class T1, class T2>
class T12_Person:{
public:
    T12_Person(T1 name, T2 age);
    T1 m_Name;
    T2 m_Age;
};
template<class T1, class T2>
T12_Person<T1,T2>::T12_Person(T1 name, T2 age){//T12_Person<T1,T2>����ģ��Ĳ����б�
    this->m_Age =age;
    this->m_Name = name;
}


// 13����ģ��ķ��ļ���д
//  .h �� .cpp�ļ��ϲ���.hpp

// 14����Ԫ��������/��ʵ��



int main(){
    template_test3_func1();
    return 0 ;
}