#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "matrix.hpp"

using namespace std;

void test()
{
     cout << "Pojedynczy konstruktor";
     Matrix m0(6);
     m0.print();

     Matrix m1(4, 5);
     Matrix m2(4, 5);

     double x = 1;
     for (int i = 0; i < m1.row(); i++)
     {
          for (int j = 0; j < m1.cols(); j++)
          {
               m1.set(i, j, x);
               x += 0.2;
          }
     }
     m2.set(1, 1, 5);
     m2.set(2, 1, 4);
     m2.set(3, 1, 3);

     cout << "-----M1-----";
     m1.print();
     cout << "-----M2-----";
     m2.print();

     cout << "-----test get m2(1,1)-----";
     int test = m2.get(1, 1);
     cout << endl
          << test << endl;

     cout << "-----M3(add)-----";
     Matrix m3 = m2.add(m1);
     m3.print();

     cout << "-----M4(subtract)-----";
     Matrix m4 = m2.subtract(m1);
     m4.print();

     cout << "-----M5(multiply m3* m6(5,3))-----";
     Matrix m6(5, 3);
     m6.set(1, 1, 5);
     Matrix m5 = m3.multiply(m6);
     m5.print();

     cout << "-----Row m1-----";
     int testrow = m1.row();
     cout << endl
          << testrow << endl;

     cout << "-----Columns m1-----";
     int testcol = m1.cols();
     cout << endl
          << testcol << endl;

     m2.store("dane.txt", "C:/Users/kubab/OneDrive/Pulpit/JIPP2/Lab4");
     Matrix m7("dane.txt", "C:/Users/kubab/OneDrive/Pulpit/JIPP2/Lab4");
     cout << "Store ->> read for file (m2)";
     m7.print();
}

int main()
{
     test();
}
