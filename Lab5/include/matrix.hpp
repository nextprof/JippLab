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
};
#endif