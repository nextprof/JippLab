#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    string wyraz = argv[1];
    int i = wyraz.length();
    char c;
    for(int j=0;j<i;j++)
    {
        c=argv[1][j];
        if(c!=wyraz[i-1])
        {
            cout << "Podany wyraz nie jest palindromem";
            return 0;
        }
        i--;
    }
    cout << "Podany wyraz jest palindromem!";
    return 0;
}