#include "passo1.hpp"

void simbolo::set_label(string l){
    this->label = l;
}

void simbolo::set_valor(int v){
    this->valor = v;
}

void simbolo::setvalorlabel(string l, int v){
    this->label = l;
    this->valor = v;
}

string simbolo::get_label(){
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

int tabela_simbolos::busca_na_tabela(string str){
    vector<simbolo>::iterator it;
    for(it = this->tabela.begin(); it < this->tabela.end(); it++){
        if(it->get_label() == str){
            return it->get_valor();
        }
    }
    return 0;
}

bool tabela_simbolos::estah_na_tabela(string str){
    vector<simbolo>::iterator it;
    for(it = tabela.begin(); it < tabela.end(); it++){
        if(it->get_label() == str){
            return true; 
        }
    }
    return false;
}

vector<string> separar_string(string linha, string deli){
    vector<string> tokens;
    int inicio = 0;
    int fim = linha.find(deli);
    if(fim == -1){
        tokens.push_back(linha);
        return tokens;
    }
    while(fim != -1){
        tokens.push_back(linha.substr(inicio, fim - inicio));
        inicio = fim + deli.size();
        fim = linha.find(deli, inicio);
    }
    return tokens;
}

vector<string> percorrer1(tabela_simbolos *ts, tabela_instrucoes * ti){
    // objetivo é preencher a tabela de simbolos com labels e psedo-instr
    string linha;
    int ilc = 0;
    int ilc_adder = 0;
    vector<string> codigo;
    while(getline(cin, linha)){
        string linha_sem_comnts = separar_string(linha, ";").front();
        if(linha_sem_comnts.find(":") != -1){                             // checar se tem label
            string label = separar_string(linha_sem_comnts, ":").front(); // explode na string
            if( !(ts->estah_na_tabela(label)) ){                           // se tiver, adiciona-la na tabela onde valor = ilc atual
                simbolo s;
                s.setvalorlabel(label, ilc);
                ts->add_na_tabela(s);
            } // NÃO SEI OQ FAZER SE FOR PSEUDO INSTRUÇÃO
        }
        string instru = separar_string(separar_string(linha_sem_comnts, ":").back(), " ").front();
        ilc_adder = ti->get_tamanho(instru);
        ilc = ilc + ilc_adder;         // ilc += espaço da instrução atual (checar tamanho em instrucoes.cpp)
        codigo.push_back(linha);
    }
    return codigo;
}
