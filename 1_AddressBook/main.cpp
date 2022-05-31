#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

// �����ϵ�˽ṹ��
struct Person{
    // ����
    string m_Name;
    // �Ա� 1�� 2Ů
    int m_Sex;
    // ����
    int m_Age;
    // �绰
    string m_Phone;
    // סַ
    string m_Addr;
};

// ͨѶ¼�ṹ��
struct Addressbooks
{
    // ͨѶ¼�б�����ϵ�˵�����
    struct Person persongArray[MAX];
    // ͨѶ¼����ϵ�˵ĸ���
    int m_Size=0;
};

// �˵���ʾ
void showMenu(){
    cout << "**************************" << endl;
    cout << "*****  1�������ϵ��  *****" << endl;
    cout << "*****  2����ʾ��ϵ��  *****" << endl;
    cout << "*****  3��ɾ����ϵ��  *****" << endl;
    cout << "*****  4��������ϵ��  *****" << endl;
    cout << "*****  5���޸���ϵ��  *****" << endl;
    cout << "*****  6�������ϵ��  *****" << endl;
    cout << "*****  0���˳�ͨѶ¼  *****" << endl;
    cout << "**************************" << endl;
}

// 1 �����ϵ��
void addPerson(Addressbooks * abs){
    // �ж�ͨѶ¼�Ƿ�����
    if (abs->m_Size == MAX){
        cout << "ͨѶ¼�������޷����!" << endl;
        return;
    }
    else{// ��Ӿ�����ϵ��
        // ����
        string name;
        cout << "������������ " << endl;
        cin >> name;
        abs->persongArray[abs->m_Size].m_Name = name;

        // �Ա� 1�� 2Ů
        cout << "�������Ա�" << endl;
        cout << "1 ---- ��" << endl;
        cout << "2 ---- Ů"  << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2){
                abs->persongArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else{
                cout << "������������������" << endl;
            }
        }

        // ����
        cout << "���������䣺 " << endl;
        int age = 0;
        cin >> age;
        abs->persongArray[abs->m_Size].m_Age = age;

        // �绰
        cout << "��������ϵ�绰�� " << endl;
        string phone;
        cin >> phone;
        abs->persongArray[abs->m_Size].m_Phone = phone;

        // סַ
        cout << "�������ַ�� " << endl;
        string address;
        cin >> address;
        abs->persongArray[abs->m_Size].m_Addr = address;

        // ����ͨѶ¼����
        abs->m_Size++;

        cout << "��ӳɹ�" << endl;
        system("pause");
        system("cls");

    }
}

// 2����ʾ��ϵ��
void showPerson(const Addressbooks *abs){
    // �ж�ͨѶ¼�������Ƿ�Ϊ0�������0����ʾ��¼Ϊ��
    // �����Ϊ0����ʾ��¼��ϵ�˵���Ϣ
    if (abs->m_Size == 0){
        cout << "��ǰ��¼Ϊ��" << endl;
        // return ;
    }
    else{
        for(int i=0; i< abs->m_Size; i++){
            cout << "����: " << abs->persongArray[i].m_Name << "\t";
            cout << "�Ա�: " << (abs->persongArray[i].m_Sex ==1 ? "��":"Ů" )<< "\t";
            cout << "����: " << abs->persongArray[i].m_Age << "\t";
            cout << "�绰: " << abs->persongArray[i].m_Phone <<  "\t";
            cout << "סַ: " << abs->persongArray[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}

// ����Ƿ���ϵ���Ƿ����
int isExist(const Addressbooks *abs, string name_lookfor){
    for(int i = 0; i < abs->m_Size; i++) {
        if(abs->persongArray[i].m_Name == name_lookfor){
            return i;
        }
    }
    return -1;
}

// 3��ɾ����ϵ��
void deletePerson(Addressbooks *abs){
    cout << "��������Ҫɾ������ϵ��" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if(ret != -1){
        for(int i = ret; i < abs->m_Size-1; i++){
            abs->persongArray[i] = abs->persongArray[i+1];
        }
        abs->m_Size -= 1;
        cout << "ɾ���ɹ�" << endl;
    }
    else{
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

// 4��������ϵ��
void findPerson(const Addressbooks * abs){
    cout << "����������Ҫ���ҵ���ϵ��" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if(ret != -1){
        cout << "����: " << abs->persongArray[ret].m_Name << "\t";
        cout << "�Ա�: " << (abs->persongArray[ret].m_Sex ==1 ? "��":"Ů" )<< "\t";
        cout << "����: " << abs->persongArray[ret].m_Age << "\t";
        cout << "�绰: " << abs->persongArray[ret].m_Phone <<  "\t";
        cout << "סַ: " << abs->persongArray[ret].m_Addr << endl;
    }
    else{
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

// 5���޸���ϵ��
void modifyPerson(Addressbooks *abs){
    cout << "������Ҫ�޸���ϵ�˵�����" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1){
        // ����
        cout << "�������޸ĺ��������" << endl;
        string name;
        cout << "" << endl;
        cin >> name;
        abs->persongArray[ret].m_Name = name;
        
        // �Ա�
        cout << "�������Ա�" << endl;
        cout << "1---��" << endl;
        cout << "2---Ů" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if(sex==1 || sex==2){
                abs->persongArray[ret].m_Sex = sex;
                break;
            }
            cout << "�Ա��������������" << endl;
        }
        
        // ����
        cout << "����������" << endl;
        int age;
        cin >> age;
        abs->persongArray[ret].m_Age = age;
        
        // �绰
        cout << "������绰" << endl;
        string phone;
        cin >> phone;
        abs->persongArray[ret].m_Phone = phone;
        
        // ��ַ
        cout << "�������ַ" << endl;
        string addr;
        cin >> addr;
        abs->persongArray[ret].m_Addr = addr;

        cout << "�޸ĳɹ�" << endl;
    }
    else{
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

// 6�������ϵ��
void cleanPerson(Addressbooks *abs){
    abs->m_Size = 0;
    cout << "ͨѶ¼�Ѿ���գ�" << endl;
    system("pause");
    system("cls");
}

int main(int argc, char*argv[]){
    // ���� ͨѶ¼�ṹ�����
    Addressbooks abs;
    abs.m_Size = 0;
    
    int select = 0;
    while (true)
    {
        // �˵���ʾ
        showMenu();

        cin >> select;
        switch (select)
        {
        case 1://�����ϵ��
            addPerson(&abs);
            break;
        case 2://��ʾ��ϵ��
            showPerson(&abs);
            break;
        case 3://ɾ����ϵ�ˣ�����Ƿ���� ��ɾ��
            deletePerson(&abs);
            break;
        case 4://������ϵ�ˣ�����Ƿ����, ���
            findPerson(&abs);
            break;
        case 5://�޸���ϵ�ˣ�����Ƿ���ڣ��޸�
            modifyPerson(&abs);
            break;
        case 6://�����ϵ��
        {   cout << "��ȷ��Ҫ���ͨѶ¼�� yes, No" << endl;
            string do_want;
            cin >> do_want;
            if(do_want == "yes")
                cleanPerson(&abs);
            else{
                system("cls");
            }
        }
            break;
        case 0://�˳�ͨѶ¼
        {   cout << "��ӭ�´�ʹ��" << endl;
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
