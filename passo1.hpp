#ifndef PASSO1_H
#define PASSO1_H
#include <string>
#include <vector>
#include <iterator>
#include "instrucoes.hpp"
#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

    // ***********************************************************
    // *                                                         *
    // * uma classe simples que encapsula dados de um simbolo da *
    // * tabela de simbolos                                      *
    // *                                                         *
    // ***********************************************************

class simbolo {
    private:
        string label;
        int valor;
    public:
        void set_label(string l);
        void set_valor(int v);
        void setvalorlabel(string l, int v);
        string get_label();
        int get_valor();
};

    // *****************************************************
    // *                                                   *
    // * classe que representa a tabela de simbolos e suas *
    // * funcionalidades                                   *
    // *                                                   *
    // *****************************************************

class tabela_simbolos {
    private:
        vector<simbolo> tabela;
    public:
        tabela_simbolos();
        void add_na_tabela(simbolo s);
        int busca_na_tabela(string str);
        bool estah_na_tabela(string str);
};

    // *****************************************************
    // *                                                   *
    // * função principal do passo1 do montador e          *
    // * função de separar a entreda em substrings         *
    // *                                                   *
    // *****************************************************

vector<string> separar_string(string linha, string deli);

vector<string> percorrer1(tabela_simbolos *t);

#endif