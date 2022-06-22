#include "instrucoes.hpp"

    void dados_instrucao::set_dados(int cod, int tam){
        this->codigo = cod;
        this->tamanho = tam;
    }

    int dados_instrucao::get_cod(){
        return this->codigo;
    }

    int dados_instrucao::get_tam(){
        return this->tamanho;
    }

    tabela_instrucoes::tabela_instrucoes(){
        dados_instrucao d;
        d.set_dados( 1, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("LOAD" , d));
        d.set_dados( 2, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("STORE", d));
        d.set_dados( 3, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("ADD"  , d));
        d.set_dados( 4, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("SUB"  , d));
        d.set_dados( 5, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("JMP"  , d));
        d.set_dados( 6, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("JPG"  , d));
        d.set_dados( 7, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("JPL"  , d));
        d.set_dados( 8, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("JPE"  , d));
        d.set_dados( 9, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("JPNE" , d));
        d.set_dados( 10, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("PUSH" , d));
        d.set_dados( 11, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("POP"  , d));
        d.set_dados( 12, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("READ" , d));
        d.set_dados( 13, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("WRITE", d));
        d.set_dados( 14, 2);
        this->tabela_instru.insert(pair<string, dados_instrucao>("CALL" , d));
        d.set_dados( 15, 1);
        this->tabela_instru.insert(pair<string, dados_instrucao>("RET"  , d));
        d.set_dados( 16, 1);
        this->tabela_instru.insert(pair<string, dados_instrucao>("HALT" , d));
    }

    int tabela_instrucoes::get_codigo(string instrucao){
        dados_instrucao p = this->tabela_instru[instrucao];
        return p.get_cod();
    }

    int tabela_instrucoes::get_tamanho(string instrucao){
        dados_instrucao p = this->tabela_instru[instrucao];
        return p.get_tam();
    }

