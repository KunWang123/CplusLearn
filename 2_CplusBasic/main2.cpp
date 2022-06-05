// ѧϰ�̳кͶ�̬
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/******************part8 �̳� ************************/
// 1���̳еĻ����﷨
//    �̳�������������������֮һ
//    �̳еĺô��������ظ��Ĵ���
//    �﷨��class ����: �̳з�ʽ ����
//         ���ࣺ������
//         ���ࣺ����
// ������ĳɷ֣�һ��ӻ����ã�һ���Լ�������
class jicheng_BasePage1{
public:
    void header(){
        cout << "��ҳ�����Ρ�ע��...������ͷ����" << endl;
    }
    void footer(){
        cout << "�������ġ���������...�������ײ���" << endl;
    }
    void left(){
        cout << "Java��Python��c++....(ѧ���б�))" << endl;
    }
};
class jicheng_Java:public jicheng_BasePage1{
public:
    void content(){
        cout << "java ѧϰ��Ƶ" << endl;
    }
};
class jicheng_Python:public jicheng_BasePage1{
public:
    void content(){
        cout << "python ѧϰ��Ƶ" << endl;
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

// 2���̳з�ʽ
//  class ���ࣺ�̳з�ʽ ����
//  �̳з�ʽ:(���������ּ̳У�������˽��Ȩ�޵ĳ�Ա���ܷ���)
//  1) �����̳У�������public��protected����
//  2) �����̳У�������public��protected��Ϊprotected
//  3) ˽�м̳У�������public��protected��Ϊprivate
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
        m_A = 100;//����Ȩ��
        m_B = 100;//����Ȩ��
        // m_C = 100;
    }
};
void func1_jicheng_test2(){
    jicheng_test2_son2 son2;
    // son2.m_A = 10; //protected ���ڿ��Է��ʣ����ⲻ��
}
class jicheng_test2_son3:private jicheng_test2_Base{
public:
    void func(){
        m_A = 10;//�ֽ׶���˽�еģ����ⲻ�ܷ���
        m_B = 10;//�ֽ׶���˽�еģ����ⲻ�ܷ���
        // m_C = 10;
    }
};

// 3���̳��еĶ���ģ��
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
};// sizeof(jicheng_test3_Son)=16,���ж����̳������ˣ�˽�г�ԱҲ�̳���ȥ�ˣ�ֻ�Ǳ����������أ����ʲ���

// 4���̳��еĹ��������˳��
//  Base���캯����Son���캯����Son����������Base��������

// 5���̳���ͬ����Ա�Ĵ���ʽ
//    ��������ͬ����Ա��ֱ�ӷ��ʼ���
//    ���ʸ���ͬ����Ա����Ҫ��������
//    �������븸��ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա����������������Է��ʵ�������ͬ������
class jicheng_test5_Base{
public:
    jicheng_test5_Base(){
        m_A = 10;
    }
    void func(){
        cout << "�����Ա����" << endl;
    }
    void func(int a){
        cout << "�����Ա���� func(int)" << endl;
    }
    int m_A;
};
class jicheng_test5_Son:public jicheng_test5_Base{
public:
    jicheng_test5_Son(){
        m_A = 100;
    }
    void func(){
        cout << "�����Ա����" << endl;
    }
    int m_A;
};
// ͬ����Ա��������
void func1_jicheng_test5(){
    jicheng_test5_Son son;
    cout << "son ���Ա���ʣ� " << son.m_A << endl;
    cout << "Base ���Ա���ʣ� " << son.jicheng_test5_Base::m_A << endl;
}
void func2_jicheng_test5(){
    jicheng_test5_Son son;
    son.func();//son ���Ա�������ʣ� 
    son.jicheng_test5_Base::func();//base���Ա��������
    // ��������г��ֺ͸���ͬ���ĳ�Ա����������ͬ�����������ص����������е�ͬ����Ա����
    // �������ʵ����౻���ص�ͬ����Ա��������Ҫ��������
    son.jicheng_test5_Base::func(10);//base���Ա�������ʣ� 
}

// 6���̳�ͬ����̬��Ա����ʽ
//    ��������ͬ����Ա��ֱ�ӷ��ʼ���
//    ���ʸ���ͬ����Ա����Ҫ��������
//    ����͸������ͬ����̬��Ա����������ͬ�����������ص���������ͬ����Ա����
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
//  ���ʳ�Ա�����ͳ�Ա������ͬ����
void func1_jicheng_test6(){
    // 1 ͨ���������
    cout << "ͨ���������" << endl;
    jicheng_test6_Son s;
    cout << "Son �� m_A: " << s.m_A << endl;
    cout << "Base �� m_A: " << s.jicheng_test6_Base::m_A << endl;

    // 2 ͨ����������
    cout << "ͨ����������" << endl;
    cout << "Son �� m_A: " << jicheng_test6_Son::m_A << endl;
    // ��һ��::����ͨ��������ʽ���ʣ�  �ڶ���:: ������ʸ�����������
    cout << "Base �� m_A: " << jicheng_test6_Son::jicheng_test6_Base::m_A << endl;
}

