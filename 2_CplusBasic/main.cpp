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

int main(){

    // int *p = func();
    
    // cout << *p <<endl;
    // delete p;
    yinyong_test2();
    return 0;
}