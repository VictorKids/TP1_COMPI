#include <bits/stdc++.h>
#include "instrucoes.hpp"
#include "passo1.hpp"
#include "passo2.hpp"

int main(void) {
    tabela_instrucoes ti = tabela_instrucoes();
    tabela_simbolos ts = tabela_simbolos();
    std::vector<std::string> codigo = percorrer1(ts, ti);
    percorrer2(codigo, ts, ti);
}