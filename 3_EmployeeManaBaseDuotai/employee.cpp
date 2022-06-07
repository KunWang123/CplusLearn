#include"employee.h"
using namespace std;

Employee::Employee(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Employee::showinfo(){
    cout << "id_number: " << this->m_Id 
        << "\tName: " << this->m_Name 
        << "\tDepartment_ID: " << this->getDeptName() 
        << "\tDuty: Do the work in order" << endl;
}

string Employee::getDeptName(){
    return string("Employee");
}