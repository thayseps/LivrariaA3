#ifndef LER_H
#define LER_H

#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

class Ler
{
    public:
        Ler();
        virtual ~Ler();
        static int _int(string prompt);
        static double _double(string prompt, bool maiorquezero);
        static string _string(string prompt, bool obrigatorio);
        static string _opcao(string prompt, vector<string>& opcoes);
};

#endif // LER_H
