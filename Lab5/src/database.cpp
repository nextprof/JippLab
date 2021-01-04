#include <matrix.hpp>
#include <database.hpp>
sqlite3 *createDB()
{
    sqlite3 *DB;
    int rc = sqlite3_open("db.sqlite", &DB);
    if (rc)
    {
        cerr << "Failed open database - Error: " << sqlite3_errmsg(DB) << endl;
        exit(0);
    }
    else
    {
        cout << "Database opened successfully" << endl;
    }
    return DB;
}

void createTable(sqlite3 *db)
{
    int rc;
    char *messaggeError;
    string sql = "CREATE TABLE IF NOT EXISTS matrices("
                 "matrix_name TEXT PRIMATY KEY, "
                 "n INTEGER NOT NULL, "
                 "m INTEGER NOT NULL, "
                 "data TEXT NOT NULL );";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
    if (rc != SQLITE_OK)
    {
        cerr << "Error create table!" << endl;
        sqlite3_free(messaggeError);
    }
    else
    {
        cout << "Table created Successfully" << endl;
    }
}

int loadMatrixData(void *matrix, int argc, char **argv, char **azColName)
{
    vector<string> *container = (vector<string> *)(matrix);

    container->push_back(argv[1]);
    container->push_back(argv[2]);
    container->push_back(argv[3]);

    return 0;
}