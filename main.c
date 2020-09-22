/**
 * @file main.c
 * @author Grupo 22-30 João Pereira , Bruno Teixeira, Rui Vieira, Carlos Ribeiro.
 * @brief Ficheiro principal onde irão ser chamados todos as funcionalidades do projeto
 * @date 27 de Novembro de 2018, 22:24
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Clientes.h"
#include "Viagens.h"
#include "Estruturas.h"
#include "API_Leitura.h"


int main(int argc, char** argv) {

    int contc = 0;
    int tam_max = 0;

    carrega_lancos();


    Cliente *vetor = NULL; //Criar vetor
    
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|             Persistência de dados               |\n");
    printf("|_________________________________________________|\n");
    printf("\n");
    
    ler_dados_cliente(&vetor, &contc, &tam_max);

    menu_principal(&vetor, &contc, &tam_max);

    free(vetor);

    return (EXIT_SUCCESS);
}

