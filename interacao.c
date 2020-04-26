#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <conio.h>
#include "interacao.h"

    //PARAMETRO (I) APRESENTA��O DO PROGRAMA
    void apresenta_programa(char* msg){

        printf("\n%s\n\n",msg);

    }
    //PARAMETRO (II) DESPEDIDA DO PROGRAMA
    void mensagem_despedida(char* msg){

        printf("\n%s\n\n",msg);

    }
    //PARAMETRO (III) LIMPA A TELA DE �SUARIO
    void limpa_tela(void){

        system("cls");//FUN��O DA 'STDLIB.H'

    }
    //PARAMETRO (IV) LIMPA O BUFFER DE ENTRADA
    void limpa_buffer(void){

        int valorLido; // VALOR LIDO DEVE SER 'INT'
        do {
            valorLido = getchar();

        } while ((valorLido != '\n') && (valorLido != EOF));

    }
    //PARAMETRO (V) INTERA��O E VALIDA��O DE UMA OP��O DIGITADA PELO �SUARIO
    int le_opcao(int menor_valor, int maior_valor){
    //L� E VALIDA A OP��O DIGITADA PELO USUARIO
         int op;
        while (1) {

            printf("\nDIGITE SUA OPCAO: ");
            op = getchar();

            if (op >= menor_valor && op <= maior_valor) {
                limpa_buffer();
                break;
            }

            else {
                printf("\nOPCAO INVALIDA. TENTE NOVAMENTE.");
                printf("\nA OPCAO DEVE ESTAR ENTRE '%c' E '%c'. \n",menor_valor, maior_valor);
                limpa_buffer();
            }
        }

    return op;

    }
    //PARAMETRO (VI) L� UMA UMA CADEIA DE CARACTERES
    char* le_string(void){

        char string[81];
        scanf(" %80[^\n]",string);
        limpa_buffer();

        return string;

    }
    //PARAMETRO (VII) APRESENTA UM MENU COM N�MERO INDETERMINADO DE OP��ES
    void apresenta_menu(int n_itens, int menor_opcao, ...){

        int i;
        va_list argumentos;
        //INICIA A LISTA DE ARGUMENTO
        va_start(argumentos,menor_opcao);
        //L� CADA ARGUMENTO E IMPRIME NA TELA
        for(i = 0;i < n_itens; ++i){
            printf("%c-%s\n",menor_opcao++,va_arg(argumentos,char *));
        }
        va_end(argumentos);

    }
    // FIM TAD 'INTERACAO.C'
