#include <iostream>
#include <string.h>

using namespace std;

void BMI_Check()
{
    double wzrost, waga, BMI;
    cout << "---- Obliczanie BMI ----" << endl;
    cout << "Podaj wzrost [m] :"; cin >> wzrost;
    cout << "Podaj mase ciala [kg] :"; cin >> waga;
    BMI = (waga)/(wzrost * wzrost);
    if(BMI<16) cout << "Twoje BMI to - wyglodzenie";
    else if((BMI>=16)&&(BMI<17)) cout << "Twoje BMI to - wychudzenie";
    else if((BMI>=17)&&(BMI<18.5)) cout << "Twoje BMI to - niedowaga";
    else if((BMI>=18.5)&&(BMI<25)) cout << "Twoje BMI to - wartosc prawidlowa";
    else if((BMI>=25)&&(BMI<30)) cout << "Twoje BMI to - nadwaga";
    else if((BMI>=30)&&(BMI<35)) cout << "Twoje BMI to - I stopien otylosci";
    else if((BMI>=35)&&(BMI<40)) cout << "Twoje BMI to - II stopien otylosci";
    else cout << "Twoje BMI to - otylosc skrajna";
}


int main(int argc, char *argv[])
{
    BMI_Check();
    return 0;
}