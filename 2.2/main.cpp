#include <iostream>
#include "Vector.h"

using namespace std;

#pragma pack(push,1)
class PackedVector
{
    float* data;
    int size;
};
#pragma pack(pop)

int main()
{
    cout << "Size of Vector: " << sizeof(Vector) << endl;
    cout << "Size with #pragma pack(1): " << sizeof(PackedVector) << endl;

    Vector v1;
    Vector v2(3);
    Vector v3(3, 5.0);

    cout << "Enter vector v2: ";
    cin >> v2;

    cout << "v2 = " << v2 << endl;
    cout << "v3 = " << v3 << endl;

    Vector v4 = v2 + v3;
    cout << "v2 + v3 = " << v4 << endl;

    v4 -= v3;
    cout << "v4 -= v3 -> " << v4 << endl;

    v4 *= 2;
    cout << "v4 * 2 = " << v4 << endl;

    cout << "v4[1] = " << v4[1] << endl;

    Vector arr[2] = { Vector(3,1), Vector(3,2) };

    cout << "Array of vectors:" << endl;
    for (int i = 0; i < 2; i++)
        cout << arr[i] << endl;

    string s = (string)v4;
    cout << "String: " << s << endl;

    return 0;
}