#include "IntRange.h"

IntRange::IntRange()
{
    first = 0;
    second = 1;
}

IntRange::IntRange(int f, int s)
{
    Init(f, s);
}

IntRange::IntRange(const IntRange& other)
{
    first = other.first;
    second = other.second;
}

void IntRange::Init(int f, int s)
{
    if (f >= s)
    {
        cout << "Error: first must be < second\n";
        exit(1);
    }
    first = f;
    second = s;
}

int IntRange::getFirst() const { return first; }
int IntRange::getSecond() const { return second; }

void IntRange::setFirst(int value)
{
    if (value >= second)
    {
        cout << "Error\n";
        exit(1);
    }
    first = value;
}

void IntRange::setSecond(int value)
{
    if (value <= first)
    {
        cout << "Error\n";
        exit(1);
    }
    second = value;
}

void IntRange::Read()
{
    int f, s;
    cout << "first = ";
    cin >> f;
    cout << "second = ";
    cin >> s;
    Init(f, s);
}

void IntRange::Display() const
{
    cout << "[" << first << ", " << second << ")";
}

bool IntRange::rangeCheck(int x) const
{
    return (x >= first && x < second);
}

IntRange::operator string() const
{
    return "[" + to_string(first) + ", " + to_string(second) + ")";
}

IntRange& IntRange::operator=(const IntRange& other)
{
    if (this != &other)
    {
        first = other.first;
        second = other.second;
    }
    return *this;
}

// ïðåô³êñ ++ (çì³íþº first)
IntRange& IntRange::operator++()
{
    ++first;
    return *this;
}

// ïîñòô³êñ ++ (çì³íþº second)
IntRange IntRange::operator++(int)
{
    IntRange temp(*this);
    second++;
    return temp;
}

// ïðåô³êñ --
IntRange& IntRange::operator--()
{
    --first;
    return *this;
}

// ïîñòô³êñ --
IntRange IntRange::operator--(int)
{
    IntRange temp(*this);
    second--;
    return temp;
}

istream& operator>>(istream& in, IntRange& r)
{
    in >> r.first >> r.second;
    if (r.first >= r.second)
    {
        cout << "Error\n";
        exit(1);
    }
    return in;
}

ostream& operator<<(ostream& out, const IntRange& r)
{
    out << "[" << r.first << ", " << r.second << ")";
    return out;
}

IntRange makeIntRange(int f, int s)
{
    if (f >= s)
    {
        cout << "Wrong parameters\n";
        exit(1);
    }
    return IntRange(f, s);
}