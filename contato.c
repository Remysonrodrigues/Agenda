#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"

    //PARAMETRO (I) ESTRUTURA TIPO 'CONTATO'
    struct contato {
        char nome[81];
        char telefone[21];
        char email[81];
    };

    // PARAMETRO (II) ALOCAR UM TIPO 'CONTATO'
    Contato* contato_cria(char* nome, char* telefone, char* email){

        Contato* c = (Contato*)malloc(sizeof(Contato));
            if(c == NULL){
                printf("ESPAÇO INSUFICEINTE NA MÉMORIA.\n");
                    exit(1);
            }
            strcpy(c->nome , nome);
            strcpy(c->telefone , telefone);
            strcpy(c->email , email);

       return c;

    }
    // PARAMETRO (III) IMPRIME DADOS DE UM 'CONTATO'
    void contato_imprime(Contato* contato){

        if(contato != NULL){

            printf("NOME: %s\nTELEFONE: %s\nE_MAIL: %s\n\n",contato->nome,contato->telefone,contato->email);
        }

    }
    // PARAMETRO (IV) EDITA OS CAMPOS DE UM TIPO 'CONTATO'
    void contato_edita(Contato* contato, char* nome, char* telefone, char* email){

        strcpy(contato->nome , nome);
        strcpy(contato->telefone , telefone);
        strcpy(contato->email , email);

    }
    // PARAMETRO (V) RETORNA 'NOME' DE UM TIPO 'CONTATO'
    char* contato_nome(Contato* contato){

        return contato->nome;

    }
    // PARAMETRO (VI) RETORNA 'TELEFONE' DE UM TIPO 'CONTATO'
    char* contato_telefone(Contato* contato){

        return contato->telefone;

    }
    // PARAMETRO (VII) RETORNA 'EMAIL' DE UM TIPO 'CONTATO'
    char* contato_email(Contato* contato){

        return contato->email;

    }
    // PARAMETRO (VIII) LIBERA O ESPAÇO EM MEMORIA RESERVADO PARA UMA ESTRUTURA DO TIPO 'CONTATO'
    void contato_libera(Contato* contato){

        free(contato);

    }
    //FIM TAD 'CONTATO.C'
