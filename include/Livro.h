#ifndef __LIVRO_H_
#define __LIVRO_H_

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "../include/Database.h"

using namespace std;

class Livro
{
private:
    Database db;

	int livro_id;

	string tipolivro;

	string editora;

	int min_estoque;

	int max_estoque;

	int qtde_estoque;

	double preco_venda;

public:

    Livro();

    void incluir();

    void mostrar(Row& livro);

	void excluir();

	void alterar();

	void consultar();

	void listar();
};

#endif // __LIVRO_H_
