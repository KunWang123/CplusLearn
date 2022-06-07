#include"workManager.h"

workManager::workManager(){
}

workManager::~workManager(){
}

// void workManager::ShowMeau(){
//     cout << "*********************************" << endl;
//     cout << "*******欢迎使用职工管理系统******" << endl;
//     cout << "******** 0. 退出管理程序******" << endl;
//     cout << "******** 1. 增加职工信息******" << endl;
//     cout << "******** 2. 显示职工信息******" << endl;
//     cout << "******** 3. 删除离职职工******" << endl;
//     cout << "******** 4. 修改职工信息******" << endl;
//     cout << "******** 5. 查找职工信息******" << endl;
//     cout << "******** 6. 按照编号排序******" << endl;
//     cout << "******** 7. 清空所有文档******" << endl;
//     cout << "*********************************" << endl;
//     cout << endl;
// }

void workManager::ShowMeau(){
    cout << "*********************************" << endl;
    cout << "*******welcome to use the manager system******" << endl;
    cout << "******** 0. quit******" << endl;
    cout << "******** 1. add one ******" << endl;
    cout << "******** 2. show one******" << endl;
    cout << "******** 3. delete one******" << endl;
    cout << "******** 4. modify one******" << endl;
    cout << "******** 5. look for one******" << endl;
    cout << "******** 6. sort all ******" << endl;
    cout << "******** 7. clear all ******" << endl;
    cout << "*********************************" << endl;
    cout << endl;
}

void workManager::ExitSystem(){
    cout << "welcome to reuse our system" << endl;
    system("pause");
    exit(0);
}