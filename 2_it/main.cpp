#include <iostream>

#include "Vector3D.hpp"
#include "Matrix3D.hpp"

using namespace std;

int main() 
{
    // Вектор задан в коде
    Vector3D A(1, 2, 3);
    // Вектор читается из cin
    Vector3D B;
    cin >> B;

    // Базовые операции с векторами
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A * 3 = " << A * 3 << endl;
    cout << "2 * B = " << 2 * B << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;

    // Матрица задана в коде
    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    // Матрица читается из cin
    Matrix3D D;
    cin >> D;

    // Базовые операции с матрицами
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "C * 3 = " << C * 3 << endl;
    cout << "2 * D = " << 2 * D << endl;
    cout << "C + D = " << C + D << endl;
    cout << "C - D = " << C - D << endl;
    cout << "C * D = " << C * D << endl;

    // Детерминант матрицы
    cout << "det(D) = " << D.det() << endl;

    // Умножение матрицы на вектор
    cout << "D * B = " << D * B << endl;

    return 0;
};