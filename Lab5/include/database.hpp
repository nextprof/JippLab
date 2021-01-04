#include <sqlite3/sqlite3.h>
#include <vector>
#ifndef DATABASE_HPP
#define DATABASE_HPP
sqlite3 *createDB();
void createTable(sqlite3 *db);
void insertData(sqlite3 *db);
int loadMatrixData(void *data, int argc, char **argv, char **azColName);
#endif
