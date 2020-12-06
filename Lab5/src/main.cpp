#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <matrix.hpp>

using namespace std;

void testErrors()
{
     cout << endl
          << "--------Testing errors------------"
          << endl
          << endl;
     try
     {
          cout << "Trying to create matrix with rows = -4" << endl;
          Matrix m10(-4, 5);
     }
     catch (invalid_argument &e)
     {
          cerr << "Error: " << e.what() << endl;
     }

     try
     {
          cout << "Trying to create matrix with columns = -5" << endl;
          Matrix m11(4, -5);
     }
     catch (invalid_argument &e)
     {
          cerr << "Error: " << e.what() << endl;
     }

     try
     {
          cout << "Trying to create matrix with 1-argument constructor with columns,rows = -2" << endl;
          Matrix m12(-2);
     }
     catch (invalid_argument &e)
     {
          cerr << "Error: " << e.what() << endl;
     }

     try
     {
          cout << "Trying to set a value to matrix[2][-1]" << endl;
          Matrix m13(3);
          m13.set(2, -1, 5);
     }
     catch (out_of_range &e)
     {
          cerr << "Error: " << e.what() << endl;
     }

     try
     {
          cout << "Trying to get a value from matrix[3][-2]" << endl;
          Matrix m14(4);
          double value = m14.get(3, -2);
     }
     catch (out_of_range &e)
     {
          cerr << "Error: " << e.what() << endl;
     }

     try
     {
          cout << "Trying to add two matrixes with not equal size m1[2][2], m2[2][3]" << endl;
          Matrix m15(2);
          Matrix m16(2, 3);
          Matrix m17 = m15.add(m16);
     }
     catch (invalid_argument &e)
     {
          cerr << "Error: " << e.what() << endl;
     }

     try
     {
          cout << "Trying to substract two matrixes with not equal size m1[3][2], m2[3][3]" << endl;
          Matrix m17(3, 2);
          Matrix m18(3);
          Matrix m19 = m17.subtract(m18);
     }
     catch (invalid_argument &e)
     {
          cerr << "Error: " << e.what() << endl;
     }

     try
     {
          cout << "Trying to multiply two matrixes with not correct size m1[2][2], m2[3][2]" << endl;
          Matrix m20(2);
          Matrix m21(3, 2);
          Matrix m22 = m20.multiply(m21);
     }
     catch (invalid_argument &e)
     {
          cerr << "Error: " << e.what() << endl;
     }

     try
     {
          cout << "Trying to open file which does not exist" << endl;
          Matrix m24("ErrorFile", "randomPath");
     }
     catch (runtime_error &e)
     {
          cerr << "Error: " << e.what() << endl;
     }
}
void test()
{

     cout << "One-argument constructor" << endl;
     Matrix m0(6);
     cout << "M0: 6x6" << endl;
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

     cout << "-----get m2(1,1)-----";
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

     m2.store("dane.txt", "C:/Users/kubab/OneDrive/Pulpit/JIPP2/Lab5");
     Matrix m7("dane.txt", "C:/Users/kubab/OneDrive/Pulpit/JIPP2/Lab5");
     cout << "Store ->> read for file (m2)";
     m7.print();
}

int main()
{
     test();
     testErrors();
}
