#include "../include/Cliente.h" // Inclui o cabeçalho do arquivo Cliente.h
#include "../include/Database.h" // Inclui o cabeçalho do arquivo Database.h
#include "../include/Ler.h" // Inclui o cabeçalho do arquivo Ler.h

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <conio.h>
#include <cstdio>

using namespace std;

// Estrutura para representar um cliente
struct StrCliente
{
    int cliente_id;
    string nome;
    string endereco;
    string telefone;
    string email;
    string cpf;
};
// Construtor da classe Cliente
Cliente::Cliente()
{
    // Cria a tabela CLIENTE no banco de dados, se ela não existir
    db.execute("CREATE TABLE IF NOT EXISTS "
               " CLIENTE( cliente_id integer primary key, nome text, endereco text, telefone text, email text, "
               "          cpf text)");
}

// Método para incluir um novo cliente
void Cliente::incluir()
{
    StrCliente cliente;

    // Pede os dados do cliente ao usuário
    cliente.cliente_id = Ler::_int("Codigo do cliente: ");
    cliente.nome = Ler::_string("Nome: ", true);
    cliente.endereco = Ler::_string("Endereco: ", true);
    cliente.telefone = Ler::_string("Telefone: ", true);
    cliente.email = Ler::_string("Email: ", true);
    cliente.cpf = Ler::_string("Cpf: ", true);

    vector<string> opcoes = {"S", "N"};
    string opcao = Ler::_opcao("Deseja gravar os itens acima <S/N>? ", opcoes);

    if ( opcao == "S" || opcao == "s")
    {
        char buffer[4000];

        // Insere os dados do cliente na tabela CLIENTE
        sprintf(buffer, "INSERT INTO CLIENTE( cliente_id, nome, endereco, telefone, email, cpf)"
                "VALUES( %d, '%s', '%s', '%s', '%s', '%s' ); ",
                cliente.cliente_id, cliente.nome.c_str(), cliente.endereco.c_str(), cliente.telefone.c_str(),
                cliente.email.c_str(), cliente.cpf.c_str());
        string sql(buffer);
        db.execute(sql);
    }
}

// Método para mostrar os dados de um cliente
void Cliente::mostrar(Row& cliente)
{
    string rotulos[cliente.columns.size()] =
    {
        "Código do cliente: ", "Nome: ", "Endereco: ", "Telefone: ", "Email: ", "Cpf: "
    };

    for (int i = 0; i < cliente.columns.size(); i++)
    {
        cout << rotulos[i] << cliente.columns[i] << endl;
    }
}

// Método para excluir um cliente
void Cliente::excluir()
{
    int cliente_id;

    cout << "Digite o codigo do cliente para excluir: ";
    cin >> cliente_id;

    char buffer[4000];
    sprintf( buffer,
             "SELECT cliente_id, nome, endereco, telefone, email, cpf "
             "FROM CLIENTE "
             "WHERE cliente_id = %d ", cliente_id );
    string sql(buffer);

    // Verifica se o cliente existe
    vector<Row> cliente = db.query(sql);

    if (cliente.empty())
    {
        cout << "Código do cliente " << cliente_id << " inexistente!";
        cout << "Digite qualquer tecla para continuar";
        getch();
    }
    else
    {
        // Exibe os dados do cliente
        mostrar(cliente[0]);
        sprintf( buffer,
                 "DELETE FROM CLIENTE "
                 "WHERE cliente_id = %d ", cliente_id );
        string sql(buffer);

        vector<string> opcoes = {"S", "N", "s", "n"};
        string opcao = Ler::_opcao("Deseja excluir o cliente acima <S/N>? ", opcoes);

        if ( opcao == "S" || opcao == "s")
        {
            // Executa a exclusão do cliente
            db.execute(sql);
            cout << "Cliente excluido!";
            cout << "Digite qualquer tecla para continuar";
            getch();
        }
    }
}

// Método para alterar os dados de um cliente
void Cliente::alterar()
{
    int cliente_id;

    cout << "Digite o código do cliente para alterar: ";
    cin >> cliente_id;

    char buffer[4000];
    sprintf( buffer,
             "SELECT cliente_id, nome, endereco, telefone, email, cpf "
             "FROM CLIENTE "
             "WHERE cliente_id = %d ", cliente_id );
    string sql(buffer);

    // Verifica se o cliente existe
    vector<Row> cliente = db.query(sql);

    if (cliente.empty())
    {
        cout << "Código do cliente " << cliente_id << " inexistente!";
        cout << "Digite qualquer tecla para continuar";
        getch();
    }
    else
    {
        // Exibe os dados do cliente
        mostrar(cliente[0]);
        StrCliente acliente;
        acliente.nome = Ler::_string("Nome: ", true);
        acliente.endereco = Ler::_string("Endereco: ", true);
        acliente.telefone = Ler::_string("Telefone: ", true);
        acliente.email = Ler::_string("Email: ", true);
        acliente.cpf = Ler::_string("Cpf: ", true);
        vector<string> opcoes = {"S", "N"};
        string opcao = Ler::_opcao("Deseja alterar os itens acima <S/N>? ", opcoes);

        if ( opcao == "S" || opcao == "s")
        {
            char buffer[4000];

            // Atualiza os dados do cliente na tabela CLIENTE
            sprintf(buffer, "UPDATE CLIENTE "
                    "SET nome = '%s', endereco = '%s', telefone = '%s', "
                    " email = '%s', cpf = '%s' "
                    "WHERE cliente_id = %d ",
                    acliente.nome.c_str(), acliente.endereco.c_str(), acliente.telefone.c_str(),
                    acliente.email.c_str(), acliente.cpf.c_str(), acliente.cliente_id );
            string sql(buffer);
            db.execute(sql);
        }
    }

}

// Método para consultar os dados de um cliente
void Cliente::consultar()
{
    int cliente_id;

    cout << "Digite o código do cliente para consultar: ";
    cin >> cliente_id;

    char buffer[4000];
    sprintf( buffer,
             "SELECT cliente_id, nome, endereco, telefone, email, cpf "
             "FROM CLIENTE "
             "WHERE cliente_id = %d ", cliente_id );
    string sql(buffer);

    // Verifica se o cliente existe
    vector<Row> cliente = db.query(sql);

    if (cliente.empty())
    {
        cout << "Código do cliente " << cliente_id << " inexistente!";
        cout << "Digite qualquer tecla para continuar";
        getch();
    }
    else
    {
        // Exibe os dados do cliente
        mostrar(cliente[0]);
        getch();
    }
}

// Método para listar todos os clientes
void Cliente::listar()
{
    string sql = "SELECT cliente_id, nome, endereco, telefone, email, cpf "
                 "FROM CLIENTE "
                 "ORDER BY cliente_id;";

    // Consulta todos os clientes
    vector<Row> result = db.query(sql);

    if (result.empty())
    {
        cout << "Nao tem clientes registrados";
    }
    else
    {
        string rotulos[result[0].columns.size()] =
        {
            "Codigo", "Nome", "Endereco", "Telefone", "Email", "CPF"
        };

        for (int i = 0; i < result[0].columns.size(); i++)
        {
            cout << rotulos[i] << " | ";
        }

        cout << endl;

        // Exibe os dados de cada cliente
        for (const auto& row: result)
        {
            for (const auto& column : row.columns)
            {
                std::cout << column << " | ";
            }
            std::cout << std::endl;
        }
    }

    getch();
}
