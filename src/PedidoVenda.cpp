#include "../include/PedidoVenda.h" // Inclui o cabeçalho do arquivo PedidoVenda.h
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

struct StrPedidoVenda
{
    int pedidovenda_id;
    int livro_id;
    int qtde;
	int cliente_id;
};

PedidoVenda::PedidoVenda()
{
    // Cria a tabela PEDIDOVENDA no banco de dados, se ela não existir
    db.execute("CREATE TABLE IF NOT EXISTS "
               " PEDIDOVENDA(pedidovenda_id integer primary key, cliente_id integer, livro_id integer, "
                           " qtde integer )");
}

void PedidoVenda::incluir()
{
    StrPedidoVenda pedidoVenda;

    pedidoVenda.pedidovenda_id = Ler::_int("Codigo do pedido: ");
    pedidoVenda.cliente_id = Ler::_int("Codigo do cliente: ");
    pedidoVenda.livro_id = Ler::_int("Codigo do livro: ");
    pedidoVenda.qtde = Ler::_int("Quantidade: ");
    vector<string> opcoes = {"S", "N"};
    string opcao = Ler::_opcao("Deseja gravar os itens acima <S/N>? ", opcoes);

    // Verifica se o usuário escolheu gravar os itens

    if ( opcao == "S" || opcao == "s")
    {
        char buffer[4000];

        sprintf(buffer, "INSERT INTO PEDIDOVENDA( pedidovenda_id, qtde, cliente_id, livro_id)"
                "VALUES( %d, %d, %d, %d ); " ,
                pedidoVenda.pedidovenda_id, pedidoVenda.qtde,
                pedidoVenda.cliente_id, pedidoVenda.livro_id);
        string sql(buffer);
        db.execute(sql);
        // Executa o comando SQL para inserir o pedido no banco de dados
    }
}

void PedidoVenda::mostrar(Row& pedidoVenda)
{
    string rotulos[pedidoVenda.columns.size()] =
    {
        "Código do pedido: ", "Quantidade: ", "Cliente: ", "Livro: "
    };

    for (int i = 0; i < pedidoVenda.columns.size(); i++)
    {
        cout << rotulos[i] << pedidoVenda.columns[i] << endl;
        // Mostra os dados do pedido na tela
    }
}

void PedidoVenda::excluir()
{
    int pedidovenda_id;

    cout << "Digite o codigo do pedido para excluir: ";
    cin >> pedidovenda_id;
    // Lê o código do pedido a ser excluído

    char buffer[4000];
    sprintf( buffer,
             "SELECT pedidovenda_id, qtde, cliente_id, livro_id "
             "FROM PEDIDOVENDA "
             "WHERE pedidovenda_id = %d ", pedidovenda_id );
    string sql(buffer);

    vector<Row> pedidoVenda = db.query(sql);
    // Consulta o pedido no banco de dados


    if (pedidoVenda.empty())
    {
        cout << "Codigo do pedido " << pedidovenda_id << " inexistente!";
        // O pedido não existe no banco de dados
        cout << "Digite qualquer tecla para continuar";
        getch();
    }
    else
    {
        mostrar(pedidoVenda[0]);
        sprintf( buffer,
                 "DELETE FROM PEDIDOVENDA "
                 "WHERE pedidovenda_id = %d ", pedidovenda_id );
        string sql(buffer);

        vector<string> opcoes = {"S", "N", "s", "n"};
        string opcao = Ler::_opcao("Deseja excluir o pedido acima <S/N>? ", opcoes);
        // Lê a opção do usuário para excluir o pedido

        if ( opcao == "S" || opcao == "s")
        // Verifica se o usuário escolheu excluir o pedido
        {
            db.execute(sql); // Executa o comando SQL para excluir o pedido do banco de dados
            cout << "Pedido excluido!";
            cout << "Digite qualquer tecla para continuar";
            getch();
        }
    }
}

