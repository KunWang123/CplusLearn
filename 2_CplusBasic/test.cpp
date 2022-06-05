#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream os;
    os.open("kk2.txt",ios::out);
    os<< "名字zhangsan" << endl;
    os.close();
    return 0;
}
// 函数格式是gb2312， 则txt也是gb2312