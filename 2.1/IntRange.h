#pragma once
#include <iostream>
#include <string>

using namespace std;

class IntRange
{
private:
    int first;
    int second;

public:
    // Конструктори
    IntRange();
    IntRange(int f, int s);
    IntRange(const IntRange& other);

    // Ініціалізація
    void Init(int f, int s);

    // Методи доступу
    int getFirst() const;
    int getSecond() const;

    void setFirst(int value);
    void setSecond(int value);

    // Методи
    void Read();
    void Display() const;
    bool rangeCheck(int x) const;

    // Перетворення в string
    operator string() const;

    // Присвоєння
    IntRange& operator=(const IntRange& other);

    // Інкремент / декремент
    IntRange& operator++();     // префікс
    IntRange operator++(int);   // постфікс
    IntRange& operator--();
    IntRange operator--(int);

    // Дружні функції вводу / виводу
    friend istream& operator>>(istream& in, IntRange& r);
    friend ostream& operator<<(ostream& out, const IntRange& r);
};

// зовнішня функція створення
IntRange makeIntRange(int f, int s);
