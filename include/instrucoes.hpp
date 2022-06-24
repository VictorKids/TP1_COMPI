#ifndef INSTRUCOES_H
#define INSTRUCOES_H
#include <map>
#include <set>

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
        std::map<std::string, dados_instrucao> tabela_instru;
        std::set<std::string> tabela_pseudo_instru;
    public:
        tabela_instrucoes();
        int get_codigo(std::string instrucao);
        int get_tamanho(std::string instrucao);
        bool pertence_set(std::string pi);
};

#endif