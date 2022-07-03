#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/****************part11 模板****************/
// c++另一种编程思想成为 泛型编程， 主要利用的技术就是模板
// c++提供两种模板机制：函数模板和类模板
// 1、函数模板语法：
//    作用：简历一个通用函数，其函数的返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代替
//     （类型参数化）
//    语法：
//      template<typename T>//函数声明或定义
//      template --- 声明创建模板
//      typename --- 表明其后面的符号是一种数据类型，可以用class代替
//      T --- 通用的数据类型，名称可以替换，通常为大写字母
// 1) 函数模板
template<typename T>
void mySwap(T&a, T&b){
    T temp = a;
    a = b;
    b = temp;
}
void template_test1(){
    int a =  10;
    int b = 20;
    // 1、T 自动类型推导
    mySwap(a, b);

    // 2、显示指定类型
    mySwap<int>(a, b);
}

// 2、函数模板注意事项
//   1) 自动类型推导，必须推导出一致的数据类型T,才可以使用
//   2) 模板必须要确定出T的数据类型，才可以使用
template<typename T>
void template_func(){
    cout << "no fix parameters type " << endl;
}
void template_test2(){
    int a = 20;
    int b = 30;
    mySwap(a, b);//正确
    // 1) 不能推导类型
    char c = 'c';
    //mySwap(a, c);//错误，传参类型不一致，无法确定T类型
    // 2) 无参数类型，不能确定T的数据类型，需要指定
    template_func<int>();//必须<int/double...>
}

// 3、函数模板案例(通用的数据排序算法，选择排序，从大到小)
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

// 4、普通函数和函数模板的区别
//  区别：
//     1) 普通函数调用时可以发生自动类型转换（隐式类型转换）
//     2) 函数模板调用时，如果利用自动类型推到，不会发生隐式类型转换
//     3) 函数模板如果利用显示指定类型的方式，可以发生隐式类型转换

// 5、普通函数和函数模板的调用规则
//   1) 如何函数模板和普通函数都可以调用，优先调用普通函数
//   2) 可以通过空模板参数列表，强制调用函数模板
//   3) 函数模板可以发生函数重载
//   4) 入伙函数模板可以产生更好的匹配，优先调用函数模板
void template5_func1(int a, int b){
    cout<< "函数" << endl;
}
template<typename T>
void template5_func1(T a, T b){
    cout<< "模板函数" << endl;
}
template<typename T>//3) 可以重载
void template5_func1(T a, T b, T c){
    cout<< "模板函数 重载" << endl;
}
void tempate_test5(){
    int a = 10;
    int b = 20;
    template5_func1(a, b);// 1)优先使用普通函数
    template5_func1<>(a, b);// 2)强制使用模板

    char c1 = 'a';
    char c2 = 'b';
    template5_func1(c1, c2);// 4) 调用模板函数，因为强制转换char2int,不如直接将T--char方便
    return ;
}

// 6、模板的局限性
//   模板不是万能的，模板具体化的数据类型，需要具体化的特殊实现
//   学习模板并不是为了写模板，而是在STL中运用系统提供的模板
// 对比两个数据是否相等
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
// 针对person具体化操作Template
template<> bool template6_func1_mycompare(Person&p1, Person&p2){
    if(p1.m_name==p2.m_name && p1.m_age==p1.m_age){
        return true;
    }
    else{
        return false;
    }
}

// 7、类模板
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

// 8、类模板和函数模板的区别
//  1) 类模板没有自动类型推导的使用方式
//  2) 类模板在模板参数列表中可以默认参数
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
    T7_Person<string, int>p1("Tom", 10);// 显式指定string 和 int
    // T7_Person p1("Tom", 110);//报错，不能

    T8_Person<string> p2("Tom2", 10);//第二个可以默认，不用给定，也可以给
}

// 9、类模板中成员函数创建时机
//   类模板中成员函数在调用时才被创建
template<class T>
class T9_Person{
public:
    T obj;
    // 两个成员函数，不调用就不会创建，不会报错
    void func1(){
        obj.show1();
    }
    void func2(){
        obj.show2();
    }
};

// 10、类模板对象做函数参数
//   类模板实例化出的对象，向函数传参的方式
//   1) 指定传入的类型 --- 直接显示对象的数据类型
//   2) 参数模板化 --- 将对象中的参数变为模板进行传递
//   3) 整个类模板化 -- 将这个对象类型 模板化传递
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
// 1)指定传入的类型; 使用广泛
void template10_test1(T10_Person<string, int>&p){
    p.show();
    return;
}
// 2)参数模板化
template<class T1, class T2>
void template10_test1(T10_Person<T1, T2>&p){
    p.show();
    return;
}
// 3)整个类模板化
template<typename T>
void template10_test1(T &p){
    p.show();
    return;
}

