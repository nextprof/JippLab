#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

void Associated_Numbers()
{
    int a, b, sum_a=0, sum_b=0;
    cout << "---- Sprawdzanie czy liczby sa skojarzone  ----" << endl;
    cout << "Podaj pierwsza liczbe :"; cin >> a;
    cout << "Podaj druga liczbe :"; cin >> b;

    for(int i=1;i<((a/2)+1);i++)
    {
        if(a % i ==0) sum_a+=i;
    }
    for(int i=1;i<((b/2)+1);i++)
    {
        if(b % i ==0) sum_b+=i;
    }
    if((sum_a == (b+1)) && (sum_b == (a+1))) cout << "Podane liczby sa skojarzone";
    else cout << "Podane liczby nie sa skojarzone";
}

int main(int argc, char *argv[])
{   
    Associated_Numbers();
    return 0;
}