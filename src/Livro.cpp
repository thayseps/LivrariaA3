#include "../include/Livro.h" // Inclui o cabe�alho do arquivo Livro.h
#include "../include/Database.h" // Inclui o cabe�alho do arquivo Database.h
#include "../include/Ler.h" // Inclui o cabe�alho do arquivo Ler.h

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <conio.h>
#include <cstdio>

using namespace std;

struct StrLivro
{
    int livro_id;
    string titulo;
    string autor;
    string tipolivro;
    string editora;
    int min_estoque;
    int max_estoque;
    int qtde_estoque;
    double preco_venda;
};

Livro::Livro()
{
    db.execute("CREATE TABLE IF NOT EXISTS "
               " LIVRO( livro_id integer primary key, titulo text, autor text, tipolivro text, editora text, "
               " min_estoque integer, max_estoque integer, qtde_estoque integer, "
               " preco_venda numeric)");
}

void Livro::incluir()
{
    StrLivro livro;

    livro.livro_id = Ler::_int("C�digo do livro: ");
    livro.titulo = Ler::_string("T�tulo: ", true);
    livro.autor = Ler::_string("Autor: ", true);
    livro.tipolivro = Ler::_string("Tipo de livro: ", true);
    livro.editora = Ler::_string("Editora: ", true);
    livro.min_estoque = Ler::_int("Estoque m�nimo: ");
    livro.max_estoque = Ler::_int("Estoque m�ximo: ");
    livro.qtde_estoque = Ler::_int("Quantidade de estoque: ");
    livro.preco_venda = Ler::_double("Pre�o de venda: ", true);

    vector<string> opcoes = {"S", "N"};
    string opcao = Ler::_opcao("Deseja gravar os itens acima <S/N>? ", opcoes);

    if ( opcao == "S" || opcao == "s")
    {
        char buffer[4000];

        sprintf(buffer, "INSERT INTO LIVRO( livro_id, titulo, autor, tipolivro, editora, min_estoque, max_estoque, qtde_estoque, preco_venda )"
                "VALUES( %d, '%s', '%s', '%s', '%s', %d, %d, %d, %f ); ",
                livro.livro_id, livro.titulo.c_str(), livro.autor.c_str(), livro.tipolivro.c_str(), livro.editora.c_str(),
                livro.min_estoque, livro.max_estoque, livro.qtde_estoque, livro.preco_venda);
        string sql(buffer);
        db.execute(sql);
        // Executa a inser��o dos dados no banco de dados
    }
}

void Livro::mostrar(Row& livro)
{
    string rotulos[livro.columns.size()] =
    {
        "C�digo do livro: ", "T�tulo: ", "Autor: ", "Tipo de livro: ", "Editora: ",
        "Estoque m�nimo: ", "Estoque m�ximo: ", "Quantidade de estoque: ", "Pre�o de venda: "
    };

    for (int i = 0; i < livro.columns.size(); i++)
    {
        // Mostra os dados do livro na tela
        cout << rotulos[i] << livro.columns[i] << endl;
    }
}

void Livro::excluir()
{
    int livro_id;

    // Solicita o c�digo do livro a ser exclu�do
    cout << "Digite o c�digo do livro para excluir: ";
    cin >> livro_id;

    char buffer[4000];
    sprintf( buffer,
             "SELECT livro_id, titulo, autor, tipolivro, editora, min_estoque, max_estoque, qtde_estoque, preco_venda "
             "FROM LIVRO "
             "WHERE livro_id = %d ", livro_id );
    string sql(buffer);

    vector<Row> livro = db.query(sql);

    if (livro.empty())
    {
        // Mensagem de erro se o livro n�o existir
        cout << "C�digo do livro " << livro_id << " inexistente!";
        cout << "Digite qualquer tecla para continuar";
        getch();
    }
    else
    {
         // Mostra os detalhes do livro encontrado
        mostrar(livro[0]);
        sprintf( buffer,
                 "DELETE FROM LIVRO "
                 "WHERE livro_id = %d ", livro_id );
        string sql(buffer);

        vector<string> opcoes = {"S", "N", "s", "n"};
        string opcao = Ler::_opcao("Deseja excluir o livro acima <S/N>? ", opcoes);

        if ( opcao == "S" || opcao == "s")
        {
            // Executa a exclus�o do livro
            db.execute(sql);
            cout << "Livro exclu�do!";
            cout << "Digite qualquer tecla para continuar";
            getch();
        }
    }
}


