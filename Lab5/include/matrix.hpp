#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sqlite3/sqlite3.h>
#include <database.hpp>
using namespace std;

#ifndef MATRIX
#define MATRIX

class Matrix
{
    int rows, columns;
    double **matrix;

public:
    Matrix(int r, int c);
    Matrix(int rc);

    void set(int n, int m, double val);
    void print();
    double get(int n, int m);

    Matrix add(Matrix m2);
    Matrix subtract(Matrix m2);
    Matrix multiply(Matrix m2);

    int cols();
    int row();

    void store(string filename, string path);

    void storeDb(sqlite3 *db, string name);

    Matrix(string filename, string path);
    Matrix(sqlite3 *db, string name);

    Matrix operator+(Matrix m2);
    Matrix operator-(Matrix m2);
    Matrix operator*(Matrix m2);
    double *operator[](int nr);
    bool operator==(Matrix m2);
    friend ostream &operator<<(ostream &out, Matrix m);
    void operator++(int);
    void operator++();
    void operator--();
    void operator--(int);
    bool operator<(double less);
    bool operator>(double greater);
};
#endif