/**
 * @file Viagens.c
 * @author Grupo 22-30 João Pereira , Bruno Teixeira, Rui Vieira, Carlos Ribeiro.
 * @brief Gestão das viagens.
 * @date 27 de Novembro de 2018
 *
 * Ficheiro onde estão implementadas um conjunto de funções relativas à gestão de viagens
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "API_Leitura.h"
#include "Clientes.h"
#include "Viagens.h"

// Estruturas que guardam as matrizes das 4 classes de um veiculo

Lanco matrizA1_c1[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c2[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c3[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c4[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_pts[NUM_PORTAGENS][NUM_PORTAGENS];

/**
 * @brief Esta função serve como "interface" da 2º opção menu principal (Gestão de viagens)
 */
void Ecra_gestao_viagens() {
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|                  Gestão de viagens                       |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Acrescentar viagem                              |\n");
    printf("|     2 -> Gestão de lanços                                |\n");
    printf("|     3 -> Pesquisar viagem                                |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Voltar ao menu principal                        |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 1º opção do menu de gestão de viagens (Acrescentar viagem)
 */
void Ecra_acrecentar_viagem() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|                Adição da viagem                 |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 2º opção menu da gestão de viagens (Gestão de lanços)
 */
void Ecra_gestao_lancos() {
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|                   Gestão de lanços                       |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Consultar lanços (Distância-Preços na A1)       |\n");
    printf("|     2 -> Edição dos preços dos lanços                    |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Voltar ao menu principal                        |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 3º opção menu da gestão de viagens (Pesquisar viagem)
 */
void Ecra_pesquisa_viagem() {
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|                  Pesquisa de viagem                      |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Veículo                                         |\n");
    printf("|     2 -> Lanço                                           |\n");
    printf("|     3 -> Data                                            |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Voltar ao menu principal                        |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 1º opção menu gestão de lanços (Consultar lanços (Distância-Preços na A1))
 */
void Ecra_consulta_distancias_precos_classes_A1() {
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|        Distância-Preço dos lanços(Classes A1)            |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Classe 1                                        |\n");
    printf("|     2 -> Classe 2                                        |\n");
    printf("|     3 -> Classe 3                                        |\n");
    printf("|     4 -> Classe 4                                        |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Voltar ao menu principal                        |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 2º opção menu gestão de lanços (Edição dos preços dos lanços)
 */
void Ecra_gestao_precos() {
    printf(" ______________________________________________________________ \n");
    printf("|                                                              |\n");
    printf("|                     Gestão de preços                         |\n");
    printf("|                                                              |\n");
    printf("|     1 -> Editar o preço para um determinado par de pórticos  |\n");
    printf("|     2 -> Editar o preço para toda a A1                       |\n");
    printf("|                                                              |\n");
    printf("|     0 -> Voltar ao menu principal                            |\n");
    printf("|______________________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 1º opção menu gestão de preços (Editar o preço para um determinado par de pórticos)
 */
void Ecra_edicao_parportico_preco() {
    printf(" ______________________________________________________________\n");
    printf("|                                                              |\n");
    printf("|            Edição de um determinado preço num dado           |\n");
    printf("|               par de pórticos dos preços(A1)                 |\n");
    printf("|                                                              |\n");
    printf("|     1 -> Classe 1                                            |\n");
    printf("|     2 -> Classe 2                                            |\n");
    printf("|     3 -> Classe 3                                            |\n");
    printf("|     4 -> Classe 4                                            |\n");
    printf("|                                                              |\n");
    printf("|     0 -> Voltar ao menu principal                            |\n");
    printf("|______________________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 2º opção menu gestão de preços  (Editar o preço para toda a A1)
 */
void Ecra_edicao_geral_precos() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|            Edição geral dos preços (A1)         |\n");
    printf("|                                                 |\n");
    printf("|     1 -> Classe 1                               |\n");
    printf("|     2 -> Classe 2                               |\n");
    printf("|     3 -> Classe 3                               |\n");
    printf("|     4 -> Classe 4                               |\n");
    printf("|                                                 |\n");
    printf("|     0 -> Voltar ao menu principal               |\n");
    printf("|_________________________________________________|\n");
}

/**
 * Função que devolve a posição em que ocorre o cliente dado o seu id
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id identificador do cliente a pesquisar
 * @return indice do cliente , se existir , ou -1 caso não exista
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
 * Função que devolve a posição em que ocorre o cliente dado o mês da viagem
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param mês mês da viagem que o cliente realizou
 * @return indice do cliente , se existir , ou -1 caso não exista
 */
int pesquisa_mes_viagens(Cliente *vetor, int num_clientes, int id, short mes) {//Esta função foi criada para a geração da fatura

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
 * Função que imprime todas as matrículas que foram introduzidas pelo utilizador até ao momento
 *  
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 */
void imprime_matriculas_existentes(Cliente* vetor, int num_clientes) {
    printf("Matrículas já criadas:\n");
    if (num_clientes == 0) {
        printf("Não há nenhuma matrícula criada até ao momento\n");
    } else {
        for (int i = 0; i < num_clientes; i++) {
            printf("%s\n", vetor[i].veiculo_cliente.matricula);
        }
    }
}

/**
 * Função que imprime todos os identificadores de clientes (id) já introduzidos pelo utilizador até ao momento
 *  
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 */
void imprime_id_existentes(Cliente* vetor, int num_clientes) {
    printf("ID já criados:\n");

    if (num_clientes == 0) {
        printf("Não há nenhum id criado até ao momento\n");
    } else {
        for (int i = 0; i < num_clientes; i++) {
            printf("%d\n", vetor[i].id);
        }
    }
}

/**
 * Função que devolve a posição em que ocorre o cliente dada a matricula do veiculo do cliente
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param matricula matricula do veiculo do cliente a pesquisar
 * @return indice do cliente , se existir , ou -1 caso não exista
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
 * Função que imprime a informação das viagens de um cliente dada a sua matricula
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param matricula matricula do veiculo do cliente a pesquisar
 */
void pesquisa_viagem_veiculo(Cliente * vetor, int num_clientes, char matricula[MAX_MAT]) {

    int pos = pesquisa_viagem_matricula(vetor, num_clientes, matricula);

    if (pos == -1) {
        printf("Matricula de veiculo inexistente!\n");
    } else {
        if (vetor[pos].num_viagens == 0) {
            printf("O cliente ainda não efetuou nenhuma viagem!\n");
        } else {
            int j;
            printf("Viagens efetuadas na matricula %s: \n", matricula);
            for (j = 0; j < vetor[pos].num_viagens; j++) {
                printf("Viagem nº%d: \n", j + 1);
                printf("\n");
                printf("Pórtico de entrada: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoEntrada);
                printf("Pórtico de saída: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoSaida);
                printf("Data da viagem: %hd/%hd/%hd\n", vetor[pos].viagem_cliente[j].dataEntrada.dia,
                        vetor[pos].viagem_cliente[j].dataEntrada.mes
                        , vetor[pos].viagem_cliente[j].dataEntrada.ano);
                printf("Hora de saída: %hd:%hd\n", vetor[pos].viagem_cliente[j].horaSaida.hora, vetor[pos].viagem_cliente[j].horaSaida.minutos);
                switch (vetor[pos].veiculo_cliente.classe) {
                    case 1:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 2:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 3:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 4:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);

                        break;
                }
                printf("\n");
            }
        }
    }
}

/**
 * Função que devolve a posição em que ocorre o cliente dado um par de pórticos
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id identificador do cliente (para determinar a posição do vetor onde fez as viagens)
 * @param num_entrada número do pórtico de entrada
 * @param num_saida número pórtico de saída
 * @return 
 */
int pesquisa_viagem_lanco(Cliente * vetor, int num_clientes, int id, short num_entrada, short num_saida) {
    int i = 0, pos;

    pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("O cliente não existe!");
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
 * Função que imprime a informação das viagens de um cliente dado um par de pórticos
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id identificador do cliente (para determinar a posição do vetor onde fez as viagens) 
 * @param num_entrada número do pórtico de entrada
 * @param num_saida número pórtico de saída
 */
void pesquisa_viagem_par_porticos(Cliente * vetor, int num_clientes, int id, short num_entrada, short num_saida) {

    int pos = pesquisa_viagem_lanco(vetor, num_clientes, id, num_entrada, num_saida);

    if (pos == -1) {
        printf("O cliente ainda não realizou viagens nesta data!\n");
    } else {
        if (vetor[pos].num_viagens == 0) {
            printf("O cliente ainda não efetuou nenhuma viagem!\n");
        } else {
            int j;
            printf("Viagens efetuadas pelo cliente nos pórticos %hd-%hd: \n", num_entrada, num_saida);
            for (j = 0; j < vetor[pos].num_viagens; j++) {
                printf("Viagem nº%d: \n", j + 1);
                printf("\n");
                printf("Pórtico de entrada: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoEntrada);
                printf("Pórtico de saída: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoSaida);
                printf("Data da viagem: %hd/%hd/%hd\n", vetor[pos].viagem_cliente[j].dataEntrada.dia,
                        vetor[pos].viagem_cliente[j].dataEntrada.mes
                        , vetor[pos].viagem_cliente[j].dataEntrada.ano);
                printf("Hora de saída: %hd:%hd\n", vetor[pos].viagem_cliente[j].horaSaida.hora, vetor[pos].viagem_cliente[j].horaSaida.minutos);
                switch (vetor[pos].veiculo_cliente.classe) {
                    case 1:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 2:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 3:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 4:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);

                        break;
                }
                printf("\n");
            }
        }
    }
}

/**
 * Função que devolve a posição em que ocorre o cliente dada a data da realização da viagem
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id identificador do cliente (para determinar a posição do vetor onde fez as viagens)
 * @param ano ano da viagem efetuada
 * @param mes mês da viagem efetuada
 * @param dia dia da viagem efetuada
 * @return indice do cliente , se existir , ou -1 caso não exista
 */
int pesquisa_data_viagens(Cliente *vetor, int num_clientes, int id, short ano, short mes, short dia) {

    int i = 0, pos;

    pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("O cliente não existe!");
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
 * Função que imprime a informação das viagens de um cliente dada a sua data
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id identificador do cliente (para determinar a posição do vetor onde fez as viagens)
 * @param ano ano da viagem efetuada
 * @param mes mês da viagem efetuada
 * @param dia dia da viagem efetuada
 */
void pesquisa_viagem_data(Cliente * vetor, int num_clientes, int id, short ano, short mes, short dia) {

    int pos = pesquisa_data_viagens(vetor, num_clientes, id, ano, mes, dia);

    if (pos == -1) {
        printf("O cliente ainda não realizou viagens nesta data!\n");
    } else {
        if (vetor[pos].num_viagens == 0) {
            printf("O cliente ainda não efetuou nenhuma viagem!\n");
        } else {
            int j;
            printf("Viagens efetuadas na data %hd/%hd/%hd: \n", dia, mes, ano);
            for (j = 0; j < vetor[pos].num_viagens; j++) {
                printf("Viagem nº%d: \n", j + 1);
                printf("\n");
                printf("Pórtico de entrada: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoEntrada);
                printf("Pórtico de saída: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoSaida);
                printf("Data da viagem: %hd/%hd/%hd\n", vetor[pos].viagem_cliente[j].dataEntrada.dia,
                        vetor[pos].viagem_cliente[j].dataEntrada.mes
                        , vetor[pos].viagem_cliente[j].dataEntrada.ano);
                printf("Hora de saída: %hd:%hd\n", vetor[pos].viagem_cliente[j].horaSaida.hora, vetor[pos].viagem_cliente[j].horaSaida.minutos);
                switch (vetor[pos].veiculo_cliente.classe) {
                    case 1:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 2:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 3:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                        break;
                    case 4:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);

                        break;
                }
                printf("\n");
            }
        }
    }
}

/**
 * Função que serve como um menu das funcionalidades de pesquisa correspondente ao "interface" 3º opção menu da gestão de viagens
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 */
void menu_gestao_pesquisa_viagens(Cliente *vetor, int num_clientes) {

    int o, id, pos;
    char matricula[MAX_MAT];
    short num_entrada, num_saida, dia, ano, mes;

    do {
        do {
            Ecra_pesquisa_viagem();
            readInt(&o, 0, 3, "Introduza opção: ");
        } while (o < 0 || o > 3);
        switch (o) {
            case 1:
                imprime_matriculas_existentes(vetor, num_clientes);
                readString(matricula, MAX_MAT - 1, "Introduza a matricula: ");
                pesquisa_viagem_veiculo(vetor, num_clientes, matricula);
                break;
            case 2:
                imprime_id_existentes(vetor,num_clientes);
                readInt(&id, 1, 1000, "Introduza o ID do cliente para pesquisar a viagem: ");
                pos = pesquisa_id_clientes(vetor, num_clientes, id);
                if (pos == -1) {
                    printf("O cliente não existe!\n");
                } else {
                    readShort(&num_entrada, 1, 6, "Introduza o pórtico de entrada: ");
                    readShort(&num_saida, 1, 6, "Introduza o pórtico de saida: ");
                    pesquisa_viagem_par_porticos(vetor, num_clientes, id, num_entrada, num_saida);
                }
                break;
            case 3:
                imprime_id_existentes(vetor,num_clientes);
                readInt(&id, 1, 1000, "Introduza o ID do cliente para pesquisar a viagem: ");
                pos = pesquisa_id_clientes(vetor, num_clientes, id);
                if (pos == -1) {
                    printf("O cliente não existe!\n");
                } else {
                    readShort(&dia, 1, 31, "Introduza o dia da viagem a pesquisar: ");
                    readShort(&mes, 1, 12, "Introduza o mês da viagem a pesquisar: ");
                    readShort(&ano, 2017, 2019, "Introduza o ano da viagem a pesquisar: ");
                    pesquisa_viagem_data(vetor, num_clientes, id, ano, mes, dia);
                }
                break;
            default: printf("Escolheu voltar ao menu anterior \n");
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
 * Função que preenche uma matriz quadrada de lado NUM_PORTAGENS com o
 * conteúdo do ficheiro especificado. A função pode ser utilizada para preencher
 * a matriz de distâncias ou a matriz de preços.
 * 
 * @param matriz A matriz a preencher, que deve ser previamente alocada
 * @param ficheiro O ficheiro de onde vão ser lidos os dados
 * @param distancia Indica se será preenchida a matriz de distâncias ou de preços
 * 
 * @return Indica se a função terminou com sucesso
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
 * Função que imprime a matriz de distância-preço de cada lanço
 * 
 * @param matriz onde irão ser guardados os valores de distância e preço dos lanços
 */
void imprime_matrizdistancias_precos_A1(Lanco matriz[NUM_PORTAGENS][NUM_PORTAGENS]) {

    int i, j;

    printf("Nºpórtico:        1                  2               3                4               5               6\n");
    for (i = 0; i < NUM_PORTAGENS; i++) {
        for (j = 0; j < NUM_PORTAGENS; j++) {

            if (j == 0)
                printf("    %d         ", i + 1);

            printf("%0.1f - %0.1f \t", matriz[i][j].dist, matriz[i][j].preco);
        }
        printf("\n");
    }
    printf("\nLegenda:\n");
    printf("1-Lisboa \t 2-Santarém \t 3-Leiria \t 4-Coimbra \t 5-Albergaria-a-velha \t 6-Porto \t\n");
}

/**
 * Função que carrega as matrizes distancia-preço de cada uma das classes dos veiculos
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
 * Função que serve de menu à interface(Ecra_consulta_distancias_precos_classes_A1) 
 * que imprime as distância-preço dos lanços das 4 classes dos veiculos da A1
 */
void menu_consulta_lancos() {
    int o;

    do {
        do {
            Ecra_consulta_distancias_precos_classes_A1();
            readInt(&o, 0, 4, "Introduza opção: ");
        } while (o < 0 || o > 4);
        switch (o) {
            case 1://Função que preenche e imprime na consola as distâncias-preços classe 1 da A1(já importados em txt na pasta do projeto)
                printf(" ___________________________________________________________________________________________________________\n");
                printf("|                                                                                                           |\n");
                printf("|                   Tabela das distâncias-preços entre os pórticos na A1(KM - €) Classe 1                   |\n");
                printf("|___________________________________________________________________________________________________________|\n");
                printf("\n");
                imprime_matrizdistancias_precos_A1(matrizA1_c1);
                break;
            case 2://Função que imprime na consola as distâncias-preços classe 2 da A1
                printf(" ___________________________________________________________________________________________________________\n");
                printf("|                                                                                                           |\n");
                printf("|                   Tabela das distâncias-preços entre os pórticos na A1(KM - €) Classe 2                   |\n");
                printf("|___________________________________________________________________________________________________________|\n");
                printf("\n");
                imprime_matrizdistancias_precos_A1(matrizA1_c2);
                break;
            case 3://Função que imprime na consola as distâncias-preços classe 3 da A1
                printf(" ___________________________________________________________________________________________________________\n");
                printf("|                                                                                                           |\n");
                printf("|                   Tabela das distâncias-preços entre os pórticos na A1(KM - €) Classe 3                   |\n");
                printf("|___________________________________________________________________________________________________________|\n");
                printf("\n");
                imprime_matrizdistancias_precos_A1(matrizA1_c3);
                break;
            case 4://Função que imprime na consola as distâncias-preços classe 4 da A1
                printf(" ___________________________________________________________________________________________________________\n");
                printf("|                                                                                                           |\n");
                printf("|                   Tabela das distâncias-preços entre os pórticos na A1(KM - €) Classe 4                   |\n");
                printf("|___________________________________________________________________________________________________________|\n");
                printf("\n");
                imprime_matrizdistancias_precos_A1(matrizA1_c4);
                break;
            default: printf("Escolheu voltar ao menu principal \n");
        }
    } while (o != 0);
}

/**
 * Esta função adiciona viagens a um dado cliente já criado no vetor de clientes
 *
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id id do cliente que se pretende adicionar uma determinada viagem
 */
void adicionar_viagem(Cliente *vetor, int num_clientes, int id) {

    int pos = pesquisa_id_viagens(vetor, num_clientes, id); //Verificar se o cliente existe através do id

    if (pos == -1) {
        printf("O cliente não existe!\n");
    } else {
        Cliente *cliente = vetor + pos; //incrementa uma posição do vetor

        Viagem * viagem = cliente->viagem_cliente + cliente->num_viagens;

        readShort(&viagem->info_lanco.porticoEntrada, 1, 6, "Introduza o nº do pórtico de entrada (1 a 6): ");
        readShort(&viagem->info_lanco.porticoSaida, 1, 6, "Introduza o nº do pórtico de saida (1 a 6) : ");
        while (viagem->info_lanco.porticoEntrada == viagem->info_lanco.porticoSaida) {
            if (viagem->info_lanco.porticoEntrada == viagem->info_lanco.porticoSaida) {
                printf("Erro não existe preço para este lanço (Pórtico de entrada = Pórtico de saída)!");
            }
            readShort(&viagem->info_lanco.porticoEntrada, 1, 6, "Introduza de novo o nº do pórtico de entrada: ");
            readShort(&viagem->info_lanco.porticoSaida, 1, 6, "Introduza de novo o nº do pórtico de saida: ");
        }
        int pts;
        pts = adicao_pontos_viaverde(vetor, num_clientes, viagem->info_lanco.porticoEntrada,
                viagem->info_lanco.porticoSaida, vetor[pos].id);

        printf("Foram adicionados %d pontos da viaverde ao cliente!\nPontos totais do cliente: %hd\n", pts, vetor[pos].num_ptsviaverde);
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

        printf("A velocidade do veículo entre o pórtico %hd e %hd é de : %d km/h", viagem->info_lanco.porticoEntrada,
                viagem->info_lanco.porticoSaida, vetor[pos].veiculo_cliente.velocidade);
        readShort(&viagem->dataEntrada.ano, 2017, 2019, "Introduza o ano: ");
        readShort(&viagem->dataEntrada.mes, 1, 12, "Introduza o mes: ");
        readShort(&viagem->dataEntrada.dia, 1, 31, "Introduza o dia de entrada: ");
        readShort(&viagem->horaSaida.hora, 0, 23, "Introduza a hora de saida: ");
        readShort(&viagem->horaSaida.minutos, 0, 59, "Introduza os minutos de saida:");
        cliente->num_viagens++;
        printf("\n");
        printf("Viagem acrecentada com sucesso!\n");
        escrever_dados_cliente(vetor, num_clientes);
    }
}

/**
 * Função que lista todas as viagens efetuadas (até ao momento) por um determinado cliente
 * (Nova Funcionalidade)
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id id do cliente que se pretende consultar o histórico das suas viagens
 */
void historico_viagens(Cliente *vetor, int num_clientes, int id) {

    int pos = pesquisa_id_viagens(vetor, num_clientes, id); //Verificar se o cliente existe através do id

    if (pos == -1) {
        printf("O cliente não existe!\n");
    } else {
        int j;

        for (j = 0; j < vetor[pos].num_viagens; j++) {

            printf("ID do cliente: %d\n", vetor[pos].id);
            printf("Nome do cliente: %s\n", vetor[pos].nome);
            printf("Número do cartão de cidadão: %s\n", vetor[pos].num_CC);
            printf("Pontos de via verde: %hd\n", vetor[pos].num_ptsviaverde);
            printf("Pórtico de entrada: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoEntrada);
            printf("Pórtico de saída: %hd\n", vetor[pos].viagem_cliente[j].info_lanco.porticoSaida);
            printf("Data da viagem: %hd/%hd/%hd\n", vetor[pos].viagem_cliente[j].dataEntrada.dia,
                    vetor[pos].viagem_cliente[j].dataEntrada.mes
                    , vetor[pos].viagem_cliente[j].dataEntrada.ano);
            printf("Hora de saída: %hd:%hd\n", vetor[pos].viagem_cliente[j].horaSaida.hora, vetor[pos].viagem_cliente[j].horaSaida.minutos);
            switch (vetor[pos].veiculo_cliente.classe) {
                case 1: printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                    break;
                case 2:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);

                    break;
                case 3:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);
                    break;
                case 4:printf("Custo da viagem: %0.1f€\n", vetor[pos].viagem_cliente[j].info_lanco.custo);

                    break;
            }
            printf("Velocidade à passagem no lanço: %d", vetor[pos].veiculo_cliente.velocidade);
            printf("\n");
        }
    }
}

/**
 * Função que edita todos os preços na matriz de todos os pares de pórticos para uma determinada classe
 * 
 * @param novo_entrada número do pórtico de entrada a editar
 * @param novo_saida número do pórtico de saída a editar
 */
void menu_edicao_par_portico_preco(short novo_entrada, short novo_saida) {

    int i, j, o;

    do {
        do {
            Ecra_edicao_parportico_preco();
            readInt(&o, 0, 4, "Introduza a classe de veiculos que pretende editar: ");
        } while (o < 0 || o > 4);
        switch (o) {
            case 1:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i + 1 == novo_entrada && j + 1 == novo_saida) {
                            printf("Introduza o novo preço entre o pórtico %d para %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c1[i][j].preco, 0, 1000, "");
                        }
                    }
                }
                FILE *file1;
                file1 = fopen("A1classe1.txt", "wt"); // cria o ficheiro desejado

                if (file1 == NULL) {
                    printf("ERRO!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file1, "%f\t", matrizA1_c1[i][j].preco); // prenche no ficheiro a matriz anteriormente criada
                        }
                        fprintf(file1, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c1, "A1classe1.txt", false);
                    fclose(file1);
                }
                printf("Preço do entre o lanço do pórtico %hd ao pórtico %hd alterado com sucesso!\n", novo_entrada, novo_saida);
                break;
            case 2:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i + 1 == novo_entrada && j + 1 == novo_saida) {
                            printf("Introduza o novo preço entre o pórtico %d para %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c2[i][j].preco, 0, 1000, "");
                        }
                    }
                }
                FILE *file2;
                file2 = fopen("A1classe2.txt", "wt"); // cria o ficheiro desejado

                if (file2 == NULL) {
                    printf("ERRO!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file2, "%f\t", matrizA1_c2[i][j].preco); // prenche no ficheiro a matriz anteriormente criada
                        }
                        fprintf(file2, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c2, "A1classe2.txt", false);
                    fclose(file2);
                }
                printf("Preço do lanço de todos os pórticos alterado com sucesso!\n");
                break;
            case 3:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i + 1 == novo_entrada && j + 1 == novo_saida) {
                            printf("Introduza o novo preço entre o pórtico %d para %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c3[i][j].preco, 0, 1000, "");
                        }
                    }
                }
                FILE *file3;
                file3 = fopen("A1classe3.txt", "wt"); // cria o ficheiro desejado

                if (file3 == NULL) {
                    printf("ERRO!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file3, "%f\t", matrizA1_c3[i][j].preco); // prenche no ficheiro a matriz anteriormente criada
                        }
                        fprintf(file3, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c3, "A1classe3.txt", false);
                    fclose(file3);
                }
                printf("Preço do lanço de todos os pórticos alterado com sucesso!\n");
                break;
            case 4:;
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i + 1 == novo_entrada && j + 1 == novo_saida) {
                            printf("Introduza o novo preço entre o pórtico %d para %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c4[i][j].preco, 0, 1000, "");
                        }
                    }
                }
                FILE *file4;
                file4 = fopen("A1classe4.txt", "wt"); // cria o ficheiro desejado

                if (file4 == NULL) {
                    printf("ERRO!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file4, "%f\t", matrizA1_c4[i][j].preco); // prenche no ficheiro a matriz anteriormente criada
                        }
                        fprintf(file4, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c4, "A1classe4.txt", false);
                    fclose(file4);
                }
                printf("Preço do lanço de todos os pórticos alterado com sucesso!\n");
                break;
            default: printf("Escolheu voltar ao menu anterior\n");
        }
    } while (o != 0);
}

/**
 * Função que edita todos os preços de todos os pares de pórticos presentes numa matriz para uma determinada classe de veículo
 */
void menu_edicao_geral_precos() {

    int i, j, o;
    do {
        do {
            Ecra_edicao_geral_precos();
            readInt(&o, 0, 4, "Introduza a classe de veiculos que pretende editar: ");
        } while (o < 0 || o > 4);
        switch (o) {
            case 1:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i == j) {
                            matrizA1_c1[i][j].preco = 0;
                        } else {
                            printf("Insira o preço entre o pórtico %d para %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c1[i][j].preco, 0, 1000, "");
                        }
                    }
                }

                FILE *file1;
                file1 = fopen("A1classe1.txt", "wt"); // cria o ficheiro desejado

                if (file1 == NULL) {
                    printf("ERRO!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file1, "%f\t", matrizA1_c1[i][j].preco); // prenche no ficheiro a matriz anteriormente criada
                        }
                        fprintf(file1, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c1, "A1classe1.txt", false);
                    fclose(file1);
                }
                printf("Preço do lanço de todos os pórticos alterado com sucesso!\n");
                break;
            case 2:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i == j) {
                            matrizA1_c1[i][j].preco = 0;
                        } else {
                            printf("Insira o preço entre o pórtico %d para %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c2[i][j].preco, 0, 1000, "");
                        }
                    }
                }

                FILE *file2;
                file2 = fopen("A1classe2.txt", "wt"); // cria o ficheiro desejado

                if (file2 == NULL) {
                    printf("ERRO!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file2, "%f\t", matrizA1_c2[i][j].preco); // prenche no ficheiro a matriz anteriormente criada
                        }
                        fprintf(file2, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c2, "A1classe2.txt", false);
                    fclose(file2);
                }
                printf("Preço do lanço de todos os pórticos alterado com sucesso!\n");
                break;
            case 3:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i == j) {
                            matrizA1_c3[i][j].preco = 0;
                        } else {
                            printf("Insira o preço entre o pórtico %d para %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c3[i][j].preco, 0, 1000, "");
                        }
                    }
                }

                FILE *file3;
                file3 = fopen("A1classe3.txt", "wt"); // cria o ficheiro desejado

                if (file3 == NULL) {
                    printf("ERRO!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file3, "%f\t", matrizA1_c3[i][j].preco); // prenche no ficheiro a matriz anteriormente criada
                        }
                        fprintf(file3, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c3, "A1classe3.txt", false);
                    fclose(file3);
                }
                printf("Preço do lanço de todos os pórticos alterado com sucesso!\n");
                break;
            case 4:
                for (i = 0; i < NUM_PORTAGENS; i++) {
                    for (j = 0; j < NUM_PORTAGENS; j++) {
                        if (i == j) {
                            matrizA1_c4[i][j].preco = 0;
                        } else {
                            printf("Insira o preço entre o pórtico %d para %d:", i + 1, j + 1);
                            readFloat(&matrizA1_c4[i][j].preco, 0, 1000, "");
                        }
                    }
                }

                FILE *file4;
                file4 = fopen("A1classe4.txt", "wt"); // cria o ficheiro desejado

                if (file4 == NULL) {
                    printf("ERRO!");
                } else {
                    for (i = 0; i < NUM_PORTAGENS; i++) {
                        printf("\n");
                        for (j = 0; j < NUM_PORTAGENS; j++) {
                            fprintf(file4, "%f\t", matrizA1_c4[i][j].preco); // prenche no ficheiro a matriz anteriormente criada
                        }
                        fprintf(file4, "\n");
                    }
                    preencheMatriz((Lanco*) matrizA1_c4, "A1classe4.txt", false);
                    fclose(file4);
                }
                printf("Preço do lanço de todos os pórticos alterado com sucesso!\n");
                break;
            default: printf("Escolheu voltar ao menu anterior\n");
        }
    } while (o != 0);
}

/**
 * Função que serve como menu à função interface (Ecra_gestao_precos) e onde vão ser chamadas também
 * as funções de edição de preço num determinado par de pórticos e de edição geral do preços
 */
void menu_gestao_precos() {

    int o;
    short novo_entrada, novo_saida;

    do {
        do {
            Ecra_gestao_precos();
            readInt(&o, 0, 2, "Introduza opção: ");
        } while (o < 0 || o > 2);
        switch (o) {
            case 1:
                readShort(&novo_entrada, 1, 6, "Introduza o pórtico de entrada (de 1 a 6): ");
                readShort(&novo_saida, 1, 6, "Introduza o pórtico de saida(de 1 a 6): ");
                menu_edicao_par_portico_preco(novo_entrada, novo_saida);
                break;
            case 2:
                menu_edicao_geral_precos();
                break;
            default: printf("Escolheu voltar ao menu principal \n");
        }
    } while (o != 0);
}

/**
 * Função que serve como menu à função interface (Ecra_gestao_lancos) e onde vão ser chamadas também
 * as funções de consultar lanços e de edição dos preços dos mesmos
 */
void menu_gestao_lancos() {

    int o;

    do {
        do {
            Ecra_gestao_lancos();
            readInt(&o, 0, 2, "Introduza opção: ");
        } while (o < 0 || o > 2);
        switch (o) {
            case 1:
                menu_consulta_lancos();
                break;
            case 2:
                menu_gestao_precos();
                break;
            default: printf("Escolheu voltar ao menu principal \n");

        }
    } while (o != 0);
}

/**
 * Função que imprime uma fatura para ficheiro txt de todas as viagens de um cliente feitas num determinado mês
 *  
 * @param vetor vetor de clietnes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id identificador do cliente
 * @param mes mês da viagem efetuada
 * @param ano ano da viagem efetuada (apesar de ser uma fatura mensal pode existir repetição de meses e o dado "ano" vai servir para não ocorrer a repetição)
 */
void geracao_fatura_cliente(Cliente *vetor, int num_clientes, int id, short mes, short ano) {
    int pos, conf;
    float total = 0;

    FILE *file;
    if (file == NULL) {
        perror("Erro:\n");
    } else {
        conf = pesquisa_id_clientes(vetor, num_clientes, id); //pesquisa para confimar a existência do id do cliente a gerar a fatura

        if (conf == -1) {
            printf("O id cliente não existe!\n");
        } else {
            if (vetor[conf].num_viagens == 0) {
                printf("De momento o cliente não efetuou nenhuma viagem logo não é possível gerar-se uma fatura para o mesmo!\n");
            } else {
                //pesquisa do mês em que foram feitas as viagens de modo a confirmar se foram feitas naquele mês ou não
                pos = pesquisa_mes_viagens(vetor, num_clientes, vetor[conf].id, mes);

                if (pos == -1) {
                    printf("O cliente não efetuou nenhuma viagem nesse mês!");
                } else {

                    file = fopen("Fatura.txt", "wt");

                    fprintf(file, " ______________________________________________________\n");
                    fprintf(file, "|                                                      |\n");
                    fprintf(file, "|      Geração da fatura mensal do cliente nº%d         |\n", vetor[conf].id);
                    fprintf(file, "|______________________________________________________|\n");
                    fprintf(file, "\n");
                    fprintf(file, "ID do cliente: %d\n", vetor[conf].id);
                    fprintf(file, "\n");
                    fprintf(file, "Nome do cliente: %s\n", vetor[conf].nome);
                    fprintf(file, "\n");
                    fprintf(file, "NIF do cliente: %d\n", vetor[conf].NIF);
                    fprintf(file, "\n");
                    fprintf(file, "Nº Cartão de cidadão: %s\n", vetor[conf].num_CC);
                    fprintf(file, "\n");
                    fprintf(file, "NIB: %s\n", vetor[conf].NIB);
                    fprintf(file, "\n");
                    fprintf(file, "Morada: %s\n", vetor[conf].morada);
                    fprintf(file, "\n");
                    fprintf(file, "Nº de pontos de via verde: %hd\n", vetor[conf].num_ptsviaverde);
                    fprintf(file, "\n");
                    fprintf(file, "Matrícula: %s\n", vetor[conf].veiculo_cliente.matricula);
                    fprintf(file, "\n");
                    fprintf(file, "Marca : %s\n", vetor[conf].veiculo_cliente.marca);
                    fprintf(file, "\n");
                    fprintf(file, "Modelo: %s\n", vetor[conf].veiculo_cliente.modelo);
                    fprintf(file, "\n");
                    fprintf(file, "Classe do veículo : %hd\n", vetor[conf].veiculo_cliente.classe);
                    fprintf(file, "\n\n");

                    for (int j = 0; j < vetor[conf].num_viagens; j++) {
                        if (vetor[conf].viagem_cliente[j].dataEntrada.mes == mes && vetor[conf].viagem_cliente[j].dataEntrada.ano == ano) {
                            fprintf(file, "Viagem nº%d", j + 1);
                            fprintf(file, "\n\n");
                            fprintf(file, "\n");
                            fprintf(file, "Pórtico de entrada: %hd\n", vetor[conf].viagem_cliente[j].info_lanco.porticoEntrada);
                            fprintf(file, "\n");
                            fprintf(file, "Pórtico de saída: %hd\n", vetor[conf].viagem_cliente[j].info_lanco.porticoSaida);
                            fprintf(file, "\n");
                            fprintf(file, "Data da viagem: %hd/%hd/%hd\n", vetor[conf].viagem_cliente[j].dataEntrada.dia,
                                    vetor[conf].viagem_cliente[j].dataEntrada.mes
                                    , vetor[conf].viagem_cliente[j].dataEntrada.ano);
                            fprintf(file, "\n");
                            fprintf(file, "Hora de saída: %hd:%hd\n", vetor[conf].viagem_cliente[j].horaSaida.hora, vetor[conf].viagem_cliente[j].horaSaida.minutos);
                            fprintf(file, "\n");
                            total += vetor[conf].viagem_cliente[j].info_lanco.custo;
                            fprintf(file, "Velocidade à passagem no lanço: %d km/h", vetor[conf].veiculo_cliente.velocidade);
                            fprintf(file, "\n\n");
                        }
                    }
                    fprintf(file, "Custo total das viagens do cliente : %0.1f€", total);
                    fprintf(file, "\n");
                    printf("Fatura mensal gerada com sucesso!\n");
                }
                fclose(file);
                total = 0;
            }
        }
    }
}

/**
 * Função que serve como um menu das funcionalidades correspondente ao "interface"
 * da 2º opção menu principal (Gestão de viagens) 
 * 
 * @param vetor vetor de clientes
 * @param num_viagens um apontador do número de viagens que existem no vetor de clientes
 * @param num_clientes um apontador do número de clientes que existem no vetor
 */
void menu_gestao_viagens(Cliente* clientes, int num_clientes) {

    int o, id;

    do {
        do {
            Ecra_gestao_viagens();
            readInt(&o, 0, 3, "Introduza opção: ");
        } while (o < 0 || o > 3);
        switch (o) {
            case 1:
                Ecra_acrecentar_viagem(); //menu para acrescentar viagem
                imprime_id_existentes(clientes, num_clientes);
                readInt(&id, 1, 1000, "Introduza o ID do cliente que pretende acrecentar a viagem: ");
                adicionar_viagem(clientes, num_clientes, id);
                break;
            case 2://menu gestão de lanços
                menu_gestao_lancos();
                break;
            case 3://menu pesquisar viagens
                menu_gestao_pesquisa_viagens(clientes, num_clientes);
                break;
            default: printf("Escolheu voltar ao menu principal \n");
        }
    } while (o != 0);
}