// 7����̳��﷨ (ʵ��ʹ���в�����)
//    �﷨�� class ���ࣺ �̳з�ʽ ����1, �̳з�ʽ ����2....
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
    //  ���ʲ�ͬ�����е�ͬ����������Ҫ��������
    cout << "base1 m_A = " << son.jicheng_test7_Base1::m_A << endl;
    cout << "base2 m_A = " << son.jicheng_test7_Base2::m_A << endl;
    // ���ʲ�ͬ���Ĳ���Ҫ����������
     cout << "base2 m_B = " << son.m_B << endl;
}

// 8�����μ̳�
//  ��� ����������̳�ͬһ�����࣬ ����ĳ����ͬʱ�̳����������࣬���ּ̳б���Ϊ���μ̳�(��ʯ�̳�)
//  ��������μ̳д�������Ҫ����������̳�������ͬ�����ݣ�������Դ�˷��Լ���������
//  ��ʩ��������̳п��Խ�����μ̳�����
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
// �̳�������Base, Ϊ�˽��������⣬����ؼ���virtual����̳�
// Base���Ϊ �����
class jicheng_test8_GrandSon:public jicheng_test8_Son1, public jicheng_test8_Son2{
};
void func1_test8(){
    jicheng_test8_GrandSon grandson;// �̳�������Base
    grandson.jicheng_test8_Son1::m_Age = 10;
    grandson.jicheng_test8_Son2::m_Age = 20;
    cout << "son1 age: " << grandson.jicheng_test8_Son1::m_Age << endl;// ��virtual֮ǰ��10��֮����20
    cout << "son2 age: " << grandson.jicheng_test8_Son2::m_Age << endl;// ��virtual֮ǰ��20��֮����20
    // ��̳к����ֱ�ӷ���
    //  ����virtual�����μ̳еĻ���������������ָ��(vbptr)ָ��������(vbtable)
    //  ���μ̳еĻ������ݻ���һ�ݣ������Ǳ߸Ķ�������Ľ��ֻ��һ��
    cout << "grand_son age:" << grandson.m_Age << endl;// ���20,�������һ�θĶ��� ��virtual֮ǰ����ֱ�ӵ���grandson.m_Age
}


/******************part9 ��̬ ************************/
// 1����̬�Ļ�������
//  ��̬��Ϊ���ࣺ
//     ��̬��̬���������� ��������� ���ھ�̬��̬�����ú�����
//     ��̬��̬����������麯��ʵ������ʱ��̬
//  ��̬��̬�Ͷ�̬��̬������
//     ��̬��̬�ĺ�����ַ��� -- ����׶�ȷ��������ַ
//     ��̬��̬�ĺ�����ַ��� -- ���н׶�ȷ��������ַ
//  ��̬��̬����������
//     1) ���ڼ̳й�ϵ
//     2) ������д������麯��(��д������ֵһ�£������б�һ�£� ������д����virtual�ؼ��ֿ�д�ɲ�д)
//  ��̬��̬��ʹ��
//     �����ָ���������ָ���������
class duotai_1_Animal{
public:
    virtual void speak(){
        cout << "������˵��" << endl;
    }
};
class duotai_1_Cat:public duotai_1_Animal{
public:
    //virtural void speak(){//ͬ��,������virtual�ؼ��ֿ�д�ɲ�д
    void speak(){
        cout << "Сè��˵��" << endl;
    }
};
// �����ָ�����ֱ��ָ������Ķ���
// Animal & animal = cat;//����
void func1_duotai_dospeak(duotai_1_Animal & animal){
    animal.speak();
}
void func_duotai_test1(){
    duotai_1_Cat cat;
    // ��animal��speak�����麯��ʱ�����õ���animal��speak
    // ��animal�е�speak���麯��ʱ������Ĳ�����ʲô���͵����ĸ������speak
    func1_duotai_dospeak(cat);
}

// 2����̬��̬������
// ������̬����̳и����vfptrָ��vftable,Ȼ��������д�麯�����滻vftable�е��麯��
// ���Ը������û���ָ��ָ������Ķ���ʱ���ٵ��ú�����ʹ�õ�������ʵ�ֵĺ���
// ����ֻ�޸��ˣ�����̳к��vftable�еĺ���ʵ�֣������б����vftable��û�иı�

// 3����̬ʵ�ּ�����
//  ��̬�ô���
//    1) ��֯�ṹ����
//    2) �ɶ��Ժ�ǿ
//    3) ����ǰ�ںͺ��ڵ���չ�Լ�ά��
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
    // ����ӷ�
    abs = new duotai_3_AddCal;
    abs->m_Num1 = 10;
    abs->m_Num2 = 10;
    cout << abs->m_Num1 << " + " << abs->m_Num2 << " = " << abs->getresult() << endl;
    delete abs;
    abs = NULL;

    // �������
    abs = new duotai_3_SubCal;
    abs->m_Num1 = 10;
    abs->m_Num2 = 10;
    cout << abs->m_Num1 << " - " << abs->m_Num2 << " = " << abs->getresult() << endl;
    delete abs;
    abs = NULL;
}

// 4�����麯���ͳ�����
//    ��̬�У�ͨ�������е��麯����ʵ���Ǻ�������ģ���Ҫ���ǵ���������д������
//    ��˿��Խ��麯����Ϊ���麯��
//    ���麯���﷨�� virtual ����ֵ���� ������ (�����б�) = 0��
//    ���������˴��麯���������Ҳ��Ϊ������
//    �������ص㣺
//      1) �޷�ʵ��������
//      2) ���������д�������еĴ�����������Ҳ�����ڳ�����
class duotai_4_Base{
public:
    virtual void func() = 0;
};

// 5���������ʹ�������
//   ��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
//   �����ʽ�������������������Ϊ ������ ���� ��������
//   �������ʹ������� ���ã��������������Խ������ָ���ͷ�������󲻸ɾ�������
//   ������������Ҫ����Ҳ��Ҫʵ��
//   ���������û�ж������ݣ����Բ�д���������ߴ�������
//   ӵ�д��������ĺ�������Ҳ���ڳ�����
class duotai_5_Animal{
public:
    duotai_5_Animal(){
        cout << "animal ����" << endl;
    }
    virtual void speak() = 0;
    virtual ~duotai_5_Animal(){// ������
        cout << "animal ����" << endl;
    }
    // virtual ~duotai_5_Animal()=0;//������������
};
// duotai_5_Animal::~duotai_5_Animal(){// ��������ʵ��
//     cout << "animal ����" << endl;
// }
class duotai_5_Cat:public duotai_5_Animal{
public:
    duotai_5_Cat(string name){
        cout << "cat ����" << endl;
        m_Name = new string(name);
    }
    void speak(){
        cout << "Сè��˵��" << endl;
    }
    ~duotai_5_Cat(){
        cout << "cat ����" << endl;
        if(m_Name!=NULL){delete m_Name; m_Name=NULL;}
    }
    string *m_Name;
};
void func_duotai_test5(){
    duotai_5_Animal * animal = new duotai_5_Cat("Tom");
    animal->speak();
    // ����ָ���ͷ���������²��ɾ�����ִ�������������������Ҫ��������
    delete animal; // ������������ʱ�򣬴�ʱ����ִ��Cat����������

}

/******************part10 �ļ����� ************************/
// c++�ж��ļ�������Ҫ����ͷ�ļ�<fstream>
// �ļ��������ࣺ
//    1) �ı��ļ� -- �ļ����ı���ASCII�����ʽ�洢�ڼ������
//    2) �������ļ� -- �ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������
// �����ļ���������
//   1) ofstream: д����
//   2) ifstream: ������
//   3) fstream: ��д����
// 1���ı��ļ�---д
void file_1_wirte(){
    ofstream ofs;
    ofs.open("./file_1_write.txt", ios::out);
    ofs << "name: zhangsan"<<endl;// ����д���ļ���������
    ofs.close();
}
// 2���ı��ļ�---��
void file_2_read(){
    ifstream ifs;
    ifs.open("file_1_write.txt", ios::in);
    if (!ifs.is_open()){
        cout << "file open failed!" << endl;
        return ;
    }
    // // ��һ��
    // char buff[1024] = {0};
    // while (ifs >> buff)
    // {
    //     cout << buff << endl;
    // }

    // // �ڶ���
    // char buff[1024] = {0};
    // while (ifs.getline(buff, sizeof(buff)))
    // {
    //     cout << buff << endl;
    // }

    // // ������
    // string buff;
    // while (getline(ifs, buff))
    // {
    //     cout << buff << endl;
    // }

    // ������
    char c;
    while ((c=ifs.get())!=EOF)
    {
        cout << c << endl;
    }

    ifs.close();
    return;
}
// 3���������ļ�-д
void file_3_writeb(){
    ofstream ofs("file_3_binay.txt", ios::out | ios::binary);
    char arr[] = {'1','2','3','4'};
    // char arr = '1';
    cout << sizeof(arr)<< endl;
    ofs.write(arr, sizeof(arr));
    ofs.close();
}
// 4���������ļ�-��
void file_3_readb(){
    ifstream ifs("file_3_binay.txt", ios::in | ios::binary);
    if(!ifs.is_open()){
        cout << "file open failed" << endl;
        return;
    }
    char arr[5] = {};//���һ���ַ���ʲô��
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