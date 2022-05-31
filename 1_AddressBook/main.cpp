#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

// 设计联系人结构体
struct Person{
    // 姓名
    string m_Name;
    // 性别 1男 2女
    int m_Sex;
    // 年龄
    int m_Age;
    // 电话
    string m_Phone;
    // 住址
    string m_Addr;
};

// 通讯录结构体
struct Addressbooks
{
    // 通讯录中保持联系人的数组
    struct Person persongArray[MAX];
    // 通讯录中联系人的个数
    int m_Size=0;
};

// 菜单显示
void showMenu(){
    cout << "**************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "**************************" << endl;
}

// 1 添加联系人
void addPerson(Addressbooks * abs){
    // 判断通讯录是否已满
    if (abs->m_Size == MAX){
        cout << "通讯录已满，无法添加!" << endl;
        return;
    }
    else{// 添加具体联系人
        // 姓名
        string name;
        cout << "请输入姓名： " << endl;
        cin >> name;
        abs->persongArray[abs->m_Size].m_Name = name;

        // 性别 1男 2女
        cout << "请输入性别：" << endl;
        cout << "1 ---- 男" << endl;
        cout << "2 ---- 女"  << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2){
                abs->persongArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else{
                cout << "输入有误，请重新输入" << endl;
            }
        }

        // 年龄
        cout << "请输入年龄： " << endl;
        int age = 0;
        cin >> age;
        abs->persongArray[abs->m_Size].m_Age = age;

        // 电话
        cout << "请输入联系电话： " << endl;
        string phone;
        cin >> phone;
        abs->persongArray[abs->m_Size].m_Phone = phone;

        // 住址
        cout << "请输入地址： " << endl;
        string address;
        cin >> address;
        abs->persongArray[abs->m_Size].m_Addr = address;

        // 更新通讯录人数
        abs->m_Size++;

        cout << "添加成功" << endl;
        system("pause");
        system("cls");

    }
}

// 2、显示联系人
void showPerson(const Addressbooks *abs){
    // 判断通讯录中人数是否为0，如果是0，提示记录为空
    // 如果不为0，显示记录联系人的信息
    if (abs->m_Size == 0){
        cout << "当前记录为空" << endl;
        // return ;
    }
    else{
        for(int i=0; i< abs->m_Size; i++){
            cout << "姓名: " << abs->persongArray[i].m_Name << "\t";
            cout << "性别: " << (abs->persongArray[i].m_Sex ==1 ? "男":"女" )<< "\t";
            cout << "年龄: " << abs->persongArray[i].m_Age << "\t";
            cout << "电话: " << abs->persongArray[i].m_Phone <<  "\t";
            cout << "住址: " << abs->persongArray[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}

// 检测是否联系人是否存在
int isExist(const Addressbooks *abs, string name_lookfor){
    for(int i = 0; i < abs->m_Size; i++) {
        if(abs->persongArray[i].m_Name == name_lookfor){
            return i;
        }
    }
    return -1;
}

// 3、删除联系人
void deletePerson(Addressbooks *abs){
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if(ret != -1){
        for(int i = ret; i < abs->m_Size-1; i++){
            abs->persongArray[i] = abs->persongArray[i+1];
        }
        abs->m_Size -= 1;
        cout << "删除成功" << endl;
    }
    else{
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

// 4、查找联系人
void findPerson(const Addressbooks * abs){
    cout << "请输入您需要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if(ret != -1){
        cout << "姓名: " << abs->persongArray[ret].m_Name << "\t";
        cout << "性别: " << (abs->persongArray[ret].m_Sex ==1 ? "男":"女" )<< "\t";
        cout << "年龄: " << abs->persongArray[ret].m_Age << "\t";
        cout << "电话: " << abs->persongArray[ret].m_Phone <<  "\t";
        cout << "住址: " << abs->persongArray[ret].m_Addr << endl;
    }
    else{
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

// 5、修改联系人
void modifyPerson(Addressbooks *abs){
    cout << "请输入要修改联系人的姓名" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1){
        // 姓名
        cout << "请输入修改后的姓名：" << endl;
        string name;
        cout << "" << endl;
        cin >> name;
        abs->persongArray[ret].m_Name = name;
        
        // 性别
        cout << "请输入性别：" << endl;
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if(sex==1 || sex==2){
                abs->persongArray[ret].m_Sex = sex;
                break;
            }
            cout << "性别错误，请重新输入" << endl;
        }
        
        // 年龄
        cout << "请输入年龄" << endl;
        int age;
        cin >> age;
        abs->persongArray[ret].m_Age = age;
        
        // 电话
        cout << "请输入电话" << endl;
        string phone;
        cin >> phone;
        abs->persongArray[ret].m_Phone = phone;
        
        // 地址
        cout << "请输入地址" << endl;
        string addr;
        cin >> addr;
        abs->persongArray[ret].m_Addr = addr;

        cout << "修改成功" << endl;
    }
    else{
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

// 6、清空联系人
void cleanPerson(Addressbooks *abs){
    abs->m_Size = 0;
    cout << "通讯录已经清空！" << endl;
    system("pause");
    system("cls");
}

int main(int argc, char*argv[]){
    // 创建 通讯录结构体变量
    Addressbooks abs;
    abs.m_Size = 0;
    
    int select = 0;
    while (true)
    {
        // 菜单显示
        showMenu();

        cin >> select;
        switch (select)
        {
        case 1://添加联系人
            addPerson(&abs);
            break;
        case 2://显示联系人
            showPerson(&abs);
            break;
        case 3://删除联系人：检测是否存在 ，删除
            deletePerson(&abs);
            break;
        case 4://查找联系人：检测是否存在, 输出
            findPerson(&abs);
            break;
        case 5://修改联系人：检测是否存在，修改
            modifyPerson(&abs);
            break;
        case 6://清空联系人
        {   cout << "你确定要清空通讯录？ yes, No" << endl;
            string do_want;
            cin >> do_want;
            if(do_want == "yes")
                cleanPerson(&abs);
            else{
                system("cls");
            }
        }
            break;
        case 0://退出通讯录
        {   cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
        }
            break;
        default:
            break;
        }
    }
    
    return 0;
}
