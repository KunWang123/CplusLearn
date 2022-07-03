#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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

/****************part12 STL****************/
// 1��Ϊ�˽������ݽṹ���㷨��һ�ױ�׼��������STL(��ߴ���ĸ����ԡ������ظ�����)
//  1) ��������
//    STL(��׼ģ��⣬ standard template library)
//    STL�ӹ����Ϸ�Ϊ��������container���㷨��algorithm����������iterator��
//    STL�������д��붼ʹ����ģ����ߺ���ģ��
//    ����������������㷨�����������º��������������ռ�������

// 1������(������㷺��һЩ���ݽṹʵ��)
//    ����ʽ����������ʽ����
// 2���㷨���ʱ��㷨�����ʱ��㷨��(��ֵ��û��)��
// 3��������������˫���������������ʵ�������

// 1��������vector��
void STL1_func1(int val){
    cout << val << endl;
}
void STL1_test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    // ͨ������������
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();
    // ��һ�ֱ���
    while (itBegin != itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }
    // �����ֱ��� ʹ���㷨
    for_each(v.begin(), v.end(), STL1_func1);
}

// 2��string
//  string��һ���࣬���ڷ�װ�˺ܶ෽��
//  1) ���캯��ԭ��
//   string(); string(const char*s); string(const string &str); string(itn n, char c)
//  2) ��ֵ����
//  3) �Ӵ���ȡ

// 3��vector����
//  1�������﷨
//  1) �����Ǿ�̬�ռ䣬vector���Զ�̬��չ
//  2) v.begin()ָ���һ��Ԫ�أ�v.end()ָ�����һ��Ԫ�ص���һ��λ��
//  3) vector���캯��
void vector_fun1(){
    vector<int> v1;//Ĭ�Ϲ���,�޲ι���
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    vector<int> v1(v1.begin(), v1.end());// ͨ�����䷽ʽ���й���
    
    vector<int> v3(10, 100);//v3����10��100

    vector<int> v4(v3);// �������캯��
}

//  2����vector�������и�ֵ
//  1) ֱ��=
//  2���ṩassign[begin,end)����
//  3) �ṩassign(n, val)
void vector_fun2(){
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    vector<int> v2;
    v2 = v1;

    vector<int>v3;
    v3.assign(v1.begin(), v1.end());

    vector<int> v4;
    v4.assign(10, 100);// (n, val)
    return;
}

//  3��������С
//  empty(), �ж��Ƿ�Ϊ��
//  capacity(), ��������
//  size(), ����Ԫ�صĸ���
//  resize(n),�����ƶ���С��������0
//  resize(n, val),����ָ����С��������val

//  4��vector�Ĳ����ɾ��
//  push_back()
//  pop_back(), ɾ�����һ��Ԫ��
//  insert(const_iterator position, val); ������ָ��λ��position����val
//  insert(const_iterator pos, int count, val); ������ָ��λ��pos,����count��val
//  erase(const_iterator pos); ɾ��������ָ���Ԫ��
//  erase(const_iterator start, const_iterator end);ɾ����������start��end֮���Ԫ��
//  clear(); ɾ������������Ԫ��

//  5��vector���ݴ�ȡ
//  at(int num);����Ԫ��
//  [int num];����Ԫ��
//  .front(); .back(); ��һ�������һ��Ԫ��

//  6��vector�����Ļ���
//  
void vector_fun6(){
    vector<int> v1;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    vector<int> v2;
    for(int i = 10; i > 1; i--){
        v2.push_back(i);
    }
    v1.swap(v2); //����v1 �� v2 ����
    return ;
    vector<int>(v1).swap(v1);//ʹ�������������v1��������size
}

//  7��Ԥ���ռ�
//   ����reserveԤ���ռ�
void vector_fun7(){
    vector<int> v1;
    v1.reserve(1000);// Ԥ��1000���ռ䣬���ⴴ��ʱ������¿����ڴ�
}

#include<deque>
// 4��deque
//  ���캯��
void deque_print1(const deque<int> &d){
    for (deque<int>::const_iterator it=d.begin(); it !=d.end(); it++)
    {
        cout<<*it<<endl;
    }
    return;
}
void deque_func1(){
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    deque<int> q2(d1.begin(), d1.end());
}
//  ��ֵ����
//  deque& operator=(const deque&deq);//���� 
//  assign(beg, end);// ��[beg,end)�����е����ݿ�����ֵ������
//  assign(n, elem);// ��n��elem������ֵ������

//  ��С����
// deque.empty()
// deque.size()
// deque.resize(n)
// deque.resize(n, val)

// ����ɾ��
//  push_back();
//  push_front();//ͷ������һ������
//  pop_back(); ɾ���������һ������
//  pop_front(); ɾ��������һ������
/// ָ��λ�ò���
//  insert(pos, elem);//posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ��
//  insert(pos, n, elem);// poseλ�ò���n��elem���ݣ��޷���ֵ
//  insert(pos, beg, end);;��posλ�ò���[beg,end)��������ݣ��޷���ֵ
//  clear();
//  erase(beg, end)
//  erase(pos);

