#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
    // show personal information
    virtual void showinfo()=0;

    // get personal work function
    virtual string getDeptName() = 0;

    // id 
    int m_Id;
    // name
    string m_Name;
    // department id 
    int m_DeptId;
};
