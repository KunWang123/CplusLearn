#include"workManager.h"

workManager::workManager(){
}

workManager::~workManager(){
}

// void workManager::ShowMeau(){
//     cout << "*********************************" << endl;
//     cout << "*******��ӭʹ��ְ������ϵͳ******" << endl;
//     cout << "******** 0. �˳��������******" << endl;
//     cout << "******** 1. ����ְ����Ϣ******" << endl;
//     cout << "******** 2. ��ʾְ����Ϣ******" << endl;
//     cout << "******** 3. ɾ����ְְ��******" << endl;
//     cout << "******** 4. �޸�ְ����Ϣ******" << endl;
//     cout << "******** 5. ����ְ����Ϣ******" << endl;
//     cout << "******** 6. ���ձ������******" << endl;
//     cout << "******** 7. ��������ĵ�******" << endl;
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