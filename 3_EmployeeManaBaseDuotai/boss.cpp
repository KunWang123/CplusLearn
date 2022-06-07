#include"boss.h"
using namespace std;

Boss::Boss(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showinfo(){
    cout << "id_number: " << this->m_Id 
        << "\tName: " << this->m_Name 
        << "\tDepartment_ID: " << this->getDeptName() 
        << "\tDuty: Think how to work" << endl;
}

string Boss::getDeptName(){
    return string("Boss");
}