#include <iostream>

using namespace std;

double sum_product(double a, double b, double *iloczyn)
{
    *iloczyn = a * b;
    return a + b;
}

int main()
{
    double iloczyn, suma, a, b;
    cout << "Podaj kolejno 2 liczby: " << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    suma = sum_product(a, b, &iloczyn);
    cout << "a: " << a << "  b: " << b << endl
         << "Iloczyn: " << iloczyn << endl
         << "Suma: " << suma;
    return 0;
}