#include <iostream>
#include "Matrix3D.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

Matrix3D::Matrix3D(): Matrix3D(0, 0, 0, 0, 0, 0, 0, 0, 0)
{

}

Matrix3D::Matrix3D(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8) 
{
    element = new double[9];
    element[0] = a0;
    element[1] = a1;
    element[2] = a2;
    element[3] = a3;
    element[4] = a4;
    element[5] = a5;
    element[6] = a6;
    element[7] = a7;
    element[8] = a8;
}

Matrix3D::~Matrix3D()
{
    delete[] element;
}


double Matrix3D::getElement(int i) const
{
    return element[i];
}

void Matrix3D::setElement(double elem, int i )
{
    element[i] = elem;
}


bool Matrix3D::operator==(const Matrix3D &m2) const
{   
    for (int i = 0; i < 9; i++)
    {
        if(element[i] != m2.getElement(i)) return false;
    }
    return true;
}

bool Matrix3D::operator!=(const Matrix3D &m2) const
{
    return !(*this == m2);
}

Matrix3D Matrix3D::operator+(const Matrix3D &m2) const
{
    Matrix3D m3;
    for (int i = 0; i < 9; i++)
    m3.setElement(element[i] + m2.getElement(i), i);
    return m3;
}

Matrix3D Matrix3D::operator-(const Matrix3D &m2) const
{
    Matrix3D m3;
    for (int i = 0; i < 9; i++)
    m3.setElement(element[i] - m2.getElement(i), i);
    return m3;
}

Matrix3D Matrix3D::operator*(const double a) const
{
    Matrix3D m3;
    for (int i = 0; i < 9; i++)
    m3.setElement(a*element[i], i);
    return m3;
}

Matrix3D Matrix3D::operator*(const Matrix3D &m2) const
{
    Matrix3D m3;
    for (int t = 0; t < 9; t++)
    {
        int i = t / 3;
        int j = t % 3;
        double count = 0;
        for (int c = 0; c < 3; c++)
        {
            count += element[i*3 + c] * m2.getElement(j + c*3);
        }
        m3.setElement(count, t);
    }
    return m3;
}


double Matrix3D::det()
{
    double a1 = 0, a2 = 0;
    a1 = element[0]*element[4]*element[8] + element[1]*element[5]*element[6] + element[2]*element[3]*element[7];
    a2 = - element[2]*element[4]*element[6] - element[1]*element[3]*element[8] - element[0]*element[5]*element[7]; 
    return a1 + a2;
}


Matrix3D operator*(const double a, Matrix3D &m2)
{
    Matrix3D m3;
    for (int i = 0; i < 9; i++)
    m3.setElement(a*m2.getElement(i), i);
    return m3;
}


ostream& operator<<(ostream& os, const Matrix3D &m)
{
    os << "(";
    for (int i = 0; i < 8; i++)
    os << m.getElement(i) << "; ";
    os << m.getElement(8) << ")";
    return os;
}

istream& operator>>(istream& is, Matrix3D &m)
{
    double in[9];
    for (int i = 0; i < 9; i++)
    {
        is >> in[i];
        m.setElement(in[i], i);
    }
    return is;
}