/**
 * @file Customers.c
 * @author João Pereira
 * @brief Customers Management
 * @date 27/11/2018
 *
 * File where a set of functions related to customers management are implemented
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "API_Leitura.h"
#include "Customers.h"
#include "Trips.h"
#include "Structures.h"


Lanco matrizA1_c1[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c2[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c3[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c4[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_pts[NUM_PORTAGENS][NUM_PORTAGENS];

/**
 * @brief This function serves as the "TUI interface" of the main menu options
 */
void Ecra_menu_principal() {//Main Menu
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|                     Via Verde                            |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Customers Management                            |\n");
    printf("|     2 -> Trips Management                                |\n");
    printf("|     3 -> Invoice Generation                              |\n");
    printf("|     4 -> Extra Features                                  |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Exit                                            |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 1st Main Menu option (Customers management)
 */
void Ecra_gestao_clientes() {
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|                  Customers Management                    |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Create customer                                 |\n");
    printf("|     2 -> Edit customer                                   |\n");
    printf("|     3 -> Remove customer                                 |\n");
    printf("|     4 -> Search customer                                 |\n");
    printf("|     5 -> List of introduced customers                    |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Back To Main Menu                               |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 1st option of Customers Management
 */
void Ecra_criar_cliente() {
    printf(" ________________________________________________\n");
    printf("|                                                |\n");
    printf("|             Creating a Customer                |\n");
    printf("|________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 2nd option of Customers Management
 */
void Ecra_editar_cliente() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|               Editing a Customer                |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 3rd option of Customers Management
 */
void Ecra_remover_cliente() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|               Removing a Customer               |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 4th option of Customers Management
 */
void Ecra_pesquisar_cliente() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|              Searching a Customer               |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 5th option of Customers Management
 */
void Ecra_listar_cliente() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|         Current list of created customers       |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 3rd option of Main Menu (Invoice Generation)
 */
void Ecra_geracaofatura() {
    printf(" _______________________________________________________\n");
    printf("|                                                       |\n");
    printf("| Generation of monthly invoice given the customer's ID |\n");
    printf("|_______________________________________________________|\n");
}

/**
 * @brief This function serves as the "TUI interface" of the 5th of Main Menu option (Customers Management)
 */
void Ecra_novas_funcionalidades() {
    printf(" ______________________________________________________________ \n");
    printf("|                                                              |\n");
    printf("|                     Extra Features                           |\n");
    printf("|                                                              |\n");
    printf("|     1 -> Discount of Via Verde points in sales promotions    |\n");
    printf("|     2 -> Customer Trips History                              |\n");
    printf("|     3 -> Simulation of the cost of a given trip              |\n");
    printf("|     4 -> Consultation of points between the pairs of tolls   |\n");
    printf("|                                                              |\n");
    printf("|     0 -> Back To Main Menu                                   |\n");
    printf("|______________________________________________________________|\n");
}

/**
 * @brief This function serves as "TUI interface" of the 1st option of the New Features menu
 */
void Ecra_desconto_pontos_viaverde() {
    printf(" _______________________________________________________________________________\n");
    printf("|                                                                               |\n");
    printf("|            Discount of Via Verde points in sales promotions                   |\n");
    printf("|                                                                               |\n");
    printf("|  1 -> 25%% discount on a ticket for 2 people to the cinema (2 points)         |\n");
    printf("|  2 -> 30%% discount wine tasting and visit to the Felgueiras winery (5 points)|\n");
    printf("|  3 -> 50 %% discount for Super Bock Super Rock general pass (10 points)       |\n");
    printf("|                                                                               |\n");
    printf("|  0 -> Back To Main Menu                                                       |\n");
    printf("|_______________________________________________________________________________|\n");
}

/**
 * @brief This function serves as "TUI interface" of the 2nd option of the New Features menu
 */
void Ecra_historico_viagens() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|             Customer Trips History              |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief This function serves as "TUI interface" of the 3rd option of the New Features menu
 */
void Ecra_classe_veiculo_simulacao() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|     Simulation of the cost of a given trip      |\n");
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
 * @param vetor array of customers
 * @param num_clientes the number of customers that exist in the customers array
 * @param id customer ID to search
 * @return customer index, if exists, or -1 if not
 */
int pesquisa_id_clientes(Cliente *vetor, int num_clientes, int id) {

    int i = 0;

    while (i < num_clientes && vetor[i].id != id)
        i++;

    if (i == num_clientes)
        return -1;
    else
        return i;
}

/**
 * Function that traverses the matrix of the Via Verde points and prints the cost  
 * and number of Via Verde points from the entrance toll to the exit toll (toll link)
 * (Extra Feature)
 * 
 * @param num_entrada entrance toll number
 * @param num_saida exit toll number
 */
void simulacao_custo_pontos(short num_entrada, short num_saida) {

    int o;

    do {
        do {
            Ecra_classe_veiculo_simulacao();
            readInt(&o, 0, 4, "Enter the class of vehicles to be used in the simulation: ");
        } while (o < 0 || o > 4);
        switch (o) {
            case 1:
                if (num_entrada == num_saida) {
                    printf("Number of the entrance toll is equal to the number of the exit toll");
                } else {
                    for (int i = 0; i < NUM_PORTAGENS; i++) {
                        for (int j = 0; j < NUM_PORTAGENS; j++) {
                            if (i + 1 == num_entrada && j + 1 == num_saida) {
                                printf("The cost between the toll %hd and the toll %hd is: %0.2f€ and the customer gets %hd Via Verde points\n",
                                        num_entrada, num_saida, matrizA1_c1[i][j].preco, matrizA1_pts[i][j].pontos);
                            }
                        }
                    }
                }
                break;
            case 2:
                if (num_entrada == num_saida) {
                    printf("Number of the entrance toll is equal to the number of the exit toll");
                } else {
                    for (int i = 0; i < NUM_PORTAGENS; i++) {
                        for (int j = 0; j < NUM_PORTAGENS; j++) {
                            if (i + 1 == num_entrada && j + 1 == num_saida) {
                                printf("The cost between the toll %hd and the toll %hd is: %0.2f€ and the customer gets %hd Via Verde points\n",
                                        num_entrada, num_saida, matrizA1_c2[i][j].preco, matrizA1_pts[i][j].pontos);
                            }
                        }
                    }
                }
                break;
            case 3:
                if (num_entrada == num_saida) {
                    printf("Number of the entrance toll is equal to the number of the exit toll");
                } else {
                    for (int i = 0; i < NUM_PORTAGENS; i++) {
                        for (int j = 0; j < NUM_PORTAGENS; j++) {
                            if (i + 1 == num_entrada && j + 1 == num_saida) {
                                printf("The cost between the toll %hd and the toll %hd is: %0.2f€ and the customer gets %hd Via Verde points\n",
                                        num_entrada, num_saida, matrizA1_c3[i][j].preco, matrizA1_pts[i][j].pontos);
                            }
                        }
                    }
                }
                break;
            case 4:
                if (num_entrada == num_saida) {
                    printf("Number of the entrance toll is equal to the number of the exit toll");
                } else {
                    for (int i = 0; i < NUM_PORTAGENS; i++) {
                        for (int j = 0; j < NUM_PORTAGENS; j++) {
                            if (i + 1 == num_entrada && j + 1 == num_saida) {
                                printf("The cost between the toll %hd and the toll %hd is: %0.2f€ and the customer gets %hd Via Verde points\n",
                                        num_entrada, num_saida, matrizA1_c4[i][j].preco, matrizA1_pts[i][j].pontos);
                            }
                        }
                    }
                }
                break;
            default: printf("You have chosen to return to the previous menu \n");
        }
    } while (o != 0);
}

/**
 * Function that prints the distance-price matrix of each toll link
 * 
 * @param matrix where distance values and points of toll links will be stored
 */
void imprime_matrizpontos_A1(Lanco matriz[NUM_PORTAGENS][NUM_PORTAGENS]) {

    int i, j;

    printf("Toll no. :1     2       3       4       5       6\n");
    printf("\n");
    for (i = 0; i < NUM_PORTAGENS; i++) {
        for (j = 0; j < NUM_PORTAGENS; j++) {
            if (j == 0)
                printf("    %d     ", i + 1);

            printf("%hd\t", matriz[i][j].pontos);
        }
        printf("\n");
    }
    printf("\nLabel:\n");
    printf("1-Lisboa \t 2-Santarém \t 3-Leiria \t 4-Coimbra \t 5-Albergaria-a-velha \t 6-Porto \t\n");
}

/**
 * Function that assigns a velocity value, random (rand () function) between 30 and 
 * 60 trying to get closer to a reality context, to the vehicle when passing 
 * through a toll link (New Feature)
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the customers array
 * @param num_viagens the number of trips that exist in the array
 * @param id customer ID 
 * @param velocidade array where the velocities are stored in each toll link that the vehicle passes
 */
void velocidade_lanco(Cliente *vetor, int num_clientes, int num_viagens, int id, int velocidade) {

    srand((unsigned) time(NULL));

    int pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("The customer ID does not exist!\n");
    } else {

        do {
            velocidade = rand() % 100;
        } while (velocidade <= 30 && velocidade >= 60);

        vetor[pos].veiculo_cliente.velocidade = velocidade;
    }
}

/**
 * Function that adds Via Verde points to the customer through the trips he takes 
 * between each toll link (New Feature)
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the customers array
 * @param num_entrada entrance toll number
 * @param num_saida exit toll number
 * @param id customer ID to assign Via Verde points
 * @return number of points assigned on a given trip
 */
int adicao_pontos_viaverde(Cliente *vetor, int num_clientes, short num_entrada, short num_saida, int id) {

    int pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("The customer ID does not exist!\n");
    } else {
        if (num_entrada == num_saida) {
            printf("Number of the entrance toll is equal to the number of the exit toll");
        } else {
            for (int i = 0; i < NUM_PORTAGENS; i++) {
                for (int j = 0; j < NUM_PORTAGENS; j++) {
                    if (i + 1 == num_entrada && j + 1 == num_saida) {
                        vetor[pos].num_ptsviaverde = vetor[pos].num_ptsviaverde + matrizA1_pts[i][j].pontos;
                        return matrizA1_pts[i][j].pontos;
                    }
                }
            }
        }
    }
}

/**
 * Function that serves as a discount menu from which the user chooses an option 
 * and a number of points is deducted from that option, if he does not have enough
 * points he receives an information saying that he does not have enough points
 * for the promotion he has chosen (New Feature)
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the customers array
 */
void descontos_pontos_viaverde(Cliente *vetor, int *num_clientes) {

    int o, id, pos;

    do {
        do {
            Ecra_desconto_pontos_viaverde();
            readInt(&o, 0, 3, "Choose a sale promotion: ");
        } while (o < 0 || o > 3);

        if (o != 0) {
            readInt(&id, 1, 1000, "Enter the customer ID for the Via Verde points discount: ");
            pos = pesquisa_id_clientes(vetor, *num_clientes, id);

            if (pos == -1) {
                printf("The customer ID does not exist!\n");
            } else {
                switch (o) {
                    case 1:
                        if (vetor[pos].num_ptsviaverde < 2) {
                            printf("You do not have enough points for this sale promotion! Current points: %hd\n",
                                    vetor[pos].num_ptsviaverde);
                        } else {
                            vetor[pos].num_ptsviaverde = vetor[pos].num_ptsviaverde - 2;
                            printf("Discount successful! Current points: %hd\n", vetor[pos].num_ptsviaverde);
                        }
                        break;
                    case 2:
                        if (vetor[pos].num_ptsviaverde < 5) {
                            printf("You do not have enough points for this sale promotion! Current points: %hd\n",
                                    vetor[pos].num_ptsviaverde);
                        } else {
                            vetor[pos].num_ptsviaverde = vetor[pos].num_ptsviaverde - 5;
                            printf("Discount successful! Current points: %hd\n", vetor[pos].num_ptsviaverde);
                        }
                        break;
                    case 3:
                        if (vetor[pos].num_ptsviaverde < 10) {
                            printf("You do not have enough points for this sale promotion! Current points: %hd\n",
                                    vetor->num_ptsviaverde);
                        } else {
                            vetor[pos].num_ptsviaverde = vetor[pos].num_ptsviaverde - 10;
                            printf("Discount successful! Current points: %hd\n", vetor[pos].num_ptsviaverde);
                        }
                        break;
                }
            }
        } else {
            printf("You have chosen to return to the previous menu \n");
        }
    } while (o != 0);
}

/**
 * Function that serves as a menu for the new features of the project
 * (New Feature)
 * 
 * @param vetor pointer to the customers array
 * @param num_clientes the number of customers that exist in the customers array
 * @param tam_max customers array length
 */
void menu_novas_funcionalidades(Cliente **vetor, int *num_clientes, int *tam_max) {

    int o, id;
    short num_entrada, num_saida;

    do {
        do {
            Ecra_novas_funcionalidades();
            readInt(&o, 0, 6, "Enter option number: ");
        } while (o < 0 || o > 6);
        switch (o) {
            case 1: descontos_pontos_viaverde(*vetor, num_clientes);
                break;
            case 2:Ecra_historico_viagens();
                readInt(&id, 0, 10000, "Enter the customer ID you want to search for: ");
                historico_viagens(*vetor, *num_clientes, id);
                break;
            case 3:
                readShort(&num_entrada, 1, 6, "Enter the number of the entrance toll (1 to 6)");
                readShort(&num_saida, 1, 6, "Enter the number of the exit toll (1 to 6)");
                simulacao_custo_pontos(num_entrada, num_saida);
                break;
            case 4:imprime_matrizpontos_A1(matrizA1_pts);
                break;
            default: printf("You have chosen to return to the main menu \n");
        }
    } while (o != 0);

}

/**
 * Writes the array content of the customer structure to a binary file
 * 
 * @param vetor pointer to the first customer of the costumers array
 * @param num_clientes the number of customers that exist in the customers array
 */
void escrever_dados_cliente(Cliente *vetor, int num_clientes) {
    FILE *f;

    if ((f = fopen("customers.bin", "wb")) == NULL)
        perror(NULL);
    else {
        fwrite(&num_clientes, sizeof (int), 1, f);
        fwrite(vetor, sizeof (Cliente), num_clientes, f);
        fclose(f);
    }
}

/**
 * Read data from file (if exists) and fill in the array of the customer structure
 * and its number
 * 
 * @param vetor a pointer to the memory address of the first customer to fill
 * @param num_clientes a pointer to the number of customers that exist in the customers array 
 * @param tam_max pointer to the size of the customers array
 */
void ler_dados_cliente(Cliente **vetor, int *num_clientes, int *tam_max) {

    FILE *f;
    int nr;

    if ((f = fopen("customers.bin", "rb")) == NULL) {
        *num_clientes = 0;
        *tam_max = 0;
        perror(NULL);
    } else {
        nr = fread(num_clientes, sizeof (int), 1, f);

        if (nr != 1) {
            printf("Error reading the number of elements!\n");
            return;
        }

        *vetor = malloc((*num_clientes + 5) * sizeof (Cliente));

        if (*vetor == NULL) {
            printf("Unable to allocate memory");
            *num_clientes = 0;
            *tam_max = 0;
        } else {
            printf("Allocated %d bytes of memory.\n", (*num_clientes) * sizeof (Cliente));
            nr = fread(*vetor, sizeof (Cliente), *num_clientes, f);

            if (nr == *num_clientes) {
                *tam_max = *num_clientes;
                *num_clientes = nr;
            } else {
                printf("Error reading elements!\n");
                *tam_max = 0;
                *num_clientes = 0;
                free(*vetor);
            }
        }
        fclose(f);
    }
}

/**
 * This function adds and creates a customer in the array
 * 
 * @param ptrcliente pointer to the customers array
 * @param num_clientes the number of customers that exist in the customers array
 * @param tam_max customers array length
 */
void criar_cliente(Cliente **ptrcliente, int *num_clientes, int *tam_max) {

    if (*ptrcliente == NULL) {
        *ptrcliente = (Cliente*) malloc(TAM_INICIAL * sizeof (Cliente)); //Vetor é declarado inicialmente com 3 posições
    } else if (*num_clientes == *tam_max) {
        *ptrcliente = realloc(*ptrcliente, ((*num_clientes) + TAM_INCREMENTO) * (sizeof (Cliente))); //Vetor é realocado mais 3 posições
        (*tam_max) += TAM_INCREMENTO;
    }

    Cliente *ptr = *ptrcliente + *num_clientes; //incrementa uma posição do ptr

    readInt(&ptr->id, 1, 1000, "ID: ");
    int pos, mat;
    pos = pesquisa_id_clientes(*ptrcliente, *num_clientes, ptr->id);
    if (pos != -1) {
        do {
            readInt(&ptr->id, 1, 1000, "Enter the ID again (the id already exists, enter another one): ");
            pos = pesquisa_id_clientes(*ptrcliente, *num_clientes, ptr->id);
        } while (pos != -1);
        printf("ID validated successfully!\n");
    }
    readString(ptr->nome, MAX_STR - 1, "Costumer Name: ");
    readInt(&ptr->NIF, 100000000, 199999999, "NIF: ");
    readString(ptr->num_CC, 8 + 1, "Nº Cartão de cidadão: ");
    readString(ptr->NIB, MAX_NIB - 1, "NIB: ");
    readString(ptr->morada, MAX_STR - 1, "Address: ");
    ptr->num_ptsviaverde = 0;
    ptr->num_viagens = 0;
    readString(ptr->veiculo_cliente.matricula, MAX_MAT - 1, "Vehicle Registration: ");
    mat = pesquisa_viagem_matricula(*ptrcliente, *num_clientes, ptr->veiculo_cliente.matricula);
    if (mat != -1) {
        do {
            readString(ptr->veiculo_cliente.matricula, MAX_MAT - 1, "Enter the vehicle registration number again (the registration number already exists, enter another one): ");
            mat = pesquisa_viagem_matricula(*ptrcliente, *num_clientes, ptr->veiculo_cliente.matricula);
        } while (mat != -1);
    }
    readString(ptr->veiculo_cliente.marca, MAX_MAT - 1, "Brand: ");
    readString(ptr->veiculo_cliente.modelo, MAX_MAT - 1, "Model: ");
    readShort(&ptr->veiculo_cliente.classe, 0, 4, "Vehicle class (number): ");
    printf("Customer successfully created! \n");
    printf("Array position: %d\n", *num_clientes);
    (*num_clientes)++;

    escrever_dados_cliente(*ptrcliente, *num_clientes);
}

/**
 * Function that returns a pointer to the customer given its id, if exist
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the customers array
 * @param id customer ID
 * @return a pointer to the customer, or NULL if it doesn't exist
 */
Cliente * getCliente(Cliente *vetor, int *num_clientes, int id) {

    int pos = pesquisa_id_clientes(vetor, *num_clientes, id);

    if (pos == -1)
        return NULL;
    else
        return &vetor[pos];
}

/**
 * Function that updates a customer's information, if it exists
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the customers array
 * @param id customer ID
 * 
 */
void atualiza_cliente(Cliente *vetor, int *num_clientes, int id) {

    int pos = pesquisa_id_clientes(vetor, *num_clientes, id); //Checks whether the customer exists through the id

    if (pos == -1) {
        printf("The customer does not exist!\n");
    } else {
        if (vetor[pos].id == id) {

            Cliente * novo;

            novo = getCliente(vetor, num_clientes, id);

            if (novo != NULL) {
                novo->id = id;
                readString(novo->nome, MAX_STR - 1, "New customer name: ");
                readInt(&novo->NIF, 100000000, 199999999, "New NIF: ");
                readString(novo->num_CC, MAX_CC - 1, "New nº Cartão de cidadão: ");
                readString(novo->NIB, MAX_NIB - 1, "New NIB: ");
                readString(novo->morada, MAX_STR - 1, "New Address: ");
                printf("Customer information updated successfully!\n");
            }
        }
    }
}

/**
 * Function that removes the customer given his id
 *
 * @param vetor pointer to the customers array
 * @param num_clientes pointer to the number of customers that exist in the array
 * @param tam_max pointer to array size
 * @param id customer ID to be deleted
 */
void remover_cliente(Cliente **vetor, int *num_clientes, int *tam_max, int id) {

    Cliente *novo;
    int pos;

    pos = pesquisa_id_clientes(*vetor, *num_clientes, id);

    if (pos > -1) {
        while (pos < (*num_clientes) - 1) {
            (*vetor)[pos] = (*vetor)[pos + 1];
            pos++;
        }
        (*num_clientes)--;
        printf("Customer removed!\n");

        if (*tam_max - *num_clientes >= TAM_DECREMENTO) {
            novo = realloc(*vetor, ((*tam_max) * sizeof (Cliente))
                    - TAM_DECREMENTO * sizeof (Cliente));
            if (novo == NULL) {
                printf("Memory relocation failed. \n");
            } else {
                printf("Reallocated memory. New size: %d bytes. \n",
                        ((*tam_max) * sizeof (Cliente)) - TAM_DECREMENTO * sizeof (Cliente));
                *vetor = novo;
                (*tam_max) -= TAM_DECREMENTO;
            }
        }
    } else
        printf("Customer with id %d does not exist! \n", id);
}

/**
 * Function that searches for the customer given his id and then prints all the 
 * information related to that customer
 * 
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the customers array
 * @param id customer ID to be searched
 * 
 */
void pesquisar_cliente(Cliente *vetor, int num_clientes, int id) {

    int pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("The customer does not exist!\n");
    } else {
        printf("ID: %d\n", vetor[pos].id);
        printf("Customer Name: %s\n", vetor[pos].nome);
        printf("NIF: %d\n", vetor[pos].NIF);
        printf("Nº Cartão de cidadão: %s\n", vetor[pos].num_CC);
        printf("NIB: %s\n", vetor[pos].NIB);
        printf("Address: %s\n", vetor[pos].morada);
        printf("No. of Via Verde points: %hd\n", vetor[pos].num_ptsviaverde);
        printf("Vehicle Registration: %s\n", vetor[pos].veiculo_cliente.matricula);
        printf("Brand: %s\n", vetor[pos].veiculo_cliente.marca);
        printf("Model: %s\n", vetor[pos].veiculo_cliente.modelo);
        printf("Vehicle(s) class: %hd\n", vetor[pos].veiculo_cliente.classe);
    }
}

/**
 * Function that lists all the customers introduced so far
 *
 * @param vetor customers array
 * @param num_clientes the number of customers that exist in the customers array
 */
void listar_clientes(Cliente *vetor, int num_clientes) {

    if (num_clientes == 0) {
        printf("No customers have been created yet!\n");
    } else {
        int j;
        for (j = 0; j < num_clientes; j++) {

            printf("Customer ID: %d\n", vetor[j].id);
            printf("Customer Name: %s\n", vetor[j].nome);
            printf("Número do cartão de cidadão: %s\n", vetor[j].num_CC);
            printf("Via Verde points: %hd\n", vetor[j].num_ptsviaverde);
            printf("Array position: %d\n", j);
            printf("\n");
        }
    }
}

/**
 * Function that serves as a menu of the functionalities corresponding to the 
 * "TUI interface" of the 1st main menu option (Customer management)
 * 
 * @param vetor pointER to the customers array
 * @param num_clientes a pointer to the number of customers that exist in the array
 * @param tam_max a pointer the size of the customer array
 */
void menu_gestao_clientes(Cliente** vetor, int *num_clientes, int *tam_max) {

    int o, id;
    do {
        do {
            Ecra_gestao_clientes();
            readInt(&o, 0, 6, "Enter option number: ");
        } while (o < 0 || o > 6);
        switch (o) {
            case 1:Ecra_criar_cliente();
                criar_cliente(vetor, num_clientes, tam_max);
                break;
            case 2: Ecra_editar_cliente();
                imprime_id_existentes(*vetor, *num_clientes);
                readInt(&id, 1, 10000, "Enter the customer ID you want to edit: ");
                atualiza_cliente(*vetor, num_clientes, id);
                break;
            case 3: Ecra_remover_cliente();
                imprime_id_existentes(*vetor, *num_clientes);
                readInt(&id, 0, 10000, "Enter the customer ID you want to remove: ");
                remover_cliente(vetor, num_clientes, tam_max, id);
                break;
            case 4: Ecra_pesquisar_cliente();
                imprime_id_existentes(*vetor, *num_clientes);
                readInt(&id, 0, 10000, "Enter the customer ID you want to search for: ");
                pesquisar_cliente(*vetor, *num_clientes, id);
                break;
            case 5: Ecra_listar_cliente();
                listar_clientes(*vetor, *num_clientes);
                break;
            default: printf("You have chosen to return to the main menu \n");
        }
    } while (o != 0);
}

/**
 * Function that serves as a menu for all project features
 *
 * @param ptrClientes array where all customer information is stored
 * @param num_clientes a pointer to the number of customers that exist in the array
 * @param tam_max a pointer the size of the customer array
 */
void menu_principal(Cliente** ptrclientes, int *num_clientes, int *tam_max) {
    int o, id;
    short mes, ano;

    do {
        do {
            Ecra_menu_principal();
            readInt(&o, 0, 5, "Enter option number: ");
        } while (o < 0 || o > 5);
        switch (o) {
            case 1:
                menu_gestao_clientes(ptrclientes, num_clientes, tam_max);
                break;
            case 2:
                menu_gestao_viagens(*ptrclientes, *num_clientes);
                break;
            case 3:
                Ecra_geracaofatura();
                imprime_id_existentes(*ptrclientes, *num_clientes);
                readInt(&id, 1, 1000, "Enter the customer ID to generate an invoice: ");
                readShort(&mes, 1, 12, "Enter the month of the invoice to be generated: ");
                readShort(&ano, 2017, 2019, "Enter the year of the invoice to be generated: ");
                geracao_fatura_cliente(*ptrclientes, *num_clientes, id, mes, ano);
                break;
            case 4:menu_novas_funcionalidades(ptrclientes, num_clientes, tam_max);
                break;
            default: printf("You have chosen to leave, thanks for using the application!");
        }
    } while (o != 0);
}
