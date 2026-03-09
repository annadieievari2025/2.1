#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector
{
private:
    float* data;
    int size;

public:
    // Конструктори
    Vector();
    Vector(int n);
    Vector(int n, float value);
    Vector(const Vector& other);

    // Деструктор
    ~Vector();

    // Методи доступу
    int getSize() const;
    float getElement(int index) const;
    void setElement(int index, float value);

    // Перевантаження операторів (методи класу)
    Vector& operator=(const Vector& other);
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector& operator*=(float scalar);
    float& operator[](int index);

    // Перетворення у рядок
    operator string() const;

    // Дружні функції
    friend Vector operator+(const Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a, const Vector& b);
    friend Vector operator*(const Vector& a, float scalar);

    // Потокові операції
    friend ostream& operator<<(ostream& out, const Vector& v);
    friend istream& operator>>(istream& in, Vector& v);
};

#endif