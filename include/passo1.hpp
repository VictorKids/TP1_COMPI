#ifndef PASSO1_H
#define PASSO1_H
#include <string>
#include <vector>
#include <iterator>
#include "instrucoes.hpp"
#include <iostream>
//#include <bits/stdc++.h>

    // ***********************************************************
    // *                                                         *
    // * uma classe simples que encapsula dados de um simbolo da *
    // * tabela de simbolos                                      *
    // *                                                         *
    // ***********************************************************

class simbolo {
    private:
        std::string label;
        int valor;
    public:
        void set_label(std::string l);
        void set_valor(int v);
        void setvalorlabel(std::string l, int v);
        std::string get_label();
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
        std::vector<simbolo> tabela;
    public:
        tabela_simbolos();
        void add_na_tabela(simbolo s);
        int busca_na_tabela(std::string str);
        bool estah_na_tabela(std::string str);
};

    // *****************************************************
    // *                                                   *
    // * função principal do passo1 do montador e          *
    // * função de separar a entreda em substrings         *
    // *                                                   *
    // *****************************************************

std::vector<std::string> separar_string(std::string linha, char deli);

std::vector<std::string> percorrer1(tabela_simbolos &ts, tabela_instrucoes &ti);

#endif