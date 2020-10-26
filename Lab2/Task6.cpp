#include <iostream>

using namespace std;

template <typename T>
void Myswap(T **r, T **s)
{
    T *pSwap = *r;
    *r = *s;
    *s = pSwap;
}

int main()
{
    double a = 15, b = 47;
    string f = "first", s = "second";
    double *ptra = &a;
    double *ptrb = &b;

    string *ptrf = &f;
    string *ptrs = &s;

    cout << "Before swap:" << endl
         << "ptra: " << *ptra << endl
         << "ptrb: " << *ptrb << endl
         << "ptrf: " << *ptrf << endl
         << "ptrs: " << *ptrs << endl
         << endl;

    Myswap(&ptra, &ptrb);
    Myswap(&ptrf, &ptrs);

    cout << "After swap:" << endl
         << endl
         << "ptra: " << *ptra << endl
         << "ptrb: " << *ptrb << endl
         << "ptrf: " << *ptrf << endl
         << "ptrs: " << *ptrs << endl;
    return 0;
}