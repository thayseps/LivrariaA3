#include "../include/Menu.h" // Inclui o cabeçalho do arquivo Menu.h
#include "../include/Livro.h" // Inclui o cabeçalho do arquivo Livro.h
#include "../include/Cliente.h" // Inclui o cabeçalho do arquivo Cliente.h
#include "../include/PedidoVenda.h" // Inclui o cabeçalho do arquivo PedidoVenda.h

#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

Menu::submenuLivro(){
    int escolha = 1;
    int escolhaMax = 6;
    int tecla = 0;
    Livro livro;

    while (true)
    {
        system("cls"); // Limpar a tela
        cout << "===== LIVRO =====" << endl;
        cout << (escolha == 1 ? "> " : "  ") << "Incluir" << endl;
        cout << (escolha == 2 ? "> " : "  ") << "Excluir" << endl;
        cout << (escolha == 3 ? "> " : "  ") << "Alterar" << endl;
        cout << (escolha == 4 ? "> " : "  ") << "Consultar" << endl;
        cout << (escolha == 5 ? "> " : "  ") << "Listar" << endl;
        cout << (escolha == 6 ? "> " : "  ") << "Exit" << endl;
        cout << "================" << endl;
        cout << "Use as setas para navegar, pressione enter para selecionar." << endl;

        tecla = _getch(); // Ler um caractere simples

        if (tecla == 224) // Tecla estendida
        {
            tecla = _getch(); // Pega caractere digitado

            switch (tecla)
            {
                case 72: // Tecla para cima
                    escolha = (escolha == 1) ? escolhaMax : escolha - 1;
                    break;
                case 80: // Tecla para baixo
                    escolha = (escolha == escolhaMax) ? 1 : escolha + 1;
                    break;
            }
        }
        else if (tecla == 13) // Tecla enter
        {
            switch (escolha)
            {
                case 1: // Inclusão
                    livro.incluir();
                    break;
                case 2: // Exclusão
                    livro.excluir();
                    break;
                case 3: // Alteração
                    livro.alterar();
                    break;
                case 4: // Consultar
                    livro.consultar();
                    break;
                case 5: // Listar
                    livro.listar();
                    break;
                case 6:
                    cout << "Saindo do submenu livro..." << endl;
                    return 0;
            }
        }
    }
}

Menu::submenuCliente(){
    int escolha = 1;
    int escolhaMax = 6;
    int tecla = 0;
    Cliente cliente;

    while (true)
    {
        system("cls"); // Limpar a tela
        cout << "===== CLIENTE =====" << endl;
        cout << (escolha == 1 ? "> " : "  ") << "Incluir" << endl;
        cout << (escolha == 2 ? "> " : "  ") << "Excluir" << endl;
        cout << (escolha == 3 ? "> " : "  ") << "Alterar" << endl;
        cout << (escolha == 4 ? "> " : "  ") << "Consultar" << endl;
        cout << (escolha == 5 ? "> " : "  ") << "Listar" << endl;
        cout << (escolha == 6 ? "> " : "  ") << "Exit" << endl;
        cout << "================" << endl;
        cout << "Use as setas para navegar, pressione enter para selecionar." << endl;

        tecla = _getch(); // Ler um caractere simples

        if (tecla == 224) // Tecla estendida
        {
            tecla = _getch(); // Pega caractere digitado

            switch (tecla)
            {
                case 72: // Tecla para cima
                    escolha = (escolha == 1) ? escolhaMax : escolha - 1;
                    break;
                case 80: // Tecla para baixo
                    escolha = (escolha == escolhaMax) ? 1 : escolha + 1;
                    break;
            }
        }
        else if (tecla == 13) // Tecla enter
        {
            switch (escolha)
            {
                case 1: // Inclusão
                    cliente.incluir();
                    break;
                case 2: // Exclusão
                    cliente.excluir();
                    break;
                case 3: // Alteração
                    cliente.alterar();
                    break;
                case 4: // Consultar
                    cliente.consultar();
                    break;
                case 5: // Listar
                    cliente.listar();
                    break;
                case 6:
                    cout << "Saindo do submenu cliente..." << endl;
                    return 0;
            }
        }
    }

}

