#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "matrix.hpp"
using namespace std;

Matrix::Matrix(int r, int c)
{
    if (r < 1 || c < 1)
    {
        cout << "Blad podczas inicjalizacji macierzy";
        exit(0);
    }
    rows = r;
    columns = c;

    matrix = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int rc)
{
    if (rc < 1)
    {
        cout << "Blad podczas inicjalizacji macierzy";
        exit(0);
    }
    rows = rc;
    columns = rc;
    matrix = new double *[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Matrix::set(int n, int m, double val)
{
    if (n < 0 || m < 0 || n > (rows - 1) || m > (columns - 1))
    {
        cout << "Blad poczas ustawiania wartosci w macierzy(set)";
        exit(1);
    }
    matrix[n][m] = val;
}

void Matrix::print()
{
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

double Matrix::get(int n, int m)
{
    if (n < 0 || m < 0 || n > (rows - 1) || m > (columns - 1))
    {
        cout << "Blad poczas pobierania wartosci z macierzy(get)";
        exit(1);
    }
    return matrix[n][m];
}

Matrix Matrix::add(Matrix m2)
{
    if ((m2.rows != rows) || (m2.columns != columns))
    {
        cout << "Blad podczas dodawania macierzy(add)";
        exit(2);
    }
    Matrix NewMatrix(rows, columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            NewMatrix.matrix[i][j] = this->matrix[i][j] + m2.matrix[i][j];
        }
    }
    return NewMatrix;
}

Matrix Matrix::subtract(Matrix m2)
{
    if ((m2.rows != rows) || (m2.columns != columns))
    {
        cout << "Blad podczas odejmowania macierzy(subtract)";
        exit(2);
    }
    Matrix NewMatrix(rows, columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            NewMatrix.matrix[i][j] = matrix[i][j] - m2.matrix[i][j];
        }
    }
    return NewMatrix;
}

Matrix Matrix::multiply(Matrix m2)
{
    if (columns != m2.rows)
    {
        cout << "Blad wymiarow macierzy (multiply)";
        exit(3);
    }
    Matrix NewMatrix(rows, m2.columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < m2.columns; j++)
        {
            double s = 0;
            for (int k = 0; k < m2.rows; k++)
            {
                s += (matrix[i][k] * m2.matrix[k][j]);
            }
            NewMatrix.matrix[i][j] = s;
        }
    }
    return NewMatrix;
}

int Matrix::cols()
{
    return columns;
}

int Matrix::row()
{
    return rows;
}

void Matrix::store(string filename, string path)
{

    ofstream file;
    string fullpath = path + '/' + filename;
    file.open(fullpath, ios_base::out);
    if (file.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku do zapisu";
    }
    else
    {
        file << rows << " " << columns << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                file << matrix[i][j] << " ";
            }
            file << endl;
        }
        file.close();
        cout << "Udalo sie zapisac plik " << fullpath << endl;
    }
}

Matrix::Matrix(string filename, string path)
{
    ifstream file;
    string fullpath = path + '/' + filename;
    file.open(fullpath, ios_base::in);
    if (file.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku do odczytu";
    }
    else
    {
        file >> rows;
        file >> columns;

        matrix = new double *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new double[columns];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                file >> matrix[i][j];
            }
        }
        file.close();
        cout << "Udalo odczytac sie plik " << fullpath << endl;
    }
}
