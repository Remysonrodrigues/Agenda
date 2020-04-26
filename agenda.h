#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

    #include "contato.h"// USO DA ESTRUTURA 'CONTATO'
    //(I) ESTRUTURA TIPO 'NO'
    typedef struct no No;
    //(II) TIPO 'AGENDA' DEFINIDO COMO PONTEIRO PARA TIPO 'NO'
    typedef No* Agenda;
    //(III) FUNCAO QUE CRIA UMA LISTA VAZIA
    Agenda agenda_cria(void);
    //(IV) FUNCAO QUE CARREGA DADOS DE UM ARQUIVO PARA 'AGENDA'
    Agenda agenda_carrega(FILE* fp);
    //(V) FUNCAO QUE INSERE UM 'CONTATO' ORDENADO EM ORDEM ALFABETICA NA 'AGENDA'
    Agenda agenda_insere(Agenda agenda, Contato* contato);
    //(VI) FUNCAO QUE BUSCA UM 'CONTATO' NA 'AGENDA'
    No* agenda_busca(Agenda agenda, char* nome);
    //(VII) FUNCAO QUE REMOVE UM 'CONTATO' DA 'AGENDA'
    Agenda agenda_remove(Agenda agenda, char* nome);
    //(VIII) FUNCAO QUE EDITA OS DADOS DE UM 'CONTATO' CONTIDO NA 'AGENDA'
    void agenda_edita(No* no, char* nome, char* telefone, char* email);
    //(IX) FUNCAO QUE IMPRIME OS DADOS DOS 'CONTATOS' NA 'AGENDA'
    void agenda_imprime(Agenda agenda);
    //(X) FUNCAO QUE SALVA OS DADOS DA 'AGENDA' EM UM ARQUIVO DE TEXTO
    void agenda_salva(FILE* fp, Agenda agenda);
    //FIM TAD 'AGENDA.H'

#endif // AGENDA_H_INCLUDED