//  deque ����
#include<algorithm>
void deque_func6(){
    deque<int> deq1;
    deq1.push_back(100);
    deq1.push_back(1);
    deq1.push_front(2);
    // ����֧��������ʵ�����������������ʹ��sort�㷨��������
    sort(deq1.begin(), deq1.end());
}

#include<stack>
//  stack 
// pop,push
void stack_func1(){
    stack<int> stk;
    stk.push(10);
    if (!stk.empty())
    {
        stk.pop();
    }
    cout << stk.size();
    
}

#include<queue>
// queue
// push(), pop()
void queue_func1(){
    queue<int> q1;
    q1.push(10);
    if (!q1.empty())
    {
        q1.pop();
    }
    // front,back
}
#include<list>
//  list
//   �������������ָ����
//   ��vector�Ƚϳ���
void list_func1(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    // ���乹��
    list<int>l2(l1.begin(), l2.end());

    // ��������
    list<int>l3(l1);

    // n��elem
    list<int> l4(10, 1000);
}
//  ��ֵ
void list_func2(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    list<int> l2;
    l2 = l1;
    list<int> l3;
    l3.assign(l1.begin(), l2.end());
    list<int>l4;
    l4.assign(10, 1000);
    l4.swap(l1);
}
// list�Ĳ����ɾ��
// push_back(); pop_back();push_front();pop_front();
// insert();clear();erase();remove();
//  inverse,sort
bool jiangxu(int val1, int val2){
     return val1 > val2;
}
void list_func3(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.reverse();
    l1.sort();// �Դ��ģ�����algorithm�еģ�����
    l1.sort(jiangxu);
}

#include<set>
// set �� multiset
//  set����������ظ�Ԫ�أ�����Ԫ�ز������Զ�����
//  multiset��������ظ�Ԫ��
void set_func1(){
    set<int> s1;
    s1.insert(10);
    return ;
}
//  size();����������С
//  empty();�Ƿ�Ϊ��
//  swap();��������setԪ��
//  insert();����
//  clear();���
//  erase(val); erase(*pointer);
//  find(key);count(key);
void set_func2(){
    set<int> s1;
    s1.insert(10);
    set<int>::iterator pos = s1.find(10);
    if(pos != s1.end()){
        cout << "�ҵ�Ԫ�أ�" << endl;
    }
    int num = s1.count(10);//ֻ����0/1
}
//  multiset
void multiset_func1(){
    multiset<int> ms1;
    ms1.insert(10);
    ms1.insert(10);// ���Զ�β�����ֵͬ
    return;
}
// pair���鴴��
//  �ɶԳ��ֵ����ݣ����ö�����Է�����������
//  ���ִ�����ʽ
//   pair<type, type> p(value1, value2);
//   pair<type, type> p = make_pair(value1, value2);
void pair_func1(){
    pair<string, int> p ("Tom", 30);
    cout << p.first << p.second << endl;
    return;
}
// �º���ָ��set����˳��
// set<int, �º���>set1;//��������ǰָ���������

#include<map>
//  map/multimap����(��Ч)
//  <key, val>
//  ����key����
//  size(); empty(); swap();
//  
void map_func1(){
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    map<int, int> m2(m1);// ��������
    map<int, int> m3;
    m3 = m1;
    return ;
}

/****************part13 ��������****************/
// �����������
//  1) ���������������ͨ������������
//  2) �������󳬳���ͨ�����ĸ���������Լ���״̬
//  3) �������������Ϊ��������
class func13_class1
{
public:
    func13_class1(){
        count = 0;
    }
    void operator()(string test){
        cout << test << endl;
        count++;
    }
    int count;//2)�Լ�״̬
};
void func13_doprint(func13_class1&mp, string test){
    mp(test);
    return ;
}
void func13_test1(){
    func13_class1 myprint;
    myprint("hello c++");
    func13_doprint(myprint, "hello c++2");//3)����������Ϊ��������
}

// 2��ν��
//  ����bool���͵ķº�����Ϊν��
//  ���operator()����һ����������ô����һԱν��
//  ���operator()����������������ô������Աν��

#include<functional>
// 3���ڽ���������
//  negate һԪ�º�����ȡ���º���
//  plus ��Ԫ�º����� �ӷ�
void function3_test1(){
    negate<int> n;
    cout << n(50) << endl;// -50

    plus<int> pl;
    cout<<pl(10, 20) << endl;// 30
}
//  greater<>; //���ڣ���ϵ�º���
//  logical_not<>;// �߼��º���

/****************part14 �㷨****************/
#include<algorithm>
// <alogrithm>������STL�ļ�������һ��
// <numeric>��ѧ�����ģ��
// <functional>������һЩģ���࣬����������������
// for_each//��������
// transform//������������һ��������
// find; find_if
// adjacent_find();//������ֵͬ
// binary_search();//���ֲ��ҷ�
// count;count_if;
// sort
// random_shuffle
// merge
// reverse
// copy; replace; replace_if
// swap
#include<numeric>
// accumulate;
// fill;
// set_intersection; set_union; set_difference;//���ϴ���Ľ���������

int main(){
    template_test3_func1();
    return 0 ;
}