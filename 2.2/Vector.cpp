#include "Vector.h"
#include <sstream>

// Конструктор за замовчуванням
Vector::Vector()
{
    size = 0;
    data = nullptr;
}

// Конструктор з 1 параметром
Vector::Vector(int n)
{
    size = n;
    data = new float[size];
    for (int i = 0; i < size; i++)
        data[i] = 0;
}

// Конструктор з 2 параметрами
Vector::Vector(int n, float value)
{
    size = n;
    data = new float[size];
    for (int i = 0; i < size; i++)
        data[i] = value;
}

// Конструктор копіювання
Vector::Vector(const Vector& other)
{
    size = other.size;
    data = new float[size];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

// Деструктор
Vector::~Vector()
{
    delete[] data;
}

// Методи доступу
int Vector::getSize() const
{
    return size;
}

float Vector::getElement(int index) const
{
    if (index >= 0 && index < size)
        return data[index];
    return 0;
}

void Vector::setElement(int index, float value)
{
    if (index >= 0 && index < size)
        data[index] = value;
}

// оператор =
Vector& Vector::operator=(const Vector& other)
{
    if (this != &other)
    {
        delete[] data;
        size = other.size;
        data = new float[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    return *this;
}

// оператор +=
Vector& Vector::operator+=(const Vector& other)
{
    for (int i = 0; i < size; i++)
        data[i] += other.data[i];
    return *this;
}

// оператор -=
Vector& Vector::operator-=(const Vector& other)
{
    for (int i = 0; i < size; i++)
        data[i] -= other.data[i];
    return *this;
}

// оператор *=
Vector& Vector::operator*=(float scalar)
{
    for (int i = 0; i < size; i++)
        data[i] *= scalar;
    return *this;
}

// оператор []
float& Vector::operator[](int index)
{
    return data[index];
}

// Перетворення у string
Vector::operator string() const
{
    stringstream ss;
    ss << "[ ";
    for (int i = 0; i < size; i++)
        ss << data[i] << " ";
    ss << "]";
    return ss.str();
}

// + (дружня функція)
Vector operator+(const Vector& a, const Vector& b)
{
    Vector result(a.size);
    for (int i = 0; i < a.size; i++)
        result.data[i] = a.data[i] + b.data[i];
    return result;
}

// -
Vector operator-(const Vector& a, const Vector& b)
{
    Vector result(a.size);
    for (int i = 0; i < a.size; i++)
        result.data[i] = a.data[i] - b.data[i];
    return result;
}

// *
Vector operator*(const Vector& a, float scalar)
{
    Vector result(a.size);
    for (int i = 0; i < a.size; i++)
        result.data[i] = a.data[i] * scalar;
    return result;
}

// <<
ostream& operator<<(ostream& out, const Vector& v)
{
    out << "[ ";
    for (int i = 0; i < v.size; i++)
        out << v.data[i] << " ";
    out << "]";
    return out;
}

// >>
istream& operator>>(istream& in, Vector& v)
{
    for (int i = 0; i < v.size; i++)
        in >> v.data[i];
    return in;
}