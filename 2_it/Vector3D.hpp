#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Matrix3D.hpp"


class Vector3D
{
protected:
    double x;
    double y;
    double z;

public:

    Vector3D();
    Vector3D(double x, double y, double z);

    ~Vector3D();

    double getX() const;
    double getY() const;
    double getZ() const;
    
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    bool operator== (const Vector3D& v2) const;
    bool operator!= (const Vector3D& v2) const;
    Vector3D operator+ (const Vector3D& v2) const;
    Vector3D operator- (const Vector3D& v2) const;
    Vector3D operator* (const double a) const;
    double operator* (const Vector3D& v2) const;
    

};

Vector3D operator* (double a, const Vector3D& v);

Vector3D operator* (const Matrix3D &m, const Vector3D &v);

std::ostream& operator<<(std::ostream& os, const Vector3D& v);
std::istream& operator>>(std::istream &is, Vector3D &v);

#endif