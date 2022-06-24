#include "passo2.hpp"

#include <bits/stdc++.h>

void percorrer2(std::vector<std::string> codigo, tabela_simbolos &ts, tabela_instrucoes &ti){
    int ilc = 0;

    for(std::string loc : codigo){
        std::string linha_sem_comnts = separar_string(loc, ';').front();

        std::string label = separar_string(linha_sem_comnts, ':').front();
        std::string instr = separar_string(linha_sem_comnts, ':').back();

        std::string operador = separar_string(instr, ' ').front();
        std::string operando = separar_string(instr, ' ').back();

        if (ti.pertence_set(operador)) {
            if (operador == "WORD") {
                ilc++;

            }

        } else {
            ilc += ti.get_tamanho(operador);

        }


        if (operador == "WORD") {
            std::cout << (
                ts.busca_na_tabela(operando) != 0 ?
                ts.busca_na_tabela(operando) :
                stoi(operando)) << " ";
        } else {
            std::cout << ti.get_codigo(operador) << " ";

            if (ti.get_tamanho(operador) == 2) {
                std::cout << (
                    ts.busca_na_tabela(operando) != 0 ?
                    ts.busca_na_tabela(operando) - ilc :
                    stoi(operando)
                ) << " ";
            }
        }
    }

    std::cout << std::endl;
}