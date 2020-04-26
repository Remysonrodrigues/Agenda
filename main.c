#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"
#include "agenda.h"
#include "interacao.h"

#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'

#define TITULO_OPCAO1 "ADICIONA CONTATO"
#define TITULO_OPCAO2 "REMOVER CONTATO"
#define TITULO_OPCAO3 "MODIFICAR CONTATO"
#define TITULO_OPCAO4 "BUSCA CONTATO"
#define TITULO_OPCAO5 "LISTA CONTATO"
#define TITULO_OPCAO6 "SAIR DO PROGRAMA"

#define N_OPCOES 6

int main(void) {

    // VARIAVEIS DE INTERACAO
    char nome[81];
    char telefone[21];
    char email[81];
    // VARIAVEIS DE INTERACAO
    char aux[81];// VETOR 'CHAR' AUXILIAR PARA MODIFICAR NOME
    int interacao = 1;
    int op;
    No* n_teste;

    FILE* fp;
    fp = fopen("Agenda_Contato.txt","rt");//ABERTURA DO ARQUIVO 'AGENDA'
    if(fp == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO !!\n");
            exit(1);
    }
    Agenda agenda_nova;
    agenda_nova = agenda_cria();
    //PASSANDO CONTATOS DO ARQUIVO 'AGENDA.TXT' PARA 'NOVA' DO TIPO 'AGENDA'
    agenda_nova = agenda_carrega(fp);

    while(interacao){

        apresenta_programa("SEJA BEM VINDO AO SEU SOFTWARE AGENDA CONTATOS!" " DESENVOLVIDO POR: Remyson R.");//'MENSAGEM' APRESENTACAO DO PROGRAMA
        apresenta_menu(N_OPCOES, OPCAO1,TITULO_OPCAO1, TITULO_OPCAO2,TITULO_OPCAO3, TITULO_OPCAO4,TITULO_OPCAO5,TITULO_OPCAO6);//APRESENTA O 'MENU'
        op = le_opcao(OPCAO1, OPCAO1 + N_OPCOES - 1);//LÊ OPCAO DIGITADA

        switch(op) {

            //OPCAO ADICIONA CONTATO
            case OPCAO1:

                        printf("\nDIGITE O NOME DO CONTATO: ");
                                strcpy(nome, le_string());
                                //CASO O NOME DO CONTATO JA ESTEJA NA AGENDA
                                while((n_teste = agenda_busca(agenda_nova,nome)) != NULL){

                                        printf("\nNOME JA ESTA SALVO NA AGENDA!!\nDIGITE OUTRO NOME: ");
                                                strcpy(nome, le_string());
                                }

                        printf("DIGITE O TELEFONE DO CONTATO: ");
                                strcpy(telefone, le_string());

                        printf("DIGITE O E-MAIL DO CONTATO: ");
                                strcpy(email, le_string());

                        agenda_nova = agenda_insere(agenda_nova,contato_cria(nome,telefone,email));//ADICIONANDO O NOVO 'CONTATO' NA 'AGENDA'
                        printf("\nCONTATO ADICIONADO COM SUCESSO !\n");
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO REMOVER CONTATO
            case OPCAO2:

                        printf("\nDIGITE O NOME DO CONTATO QUE DESEJA REMOVER: ");
                                strcpy(nome, le_string());

                        n_teste = agenda_busca(agenda_nova,nome);
                        if(n_teste!=NULL){

                            agenda_nova = agenda_remove(agenda_nova,nome);

                        }
                        else{
                            // CASO O CONTATO A SER REMOVIDO NAO ESTEJA NA AGENDA
                            while(n_teste==NULL){

                                printf("\nO CONTATO QUE DEJESA REMOVER NAO EXISTE NA AGENDA !\nDIGITE OUTRO NOME: ");
                                        strcpy(nome, le_string());
                                n_teste = agenda_busca(agenda_nova,nome);
                            }
                            agenda_nova = agenda_remove(agenda_nova,nome);
                        }

                        printf("\nCONTATO REMOVIDO COM SUCESSO !\n");
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO MODIFICAR CONTATO
            case OPCAO3:

                        printf("\nDIGITE O NOME DO CONTATO QUE DEJESA MODIFICAR: ");
                                strcpy(aux, le_string());
                        //VERIFICAR SE O CONTATO ESTA NA AGENDA
                        n_teste = agenda_busca(agenda_nova,aux);
                        while(n_teste==NULL){//'CONTATO' NAO ESTA NA AGENDA


                            printf("\nO CONTATO QUE DESEJA REMOVER NAO EXISTE NA AGENDA !\nDIGITE OUTRO NOME: ");
                                    strcpy(aux, le_string());
                            n_teste = agenda_busca(agenda_nova,aux);

                        }
                        if(n_teste!=NULL){//'CONTATO' ENCONTRADO

                             printf("EDITAR(NOME): ");
                                    strcpy(nome, le_string());

                            printf("EDITAR(TELEFONE): ");
                                    strcpy(telefone, le_string());

                            printf("EDITAR(E-MAIL): ");
                                    strcpy(email, le_string());


                            agenda_edita(n_teste,nome,telefone,email);

                        }

                        printf("\nCONTATO MODIFICADO COM SUCESSO !\n");
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO BUSCA CONTATO
            case OPCAO4:

                        printf("\nDIGITE O NOME DO CONTATO QUE DESEJA BUSCA: ");
                                strcpy(nome, le_string());

                        n_teste = agenda_busca(agenda_nova,nome);
                        if(n_teste==NULL){//'CONTATO' NAO ENCONTRADO

                            limpa_tela();
                            printf("\nO CONTATO QUE BUSCA NAO ESTA NA AGENDA !\n");
                        }
                        else{//'CONTATO' ENCONTRADO

                            printf("\nCONTATO ENCONTRADO COM SUCESSO !\n");
                            imprime(n_teste);
                            system("pause");
                            limpa_tela();

                        }

                        break;

            //OPCAO LISTA CONTATO
            case OPCAO5:

                        limpa_tela();
                        printf("\tAGENDA\n\n");
                        agenda_imprime(agenda_nova);//IMPRIMIR TODOS OS 'CONTATOS' DA 'AGENDA'
                        system("pause");
                        limpa_tela();
                        break;

            //OPCAO DE SAIR DO PROGRAMA
            case OPCAO6:

                    mensagem_despedida("OBRIGADO E ATE LOGO!");//'MENSAGEM' DESPEDIDA DO PROGRAMA
                    interacao = 0;
                    break;

            default:

                    printf("ESTE PROGRAMA POSSUI UM BUG.");//ERRO NO PROGRAMA
                    return 1;
        }
    }

    fp = fopen("Agenda_Contato.txt","wt");//ABERTURA DO ARQUIVO 'AGENDA' NO MODO 'ESCRITA'
    if(fp == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO !!\n");
            exit(1);
    }

    agenda_salva(fp,agenda_nova);//SALVAR AS MODIFICACOES PARA 'ARQUIVO' 'AGENDA'
    fclose(fp);

    return 0;
}

