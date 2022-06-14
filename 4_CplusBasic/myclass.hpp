#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class MyArray{
public:
    MyArray(int capacity){
        cout<<"���캯��"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    // �������캯��
    MyArray(const MyArray&arr){
        cout<<"�������캯��"<<endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        this->pAddress = new T[arr.m_Capacity];
        for(int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    MyArray& operator=(const MyArray&arr){
        cout<<"operator���غ���"<<endl;
        // ���
        if(this->pAddress != NULL){
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        // ���
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
        cout<<"��������"<<endl;
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