void Livro::alterar()
{
    int livro_id;

    // Solicita o c�digo do livro a ser alterado
    cout << "Digite o c�digo do livro para alterar: ";
    cin >> livro_id;

    char buffer[4000];
    sprintf( buffer,
             "SELECT livro_id, titulo, autor, tipolivro, editora, min_estoque, max_estoque, qtde_estoque, preco_venda "
             "FROM LIVRO "
             "WHERE livro_id = %d ", livro_id );
    string sql(buffer);

    vector<Row> livro = db.query(sql);

    if (livro.empty())
    {
        // Mensagem de erro se o livro n�o existir
        cout << "C�digo do livro " << livro_id << " inexistente!";
        cout << "Digite qualquer tecla para continuar";
        getch();
    }
    else
    {
        // Mostra os detalhes do livro encontrado
        mostrar(livro[0]);
        StrLivro alivro;
        alivro.livro_id = stoi(livro[0].columns[0]);
        alivro.titulo = Ler::_string("T�tulo: ", true);
        alivro.autor = Ler::_string("Autor: ", true);
        alivro.tipolivro = Ler::_string("Tipo de livro: ", true);
        alivro.editora = Ler::_string("Editora: ", true);
        alivro.min_estoque = Ler::_int("Estoque m�nimo: ");
        alivro.max_estoque = Ler::_int("Estoque m�ximo: ");
        alivro.qtde_estoque = Ler::_int("Quantidade de estoque: ");
        alivro.preco_venda = Ler::_double("Pre�o de venda: ", true);

        vector<string> opcoes = {"S", "N"};
        string opcao = Ler::_opcao("Deseja alterar os itens acima <S/N>? ", opcoes);

        if ( opcao == "S" || opcao == "s")
        {
            char buffer[4000];

            sprintf(buffer, "UPDATE LIVRO "
                    "SET titulo = '%s', autor = '%s', tipolivro = '%s', "
                    " editora = '%s', min_estoque = %d, max_estoque = %d, qtde_estoque = %d, "
                    " preco_venda  = %f "
                    "WHERE livro_id = %d ",
                    alivro.titulo.c_str(), alivro.autor.c_str(), alivro.tipolivro.c_str(), alivro.editora.c_str(),
                    alivro.min_estoque, alivro.max_estoque, alivro.qtde_estoque, alivro.preco_venda, alivro.livro_id);
            string sql(buffer);
            db.execute(sql);
            // Executa a altera��o dos dados do livro
        }
    }

}

void Livro::consultar()
{
    int livro_id;

    cout << "Digite o c�digo do livro para consultar: ";
    cin >> livro_id;
    // Solicita o c�digo do livro a ser consultado

    char buffer[4000];
    sprintf( buffer,
             "SELECT livro_id, titulo, autor, tipolivro, editora, min_estoque, max_estoque, qtde_estoque, preco_venda "
             "FROM LIVRO "
             "WHERE livro_id = %d ", livro_id );
    string sql(buffer);

    vector<Row> livro = db.query(sql);

    if (livro.empty())
    {
        cout << "C�digo do livro " << livro_id << " inexistente!";
        getch();
        // Mensagem de erro se o livro n�o existir
    }
    else
    {
        // Mostra os detalhes do livro encontrado
        mostrar(livro[0]);
        getch();
    }
}

// Mostra os livros cadastrados
void Livro::listar()
{
    string sql = "SELECT livro_id, titulo, autor, tipolivro, editora, min_estoque, max_estoque, qtde_estoque, preco_venda "
                 "FROM LIVRO "
                 "ORDER BY livro_id;";

    vector<Row> result = db.query(sql);

    if (result.empty())
    {
        cout << "Nao tem livros registrados";
    }
    else
    {
        string rotulos[result[0].columns.size()] =
        {
            "C�digo", "T�tulo", "Autor", "Tipo", "Editora",
            "Est M�n", "Est Max", "Qtde", "Pre�o"
        };

        for (int i = 0; i < result[0].columns.size(); i++)
        {
            cout << rotulos[i] << " | ";
        }

        cout << endl;

        for (const auto& row: result)
        {
            for (const auto& column : row.columns)
            {
                std::cout << column << " | ";
                 // Mostra os dados dos livros
            }
            std::cout << std::endl;
        }
    }

    getch();
}
