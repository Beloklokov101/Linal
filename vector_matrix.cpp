#include <string>
#include <iostream>

using namespace std;

//ВЕКТОРЫ

class Vector3D
{
public:
    // Конструкторы
    Vector3D() : Vector3D(0, 0, 0){ }
    Vector3D(double x, double y, double z): x(x), y(y), z(z) { }

    // Деструктор
    ~Vector3D(){}

    // Получение координат
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    double getZ() const
    {
        return z;
    }

    // Задание координат
    void setX(double x){
        this->x = x;
    }
    void setY(double y){
        this->y = y;
    }
    void setZ(double z){
        this->z = z;
    }

    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector3D& v2) const
    {
        return ((x == v2.x) && (y == v2.y) && (z == v2.z));
    }

    // Ещё один перегруженный оператор - неравенство векторов
    // Да, это отдельный оператор! Хинт - настоящие джедаи смогут для != использовать уже написанное ==
    bool operator!= (const Vector3D& v2) const
    {
        return ((x != v2.x) || (y != v2.y) || (z != v2.z));
    }

    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector3D operator+ (const Vector3D& v2) const
    {
        Vector3D v3(x + v2.x, y + v2.y, z + v2.z);
        return v3;
    }

    // Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
    Vector3D operator- (const Vector3D& v2) const
    {
        Vector3D v3(x - v2.x, y - v2.y, z - v2.z);
        return v3;
    }

    // Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
    Vector3D operator* (const double a) const
    {
        Vector3D v2(x*a, y*a, z*a);
        return v2;
    }

    //Оператор скалярного умножения вектора на вектор
    double operator* (const Vector3D& v2) const
    {
        double result = x*v2.getX() + y*v2.getY() + z*v2.getZ();
        return result;
    }

protected:
    double x;
    double y;
    double z;
};

// Оператор умножения скаляра на вектор, исходный вектор не меняется, возвращается новый вектор
// Неожиданно, правда? Умножение скаляра на вектор - это отдельный оператор, причём описанный *вне* класса.
Vector3D operator* (double a, const Vector3D& v)
{
    Vector3D v2;
    v2.setX(a*v.getX());
    v2.setY(a*v.getY());
    v2.setZ(a*v.getZ());
    return v2;
}

// Вывод вектора, ожидается строго в формате (1; 1)
ostream& operator<<(ostream& os, const Vector3D& v)
{
    os << "(" << v.getX() << "; "<< v.getY() << "; " << v.getZ() << ")" ;
    return os;
}

// Чтение вектора, читает просто две координаты без хитростей
istream& operator>>(istream &is, Vector3D &v)
{
    double x, y, z;
    is >> x >> y >> z;
    v.setX(x);
    v.setY(y);
    v.setZ(z);
    return is;
}



// МАТРИЦЫ

class Matrix3D
{
protected:
    double* element;

public:
    Matrix3D(): Matrix3D(0, 0, 0, 0, 0, 0, 0, 0, 0){}
    Matrix3D(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8) 
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

    ~Matrix3D()
    {
        delete[] element;
    }

    double getElement(int i) const
    {
        return element[i];
    }

    void setElement(double elem, int i )
    {
        element[i] = elem;
    }

    bool operator==(const Matrix3D &m2) const
    {   
        for (int i = 0; i < 9; i++)
        {
            if(element[i] != m2.getElement(i)) return false;
        }
        return true;
    }

    bool operator!=(const Matrix3D &m2) const
    {
        return !(*this == m2);
    }

    Matrix3D operator+(const Matrix3D &m2) const
    {
        Matrix3D m3;
        for (int i = 0; i < 9; i++)
        m3.setElement(element[i] + m2.getElement(i), i);
        return m3;
    }

    Matrix3D operator-(const Matrix3D &m2) const
    {
        Matrix3D m3;
        for (int i = 0; i < 9; i++)
        m3.setElement(element[i] - m2.getElement(i), i);
        return m3;
    }

    Matrix3D operator*(const double a) const
    {
        Matrix3D m3;
        for (int i = 0; i < 9; i++)
        m3.setElement(a*element[i], i);
        return m3;
    }

    Matrix3D operator*(const Matrix3D &m2) const
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

    double det()
    {
        double a1 = 0, a2 = 0;
        a1 = element[0]*element[4]*element[8] + element[1]*element[5]*element[6] + element[2]*element[3]*element[7];
        a2 = - element[2]*element[4]*element[6] - element[1]*element[3]*element[8] - element[0]*element[5]*element[7]; 
        return a1 + a2;
    }
};

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
}