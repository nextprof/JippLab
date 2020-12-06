#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <matrix.hpp>
#include <exception>
#include <sstream>
using namespace std;

Matrix::Matrix(int r, int c)
{
    rows = r;
    columns = c;

    if (r <= 0)
    {
        string errorMsg = "Numbers of rows are less than 1";
        throw invalid_argument(errorMsg);
    }
    if (c <= 0)
    {
        string errorMsg = "Numbers of columns are less than 1";
        throw invalid_argument(errorMsg);
    }
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
    if (rc <= 0)
    {
        string errorMsg = "Numbers of rows or columns are less than 1";
        throw invalid_argument(errorMsg);
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
    if (n < 0 || n > (rows - 1))
    {
        string errorMsg = "Number of row does not exist(set)";
        throw out_of_range(errorMsg);
    }
    if (m < 0 || m > (columns - 1))
    {
        string errorMsg = "Number of column does not exist(set)";
        throw out_of_range(errorMsg);
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
    if (n < 0 || n > (rows - 1))
    {
        string errorMsg = "Number of row does not exist(get)";
        throw out_of_range(errorMsg);
    }
    if (m < 0 || m > (columns - 1))
    {
        string errorMsg = "Numbers of column does not exist(get)";
        throw out_of_range(errorMsg);
    }
    return matrix[n][m];
}

Matrix Matrix::add(Matrix m2)
{
    if ((m2.rows != rows) || (m2.columns != columns))
    {
        stringstream errorMsg;
        errorMsg << "Matrixes are not same size(add)"
                 << "  Size of matrixes:  m1: " << this->rows << "," << this->columns << "   m2: " << m2.rows << "," << m2.columns;
        throw invalid_argument(errorMsg.str());
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
        stringstream errorMsg;
        errorMsg << "Matrixes are not same size(substract)"
                 << "  Size of matrixes:  m1: " << this->rows << "," << this->columns << "   m2: " << m2.rows << "," << m2.columns;
        throw invalid_argument(errorMsg.str());
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
        stringstream errorMsg;
        errorMsg << "Matrix's columns are not equal to matrix-argument's rows(multiply)"
                 << "  Size of matrixes:  m1: " << this->rows << "," << this->columns << "   m2: " << m2.rows << "," << m2.columns;
        throw invalid_argument(errorMsg.str());
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
        stringstream errorMsg;
        errorMsg << fullpath << " file opening to put the matrix in the file - failed";
        throw runtime_error(errorMsg.str());
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
        cout << "The file was successfully saved " << fullpath << endl;
    }
}

Matrix::Matrix(string filename, string path)
{
    ifstream file;
    string fullpath = path + '/' + filename;
    file.open(fullpath, ios_base::in);
    if (file.good() == false)
    {
        stringstream errorMsg;
        errorMsg << fullpath << " file opening to read the matrix from the file - failed";
        throw runtime_error(errorMsg.str());
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
        cout << "The file has been read successfully " << fullpath << endl;
    }
}
