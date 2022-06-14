#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray{
public:
    MyArray(int capacity){
        cout<<"构造函数"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    // 拷贝构造函数
    MyArray(const MyArray&arr){
        cout<<"拷贝构造函数"<<endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        this->pAddress = new T[arr.m_Capacity];
        for(int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    MyArray& operator=(const MyArray&arr){
        cout<<"operator重载函数"<<endl;
        // 清空
        if(this->pAddress != NULL){
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T [arr.m_Capacity];
        for(int i = 0; i<this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }
    T& operator[](int index){
        return this->pAddress[index];
    }

    ~MyArray(){
        cout<<"析构函数"<<endl;
        if(this->pAddress != NULL){
            delete [] this->pAddress;
            this->pAddress = NULL;
        }
    }
    
private:
    T* pAddress;
    int m_Capacity;
    int m_Size;
};