#ifndef MATRIX3D_H
#define MATRIX3D_H

class Matrix3D
{
protected:
    double* element;

public:

    Matrix3D();
    Matrix3D(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8);
    ~Matrix3D();

    double getElement(int i) const;
    void setElement(double elem, int i);

    bool operator==(const Matrix3D &m2) const;
    bool operator!=(const Matrix3D &m2) const;
    Matrix3D operator+(const Matrix3D &m2) const;
    Matrix3D operator-(const Matrix3D &m2) const;
    Matrix3D operator*(const double a) const;
    Matrix3D operator*(const Matrix3D &m2) const;
    double det();
};

Matrix3D operator*(const double a, Matrix3D &m2);

std::ostream& operator<<(std::ostream& os, const Matrix3D &m);
std::istream& operator>>(std::istream& is, Matrix3D &m);

#endif