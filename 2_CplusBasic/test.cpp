#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream os;
    os.open("kk2.txt",ios::out);
    os<< "����zhangsan" << endl;
    os.close();
    return 0;
}
// ������ʽ��gb2312�� ��txtҲ��gb2312