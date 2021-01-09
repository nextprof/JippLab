#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <matrix.hpp>
#include <database.hpp>

using namespace std;

void testErrors(sqlite3 *db)
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
     try
     {
          cout << "Loading matrix which does not exist" << endl;
          Matrix(db, "matrixOOPS");
     }
     catch (runtime_error &e)
     {
          cout << "Error: " << e.what() << endl;
     }

     try
     {
          cout << "Trying to add matrixes with operator + with not same size" << endl;
          Matrix m40(4, 4);
          Matrix m41(5, 5);
          Matrix m42 = m40 + m41;
     }
     catch (invalid_argument &e)
     {
          cout << "Error: " << e.what() << endl;
     }

     try
     {
          cout << "Trying to substract matrixes with operator - with not same size" << endl;
          Matrix m43(4, 4);
          Matrix m44(5, 5);
          Matrix m45 = m43 - m44;
     }
     catch (invalid_argument &e)
     {
          cout << "Error: " << e.what() << endl;
     }
     try
     {
          cout << "Trying to store row with too high index with [] operator" << endl;
          Matrix m46(4, 4);
          double *testerr = m46[4];
     }
     catch (invalid_argument &e)
     {
          cout << "Error: " << e.what() << endl;
     }
}
void test(sqlite3 *db)
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
     cout << "Store ->> read from file (m2)";
     m7.print();

     Matrix m30(4, 5);

     double xx = 1;
     for (int i = 0; i < m30.row(); i++)
     {
          for (int j = 0; j < m30.cols(); j++)
          {
               m30.set(i, j, xx);
               xx += 0.2;
          }
     }
     m30.storeDb(db, "matrixnr1");
     Matrix m31(db, "matrixnr1");
     cout << "Stored ->> readed from db (m30)";
     m30.print();

     Matrix m32(4, 4);
     for (int i = 0; i < m32.row(); i++)
     {
          for (int j = 0; j < m32.cols(); j++)
          {
               m32.set(i, j, xx);
               xx += 0.2;
          }
     }
     Matrix m33(4, 4);
     for (int i = 0; i < m33.row(); i++)
     {
          for (int j = 0; j < m33.cols(); j++)
          {
               m33.set(i, j, xx);
               xx += 0.2;
          }
     }

     cout << "Testing operator +" << endl
          << "first matrix:" << endl;
     m32.print();
     cout << "Second matrix: " << endl;
     m33.print();
     cout << "And result of addition" << endl;

     Matrix m34 = m33 + m32;
     m34.print();

     Matrix m35(4, 4);
     for (int i = 0; i < m35.row(); i++)
     {
          for (int j = 0; j < m35.cols(); j++)
          {
               m35.set(i, j, xx);
               xx += 0.2;
          }
     }
     Matrix m36(4, 4);
     for (int i = 0; i < m36.row(); i++)
     {
          for (int j = 0; j < m36.cols(); j++)
          {
               m36.set(i, j, xx);
               xx -= 0.2;
          }
     }
     cout << endl
          << "Testing operator -" << endl
          << "first matrix:" << endl;
     m35.print();
     cout << "Second matrix: " << endl;
     m36.print();
     cout << "And result of substraction" << endl;

     Matrix m37 = m35 - m36;
     m37.print();
     cout << "Testing operator []" << endl
          << "Matrix:" << endl;
     m35.print();
     cout << "Trying to save matrix[2]-3rd row" << endl;
     double *testoperator = m35[2];
     for (int i = 0; i < m35.cols(); i++)
          cout << testoperator[i] << " ";
}

int main()
{
     sqlite3 *db = createDB();
     createTable(db);

     test(db);

     testErrors(db);
}