void PedidoVenda::alterar()
{
    int pedidovenda_id;

    cout << "Digite o codigo do pedido para alterar: ";
    cin >> pedidovenda_id;
    // Lê o código do pedido a ser alterado

    char buffer[4000];
    sprintf( buffer,
             "SELECT pedidovenda_id, qtde, cliente_id, livro_id "
             "FROM PEDIDOVENDA "
             "WHERE pedidovenda_id = %d ", pedidovenda_id );
    string sql(buffer);

    vector<Row> pedidoVenda = db.query(sql);
    // Consulta o pedido no banco de dados

    if (pedidoVenda.empty())
    {
        cout << "Codigo do pedido " << pedidovenda_id << " inexistente!";
        // O pedido não existe no banco de dados
        cout << "Digite qualquer tecla para continuar";
        getch();
    }
    else
    {
        mostrar(pedidoVenda[0]);
        StrPedidoVenda apedidoVenda;
        // Lê os novos valores
        apedidoVenda.cliente_id = Ler::_int("Cliente: ");
        apedidoVenda.livro_id = Ler::_int("Livro: ");
        apedidoVenda.qtde = Ler::_int("Quantidade: ");
        vector<string> opcoes = {"S", "N"};
        string opcao = Ler::_opcao("Deseja alterar os itens acima <S/N>? ", opcoes);
        // Lê a opção do usuário para alterar os itens

        if ( opcao == "S" || opcao == "s")
        // Verifica se o usuário escolheu alterar os itens
        {
            char buffer[4000];

            sprintf(buffer, "UPDATE PEDIDOVENDA "
                    "SET qtde = %d, cliente_id = %d, livro_id = %d "
                    "WHERE pedidovenda_id = %d ",
                    apedidoVenda.qtde, apedidoVenda.cliente_id,
                    apedidoVenda.livro_id, pedidovenda_id );
            string sql(buffer);
            db.execute(sql);
            // Executa o comando SQL para alterar o pedido no banco de dados
        }
    }

}

void PedidoVenda::consultar()
{
    int pedidovenda_id;

    cout << "Digite o codigo do pedido para consultar: ";
    cin >> pedidovenda_id;
    // Lê o código do pedido a ser consultado

    char buffer[4000];
    sprintf( buffer,
             "SELECT pedidovenda_id, qtde, cliente_id, livro_id "
             "FROM PEDIDOVENDA "
             "WHERE pedidovenda_id = %d ", pedidovenda_id );
    string sql(buffer);

    vector<Row> pedidoVenda = db.query(sql);
    // Consulta o pedido no banco de dados

    if (pedidoVenda.empty())
    {
        cout << "Codigo do pedido " << pedidovenda_id << " inexistente!";
        // O pedido não existe no banco de dados
        cout << "Digite qualquer tecla para continuar";
        getch();
    }
    else
    {
        mostrar(pedidoVenda[0]);
        // Mostra os dados do pedido encontrado
        getch();
    }
}

void PedidoVenda::listarPedidosVenda()
{
    string sql = "SELECT pedidovenda_id, qtde, cliente_id, livro_id "
                 "FROM PEDIDOVENDA "
                 "ORDER BY pedidovenda_id;";

    vector<Row> result = db.query(sql);
    // Consulta todos os pedidos no banco de dados

    if (result.empty())
    {
        cout << "Nao tem pedidos registrados"; // Não há pedidos registrados no banco de dados
    }
    else
    {
        string rotulos[result[0].columns.size()] =
        {
            "Codigo", "Quantidade", "Cliente", "Livro"
        };

        for (int i = 0; i < result[0].columns.size(); i++)
        {
            cout << rotulos[i] << " | ";
            // Mostra os dados de cada pedido na tela
        }

        cout << endl;

        for (const auto& row: result)
        {
            for (const auto& column : row.columns)
            {
                cout << column << " | ";
            }
            cout << endl;
        }
    }

    getch();
}
