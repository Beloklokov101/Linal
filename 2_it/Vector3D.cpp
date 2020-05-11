#include <iostream>
#include "Vector3D.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

Vector3D::Vector3D(): Vector3D(0, 0, 0)
{
    
}

Vector3D::Vector3D(double x, double y, double z): x(x), y(y), z(z)
{

}

Vector3D::~Vector3D()
{

}


double Vector3D::getX() const
{
    return x;
}

double Vector3D::getY() const
{
    return y;
}

double Vector3D::getZ() const
{
    return z;
}


void Vector3D::setX(double x)
{
    this->x = x;
}

void Vector3D::setY(double y)
{
    this->y = y;
}

void Vector3D::setZ(double z)
{
    this->z = z;
}


bool Vector3D::operator== (const Vector3D& v2) const
{
    return ((x == v2.x) && (y == v2.y) && (z == v2.z));
}

bool Vector3D::operator!= (const Vector3D& v2) const
{
    return ((x != v2.x) || (y != v2.y) || (z != v2.z));
}

Vector3D Vector3D::operator+ (const Vector3D& v2) const
{
    Vector3D v3(x + v2.x, y + v2.y, z + v2.z);
    return v3;
}

Vector3D Vector3D::operator- (const Vector3D& v2) const
{
    Vector3D v3(x - v2.x, y - v2.y, z - v2.z);
    return v3;
}

Vector3D Vector3D::operator* (const double a) const
{
    Vector3D v2(x*a, y*a, z*a);
    return v2;
}

double Vector3D::operator* (const Vector3D& v2) const
{
    double result = x*v2.getX() + y*v2.getY() + z*v2.getZ();
    return result;
}

Vector3D operator* (double a, const Vector3D& v)
{
    Vector3D v2;
    v2.setX(a*v.getX());
    v2.setY(a*v.getY());
    v2.setZ(a*v.getZ());
    return v2;
}

Vector3D operator* (const Matrix3D &m, const Vector3D &v)
{
    Vector3D v2;
    double a[3];

    a[0] = v.getX() * m.getElement(0) + v.getY() * m.getElement(1) + v.getZ() * m.getElement(2);
    a[1] = v.getX() * m.getElement(3) + v.getY() * m.getElement(4) + v.getZ() * m.getElement(5);
    a[2] = v.getX() * m.getElement(6) + v.getY() * m.getElement(7) + v.getZ() * m.getElement(8);
    v2.setX(a[0]);
    v2.setY(a[1]);
    v2.setZ(a[2]);

    return v2;
}


ostream& operator<<(ostream& os, const Vector3D& v)
{
    os << "(" << v.getX() << "; "<< v.getY() << "; " << v.getZ() << ")" ;
    return os;
}

istream& operator>>(istream &is, Vector3D &v)
{
    double x, y, z;
    is >> x >> y >> z;
    v.setX(x);
    v.setY(y);
    v.setZ(z);
    return is;
}