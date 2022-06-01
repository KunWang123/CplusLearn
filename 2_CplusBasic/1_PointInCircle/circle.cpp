#include"circle.h"
#include<math.h>

double Circle::getR(){
    return m_R;

}
void Circle::setR(double r){
    m_R = r;

}

Point Circle::getCenter(){
    return m_center;

}
void Circle::setCenter(Point p1){
    m_center.setX(p1.getX());
    m_center.setY(p1.getY());

}
void Circle::isInCircle(Point p1){
    double dis = 
    pow(p1.getX() * m_center.getX(),2) + 
    pow(p1.getY() * m_center.getY(),2);
    double normal = pow(m_R, 2);
    if(dis == normal){
        cout << "point is on circle" << endl;
    }
    else if (dis > normal)
    {
        cout << "point is out circle" << endl;
    }
    else{
        cout << "point is in circle" << endl;
    }
    
}