// 11、类模板与继承
//  1) 当儿子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
//  2) 如果不指定，编译器无法给子类分配内存
//  3) 如果想灵活指出父类中T的类型，子类也需变为类模板
template<class T>
class T11_Base{
public:
    T m_K;
};
//class T11_Son:public T11_Base//报错
class T11_Son:public T11_Base<int>
{
};
template<class T1, class T2>
class T11_Son2:public T11_Base<T2>{
public:
    T1 m_L;
};

// 12、类模板成员函数类外实现
template<class T1, class T2>
class T12_Person:{
public:
    T12_Person(T1 name, T2 age);
    T1 m_Name;
    T2 m_Age;
};
template<class T1, class T2>
T12_Person<T1,T2>::T12_Person(T1 name, T2 age){//T12_Person<T1,T2>加上模板的参数列表
    this->m_Age =age;
    this->m_Name = name;
}


// 13、类模板的分文件编写
//  .h 和 .cpp文件合并成.hpp

// 14、友元函数类内/外实现

/****************part12 STL****************/
// 1、为了建立数据结构和算法的一套标准，诞生了STL(提高代码的复用性、减少重复工作)
//  1) 基本概念
//    STL(标准模板库， standard template library)
//    STL从广义上分为：容器（container）算法（algorithm）迭代器（iterator）
//    STL几乎所有代码都使用类模板或者函数模板
//    六大组件：容器、算法、迭代器、仿函数、适配器、空间配置器

// 1、容器(运用最广泛的一些数据结构实现)
//    序列式容器；关联式容器
// 2、算法（质变算法；非质变算法；(数值变没变)）
// 3、迭代器（常用双向迭代器和随机访问迭代器）

// 1、容器（vector）
void STL1_func1(int val){
    cout << val << endl;
}
void STL1_test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    // 通过迭代器访问
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();
    // 第一种遍历
    while (itBegin != itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }
    // 第三种遍历 使用算法
    for_each(v.begin(), v.end(), STL1_func1);
}

// 2、string
//  string是一个类，类内封装了很多方法
//  1) 构造函数原型
//   string(); string(const char*s); string(const string &str); string(itn n, char c)
//  2) 赋值操作
//  3) 子串获取

// 3、vector容器
//  1、基本语法
//  1) 数组是静态空间，vector可以动态扩展
//  2) v.begin()指向第一个元素，v.end()指向最后一个元素的下一个位置
//  3) vector构造函数
void vector_fun1(){
    vector<int> v1;//默认构造,无参构造
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    vector<int> v1(v1.begin(), v1.end());// 通过区间方式进行构造
    
    vector<int> v3(10, 100);//v3里面10个100

    vector<int> v4(v3);// 拷贝构造函数
}

//  2、给vector容器进行赋值
//  1) 直接=
//  2）提供assign[begin,end)区间
//  3) 提供assign(n, val)
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

//  3、容量大小
//  empty(), 判断是否为空
//  capacity(), 容器容量
//  size(), 容器元素的个数
//  resize(n),重新制定大小，过长则补0
//  resize(n, val),重新指定大小，过长则补val

//  4、vector的插入和删除
//  push_back()
//  pop_back(), 删除最后一个元素
//  insert(const_iterator position, val); 迭代器指定位置position插入val
//  insert(const_iterator pos, int count, val); 迭代器指定位置pos,插入count个val
//  erase(const_iterator pos); 删除迭代器指向的元素
//  erase(const_iterator start, const_iterator end);删除迭代器从start到end之间的元素
//  clear(); 删除容器中所有元素

//  5、vector数据存取
//  at(int num);访问元素
//  [int num];访问元素
//  .front(); .back(); 第一个、最后一个元素

//  6、vector容器的互换
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
    v1.swap(v2); //互换v1 和 v2 数据
    return ;
    vector<int>(v1).swap(v1);//使用匿名对象更新v1的容量和size
}

//  7、预留空间
//   利用reserve预留空间
void vector_fun7(){
    vector<int> v1;
    v1.reserve(1000);// 预留1000个空间，避免创建时多次重新开辟内存
}

#include<deque>
// 4、deque
//  构造函数
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
//  赋值操作
//  deque& operator=(const deque&deq);//重载 
//  assign(beg, end);// 将[beg,end)区间中的数据拷贝赋值给本身
//  assign(n, elem);// 将n个elem拷贝赋值给本身

