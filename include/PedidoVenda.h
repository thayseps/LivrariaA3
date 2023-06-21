#ifndef __PEDIDOVENDA_H_
#define __PEDIDOVENDA_H_

#include "Cliente.h"

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include "../include/Database.h"

class PedidoVenda
{
private:
    Database db;
	int pedidovenda_id;
	int livro_id;
	int qtde;
    int cliente_id;

public:

    PedidoVenda();

	void incluir();

	void mostrar(Row& livro);

	void excluir();

	void alterar();

	void consultar();

	void listarPedidosVenda();
};

#endif // __PEDIDOVENDA_H_
