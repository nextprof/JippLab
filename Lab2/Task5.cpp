#include <iostream>

using namespace std;

void My_swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    double a, b;
    cout << "Podaj kolejno 2 liczby: " << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    My_swap(&a, &b);

    cout << "a: " << a << "  b: " << b;
    return 0;
}