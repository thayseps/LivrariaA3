#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <string>

using namespace std;

struct Row {
    vector<string> columns;
};

class Database
{
private:
    sqlite3* db;

public:
    Database();

    void execute(const string& sql);
    vector<Row> query(const string& sql);

    sqlite3* getDB();

    ~Database();
};

#endif // DATABASE_H
