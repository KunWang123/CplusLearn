#include"manager.h"
using namespace std;

Manager::Manager(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Manager::showinfo(){
    cout << "id_number: " << this->m_Id 
        << "\tName: " << this->m_Name 
        << "\tDepartment_ID: " << this->getDeptName() 
        << "\tDuty: Do the work with thinking" << endl;
}

string Manager::getDeptName(){
    return string("Manager");
}