//  大小操作
// deque.empty()
// deque.size()
// deque.resize(n)
// deque.resize(n, val)

// 插入删除
//  push_back();
//  push_front();//头部插入一个数据
//  pop_back(); 删除容器最后一个数据
//  pop_front(); 删除容器第一个数据
/// 指定位置操作
//  insert(pos, elem);//pos位置插入一个elem元素的拷贝，返回新数据的位置
//  insert(pos, n, elem);// pose位置插入n个elem数据，无返回值
//  insert(pos, beg, end);;在pos位置插入[beg,end)区间的数据，无返回值
//  clear();
//  erase(beg, end)
//  erase(pos);

//  deque 排序
#include<algorithm>
void deque_func6(){
    deque<int> deq1;
    deq1.push_back(100);
    deq1.push_back(1);
    deq1.push_front(2);
    // 对于支持随机访问迭代器的容器都可以使用sort算法进行排序
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
//   包含：数据域和指针域
//   和vector比较常用
void list_func1(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    // 区间构造
    list<int>l2(l1.begin(), l2.end());

    // 拷贝构造
    list<int>l3(l1);

    // n个elem
    list<int> l4(10, 1000);
}
//  赋值
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
// list的插入和删除
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
    l1.sort();// 自带的，不是algorithm中的，升序
    l1.sort(jiangxu);
}

#include<set>
// set 和 multiset
//  set不允许存在重复元素，所有元素插入后会自动排序，
//  multiset允许存在重复元素
void set_func1(){
    set<int> s1;
    s1.insert(10);
    return ;
}
//  size();返回容器大小
//  empty();是否为空
//  swap();交换两个set元素
//  insert();插入
//  clear();清除
//  erase(val); erase(*pointer);
//  find(key);count(key);
void set_func2(){
    set<int> s1;
    s1.insert(10);
    set<int>::iterator pos = s1.find(10);
    if(pos != s1.end()){
        cout << "找到元素：" << endl;
    }
    int num = s1.count(10);//只能是0/1
}
//  multiset
void multiset_func1(){
    multiset<int> ms1;
    ms1.insert(10);
    ms1.insert(10);// 可以多次插入相同值
    return;
}
// pair对组创建
//  成对出现的数据，利用对组可以返回两个数据
//  两种创建方式
//   pair<type, type> p(value1, value2);
//   pair<type, type> p = make_pair(value1, value2);
void pair_func1(){
    pair<string, int> p ("Tom", 30);
    cout << p.first << p.second << endl;
    return;
}
// 仿函数指定set排序顺序
// set<int, 仿函数>set1;//插入数据前指定排序规则

#include<map>
//  map/multimap容器(高效)
//  <key, val>
//  按照key排序
//  size(); empty(); swap();
//  
void map_func1(){
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    map<int, int> m2(m1);// 拷贝构造
    map<int, int> m3;
    m3 = m1;
    return ;
}

/****************part13 函数对象****************/
// 函数对象概念
//  1) 函数对象可以想普通函数那样调用
//  2) 函数对象超出普通函数的概念，可以有自己的状态
//  3) 函数对象可以作为参数传递
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
    int count;//2)自己状态
};
void func13_doprint(func13_class1&mp, string test){
    mp(test);
    return ;
}
void func13_test1(){
    func13_class1 myprint;
    myprint("hello c++");
    func13_doprint(myprint, "hello c++2");//3)函数对象作为参数传递
}

// 2、谓词
//  返回bool类型的仿函数称为谓词
//  如果operator()接受一个参数，那么叫做一员谓词
//  如果operator()接受两个参数，那么叫做二员谓词

#include<functional>
// 3、内建函数对象
//  negate 一元仿函数，取反仿函数
//  plus 二元仿函数， 加法
void function3_test1(){
    negate<int> n;
    cout << n(50) << endl;// -50

    plus<int> pl;
    cout<<pl(10, 20) << endl;// 30
}
//  greater<>; //大于，关系仿函数
//  logical_not<>;// 逻辑仿函数

/****************part14 算法****************/
#include<algorithm>
// <alogrithm>是所有STL文件中最大的一个
// <numeric>数学运算的模板
// <functional>定义了一些模板类，用以声明函数对象
// for_each//遍历容器
// transform//搬运容器到另一个容器中
// find; find_if
// adjacent_find();//关联相同值
// binary_search();//二分查找法
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
// set_intersection; set_union; set_difference;//集合处理的交、并、差

int main(){
    template_test3_func1();
    return 0 ;
}