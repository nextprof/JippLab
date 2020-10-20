#include <iostream>

using namespace std;

void My_swap(int &a, int &b)
{

    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b;
    cout << "Podaj kolejno 2 liczby: " << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    My_swap(a, b);

    cout << "a: " << a << "  b: " << b;
    return 0;
}