Menu::submenuPedidoVenda(){
    int escolha = 1;
    int escolhaMax = 6;
    int tecla = 0;
    PedidoVenda pedidoVenda;

    while (true)
    {
        system("cls"); // Limpar a tela
        cout << "===== Pedido =====" << endl;
        cout << (escolha == 1 ? "> " : "  ") << "Incluir" << endl;
        cout << (escolha == 2 ? "> " : "  ") << "Excluir" << endl;
        cout << (escolha == 3 ? "> " : "  ") << "Alterar" << endl;
        cout << (escolha == 4 ? "> " : "  ") << "Consultar" << endl;
        cout << (escolha == 5 ? "> " : "  ") << "Listar" << endl;
        cout << (escolha == 6 ? "> " : "  ") << "Exit" << endl;
        cout << "================" << endl;
        cout << "Use as setas para navegar, pressione enter para selecionar." << endl;

        tecla = _getch(); // Ler um caractere simples

        if (tecla == 224) // Tecla estendida
        {
            tecla = _getch(); // Pega caractere digitado

            switch (tecla)
            {
                case 72: // Tecla para cima
                    escolha = (escolha == 1) ? escolhaMax : escolha - 1;
                    break;
                case 80: // Tecla para baixo
                    escolha = (escolha == escolhaMax) ? 1 : escolha + 1;
                    break;
            }
        }
        else if (tecla == 13) // Tecla enter
        {
            switch (escolha)
            {
                case 1: // Inclusão
                    pedidoVenda.incluir();
                    break;
                case 2: // Excluir
                    pedidoVenda.excluir();
                    break;
                case 3: // Alterar
                    pedidoVenda.alterar();
                    break;
                case 4: // Consultar
                    pedidoVenda.consultar();
                    break;
                case 5: // Listar
                    pedidoVenda.listarPedidosVenda();
                    break;
                case 6:
                    cout << "Saindo do submenu livro..." << endl;
                    return 0;
            }
        }
    }
}


Menu::executar(){
    int escolha = 1;
    int escolhaMax = 4;
    int tecla = 0;

    while (true)
    {
        system("cls"); // Limpar a tela
        cout << "===== MENU =====" << endl;
        cout << (escolha == 1 ? "> " : "  ") << "Livro" << endl;
        cout << (escolha == 2 ? "> " : "  ") << "Cliente" << endl;
        cout << (escolha == 3 ? "> " : "  ") << "Pedido" << endl;
        cout << (escolha == 4 ? "> " : "  ") << "Exit" << endl;
        cout << "================" << endl;
        cout << "Use as setas para navegar, pressione enter para selecionar." << endl;

        tecla = _getch(); // Ler um caractere simples

        if (tecla == 224) // Tecla estendida
        {
            tecla = _getch(); // Pega caractere digitado

            switch (tecla)
            {
                case 72: // Tecla para cima
                    escolha = (escolha == 1) ? escolhaMax : escolha - 1;
                    break;
                case 80: // Tecla para baixo
                    escolha = (escolha == escolhaMax) ? 1 : escolha + 1;
                    break;
            }
        }
        else if (tecla == 13) // Tecla enter
        {
            switch (escolha)
            {
                case 1:
                    // cout << "Opcao 1 selecionada" << endl;
                    submenuLivro();
                    break;
                case 2:
                    submenuCliente();
                    break;
                case 3:
                    submenuPedidoVenda();
                    break;
                case 4:
                    cout << "Saindo do programa ..." << endl;
                    return 0;
            }
        }
    }
}

Menu::Menu(){

}
Menu::~Menu(){

}
