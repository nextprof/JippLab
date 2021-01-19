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

void Matrix::storeDb(sqlite3 *db, string name)
{
    stringstream sql;
    char *messaggeError;
    int rc;

    sql << "INSERT INTO matrices ('matrix_name', 'n', 'm', 'data') ";
    sql << "VALUES ('" << name << "','" << this->rows << "','" << this->columns << "', '";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            sql << matrix[i][j] << ' ';

    sql << "');";

    string sqlstring = sql.str();
    rc = sqlite3_exec(db, sqlstring.c_str(), NULL, 0, &messaggeError);
    if (rc != SQLITE_OK)
    {
        stringstream errorMsg;
        errorMsg << "matrix: " << name << " - Store failed.";
        cerr << "Error create table!" << endl;
        sqlite3_free(messaggeError);
        throw(runtime_error(errorMsg.str()));
    }
    else
    {
        cout << "Matrix " << name << " stored successfully" << endl;
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
Matrix::Matrix(sqlite3 *db, string name)
{
    int rc;
    char *messaggeError;
    stringstream sql;
    vector<string> container;
    sql << "SELECT * FROM matrices WHERE matrix_name == '" << name << "'";
    string sqlstring = sql.str();

    rc = sqlite3_exec(db, sqlstring.c_str(), loadMatrixData, &container, &messaggeError);
    if (rc != SQLITE_OK)
    {
        stringstream errorMsg;
        errorMsg << "matrix: " << name << " - Loading failed.";
        throw(runtime_error(errorMsg.str()));
    }
    else
    {
        if (container.empty())
        {
            stringstream errorMsg;
            errorMsg << "matrix: " << name << " Not found.";
            throw(runtime_error(errorMsg.str()));
        }
        else
        {
            cout << "Matrix: " << name << " loaded succesfully" << endl;
        }
    }

    string nRows = container[0];
    string mCols = container[1];
    stringstream values(container[2]);

    this->rows = atoi(nRows.c_str());
    this->columns = atoi(mCols.c_str());

    matrix = new double *[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];

        for (int j = 0; j < columns; j++)
        {
            string bufor;
            values >> bufor;

            matrix[i][j] = atof(bufor.c_str());
        }
    }
}

Matrix Matrix::operator+(Matrix m2)
{
    if ((m2.rows != this->rows) || (m2.columns != this->columns))
    {
        stringstream errorMsg;
        errorMsg << "Matrixes are not same size(add)"
                 << "  Size of matrixes:  m1: " << this->rows << "," << this->columns << "   m2: " << m2.rows << "," << m2.columns;
        throw invalid_argument(errorMsg.str());
    }
    int n = this->rows;
    int m = this->columns;
    Matrix newMatrix(n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            newMatrix.matrix[i][j] = this->matrix[i][j] + m2.matrix[i][j];

    return newMatrix;
}
Matrix Matrix::operator-(Matrix m2)
{
    if ((m2.rows != this->rows) || (m2.columns != this->columns))
    {
        stringstream errorMsg;
        errorMsg << "Matrixes are not same size(substrct)"
                 << "  Size of matrixes:  m1: " << this->rows << "," << this->columns << "   m2: " << m2.rows << "," << m2.columns;
        throw invalid_argument(errorMsg.str());
    }
    int n = this->rows;
    int m = this->columns;
    Matrix newMatrix(n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            newMatrix.matrix[i][j] = this->matrix[i][j] - m2.matrix[i][j];

    return newMatrix;
}
double *Matrix::operator[](int nr)
{
    if (nr >= this->rows)
    {
        stringstream errorMsg;
        errorMsg << "Number of matrix's rows are less than returned row" << endl;
        errorMsg << "Argument: " << nr << endl;
        errorMsg << "Number of matrix's rows: " << this->rows << endl
                 << "[" << this->rows - 1 << "]"
                 << "is the highest index" << endl;
        throw invalid_argument(errorMsg.str());
    }
    else if (nr <= 0)
    {
        stringstream errorMsg;
        errorMsg << "Number of recieved matrix should be greater than 0" << endl;
        errorMsg << "Argument: " << nr << endl;
        throw invalid_argument(errorMsg.str());
    }
    return this->matrix[nr];
}

Matrix Matrix::operator*(Matrix m2)
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
bool Matrix::operator==(Matrix m2)
{
    if ((m2.rows != this->rows) || (m2.columns != this->columns))
    {
        stringstream errorMsg;
        errorMsg << "Matrixes are not same size(COMPARE ==)"
                 << "  Size of matrixes:  m1: " << this->rows << "," << this->columns << "   m2: " << m2.rows << "," << m2.columns;
        throw invalid_argument(errorMsg.str());
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (matrix[i][j] != m2.matrix[i][j])
                return false;

    return true;
}
ostream &operator<<(ostream &out, Matrix m)
{
    out << m.cols() << " " << m.row() << endl;
    for (int i = 0; i < m.cols(); i++)
    {
        for (int j = 0; j < m.row(); j++)
            out << m.get(i, j) << ' ';
        out << endl;
    }
    return out;
}
void Matrix::operator++(int)
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            matrix[i][j]++;
        }
    }
}

void Matrix::operator++()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            matrix[i][j]++;
        }
    }
}

void Matrix::operator--(int)
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            matrix[i][j]--;
        }
    }
}

void Matrix::operator--()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            matrix[i][j]--;
        }
    }
}
bool Matrix::operator<(double less)
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            if (matrix[i][j] > less)
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator>(double greater)
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            if (matrix[i][j] < greater)
            {
                return false;
            }
        }
    }
    return true;
}
