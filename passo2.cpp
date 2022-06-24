void percorrer2(vector<string> codigo, tabela_simbolos *ts, tabela_instrucoes *ti){
    
    for(string loc : codigo){
        
        string linha_sem_comnts = separar_string(linha, ";").front();      
        if(linha_sem_comnts.find(":") != -1){                              
            string label = separar_string(linha_sem_comnts, ":").front();  
            string instr = separar_string(linha_sem_comnts, ":").back();
            string operador = separar_string(instr, " ").front();
            int operando = stoi(separar_string(instr, " ").back());

            if(ti->pertence_set(operador)){                                 
                eh_pseudo = true;
                if(operador == "WORD"){
                     
                }else if(operador == "END"){
                    break;
                }
            }else if( !(ts->estah_na_tabela(label)) ){                      
                simbolo s;
                s.setvalorlabel(label, ilc);
                ts->add_na_tabela(s);
            }
        }
        if(!eh_pseudo){
        string instru = separar_string(separar_string(linha_sem_comnts, ":").back(), " ").front();
        ilc_adder = ti->get_tamanho(instru);
        }
        ilc = ilc + ilc_adder;         
        codigo.push_back(linha);
    }
}
    
    /* 
    pesquisar na tabela de pseudos (if)
    tomar as ações referentes as pseudos (then)
    pesquisar na tabela de instruções (else if)
    pegar dados sobre a instrução (then)
    eval
    cout
    mudar contador
    */
    
    
    
    
    
    
}
