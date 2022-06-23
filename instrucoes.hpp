#ifndef INSTRUCOES_H
#define INSTRUCOES_H
#include <map>
#include <set>

using namespace std;

    // ***********************************************************
    // *                                                         *
    // * uma classe simples que encapsula dados de uma instrução *
    // *                                                         *
    // ***********************************************************

class dados_instrucao {
    private:
        int codigo;
        int tamanho;
    public:
        void set_dados(int cod, int tam);
        int get_cod();
        int get_tam();
};

    // ************************************************************
    // *                                                          *
    // * uma classe que reune as possíveis instruções do hardware *
    // *                                                          *
    // ************************************************************

class tabela_instrucoes {
    private:
        map<string, dados_instrucao> tabela_instru;
        set<string> tabela_pseudo_instru;
    public:
        tabela_instrucoes();
        int get_codigo(string instrucao);
        int get_tamanho(string instrucao);
        bool pertence_set(string pi);
};

#endif