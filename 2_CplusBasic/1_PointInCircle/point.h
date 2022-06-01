#pragma once
#include<iostream>
using namespace std;

class Point
{
private:
    double m_X=0;
    double m_Y=0; 
public:
    void setX(double x);
    double getX();
    void setY(double y);
    double getY();
};

