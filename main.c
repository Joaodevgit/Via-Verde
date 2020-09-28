/**
 * @file main.c
 * @author João Pereira
 * @brief Main file where all the project's features will be called
 * @date 27/11/2018 22:24
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Customers.h"
#include "Trips.h"
#include "Structures.h"
#include "API_Leitura.h"


int main(int argc, char** argv) {

    int contc = 0;
    int tam_max = 0;

    carrega_lancos();


    Cliente *vetor = NULL; //Creates the array
    
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|                 Data Persistence                |\n");
    printf("|_________________________________________________|\n");
    printf("\n");
    
    ler_dados_cliente(&vetor, &contc, &tam_max);

    menu_principal(&vetor, &contc, &tam_max);

    free(vetor);

    return (EXIT_SUCCESS);
}

