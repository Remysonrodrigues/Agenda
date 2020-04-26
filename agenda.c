#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#include "contato.h"

    //PARAMETRO (I) ESTRUTURA TIPO 'NO'
    struct no {
        Contato* info;//TIPO 'CONTATO'
        struct no* prox;

    };
    //PARAMETRO (III) CRIA UMA LISTA VAZIA
    Agenda agenda_cria(void){

        return NULL;

    }
    //PARAMETRO (IV) CARREGAR DADOS DE UM ARQUIVO PARA 'AGENDA'
    Agenda agenda_carrega(FILE* fp){

        Agenda agenda_novo = agenda_cria();


        char nome[81];
        char telefone[21];
        char email[81];
        while(fscanf(fp, " %80[^\n] %20[^\n] %80[^\n]", nome, telefone, email)!= EOF){
             No* novo_c = (No*)malloc(sizeof(No));
             Contato* c;
             c = contato_cria(nome, telefone, email);
             novo_c->info = c;

             No* ant = NULL;
             No* aux = agenda_novo;

             while(aux != NULL && strcmp(contato_nome(aux->info),contato_nome(c)) < 0){

                ant = aux;
                aux = ant->prox;
            }

            novo_c = (No*)malloc(sizeof(No));
            novo_c->info = c;

            if(ant == NULL){

                novo_c->prox = agenda_novo;
                agenda_novo = novo_c;
            }
            else{

                novo_c->prox = ant->prox;
                ant->prox = novo_c;
            }

        }

        return agenda_novo;

        }

    //PARAMETRO (V) INSERE UM 'CONTATO' ORDENADO EM ORDEM ALFABETICA NA 'AGENDA'
    Agenda agenda_insere(Agenda agenda, Contato* contato){

        No* novo = (No*)malloc(sizeof(No));
        novo->info = contato;
        No* ant = NULL;
        No* p = agenda;

            while(p != NULL && strcmp(contato_nome(p->info),contato_nome(contato)) < 0){

                ant = p;
                p = p->prox;
            }

            if(ant == NULL){

                novo->prox = agenda;
                agenda = novo;
            }
            else{

                novo->prox = ant->prox;
                ant->prox = novo;
            }
        return agenda;

    }
    //PARAMETRO (VI) BUSCA UM 'CONTATO' NA 'AGENDA'
    No* agenda_busca(Agenda agenda, char* nome){

         No* p = agenda;
            for(p = agenda;p != NULL ;p = p->prox)
                    if(strcmp(contato_nome(p->info),nome) == 0)
                        return p;

            return NULL;//NÃO ACHOU O ELEMENTO

    }
    //PARAMETRO (VII) REMOVE UM 'CONTATO' DA 'AGENDA'
    Agenda agenda_remove(Agenda agenda, char* nome){

        No* ant = NULL;
        No* p = agenda;

            while(p != NULL && strcmp(contato_nome(p->info),nome)!= 0){

                ant = p;
                p = p->prox;
            }
            if(p == NULL)
                return agenda; //NÃO ACHOU

            if(ant == NULL){
                agenda = p->prox;
            }
            else{
                ant->prox = p->prox;
            }
            free(p);
            return agenda;

    }
    //PARAMETRO (VIII) EDITAR OS DADOS DE UM 'CONTATO' CONTIDO NA 'AGENDA'
    void agenda_edita(No* no, char* nome, char* telefone, char* email){

        contato_edita(no->info,nome,telefone,email);

    }
    //PARAMETRO (IX) IMPRIME OS DADOS DOS 'CONTATOS' NA 'AGENDA'
    void agenda_imprime(Agenda agenda){

            No* p = NULL;

            if(agenda!=NULL){

                for(p = agenda;p != NULL;p = p->prox){
                        contato_imprime(p->info);
                }
            }
            else{

                printf("A AGENDA ESTA VAZIA !!\n");
            }

    }
    //PARAMETRO (X) SALVA OS DADOS DA 'AGENDA' EM UM ARQUIVO DE TEXTO
    void agenda_salva(FILE* fp, Agenda agenda){

        char nome[81];
        char telefone[21];
        char email[81];

        No* aux = agenda;
        while(aux!=NULL){

                strcpy(nome,contato_nome(aux->info));
                strcpy(telefone,contato_telefone(aux->info));
                strcpy(email,contato_email(aux->info));
                //COPIANDO PARA ARQUIVO 'AGENDA'
                fprintf(fp,"%s\n%s\n%s\n",nome,telefone,email);
                aux = aux->prox;
        }

    }
    //PARAMETRO (AUX) IMPRIMIR A INFORMACAO DE UM 'NO'
    void imprime(Agenda agenda){

        No* c = agenda;
        contato_imprime(c->info);
    }

    // FIM TAD 'AGENDA.C'
