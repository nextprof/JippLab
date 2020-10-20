#include <iostream>

using namespace std;

template <typename T>
void Myswap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    double a = 15, b = 47;
    string f = "first", s = "second";

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "f: " << f << endl;
    cout << "s: " << s << endl;

    Myswap(&a, &b);
    Myswap(&f, &s);

    cout << "After swap:" << endl
         << "a: " << a << endl
         << "b: " << b << endl
         << "f: " << f << endl
         << "s: " << s << endl;
    return 0;
}