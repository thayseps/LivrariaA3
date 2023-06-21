#ifndef __CLIENTE_H_
#define __CLIENTE_H_

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "../include/Database.h"

using namespace std;

class Cliente
{
private:
    Database db;

	int cliente_id;

	string nome;

	string endereco;

	string telefone;

	string email;

	string cpf;

public:

    Cliente();

	void incluir();

    void mostrar(Row& livro);

	void excluir();

	void alterar();

	void consultar();

	void listar();

};

#endif // __CLIENTE_H_

