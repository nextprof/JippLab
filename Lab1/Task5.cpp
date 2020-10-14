#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

void Get_Matrix(char **tab)
{
    double m1[2][3];
    double m2[2][3];
    double m3[2][3];
    int counter=1;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            m1[i][j]=atof(tab[counter++]);
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            m2[i][j]=atof(tab[counter++]);
        }
    }
    cout << " ---- MACIERZ PIERWSZA ---- "; cout << endl;
    for (int i = 0; i < 2; i++)		//WYPISYWANIE 1szej
	{
        cout << "  ";
		for (int j = 0; j < 3; j++)
		{
			cout << m1[i][j]; cout << "  ";
		}
		cout << endl;
	}

    cout << " ---- MACIERZ DRUGA ---- "; cout << endl;
    for (int i = 0; i < 2; i++)		//WYPISYWANIE 2giej
	{
        cout << "  ";
		for (int j = 0; j < 3; j++)
		{
			cout << m2[i][j]; cout << "  ";
		}
		cout << endl;
	}

    for (int i = 0; i < 2; i++)		//Sumowanie macierzy
	{
		for (int j = 0; j < 3; j++)
		{
			m3[i][j]=m2[i][j]+m1[i][j];
		}
    }

    cout << " ---- MACIERZ ZSUMOWANA ---- "; cout << endl;
    for (int i = 0; i < 2; i++)		//WYPISYWANIE zsumowanej macierzy
	{
        cout << "  ";
		for (int j = 0; j < 3; j++)
		{
			cout << m3[i][j]; cout << "  ";
		}
		cout << endl;
	}
}



int main(int argc, char *argv[])
{   
    Get_Matrix(argv);
   
    return 0;
}