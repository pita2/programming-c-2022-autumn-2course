#pragma once
#include <iostream>
class Kvaternion
{
private:
    double s;
    double x;
    double y;
    double z;
    
public:
    Kvaternion(double s = 0, double x = 0, double y = 0, double z = 0);
    Kvaternion(const Kvaternion& complex);
    ~Kvaternion();
    
    double getS();
    void setS(double s);
    
    double getX();
    void setX(double x);
    
    double getY();
    void setY(double y);
    
    double getZ();
    void setZ(double z);
    
    void set(double s, double x, double y, double z);
    
    double abs();
    
    double arg();
    
    Kvaternion conjugate();
    
    Kvaternion reverse();
    
    void operator=(const Kvaternion& complex);
    
    friend Kvaternion operator+(const Kvaternion& num1, const Kvaternion& num2);
    friend Kvaternion operator+(double d, const Kvaternion& num);
    friend Kvaternion operator+(const Kvaternion& num, double d);
    friend Kvaternion operator-(const Kvaternion& num1, const Kvaternion& num2);
    friend Kvaternion operator-(double d, const Kvaternion& num);
    friend Kvaternion operator-(const Kvaternion& num, double d);
    friend Kvaternion operator/(Kvaternion& num1, Kvaternion& num2);
    friend Kvaternion operator/(double d, const Kvaternion& num);
    friend Kvaternion operator/(const Kvaternion& num, double d);
    friend Kvaternion operator*(const Kvaternion& num1, const Kvaternion& num2);
    friend Kvaternion operator*(double d, const Kvaternion& num);
    friend Kvaternion operator*(const Kvaternion& num, double d);
    friend Kvaternion operator+=(Kvaternion& num1, const Kvaternion& num2);
    friend Kvaternion operator-=(Kvaternion& num1, const Kvaternion& num2);
    friend Kvaternion operator/=(Kvaternion& num1, const Kvaternion& num2);
    friend Kvaternion operator*=(Kvaternion& num1, const Kvaternion& num2);
    
    
    friend std::ostream& operator<<(std::ostream& stream, const Kvaternion& num);
    

};

