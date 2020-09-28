/**
 * @file Trips.c
 * @author João Pereira
 * @brief Trips Management
 * @date 27/11/2018
 *
 * File where a set of functions related to trips management are implemented
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "API_Leitura.h"
#include "Customers.h"
#include "Trips.h"

// Structures that hold the matrices of the 4 classes of a vehicle

Lanco matrizA1_c1[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c2[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c3[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c4[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_pts[NUM_PORTAGENS][NUM_PORTAGENS];

/**
 * @brief This function serves as the "TUI interface" of the 2nd main menu option (Trip Management)
 */
void Ecra_gestao_viagens() {
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|                  Trip Management                         |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Add Trip                                        |\n");
    printf("|     2 -> Toll Links Management                           |\n");
    printf("|     3 -> Search For Trip                                 |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Back To Main Menu                               |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 1st option of the Trip Management menu (Add Trip)
 */
void Ecra_acrecentar_viagem() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|                   Adding Trip                   |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 2nd Trip Management menu option (Toll Sections Management)
 */
void Ecra_gestao_lancos() {
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|                 Toll Links Management                    |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Consult Links (Distance-Price on A1)            |\n");
    printf("|     2 -> Edit Toll Links Price                           |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Back To Main Menu                               |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 3rd Trip Management menu option (Search For Trip)
 */
void Ecra_pesquisa_viagem() {
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|                       Search For Trip                    |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Vehicle                                         |\n");
    printf("|     2 -> Link                                            |\n");
    printf("|     3 -> Date                                            |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Back To Main Menu                               |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 1st option of the Toll Links Management (Consult Links (Distance-Price on A1))
 */
void Ecra_consulta_distancias_precos_classes_A1() {
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|          Distance-Price of Links (Classes A1)            |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Class 1                                         |\n");
    printf("|     2 -> Class 2                                         |\n");
    printf("|     3 -> Class 3                                         |\n");
    printf("|     4 -> Class 4                                         |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Back To Main Menu                               |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 2nd option of the Toll Links Management (Edit Toll Links Price)
 */
void Ecra_gestao_precos() {
    printf(" ______________________________________________________________ \n");
    printf("|                                                              |\n");
    printf("|                     Price Management                         |\n");
    printf("|                                                              |\n");
    printf("|     1 -> Edit price of a given pair of tolls                 |\n");
    printf("|     2 -> Edit price for the entire A1                        |\n");
    printf("|                                                              |\n");
    printf("|     0 -> Back To Main Menu                                   |\n");
    printf("|______________________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 1st Price Management menu option (Edit price of a given pair of tolls)
 */
void Ecra_edicao_parportico_preco() {
    printf(" ______________________________________________________________\n");
    printf("|                                                              |\n");
    printf("|            Edit price of a given pair of tolls               |\n");
    printf("|                                                              |\n");
    printf("|     1 -> Class 1                                             |\n");
    printf("|     2 -> Class 2                                             |\n");
    printf("|     3 -> Class 3                                             |\n");
    printf("|     4 -> Class 4                                             |\n");
    printf("|                                                              |\n");
    printf("|     0 -> Back To Main Menu                                   |\n");
    printf("|______________________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 2nd Price Management menu option (Edit the price for the entire A1)
 */
void Ecra_edicao_geral_precos() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|        Edit the price for the entire A1         |\n");
    printf("|                                                 |\n");
    printf("|     1 -> Class 1                                |\n");
    printf("|     2 -> Class 2                                |\n");
    printf("|     3 -> Class 3                                |\n");
    printf("|     4 -> Class 4                                |\n");
    printf("|                                                 |\n");
    printf("|     0 -> Back To Main Menu                      |\n");
    printf("|_________________________________________________|\n");
}

/**
 * Function that returns the position in which the customer occurs given his id
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param id customer ID to search
 * @return customer index, if it exists, or -1 if not
 */
int pesquisa_id_viagens(Cliente *vetor, int num_clientes, int id) {

    int i = 0;

    while (i < num_clientes && vetor[i].id != id)
        i++;

    if (i == num_clientes)
        return -1;
    else
        return i;
}

/**
 * Function that returns the position in which the customer occurs given the month of trip
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param mês month of the trip the customer took
 * @return customer index, if it exists, or -1 if not
 */
int pesquisa_mes_viagens(Cliente *vetor, int num_clientes, int id, short mes) {//This function was created to generate the invoice

    int i = 0, pos;

    pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("O cliente não existe!");
    } else {

        while (i < vetor[pos].num_viagens && vetor[pos].viagem_cliente[i].dataEntrada.mes != mes)
            i++;


        if (i == vetor[pos].num_viagens)
            return -1;
        else
            return i;
    }
}

/**
 * Function that prints all vehicles registrations that have been entered by the user so far
 *  
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 */
void imprime_matriculas_existentes(Cliente* vetor, int num_clientes) {
    printf("Vehicles registrations already created:\n");
    if (num_clientes == 0) {
        printf("There is no vehicle registration created so far\n");
    } else {
        for (int i = 0; i < num_clientes; i++) {
            printf("%s\n", vetor[i].veiculo_cliente.matricula);
        }
    }
}

/**
 * Function that prints all customer IDs already entered by the user so far
 *  
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 */
void imprime_id_existentes(Cliente* vetor, int num_clientes) {
    printf("IDs already created:\n");

    if (num_clientes == 0) {
        printf("There is no ID created so far\n");
    } else {
        for (int i = 0; i < num_clientes; i++) {
            printf("%d\n", vetor[i].id);
        }
    }
}

/**
 * Function that returns the position in which the customer occurs given the registration of the customer's vehicle
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param matricula registration of the customer's vehicle to be searched
 * @return customer index, if it exists, or -1 if not
 */
int pesquisa_viagem_matricula(Cliente * vetor, int num_clientes, char matricula[MAX_MAT]) {
    int i = 0;

    while (i < num_clientes && strcmp(vetor[i].veiculo_cliente.matricula, matricula) != 0)
        i++;

    if (i == num_clientes)
        return -1;

    else
        return i;
}

/**
 * Function that prints a customer's trip information given his registration vehicle number
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param matricula registration of the customer's vehicle to be searched
 */
void pesquisa_viagem_veiculo(Cliente * vetor, int num_clientes, char matricula[MAX_MAT]) {

    int pos = pesquisa_viagem_matricula(vetor, num_clientes, matricula);

    if (pos == -1) {
        printf("Vehicle registration does not exist!\n");
    } else {
        if (vetor[pos].num_viagens == 0) {
            printf("The customer hasn't made any trips yet!\n");
        } else {
            int j;
            printf("Trips taken at vehicle registration %s: \n", matricula);
            for (j = 0; j < vetor[pos].num_viagens; j++) {
                printf("Trip no.%d: \n", j + 1);
                printf("\n");
                printf("Entrance Toll: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoEntrada);
                printf("Exit Toll: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoSaida);
                printf("Trip Date: %hd/%hd/%hd\n", vetor[pos].viagem_cliente[j].dataEntrada.dia,
                        vetor[pos].viagem_cliente[j].dataEntrada.mes
                        , vetor[pos].viagem_cliente[j].dataEntrada.ano);
                printf("Exit Time: %hd:%hd\n", vetor[pos].viagem_cliente[j].horaSaida.hora, vetor[pos].viagem_cliente[j].horaSaida.minutos);
                switch (vetor[pos].veiculo_cliente.classe) {
                    case 1:printf("Trip cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 2:printf("Trip cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 3:printf("Trip cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 4:printf("Trip cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);

                        break;
                }
                printf("\n");
            }
        }
    }
}

/**
 * Function that returns the position where the client occurs given a pair of tolls
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param id customer ID (to determine the position of the array where the customer made the trips)
 * @param num_entrada entrance toll number
 * @param num_saida entrance toll number
 * @return 
 */
int pesquisa_viagem_lanco(Cliente * vetor, int num_clientes, int id, short num_entrada, short num_saida) {
    int i = 0, pos;

    pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("The customer does not exist!");
    } else {

        while (i < vetor[pos].num_viagens && (vetor[pos].viagem_cliente[i].info_lanco.porticoEntrada != num_entrada &&
                vetor[pos].viagem_cliente[i].info_lanco.porticoSaida != num_saida))
            i++;

        if (i == vetor[pos].num_viagens)
            return -1;
        else
            return i;
    }
}

/**
 * Function that prints a customer's trip information given a pair of tolls
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param id customer ID (to determine the position of the array where the customer made the trips)
 * @param num_entrada entrance toll number
 * @param num_saida entrance toll number
 */
void pesquisa_viagem_par_porticos(Cliente * vetor, int num_clientes, int id, short num_entrada, short num_saida) {

    int pos = pesquisa_viagem_lanco(vetor, num_clientes, id, num_entrada, num_saida);

    if (pos == -1) {
        printf("The customer has not yet traveled on this date!\n");
    } else {
        if (vetor[pos].num_viagens == 0) {
            printf("The customer hasn't made any trips yet!\n");
        } else {
            int j;
            printf("Trips made by the client in the tolls %hd-%hd: \n", num_entrada, num_saida);
            for (j = 0; j < vetor[pos].num_viagens; j++) {
                printf("Trip no.%d: \n", j + 1);
                printf("\n");
                printf("Entrance Toll: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoEntrada);
                printf("Exit Toll: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoSaida);
                printf("Trip Date: %hd/%hd/%hd\n", vetor[pos].viagem_cliente[j].dataEntrada.dia,
                        vetor[pos].viagem_cliente[j].dataEntrada.mes
                        , vetor[pos].viagem_cliente[j].dataEntrada.ano);
                printf("Exit Time: %hd:%hd\n", vetor[pos].viagem_cliente[j].horaSaida.hora, vetor[pos].viagem_cliente[j].horaSaida.minutos);
                switch (vetor[pos].veiculo_cliente.classe) {
                    case 1:printf("Trip cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 2:printf("Trip cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 3:printf("Trip cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 4:printf("Trip cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);

                        break;
                }
                printf("\n");
            }
        }
    }
}

/**
 * Function that returns the position in which the customer occurs given the date of trip
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param id customer ID (to determine the position of the array where the customer made the trips)
 * @param ano year of the trip
 * @param mes month of the trip
 * @param dia day of the trip
 * @return customer index, if it exists, or -1 if not
 */
int pesquisa_data_viagens(Cliente *vetor, int num_clientes, int id, short ano, short mes, short dia) {

    int i = 0, pos;

    pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("The customer does not exist!");
    } else {

        while (i < vetor[pos].num_viagens && (vetor[pos].viagem_cliente[i].dataEntrada.ano != ano &&
                vetor[pos].viagem_cliente[i].dataEntrada.mes != mes &&
                vetor[pos].viagem_cliente[i].dataEntrada.dia != dia))
            i++;


        if (i == vetor[pos].num_viagens)
            return -1;
        else
            return i;
    }
}

/**
 * Function that prints a customer's trip information given a date
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param id customer ID (to determine the position of the array where the customer made the trips)
 * @param ano year of the trip
 * @param mes month of the trip
 * @param dia day of the trip
 */
void pesquisa_viagem_data(Cliente * vetor, int num_clientes, int id, short ano, short mes, short dia) {

    int pos = pesquisa_data_viagens(vetor, num_clientes, id, ano, mes, dia);

    if (pos == -1) {
        printf("The customer has not yet traveled on this date!\n");
    } else {
        if (vetor[pos].num_viagens == 0) {
            printf("The customer hasn't made any trips yet!\n");
        } else {
            int j;
            printf("Trips taken on the date %hd/%hd/%hd: \n", dia, mes, ano);
            for (j = 0; j < vetor[pos].num_viagens; j++) {
                printf("Trip no.%d: \n", j + 1);
                printf("\n");
                printf("Entrance Toll: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoEntrada);
                printf("Exit Toll: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoSaida);
                printf("Trip Date: %hd/%hd/%hd\n", vetor[pos].viagem_cliente[j].dataEntrada.dia,
                        vetor[pos].viagem_cliente[j].dataEntrada.mes
                        , vetor[pos].viagem_cliente[j].dataEntrada.ano);
                printf("Exit Time: %hd:%hd\n", vetor[pos].viagem_cliente[j].horaSaida.hora, vetor[pos].viagem_cliente[j].horaSaida.minutos);
                switch (vetor[pos].veiculo_cliente.classe) {
                    case 1:printf("Trip Cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 2:printf("Trip Cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 3:printf("Trip Cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 4:printf("Trip Cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);

                        break;
                }
                printf("\n");
            }
        }
    }
}

/**
 * Function that serves as a menu of search features corresponding to the 
 * "TUI interface" 3rd option of the Trip Management menu
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 */
void menu_gestao_pesquisa_viagens(Cliente *vetor, int num_clientes) {

    int o, id, pos;
    char matricula[MAX_MAT];
    short num_entrada, num_saida, dia, ano, mes;

    do {
        do {
            Ecra_pesquisa_viagem();
            readInt(&o, 0, 3, "Enter option number: ");
        } while (o < 0 || o > 3);
        switch (o) {
            case 1:
                imprime_matriculas_existentes(vetor, num_clientes);
                readString(matricula, MAX_MAT - 1, "Enter the vehicle registration number: ");
                pesquisa_viagem_veiculo(vetor, num_clientes, matricula);
                break;
            case 2:
                imprime_id_existentes(vetor, num_clientes);
                readInt(&id, 1, 1000, "Enter the customer ID to search for the trip: ");
                pos = pesquisa_id_clientes(vetor, num_clientes, id);
                if (pos == -1) {
                    printf("The customer does not exist!\n");
                } else {
                    readShort(&num_entrada, 1, 6, "Enter the entrance toll: ");
                    readShort(&num_saida, 1, 6, "Enter the exit toll: ");
                    pesquisa_viagem_par_porticos(vetor, num_clientes, id, num_entrada, num_saida);
                }
                break;
            case 3:
                imprime_id_existentes(vetor, num_clientes);
                readInt(&id, 1, 1000, "Enter the customer ID to search for the trip: ");
                pos = pesquisa_id_clientes(vetor, num_clientes, id);
                if (pos == -1) {
                    printf("The customer does not exist!\n");
                } else {
                    readShort(&dia, 1, 31, "Enter the day of the trip to search: ");
                    readShort(&mes, 1, 12, "Enter the month of the trip to search: ");
                    readShort(&ano, 2017, 2019, "Enter the year of the trip to search: ");
                    pesquisa_viagem_data(vetor, num_clientes, id, ano, mes, dia);
                }
                break;
            default: printf("You have chosen to return to the previous menu \n");
        }
    } while (o != 0);
}

/**
 * Função que preenche uma matriz quadrada de lado NUM_PORTAGENS com o
 * conteúdo do ficheiro especificado. A função pode ser utilizada para preencher
 * a matriz de distâncias ou a matriz de pontos.
 * 
 * @param matriz A matriz a preencher, que deve ser previamente alocada
 * @param ficheiro O ficheiro de onde vão ser lidos os dados
 * @param distancia Indica se será preenchida a matriz de distâncias ou de pontos
 * @return Indica se a função terminou com sucesso
 */
bool preencheMatrizpontos(Lanco *matriz, char *ficheiro, bool distancia) {
    FILE * fp;
    char * linha = NULL;
    size_t len = 0;
    const char s[] = "\t\n\0";
    char *token;
    int i = 0, j = 0;

    fp = fopen(ficheiro, "r");
    if (fp == NULL)
        return false;

    while ((getline(&linha, &len, fp)) != -1) {
        j = 0;
        token = strtok(linha, s);

        if (distancia) matriz[i * NUM_PORTAGENS + j].dist = atof(token);
        else matriz[i * NUM_PORTAGENS + j].pontos = atof(token);

        j++;
        while (token != NULL) {
            token = strtok(NULL, s);

            if (token != NULL) {
                if (distancia) matriz[i * NUM_PORTAGENS + j].dist = atof(token);
                else matriz[i * NUM_PORTAGENS + j].pontos = atof(token);
            }
            j++;
        }
        i++;
    }

    fclose(fp);
    if (linha)
        free(linha);

    return true;
}

/**
 * Function that fills a square matrix with size NUM_PORTAGENS with the content 
 * of the specified file. The function can be used to fill the distance matrix 
 * or the price matrix.
 * 
 * @param matriz the matrix to be filled, which must be previously allocated
 * @param ficheiro the file from which the data will be read
 * @param distancia indicates whether the distance or price matrix will be filled
 * 
 * @return Indicates whether the function ended successfully or not
 */
bool preencheMatriz(Lanco *matriz, char *ficheiro, bool distancia) {
    FILE * fp;
    char * linha = NULL;
    size_t len = 0;
    const char s[] = "\t\n\0";
    char *token;
    int i = 0, j = 0;

    fp = fopen(ficheiro, "r");
    if (fp == NULL)
        return false;

    while ((getline(&linha, &len, fp)) != -1) {
        j = 0;
        token = strtok(linha, s);

        if (distancia) matriz[i * NUM_PORTAGENS + j].dist = atof(token);
        else matriz[i * NUM_PORTAGENS + j].preco = atof(token);

        j++;
        while (token != NULL) {
            token = strtok(NULL, s);

            if (token != NULL) {
                if (distancia) matriz[i * NUM_PORTAGENS + j].dist = atof(token);
                else matriz[i * NUM_PORTAGENS + j].preco = atof(token);
            }
            j++;
        }
        i++;
    }

    fclose(fp);
    if (linha)
        free(linha);

    return true;
}

/**
 * Function that prints the distance-price matrix of each tolls link
 * 
 * @param matriz where they will be stored the values of distance and price of tolls link
 */
void imprime_matrizdistancias_precos_A1(Lanco matriz[NUM_PORTAGENS][NUM_PORTAGENS]) {

    int i, j;

    printf("Toll no. :        1                  2               3                4               5               6\n");
    for (i = 0; i < NUM_PORTAGENS; i++) {
        for (j = 0; j < NUM_PORTAGENS; j++) {

            if (j == 0)
                printf("    %d         ", i + 1);

            printf("%0.1f - %0.1f \t", matriz[i][j].dist, matriz[i][j].preco);
        }
        printf("\n");
    }
    printf("\nLabel:\n");
    printf("1-Lisboa \t 2-Santarém \t 3-Leiria \t 4-Coimbra \t 5-Albergaria-a-velha \t 6-Porto \t\n");
}

/**
 * Function that loads the distance-price matrices of each vehicle class
 */
void carrega_lancos() {

    preencheMatriz((Lanco*) matrizA1_c1, "A1distancia.txt", true);
    preencheMatriz((Lanco*) matrizA1_c1, "A1classe1.txt", false);

    preencheMatriz((Lanco*) matrizA1_c2, "A1distancia.txt", true);
    preencheMatriz((Lanco*) matrizA1_c2, "A1classe2.txt", false);

    preencheMatriz((Lanco*) matrizA1_c3, "A1distancia.txt", true);
    preencheMatriz((Lanco*) matrizA1_c3, "A1classe3.txt", false);

    preencheMatriz((Lanco*) matrizA1_c4, "A1distancia.txt", true);
    preencheMatriz((Lanco*) matrizA1_c4, "A1classe4.txt", false);

    preencheMatrizpontos((Lanco*) matrizA1_pts, "A1pontos.txt", false);
}

/**
 * Function that serves as a menu to the interface (Ecra_consulta_distancias_precos_classes_A1)
 * that prints the distance-price of sections of the 4 classes of A1 vehicles
 */
void menu_consulta_lancos() {
    int o;

    do {
        do {
            Ecra_consulta_distancias_precos_classes_A1();
            readInt(&o, 0, 4, "Enter option number: ");
        } while (o < 0 || o > 4);
        switch (o) {
            case 1://Function that fills and prints A1 class-price distances on the console (already imported in txt in the project folder)
                printf(" ___________________________________________________________________________________________________________\n");
                printf("|                                                                                                           |\n");
                printf("|                   Table of distance-prices between the tolls on the A1 (KM - €) Class 1                   |\n");
                printf("|___________________________________________________________________________________________________________|\n");
                printf("\n");
                imprime_matrizdistancias_precos_A1(matrizA1_c1);
                break;
            case 2://Function that prints A1 class 2 price distances on the console
                printf(" ___________________________________________________________________________________________________________\n");
                printf("|                                                                                                           |\n");
                printf("|                  Table of distance-prices between the tolls on the A1 (KM - €) Class 2                    |\n");
                printf("|___________________________________________________________________________________________________________|\n");
                printf("\n");
                imprime_matrizdistancias_precos_A1(matrizA1_c2);
                break;
            case 3://Function that prints A1 class 3 price distances on the console
                printf(" ___________________________________________________________________________________________________________\n");
                printf("|                                                                                                           |\n");
                printf("|                   Table of distance-prices between the tolls on the A1 (KM - €) Class 3                   |\n");
                printf("|___________________________________________________________________________________________________________|\n");
                printf("\n");
                imprime_matrizdistancias_precos_A1(matrizA1_c3);
                break;
            case 4://Function that prints A1 class 4 price distances on the console
                printf(" ___________________________________________________________________________________________________________\n");
                printf("|                                                                                                           |\n");
                printf("|                   Table of distance-prices between the tolls on the A1 (KM - €) Class 4                   |\n");
                printf("|___________________________________________________________________________________________________________|\n");
                printf("\n");
                imprime_matrizdistancias_precos_A1(matrizA1_c4);
                break;
            default: printf("You have chosen to return to the previous menu \n");
        }
    } while (o != 0);
}

/**
 * This function adds trips to a given customer already created in the customer array
 *
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param id customer id that you want to add a particular trip
 */
void adicionar_viagem(Cliente *vetor, int num_clientes, int id) {

    int pos = pesquisa_id_viagens(vetor, num_clientes, id); //Checks whether the customer exists through the id

    if (pos == -1) {
        printf("The customer does not exist!\n");
    } else {
        Cliente *cliente = vetor + pos; //increments an array position

        Viagem * viagem = cliente->viagem_cliente + cliente->num_viagens;

        readShort(&viagem->info_lanco.porticoEntrada, 1, 6, "Enter the number of the entrance toll (1 to 6): ");
        readShort(&viagem->info_lanco.porticoSaida, 1, 6, "Enter the number of the exit toll (1 to 6): ");
        while (viagem->info_lanco.porticoEntrada == viagem->info_lanco.porticoSaida) {
            if (viagem->info_lanco.porticoEntrada == viagem->info_lanco.porticoSaida) {
                printf("Error there is no price for this toll link (Entrance toll = Exit toll)!");
            }
            readShort(&viagem->info_lanco.porticoEntrada, 1, 6, "Enter the entry toll number again: ");
            readShort(&viagem->info_lanco.porticoSaida, 1, 6, "Enter the exit toll number again: ");
        }
        int pts;
        pts = adicao_pontos_viaverde(vetor, num_clientes, viagem->info_lanco.porticoEntrada,
                viagem->info_lanco.porticoSaida, vetor[pos].id);

        printf("%d Via Verde points were added to the customer!\n Total customer points: %hd\n", pts, vetor[pos].num_ptsviaverde);
        switch (vetor[pos].veiculo_cliente.classe) {
            case 1:viagem->info_lanco.custo = matrizA1_c1[viagem->info_lanco.porticoEntrada - 1][viagem->info_lanco.porticoSaida - 1].preco;
                break;
            case 2:viagem->info_lanco.custo = matrizA1_c2[viagem->info_lanco.porticoEntrada - 1][viagem->info_lanco.porticoSaida - 1].preco;
                break;
            case 3:viagem->info_lanco.custo = matrizA1_c3[viagem->info_lanco.porticoEntrada - 1][viagem->info_lanco.porticoSaida - 1].preco;
                break;
            case 4:viagem->info_lanco.custo = matrizA1_c4[viagem->info_lanco.porticoEntrada - 1][viagem->info_lanco.porticoSaida - 1].preco;

                break;
        }
        velocidade_lanco(vetor, num_clientes, cliente->num_viagens, vetor[pos].id, vetor[pos].veiculo_cliente.velocidade);

        printf("The vehicle speed between the %hd and %hd toll is: %d km/h", viagem->info_lanco.porticoEntrada,
                viagem->info_lanco.porticoSaida, vetor[pos].veiculo_cliente.velocidade);
        readShort(&viagem->dataEntrada.ano, 2017, 2019, "Enter year: ");
        readShort(&viagem->dataEntrada.mes, 1, 12, "Enter month: ");
        readShort(&viagem->dataEntrada.dia, 1, 31, "Enter entrance day: ");
        readShort(&viagem->horaSaida.hora, 0, 23, "Enter exit time: ");
        readShort(&viagem->horaSaida.minutos, 0, 59, "Enter the minutes of departure:");
        cliente->num_viagens++;
        printf("\n");
        printf("Trip added successfully!\n");
        escrever_dados_cliente(vetor, num_clientes);
    }
}

/**
 * Function that lists all trips made (so far) by a specific customer (New Feature)
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param id id of the client who wants to consult his trip history
 */
void historico_viagens(Cliente *vetor, int num_clientes, int id) {

    int pos = pesquisa_id_viagens(vetor, num_clientes, id); //Verificar se o cliente existe através do id

    if (pos == -1) {
        printf("The customer does not exist!\n");
    } else {
        int j;

        for (j = 0; j < vetor[pos].num_viagens; j++) {

            printf("Customer ID: %d\n", vetor[pos].id);
            printf("Customer Name: %s\n", vetor[pos].nome);
            printf("Nº do cartão de cidadão: %s\n", vetor[pos].num_CC);
            printf("Via Verde points: %hd\n", vetor[pos].num_ptsviaverde);
            printf("Entrance Toll: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoEntrada);
            printf("Exit Toll: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoSaida);
            printf("Trip Date: %hd/%hd/%hd\n", vetor[pos].viagem_cliente[j].dataEntrada.dia,
                    vetor[pos].viagem_cliente[j].dataEntrada.mes
                    , vetor[pos].viagem_cliente[j].dataEntrada.ano);
            printf("Exit Time: %hd:%hd\n", vetor[pos].viagem_cliente[j].horaSaida.hora, vetor[pos].viagem_cliente[j].horaSaida.minutos);
            switch (vetor[pos].veiculo_cliente.classe) {
                case 1: printf("Trip Cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                    break;
                case 2:printf("Trip Cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);

                    break;
                case 3:printf("Trip Cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                    break;
                case 4:printf("Trip Cost: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);

                    break;
            }
            printf("Velocity when passing through the tolls link: %d", vetor[pos].veiculo_cliente.velocidade);
            printf("\n");
        }
    }
}

/**
 * Function that edits all prices in the matrix of all pairs of tolls for a given class
 * 
 * @param novo_entrada entry toll number to edit
 * @param novo_saida exit toll number to edit
 */
void menu_edicao_par_portico_preco(short novo_entrada, short novo_saida) {

    int i, j, o;

    do {
        do {
            Ecra_edicao_parportico_preco();
            readInt(&o, 0, 4, "Enter the class of vehicles you want to edit: ");
        } while (o < 0 || o > 4);
        switch (o) {
            case 1:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i + 1 == novo_entrada && j + 1 == novo_saida) {
                            printf("Enter the new price between toll %d to %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c1[i][j].preco, 0, 1000, "");
                        }
                    }
                }
                FILE *file1;
                file1 = fopen("A1classe1.txt", "wt"); // creates the pretended file

                if (file1 == NULL) {
                    printf("ERROR!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file1, "%f\t", matrizA1_c1[i][j].preco); //fills in the file the matrix previously created
                        }
                        fprintf(file1, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c1, "A1classe1.txt", false);
                    fclose(file1);
                }
                printf("Price between the link of the toll %hd to the toll %hd changed successfully!\n", novo_entrada, novo_saida);
                break;
            case 2:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i + 1 == novo_entrada && j + 1 == novo_saida) {
                            printf("Enter the new price between toll %d to %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c2[i][j].preco, 0, 1000, "");
                        }
                    }
                }
                FILE *file2;
                file2 = fopen("A1classe2.txt", "wt"); //creates the pretended file

                if (file2 == NULL) {
                    printf("ERROR!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file2, "%f\t", matrizA1_c2[i][j].preco); //fills in the file the matrix previously created
                        }
                        fprintf(file2, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c2, "A1classe2.txt", false);
                    fclose(file2);
                }
                printf("The price of the link of all the tolls changed successfully!\n");
                break;
            case 3:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i + 1 == novo_entrada && j + 1 == novo_saida) {
                            printf("Enter the new price between toll %d to %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c3[i][j].preco, 0, 1000, "");
                        }
                    }
                }
                FILE *file3;
                file3 = fopen("A1classe3.txt", "wt"); //creates the pretended file

                if (file3 == NULL) {
                    printf("ERROR!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file3, "%f\t", matrizA1_c3[i][j].preco); //fills in the file the matrix previously created
                        }
                        fprintf(file3, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c3, "A1classe3.txt", false);
                    fclose(file3);
                }
                printf("The price of the link of all the tolls changed successfully!\n\n");
                break;
            case 4:;
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i + 1 == novo_entrada && j + 1 == novo_saida) {
                            printf("Enter the new price between toll %d to %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c4[i][j].preco, 0, 1000, "");
                        }
                    }
                }
                FILE *file4;
                file4 = fopen("A1classe4.txt", "wt"); //creates the pretended file

                if (file4 == NULL) {
                    printf("ERRO!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file4, "%f\t", matrizA1_c4[i][j].preco); //fills in the file the matrix previously created
                        }
                        fprintf(file4, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c4, "A1classe4.txt", false);
                    fclose(file4);
                }
                printf("The price of the link of all the tolls changed successfully!\n");
                break;
            default: printf("You have chosen to return to the previous menu\n");
        }
    } while (o != 0);
}

/**
 * Function that edits all the prices of all the pairs of tolls present in a matrix for a given class of vehicle
 */
void menu_edicao_geral_precos() {

    int i, j, o;
    do {
        do {
            Ecra_edicao_geral_precos();
            readInt(&o, 0, 4, "Enter the class of vehicles you want to edit: ");
        } while (o < 0 || o > 4);
        switch (o) {
            case 1:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i == j) {
                            matrizA1_c1[i][j].preco = 0;
                        } else {
                            printf("Enter the price between toll %d to %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c1[i][j].preco, 0, 1000, "");
                        }
                    }
                }

                FILE *file1;
                file1 = fopen("A1classe1.txt", "wt"); //creates the pretended file

                if (file1 == NULL) {
                    printf("ERROR!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file1, "%f\t", matrizA1_c1[i][j].preco); //fills in the file the matrix previously created
                        }
                        fprintf(file1, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c1, "A1classe1.txt", false);
                    fclose(file1);
                }
                printf("The price of the link of all the tolls changed successfully!\n");
                break;
            case 2:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i == j) {
                            matrizA1_c1[i][j].preco = 0;
                        } else {
                            printf("Enter the price between toll %d to %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c2[i][j].preco, 0, 1000, "");
                        }
                    }
                }

                FILE *file2;
                file2 = fopen("A1classe2.txt", "wt"); //creates the pretended file

                if (file2 == NULL) {
                    printf("ERROR!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file2, "%f\t", matrizA1_c2[i][j].preco); //fills in the file the matrix previously created
                        }
                        fprintf(file2, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c2, "A1classe2.txt", false);
                    fclose(file2);
                }
                printf("The price of the link of all the tolls changed successfully!\n");
                break;
            case 3:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i == j) {
                            matrizA1_c3[i][j].preco = 0;
                        } else {
                            printf("Enter the price between toll %d to %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c3[i][j].preco, 0, 1000, "");
                        }
                    }
                }

                FILE *file3;
                file3 = fopen("A1classe3.txt", "wt"); //creates the pretended file

                if (file3 == NULL) {
                    printf("ERROR!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file3, "%f\t", matrizA1_c3[i][j].preco); //fills in the file the matrix previously created
                        }
                        fprintf(file3, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c3, "A1classe3.txt", false);
                    fclose(file3);
                }
                printf("The price of the link of all the tolls changed successfully!\n");
                break;
            case 4:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i == j) {
                            matrizA1_c4[i][j].preco = 0;
                        } else {
                            printf("Enter the price between toll %d to %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c4[i][j].preco, 0, 1000, "");
                        }
                    }
                }

                FILE *file4;
                file4 = fopen("A1classe4.txt", "wt"); //creates the pretended file

                if (file4 == NULL) {
                    printf("ERROR!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file4, "%f\t", matrizA1_c4[i][j].preco); //fills in the file the matrix previously created
                        }
                        fprintf(file4, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c4, "A1classe4.txt", false);
                    fclose(file4);
                }
                printf("The price of the link of all the tolls changed successfully!\n");
                break;
            default: printf("You have chosen to return to the previous menu\n");
        }
    } while (o != 0);
}

/**
 * Function that serves as a menu to the interface function (Ecra_gestao_precos) 
 * and where the price editing functions will also be called in a given pair of 
 * tolls and general price editing
 */
void menu_gestao_precos() {

    int o;
    short novo_entrada, novo_saida;

    do {
        do {
            Ecra_gestao_precos();
            readInt(&o, 0, 2, "Enter option number: ");
        } while (o < 0 || o > 2);
        switch (o) {
            case 1:
                readShort(&novo_entrada, 1, 6, "Enter the number of the entrance toll (1 to 6): ");
                readShort(&novo_saida, 1, 6, "Enter the number of the exit toll (1 to 6): ");
                menu_edicao_par_portico_preco(novo_entrada, novo_saida);
                break;
            case 2:
                menu_edicao_geral_precos();
                break;
            default: printf("You have chosen to return to the main menu \n");
        }
    } while (o != 0);
}

/**
 * Function that serves as a menu to the interface function (Ecra_gestao_lancos) 
 * and where they will also be called the functions of consulting tolls links and 
 * editing their prices
 */
void menu_gestao_lancos() {

    int o;

    do {
        do {
            Ecra_gestao_lancos();
            readInt(&o, 0, 2, "Enter option number: ");
        } while (o < 0 || o > 2);
        switch (o) {
            case 1:
                menu_consulta_lancos();
                break;
            case 2:
                menu_gestao_precos();
                break;
            default: printf("You have chosen to return to the main menu \n");

        }
    } while (o != 0);
}

/**
 * Function that prints an invoice to a txt file of all customer trips made in a given month
 *  
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the array
 * @param id customer ID
 * @param mes month of the trip
 * @param ano year of the trip made (despite being a monthly invoice, there may 
 * be repetition of months and the given "year" will be used to avoid repetition)
 */
void geracao_fatura_cliente(Cliente *vetor, int num_clientes, int id, short mes, short ano) {
    int pos, conf;
    float total = 0;

    FILE *file;
    if (file == NULL) {
        perror("Error:\n");
    } else {
        conf = pesquisa_id_clientes(vetor, num_clientes, id); //search to confirm the existence of the customer id generating the invoice

        if (conf == -1) {
            printf("The client id does not exist!\n");
        } else {
            if (vetor[conf].num_viagens == 0) {
                printf("At the moment the customer has not made any trips so it is not possible to generate an invoice for it!\n");
            } else {
                //search of the month the trips were made in order to confirm whether they were made in that month or not
                pos = pesquisa_mes_viagens(vetor, num_clientes, vetor[conf].id, mes);

                if (pos == -1) {
                    printf("The customer did not make any trips that month!");
                } else {

                    file = fopen("Invoice.txt", "wt");

                    fprintf(file, " ______________________________________________________\n");
                    fprintf(file, "|                                                      |\n");
                    fprintf(file, "|      Generation of customer's monthly invoice #% d    |\n", vetor[conf].id);
                    fprintf(file, "|______________________________________________________|\n");
                    fprintf(file, "\n");
                    fprintf(file, "Customer ID: %d\n", vetor[conf].id);
                    fprintf(file, "\n");
                    fprintf(file, "Customer Name: %s\n", vetor[conf].nome);
                    fprintf(file, "\n");
                    fprintf(file, "Customer NIF: %d\n", vetor[conf].NIF);
                    fprintf(file, "\n");
                    fprintf(file, "Nº Cartão de cidadão: %s\n", vetor[conf].num_CC);
                    fprintf(file, "\n");
                    fprintf(file, "NIB: %s\n", vetor[conf].NIB);
                    fprintf(file, "\n");
                    fprintf(file, "Address: %s\n", vetor[conf].morada);
                    fprintf(file, "\n");
                    fprintf(file, "Via Verde points: %hd\n", vetor[conf].num_ptsviaverde);
                    fprintf(file, "\n");
                    fprintf(file, "Vehicle registration number: %s\n", vetor[conf].veiculo_cliente.matricula);
                    fprintf(file, "\n");
                    fprintf(file, "Brand : %s\n", vetor[conf].veiculo_cliente.marca);
                    fprintf(file, "\n");
                    fprintf(file, "Model: %s\n", vetor[conf].veiculo_cliente.modelo);
                    fprintf(file, "\n");
                    fprintf(file, "Vehicle Class : %hd\n", vetor[conf].veiculo_cliente.classe);
                    fprintf(file, "\n\n");

                    for (int j = 0; j < vetor[conf].num_viagens; j++) {
                        if (vetor[conf].viagem_cliente[j].dataEntrada.mes == mes && vetor[conf].viagem_cliente[j].dataEntrada.ano == ano) {
                            fprintf(file, "Trip no%d", j + 1);
                            fprintf(file, "\n\n");
                            fprintf(file, "\n");
                            fprintf(file, "Entrance Toll: %hd\n", vetor[conf].viagem_cliente[j].info_lanco.porticoEntrada);
                            fprintf(file, "\n");
                            fprintf(file, "Exit Toll: %hd\n", vetor[conf].viagem_cliente[j].info_lanco.porticoSaida);
                            fprintf(file, "\n");
                            fprintf(file, "Trip Date: %hd/%hd/%hd\n", vetor[conf].viagem_cliente[j].dataEntrada.dia,
                                    vetor[conf].viagem_cliente[j].dataEntrada.mes
                                    , vetor[conf].viagem_cliente[j].dataEntrada.ano);
                            fprintf(file, "\n");
                            fprintf(file, "Exit Time: %hd:%hd\n", vetor[conf].viagem_cliente[j].horaSaida.hora, vetor[conf].viagem_cliente[j].horaSaida.minutos);
                            fprintf(file, "\n");
                            total += vetor[conf].viagem_cliente[j].info_lanco.custo;
                            fprintf(file, "Velocity when passing through the tolls link: %d km/h", vetor[conf].veiculo_cliente.velocidade);
                            fprintf(file, "\n\n");
                        }
                    }
                    fprintf(file, "Total cost of client trip: %0.1f€", total);
                    fprintf(file, "\n");
                    printf("Monthly invoice successfully generated!\n");
                }
                fclose(file);
                total = 0;
            }
        }
    }
}

/**
 * Function that serves as a menu of the features corresponding to the "TUI interface"
 *  of the 2nd Main Menu option (Trip management)
 * 
 * @param vetor customer array
 * @param num_viagens a pointer to the number of trips that exist in the customer vector
 * @param num_clientes a pointer to the number of customers that exist in the array
 */
void menu_gestao_viagens(Cliente* clientes, int num_clientes) {

    int o, id;

    do {
        do {
            Ecra_gestao_viagens();
            readInt(&o, 0, 3, "Enter option number: ");
        } while (o < 0 || o > 3);
        switch (o) {
            case 1:
                Ecra_acrecentar_viagem(); //menu para acrescentar viagem
                imprime_id_existentes(clientes, num_clientes);
                readInt(&id, 1, 1000, "Enter the Client ID you want to add the trip: ");
                adicionar_viagem(clientes, num_clientes, id);
                break;
            case 2://menu gestão de lanços
                menu_gestao_lancos();
                break;
            case 3://menu pesquisar viagens
                menu_gestao_pesquisa_viagens(clientes, num_clientes);
                break;
            default: printf("You have chosen to return to the main menu \n");
        }
    } while (o != 0);
}
