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

int main(){

    // int *p = func();
    
    // cout << *p <<endl;
    // delete p;
    // yinyong_test2();
    function_test2(10);
    return 0;
}