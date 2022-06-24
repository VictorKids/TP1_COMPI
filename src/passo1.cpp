#include "passo1.hpp"

void simbolo::set_label(std::string l){
    this->label = l;
}

void simbolo::set_valor(int v){
    this->valor = v;
}

void simbolo::setvalorlabel(std::string l, int v){
    this->label = l;
    this->valor = v;
}

std::string simbolo::get_label(){
    return this->label;
}

int simbolo::get_valor(){
    return this->valor;
}

tabela_simbolos::tabela_simbolos(){
    simbolo s;
    s.setvalorlabel("PC", 0);
    this->tabela.push_back(s);
    s.setvalorlabel("AC", 0);
    this->tabela.push_back(s);
    s.setvalorlabel("SP", 999);  // ??? n tenho certeza
    this->tabela.push_back(s);
}

void tabela_simbolos::add_na_tabela(simbolo s){
    this->tabela.push_back(s);
}

int tabela_simbolos::busca_na_tabela(std::string str){
    std::vector<simbolo>::iterator it;
    for(it = this->tabela.begin(); it < this->tabela.end(); it++){
        if(it->get_label() == str){
            return it->get_valor();
        }
    }
    return 0;
}

bool tabela_simbolos::estah_na_tabela(std::string str){
    std::vector<simbolo>::iterator it;
    for(it = tabela.begin(); it < tabela.end(); it++){
        if(it->get_label() == str){
            return true;
        }
    }
    return false;
}

std::vector<std::string> separar_string(std::string linha, char deli){
    std::vector<std::string> tokens;
    int inicio = -1;
    int tam = 0;
    for (int i = 0; i < int(linha.size()); i++) {
        if (tam == 0 && linha[i] == deli) {
            continue;

        } else if (linha[i] == deli) {
            tokens.push_back(linha.substr(inicio, tam));
            tam = 0;
            inicio = -1;

        } else if (inicio == -1) {
            inicio = i;
            tam++;

        } else {
            tam++;

        }
    }
    tokens.push_back(linha.substr(inicio, tam));
    return tokens;
}

std::vector<std::string> percorrer1(tabela_simbolos &ts, tabela_instrucoes &ti){
    // objetivo é preencher a tabela de simbolos com labels e pseudo-instru
    std::string linha;
    int ilc = 0;
    int ilc_adder = 0;
    std::vector<std::string> codigo;
    bool eh_pseudo;
    while(getline(std::cin, linha)){
        eh_pseudo = false;
        std::string linha_sem_comnts = separar_string(linha, ';').front();      // remove comentários
        if(int(linha_sem_comnts.find(":")) != -1){                              // checar se tem label

            std::string label = separar_string(linha_sem_comnts, ':').front();  // explode na string
            std::string instr = separar_string(linha_sem_comnts, ':').back();
            std::string operador = separar_string(instr, ' ').front();
            std::string operando = separar_string(instr, ' ').back();

            if(ti.pertence_set(operador)){                                 // é uma pseudo-instrução ?
                eh_pseudo = true;
                if(operador == "WORD"){
                    simbolo s;
                    s.setvalorlabel(label, ilc);
                    ts.add_na_tabela(s);

                    ilc_adder = 1;
                }else if(operador == "END"){
                    break;
                }
            }else if( !(ts.estah_na_tabela(label)) ){                      // se for uma instrução normal, adiciona label na tabela onde valor = ilc atual
                simbolo s;
                s.setvalorlabel(label, ilc);
                ts.add_na_tabela(s);
            }
        }
        if(!eh_pseudo){
            std::string instru = separar_string(separar_string(linha_sem_comnts, ':').back(), ' ').front();
            ilc_adder = ti.get_tamanho(instru);
        }
        ilc = ilc + ilc_adder;         // ilc += espaço da instrução atual (checar tamanho em instrucoes.cpp)
        codigo.push_back(linha);
    }

    std::cout << "MV1 0 999 " << ilc << " ";
    return codigo;
}
