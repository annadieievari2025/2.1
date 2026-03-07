#include "IntRange.h"

int main()
{
    IntRange a;
    IntRange b(2, 10);
    IntRange c = b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "\nEnter range:\n";
    cin >> a;
    cout << "You entered: " << a << endl;

    int x;
    cout << "Enter number to check: ";
    cin >> x;

    if (a.rangeCheck(x))
        cout << "Number in range\n";
    else
        cout << "Number NOT in range\n";

    ++a;
    cout << "After ++a: " << a << endl;

    a++;
    cout << "After a++: " << a << endl;

    cout << "String: " << string(a) << endl;

    IntRange d = makeIntRange(5, 15);
    cout << "d = " << d << endl;

    return 0;
}