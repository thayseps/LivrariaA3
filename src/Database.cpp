#include "../include/Database.h" // Inclui o cabeçalho do arquivo Database.h
#include <stdio.h>
#include <conio.h>

using namespace std;

Database::Database()
{
    // Abre o banco de dados "livraria.db"
    int rc = sqlite3_open("livraria.db", &db);
    if (rc)
    {
        cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        cout << "Digite qualquer tecla para continuar";
        getch();
    }
    else
    {
        cout << "Banco de dados aberto com sucesso!" << std::endl;
    }
}

void Database::execute(const std::string& sql)
{
    char* errorMessage;
    // Executa a consulta SQL
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errorMessage);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao executar a consulta: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        cout << "Digite qualquer tecla para continuar";
        getch();
    }
}

vector<Row> Database::query(const string& sql)
{
    vector<Row> result;

    sqlite3_stmt* stmt;
    // Prepara a consulta SQL
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        cout << "Digite qualquer tecla para continuar";
        getch();
        return result;
    }

    int columnCount = sqlite3_column_count(stmt);
    // Repete sobre as linhas retornadas pela consulta
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Row row;
        // Obtém os valores das colunas da linha atual
        for (int i = 0; i < columnCount; ++i)
        {
            const unsigned char* value = sqlite3_column_text(stmt, i);
            if (value)
            {
                row.columns.push_back(reinterpret_cast<const char*>(value));
            }
            else
            {
                row.columns.push_back("NULL");
            }
        }
        result.push_back(row);
    }

    sqlite3_finalize(stmt);
    return result;

}

sqlite3* Database::getDB()
{
    return db;
}

Database::~Database()
{
    // Fecha o banco de dados
    sqlite3_close(db);
    std::cout << "Banco de dados fechado." << std::endl;
}


