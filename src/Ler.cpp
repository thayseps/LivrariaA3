#include "Ler.h" // Inclui o cabe�alho do arquivo Ler.h

Ler::Ler()
{
  // Construtor padr�o
}

Ler::~Ler()
{
 // Destrutor padr�o

}

int Ler::_int(string prompt)
{
    int valor;
    while (true)
    {
        cout << prompt;
        cin >> valor;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "N�mero inv�lido. Digite um inteiro.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    return valor;
}

double Ler::_double(string prompt, bool maiorquezero)
{
    double valor;
    while (true)
    {
        cout << prompt;
        cin >> valor;

        if (maiorquezero && valor <= 0)
        {
            cout << "Valor deve ser maior ou igual a zero.\n";
        }
        else
        {
            break;
        }
    }

    return valor;
}

string Ler::_string(string prompt, bool obrigatorio)
{
    string valor;

    while (true)
    {
        cout << prompt;
        getline(cin, valor);

        if (obrigatorio && valor.empty())
        {
            cout << "Entrada n�o pode ser vazia. Por favor digite um valor.\n";
        }
        else
        {
            break;
        }
    }

    return valor;
}

string Ler::_opcao(string prompt, vector<string>& opcoes)
{
    bool eureka = false;
    string escolha;

    while (!eureka)
    {
        cout << prompt;
        cin >> escolha;

        for (const string& opcao: opcoes)
        {
            if (escolha == opcao)
            {
                eureka = true;
                break;
            }
        }

        if (!eureka)
        {
            cout << "Op��o inv�lida! Escolha uma op��o v�lida!\n";
        }
    }

    return escolha;
}
