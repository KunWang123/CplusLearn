#pragma once
#include<iostream>
using namespace std;
#include"point.h"

class Circle
{
private:
    double m_R=0;
    Point m_center;
public:
    double getR();
    void setR(double r);
    Point getCenter();
    void setCenter(Point p1);
    void isInCircle(Point p1); 
};
