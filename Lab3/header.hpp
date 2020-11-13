#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

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
    Matrix(string filename, string path);
};
