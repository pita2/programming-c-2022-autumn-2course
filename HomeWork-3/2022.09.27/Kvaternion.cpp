#include "Kvaternion.hpp"
#include <cmath>

Kvaternion::Kvaternion(double s, double x, double y, double z) : s(s), x(x), y(y), z(z) {};

Kvaternion::Kvaternion(const Kvaternion& num) : s(num.s), x(num.x), y(num.y), z(num.z) {};

Kvaternion::~Kvaternion()
{
    this->s = 0;
    this->x = 0;
    this->y = 0;
    this->z = 0;
};

double Kvaternion::getS()
{
    return this->s;
}
void Kvaternion::setS(double s)
{
    this->s = s;
}

double Kvaternion::getX()
{
    return this->s;
}
void Kvaternion::setX(double x)
{
    this->x = x;
}

double Kvaternion::getY()
{
    return this->y;
}
void Kvaternion::setY(double y)
{
    this->y = y;
}

double Kvaternion::getZ()
{
    return this->z;
}
void Kvaternion::setZ(double z)
{
    this->z = z;
}


void Kvaternion::set(double s, double x, double y, double z)
{
    this->s = s;
    this->x = x;
    this->y = y;
    this->z = z;
}

Kvaternion Kvaternion::conjugate()
{
    return Kvaternion(this->s, this->x * (-1), this->y * (-1), this->z * (-1));
}

Kvaternion Kvaternion::reverse()
{
    Kvaternion a = Kvaternion(this->s, this->x, this->y, this->z);
    return Kvaternion(a.conjugate() / (a.abs() * a.abs()));
}

double Kvaternion::abs()
{
    return sqrt(this->s * this->s + this->x * this->x + this->y * this->y + this->z * this->z);
}

void Kvaternion::operator=(const Kvaternion& num)
{
    this->s = num.s;
    this->x = num.x;
    this->y = num.y;
    this->z = num.z;
}

Kvaternion operator+(const Kvaternion& num1, const Kvaternion& num2)
{
    return Kvaternion(num1.s + num2.s, num1.x + num2.x, num1.y + num2.y, num1.z + num2.z);
}

Kvaternion operator+(double d, const Kvaternion& num)
{
    return Kvaternion(d + num.s, num.x, num.y, num.z);
}

Kvaternion operator+(const Kvaternion& num, double d)
{
    return Kvaternion(num.s + d, num.x, num.y, num.z);
}

Kvaternion operator-(const Kvaternion& num1, const Kvaternion& num2)
{
    return Kvaternion(num1.s - num2.s, num1.x - num2.x, num1.y - num2.y, num1.z - num2.z);
}

Kvaternion operator-(double d, const Kvaternion& num)
{
    return Kvaternion(d - num.s, num.x, num.y, num.z);
}

Kvaternion operator-(const Kvaternion& num, double d)
{
    return Kvaternion(num.s - d, num.x, num.y, num.z);
}

Kvaternion operator*(const Kvaternion& num1, const Kvaternion& num2)
{
    return Kvaternion(num1.s*num2.s - num1.x*num2.x - num1.y*num2.y - num1.z*num2.z,
                      num1.s*num2.x + num1.x*num2.s + num1.y*num2.z - num1.z*num2.y,
                      num1.s*num2.y + num1.y*num2.s + num1.z*num2.x - num1.x*num2.z,
                      num1.s*num2.z + num1.z*num2.s + num1.x*num2.y - num1.y*num2.x);
}

Kvaternion operator*(double d, const Kvaternion& num)
{
    return Kvaternion(d * num.s, d * num.x, d * num.y, d * num.z);
}

Kvaternion operator*(const Kvaternion& num, double d)
{
    return Kvaternion(d * num.s, d * num.x, d * num.y, d * num.z);
}

Kvaternion operator/(const Kvaternion& num1, const Kvaternion& num2)
{
    Kvaternion num = Kvaternion(num2);
    return Kvaternion(num1 * num.reverse());
}

Kvaternion operator/(double d, const Kvaternion& num)
{
    Kvaternion a = Kvaternion(num);
    return Kvaternion(d * a.reverse());
}

Kvaternion operator/(const Kvaternion& num, double d)
{
    return Kvaternion(num.s / d, num.x / d, num.y / d, num.z / d);
}

Kvaternion operator+=(Kvaternion& num1, const Kvaternion& num2)
{
    num1 = num1 + num2;
    return num1;
}

Kvaternion operator-=(Kvaternion& num1, const Kvaternion& num2)
{
    num1 = num1 - num2;
    return num1;
}

Kvaternion operator*=(Kvaternion& num1, const Kvaternion& num2)
{
    num1 = num1 * num2;
    return num1;
}

Kvaternion operator/=(Kvaternion& num1, const Kvaternion& num2)
{
    num1 = num1 / num2;
    return num1;
}

std::ostream& operator<<(std::ostream& stream, const Kvaternion& num)
{
    std::string s = "";
    if (num.s != 0)
    {
        if (num.s < 0)
        {
            s += "- ";
            s += std::to_string(abs(num.s));
            s += " ";
        }
        else
        {
            if (s != "")
            {
                s += "+ ";
            }
            s += std::to_string(abs(num.s));
            s += " ";
        }
    }
    
    if (num.x != 0)
    {
        if (num.x < 0)
        {
            s += "- ";
            s += std::to_string(abs(num.x));
            s += "i ";
        }
        else
        {
            if (s != "")
            {
                s += "+ ";
            }
            s += std::to_string(abs(num.x));
            s += "i ";
        }
    }
    
    if (num.y != 0)
    {
        if (num.y < 0)
        {
            s += "- ";
            s += std::to_string(abs(num.y));
            s += "j ";
        }
        else
        {
            if (s != "")
            {
                s += "+ ";
            }
            s += std::to_string(abs(num.y));
            s += "j ";
        }
    }
    
    if (num.z != 0)
    {
        if (num.z < 0)
        {
            s += "- ";
            s += std::to_string(abs(num.z));
            s += "k ";
        }
        else
        {
            if (s != "")
            {
                s += "+ ";
            }
            s += std::to_string(abs(num.z));
            s += "k ";
        }
    }
    
    
    stream << s;
    return stream;
}

