/**
 * @file Clientes.c
 * @author Grupo 22-30 João Pereira , Bruno Teixeira, Rui Vieira, Carlos Ribeiro.
 * @brief Gestão de clientes.
 * @date 27 de Novembro de 2018
 *
 * Ficheiro onde estão implementadas um conjunto de funções relativas à gestão de clientes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "API_Leitura.h"
#include "Clientes.h"
#include "Viagens.h"
#include "Estruturas.h"


Lanco matrizA1_c1[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c2[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c3[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_c4[NUM_PORTAGENS][NUM_PORTAGENS];
Lanco matrizA1_pts[NUM_PORTAGENS][NUM_PORTAGENS];

/**
 * @brief Esta função serve como "interface" das opções do menu principal
 */
void Ecra_menu_principal() {//Menu principal
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|                     Via Verde                            |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Gestão de clientes                              |\n");
    printf("|     2 -> Gestão de viagens                               |\n");
    printf("|     3 -> Geração de faturas                              |\n");
    printf("|     4 -> Novas funcionalidades                           |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Sair                                            |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 1º opção menu principal (Gestão de clientes)
 */
void Ecra_gestao_clientes() {
    printf(" __________________________________________________________ \n");
    printf("|                                                          |\n");
    printf("|                  Gestão de clientes                      |\n");
    printf("|                                                          |\n");
    printf("|     1 -> Criar cliente                                   |\n");
    printf("|     2 -> Editar cliente                                  |\n");
    printf("|     3 -> Remover cliente                                 |\n");
    printf("|     4 -> Pesquisar cliente                               |\n");
    printf("|     5 -> Lista dos clientes introduzidos                 |\n");
    printf("|                                                          |\n");
    printf("|     0 -> Voltar ao menu principal                        |\n");
    printf("|__________________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 1º opção da gestão de clientes
 */
void Ecra_criar_cliente() {
    printf(" ________________________________________________\n");
    printf("|                                                |\n");
    printf("|             Criação do cliente                 |\n");
    printf("|________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 2º opção da gestão de clientes
 */
void Ecra_editar_cliente() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|               Edição do cliente                 |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 3º opção da gestão de clientes
*/
void Ecra_remover_cliente() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|               Remoção do cliente                |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 4º opção da gestão de clientes
 */
void Ecra_pesquisar_cliente() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|              Pesquisa do cliente                |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 5º opção da gestão de clientes
 */
void Ecra_listar_cliente() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|   Lista dos clientes criados até ao momento     |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 3º opção menu principal (Geração de faturas)
 */
void Ecra_geracaofatura() {//4ºOpção do menu principal(Geração de faturas
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|    Geração da fatura mensal do cliente nº       |\n");
    printf("|_________________________________________________|\n");
}
 /**
  * @brief Esta função serve como "interface" da para o uso da persistência de dado usado no main
  */
void ecra_persistenciadados() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|             Persistência de dados               |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 5º opção menu principal (Gestão de clientes)
 */
void Ecra_novas_funcionalidades() {
    printf(" ______________________________________________________________ \n");
    printf("|                                                              |\n");
    printf("|                  Novas funcionalidades                       |\n");
    printf("|                                                              |\n");
    printf("|     1 -> Desconto dos pontos via verde nas promoções         |\n");
    printf("|     2 -> Histórico de viagens de um cliente                  |\n");
    printf("|     3 -> Simulação do custo de uma dada viagem               |\n");
    printf("|     4 -> Velocidade do veiculo num lanço                     |\n");
    printf("|     5 -> Adição de pontos de viaverde ao cliente             |\n");
    printf("|     6 -> Consulta dos pontos entre os pares de pórticos      |\n");
    printf("|                                                              |\n");
    printf("|     0 -> Voltar ao menu principal                            |\n");
    printf("|______________________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 1º opção das novas funcionalidades
 */
void Ecra_desconto_pontos_viaverde() {
    printf(" _______________________________________________________________________________\n");
    printf("|                                                                               |\n");
    printf("|                 Desconto dos pontos via verde nas promoções                   |\n");
    printf("|                                                                               |\n");
    printf("|  1 -> Desconto 25%% num bilhete para 2 pessoas para o cinema NOS (2 pontos)   |\n");
    printf("|  2 -> Desconto 30%% prova de vinhos e visita à adega de Felgueiras (5 pontos) |\n");
    printf("|  3 -> Desconto 50%% para o passe geral Super Bock Super Rock  (10 pontos)     |\n");
    printf("|                                                                               |\n");
    printf("|  0 -> Voltar ao menu principal                                                |\n");
    printf("|_______________________________________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 2º opção das novas funcionalidades
 */
void Ecra_historico_viagens() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|       Histórico das viagens do cliente          |\n");
    printf("|_________________________________________________|\n");
}

/**
 * @brief Esta função serve como "interface" da 3º opção das novas funcionalidades
 */
void Ecra_classe_veiculo_simulacao() {
    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|   Simulacao de custo e pontos de uma viagem     |\n");
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
 * Função que percorre a matriz dos pontos da via verde e imprime o custo e o nº de pontos da via verde do pórtico de entrada ao pórtico de saída (lanço)
 * (Nova funcionalidade)
 *  
 * @param num_entrada número do pórtico de entrada
 * @param num_saida número do pórtico de saída
 */
void simulacao_custo_pontos(short num_entrada, short num_saida) {

    int o;

    do {
        do {
            Ecra_classe_veiculo_simulacao();
            readInt(&o, 0, 4, "Introduza a classe dos veículos a usar na simulação: ");
        } while (o < 0 || o > 4);
        switch (o) {
            case 1:
                if (num_entrada == num_saida) {
                    printf("Nº do pórtico de entrada é igual ao nº do pórtico de saída");
                } else {
                    for (int i = 0; i < NUM_PORTAGENS; i++) {
                        for (int j = 0; j < NUM_PORTAGENS; j++) {
                            if (i + 1 == num_entrada && j + 1 == num_saida) {
                                printf("O custo entre o pórtico %hd e o pórtico %hd é de : %0.2f€ e o cliente ganha %hd pontos da via verde\n",
                                        num_entrada, num_saida, matrizA1_c1[i][j].preco, matrizA1_pts[i][j].pontos);
                            }
                        }
                    }
                }
                break;
            case 2:
                if (num_entrada == num_saida) {
                    printf("Nº do pórtico de entrada é igual ao nº do pórtico de saída");
                } else {
                    for (int i = 0; i < NUM_PORTAGENS; i++) {
                        for (int j = 0; j < NUM_PORTAGENS; j++) {
                            if (i + 1 == num_entrada && j + 1 == num_saida) {
                                printf("O custo entre o pórtico %hd e o pórtico %hd é de : %0.2f€ e o cliente ganha %hd pontos da via verde\n",
                                        num_entrada, num_saida, matrizA1_c2[i][j].preco, matrizA1_pts[i][j].pontos);
                            }
                        }
                    }
                }
                break;
            case 3:
                if (num_entrada == num_saida) {
                    printf("Nº do pórtico de entrada é igual ao nº do pórtico de saída");
                } else {
                    for (int i = 0; i < NUM_PORTAGENS; i++) {
                        for (int j = 0; j < NUM_PORTAGENS; j++) {
                            if (i + 1 == num_entrada && j + 1 == num_saida) {
                                printf("O custo entre o pórtico %hd e o pórtico %hd é de : %0.2f€ e o cliente ganha %hd pontos da via verde\n",
                                        num_entrada, num_saida, matrizA1_c3[i][j].preco, matrizA1_pts[i][j].pontos);
                            }
                        }
                    }
                }
                break;
            case 4:
                if (num_entrada == num_saida) {
                    printf("Nº do pórtico de entrada é igual ao nº do pórtico de saída");
                } else {
                    for (int i = 0; i < NUM_PORTAGENS; i++) {
                        for (int j = 0; j < NUM_PORTAGENS; j++) {
                            if (i + 1 == num_entrada && j + 1 == num_saida) {
                                printf("O custo entre o pórtico %hd e o pórtico %hd é de : %0.2f€ e o cliente ganha %hd pontos da via verde\n",
                                        num_entrada, num_saida, matrizA1_c4[i][j].preco, matrizA1_pts[i][j].pontos);
                            }
                        }
                    }
                }
                break;
            default: printf("Escolheu voltar ao menu anterior \n");
        }
    } while (o != 0);
}

/**
 * Função que imprime a matriz de distância-preço de cada lanço
 * 
 * @param matriz onde irão ser guardados os valores de distância e os pontos dos lanços
 */
void imprime_matrizpontos_A1(Lanco matriz[NUM_PORTAGENS][NUM_PORTAGENS]) {

    int i, j;

    printf("Nºpórtico:1     2       3       4       5       6\n");
    printf("\n");
    for (i = 0; i < NUM_PORTAGENS; i++) {
        for (j = 0; j < NUM_PORTAGENS; j++) {
            if (j == 0)
                printf("    %d     ", i + 1);

            printf("%hd\t", matriz[i][j].pontos);
        }
        printf("\n");
    }
    printf("\nLegenda:\n");
    printf("1-Lisboa \t 2-Santarém \t 3-Leiria \t 4-Coimbra \t 5-Albergaria-a-velha \t 6-Porto \t\n");
}

/**
 * Função que atribui um valor de velocidade ,aleatório(função rand()) compreendido entre 30 e 60 tentando aproximar se da realidade, ao veiculo 
 * aquando da passagem por um lanço
 * (Nova Funcionalidade)
 * 
 * @param vetor vetor dos clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param num_viagens o número de viagens que existem no vetor
 * @param id identificador do cliente 
 * @param velocidade vetor onde estão guardadas as velocidades em cada lanço que o veiculo passa
 */
void velocidade_lanco(Cliente *vetor, int num_clientes, int num_viagens, int id, int velocidade) {

    srand((unsigned) time(NULL));

    int pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("O id do cliente não existe!\n");
    } else {

        do {
            velocidade = rand() % 100;
        } while (velocidade <= 30 && velocidade >= 60);

        vetor[pos].veiculo_cliente.velocidade = velocidade;
    }
}

/**
 * Função que adiciona pontos de viaverde ao cliente mediante as viagens que vai fazendo entre cada lanço
 * (Nova Funcionalidade)
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param num_entrada o número do pórtico de entrada
 * @param num_saida o número do pórtico de saída
 * @param id identificador do cliente a atribuir os pontos da via verde
 * @return número de pontos atribuidos numa determinada viagem
 */
int adicao_pontos_viaverde(Cliente *vetor, int num_clientes, short num_entrada, short num_saida, int id) {

    int pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("O id do cliente não existe!\n");
    } else {
        if (num_entrada == num_saida) {
            printf("Nº do pórtico de entrada é igual ao nº do pórtico de saída");
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
 * Função que serve como um menu de descontos ao qual o utilizador escolhe uma opção e nessa opção é lhe descontado um número de pontos,
 * se não tiver pontos suficientes recebe uma informação a dizer que não tem pontos suficientes para a promoção que escolheu
 * (Nova Funcionalidade)
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 */
void descontos_pontos_viaverde(Cliente *vetor, int *num_clientes) {

    int o, id, pos;

    do {
        do {
            Ecra_desconto_pontos_viaverde();
            readInt(&o, 0, 3, "Escolha promoção: ");
        } while (o < 0 || o > 3);

        if (o != 0) {
            readInt(&id, 1, 1000, "Introduza o ID do cliente para o desconto de pontos da via verde: ");
            pos = pesquisa_id_clientes(vetor, *num_clientes, id);

            if (pos == -1) {
                printf("O id do cliente não existe!\n");
            } else {
                switch (o) {
                    case 1:
                        if (vetor[pos].num_ptsviaverde < 2) {
                            printf("Não tem pontos suficientes para esta promoção! Pontos atuais: %hd\n",
                                    vetor[pos].num_ptsviaverde);
                        } else {
                            vetor[pos].num_ptsviaverde = vetor[pos].num_ptsviaverde - 2;
                            printf("Desconto efetuado com êxito!Pontos atuais vetor: %hd\n", vetor[pos].num_ptsviaverde);
                        }
                        break;
                    case 2:
                        if (vetor[pos].num_ptsviaverde < 5) {
                            printf("Não tem pontos suficientes para esta promoção! Pontos atuais: %hd\n",
                                    vetor[pos].num_ptsviaverde);
                        } else {
                            vetor[pos].num_ptsviaverde = vetor[pos].num_ptsviaverde - 5;
                            printf("Desconto efetuado com êxito!Pontos atuais vetor: %hd\n", vetor[pos].num_ptsviaverde);
                        }
                        break;
                    case 3:
                        if (vetor[pos].num_ptsviaverde < 10) {
                            printf("Não tem pontos suficientes para esta promoção! Pontos atuais: %hd\n",
                                    vetor->num_ptsviaverde);
                        } else {
                            vetor[pos].num_ptsviaverde = vetor[pos].num_ptsviaverde - 10;
                            printf("Desconto efetuado com êxito!Pontos atuais vetor: %hd\n", vetor[pos].num_ptsviaverde);
                        }
                        break;
                }
            }
        } else {
            printf("Escolheu voltar ao menu anterior \n");
        }
    } while (o != 0);
}

/**
 * Função que serve como um menu para as novas funcionalidades do projeto
 * (Novas Funcionalidades)
 * 
 * @param vetor apontador para o vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param tam_max o tamanho do vetor
 */
void menu_novas_funcionalidades(Cliente **vetor, int *num_clientes, int *tam_max) {

    int o, id;
    short num_entrada, num_saida;

    do {
        do {
            Ecra_novas_funcionalidades();
            readInt(&o, 0, 6, "Introduza opção: ");
        } while (o < 0 || o > 6);
        switch (o) {
            case 1: descontos_pontos_viaverde(*vetor, num_clientes);
                break;
            case 2:Ecra_historico_viagens();
                readInt(&id, 0, 10000, "Introduza o ID do cliente que pretende pesquisar: ");
                historico_viagens(*vetor, *num_clientes, id);
                break;
            case 3:
                readShort(&num_entrada, 1, 6, "Introduza o número do pórtico de entrada(1 a 6)");
                readShort(&num_saida, 1, 6, "Introduza o número do pórtico de saída(1 a 6)");
                simulacao_custo_pontos(num_entrada, num_saida);
                break;
            case 4:printf("Consultar viagens.c -> função adicionar_viagens -> linha 757");
                break;
            case 5: printf("Consultar viagens.c -> função adicionar_viagens -> linha 742 à 745");
                break;
            case 6:imprime_matrizpontos_A1(matrizA1_pts);
                break;
            default: printf("Escolheu voltar ao menu principal \n");
        }
    } while (o != 0);

}

/**
 * Escreve o conteúdo do vetor da estrutura cliente em ficheiro binário
 *
 * @param vetor apontador para o primeiro cliente do vetor
 * @param num_clientes número de clientes que existem no vetor de clientes
 */
void escrever_dados_cliente(Cliente *vetor, int num_clientes) {
    FILE *f;

    if ((f = fopen("clientes.bin", "wb")) == NULL)
        perror(NULL);
    else {
        fwrite(&num_clientes, sizeof (int), 1, f);
        fwrite(vetor, sizeof (Cliente), num_clientes, f);
        fclose(f);
    }
}

/**
 * Lê dados de ficheiro(se existir) e preenche o vetor da estrutura cliente e o
 * seu número
 *
 * @param vetor um apontador para o endereço de memória do primeiro cliente
 * a preencher
 * @param num_clientes um apontador para o número de clientes que existem no vetor de clientes
 * @param tam_max apontador para o tamanho do vetor de clientes
 */
void ler_dados_cliente(Cliente **vetor, int *num_clientes, int *tam_max) {

    FILE *f;
    int nr;

    if ((f = fopen("clientes.bin", "rb")) == NULL) {
        *num_clientes = 0;
        *tam_max = 0;
        perror(NULL);
    } else {
        nr = fread(num_clientes, sizeof (int), 1, f);

        if (nr != 1) {
            printf("Erro ao ler o número de elementos!\n");
            return;
        }

        *vetor = malloc((*num_clientes + 5) * sizeof (Cliente));

        if (*vetor == NULL) {
            printf("Impossível alocar memória");
            *num_clientes = 0;
            *tam_max = 0;
        } else {
            printf("Alocou %d bytes de memória.\n", (*num_clientes) * sizeof (Cliente));
            nr = fread(*vetor, sizeof (Cliente), *num_clientes, f);

            if (nr == *num_clientes) {
                *tam_max = *num_clientes;
                *num_clientes = nr;
            } else {
                printf("Erro ao ler elementos!\n");
                *tam_max = 0;
                *num_clientes = 0;
                free(*vetor);
            }
        }
        fclose(f);
    }
}

/**
 * Esta função adiciona e cria um cliente no vetor
 * 
 * @param ptrcliente apontador para o vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param tam_max o tamanho do vetor de clientes
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
            readInt(&ptr->id, 1, 1000, "Introduza de novo o ID (O id já existe introduza outro): ");
            pos = pesquisa_id_clientes(*ptrcliente, *num_clientes, ptr->id);
        } while (pos != -1);
        printf("ID validado com sucesso!\n");
    }
    readString(ptr->nome, MAX_STR - 1, "Nome do cliente: ");
    readInt(&ptr->NIF, 100000000, 199999999, "NIF: ");
    readString(ptr->num_CC, 8 + 1, "Nº Cartão de cidadão: ");
    readString(ptr->NIB, MAX_NIB - 1, "NIB: ");
    readString(ptr->morada, MAX_STR - 1, "Morada: ");
    ptr->num_ptsviaverde = 0;
    ptr->num_viagens = 0;
    readString(ptr->veiculo_cliente.matricula, MAX_MAT - 1, "Matrícula: ");
    mat = pesquisa_viagem_matricula(*ptrcliente, *num_clientes, ptr->veiculo_cliente.matricula);
    if (mat != -1) {
        do {
            readString(ptr->veiculo_cliente.matricula, MAX_MAT - 1, "Introduza de novo a matrícula do veículo(a matrícula já existe introduza outra): ");
            mat = pesquisa_viagem_matricula(*ptrcliente, *num_clientes, ptr->veiculo_cliente.matricula);
        } while (mat != -1);
    }
    readString(ptr->veiculo_cliente.marca, MAX_MAT - 1, "Marca : ");
    readString(ptr->veiculo_cliente.modelo, MAX_MAT - 1, "Modelo: ");
    readShort(&ptr->veiculo_cliente.classe, 0, 4, "Classe do veículo : ");
    printf("Cliente criado com sucesso! \n");
    printf("Posição do vetor: %d\n", *num_clientes);
    (*num_clientes)++;

    escrever_dados_cliente(*ptrcliente, *num_clientes);
}

/**
 * Função que devolve um apontador para o cliente dado o seu id, se existir
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id identificador do cliente a obter
 * @return um apontador para o cliente , ou NULL se não existir
 */
Cliente * getCliente(Cliente *vetor, int *num_clientes, int id) {

    int pos = pesquisa_id_clientes(vetor, *num_clientes, id);

    if (pos == -1)
        return NULL;
    else
        return &vetor[pos];
}

/**
 * Função que atualiza a informação de um cliente, se existir
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id identificador do cliente a obter
 */
void atualiza_cliente(Cliente *vetor, int *num_clientes, int id) {

    int pos = pesquisa_id_clientes(vetor, *num_clientes, id); //Verificar se o cliente existe através do id

    if (pos == -1) {
        printf("O cliente não existe!\n");
    } else {
        if (vetor[pos].id == id) {

            Cliente * novo;

            novo = getCliente(vetor, num_clientes, id);

            if (novo != NULL) {
                novo->id = id;
                readString(novo->nome, MAX_STR - 1, "Novo nome do cliente: ");
                readInt(&novo->NIF, 100000000, 199999999, "Novo NIF: ");
                readString(novo->num_CC, MAX_CC - 1, "Novo nº Cartão de cidadão: ");
                readString(novo->NIB, MAX_NIB - 1, "Novo NIB: ");
                readString(novo->morada, MAX_STR - 1, "NovaMorada: ");
                printf("Informações do cliente atualizados com sucesso!\n");
            }
        }
    }
}

/**
 * Função que remove o cliente dado o seu id
 * 
 * @param vetor apontador para o vetor de clientes
 * @param num_clientes apontador para o número de clientes que existem no vetor
 * @param tam_max apontador para o tamanho do vetor
 * @param id identificador do cliente a remover
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
        printf("Cliente removido!\n");

        if (*tam_max - *num_clientes >= TAM_DECREMENTO) {
            novo = realloc(*vetor, ((*tam_max) * sizeof (Cliente))
                    - TAM_DECREMENTO * sizeof (Cliente));
            if (novo == NULL) {
                printf("Realocação de memória falhou. \n");
            } else {
                printf("Realocou memória. Novo tamanho: %d bytes. \n",
                        ((*tam_max) * sizeof (Cliente)) - TAM_DECREMENTO * sizeof (Cliente));
                *vetor = novo;
                (*tam_max) -= TAM_DECREMENTO;
            }
        }
    } else
        printf("Cliente com id %d não existe! \n", id);
}

/**
 * Função que pesquisa o cliente dado o seu id e de seguida imprime toda a informação 
 * relativa a esse mesmo cliente
 * 
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 * @param id identificador do cliente a pesquisar
 */
void pesquisar_cliente(Cliente *vetor, int num_clientes, int id) {

    int pos = pesquisa_id_clientes(vetor, num_clientes, id);

    if (pos == -1) {
        printf("O cliente não existe!\n");
    } else {
        printf("ID: %d\n", vetor[pos].id);
        printf("Nome do cliente: %s\n", vetor[pos].nome);
        printf("NIF: %d\n", vetor[pos].NIF);
        printf("Nº Cartão de cidadão: %s\n", vetor[pos].num_CC);
        printf("NIB: %s\n", vetor[pos].NIB);
        printf("Morada: %s\n", vetor[pos].morada);
        printf("Nº de pontos de via verde: %hd\n", vetor[pos].num_ptsviaverde);
        printf("Matrícula: %s\n", vetor[pos].veiculo_cliente.matricula);
        printf("Marca : %s\n", vetor[pos].veiculo_cliente.marca);
        printf("Modelo: %s\n", vetor[pos].veiculo_cliente.modelo);
        printf("Classe do veículo : %hd\n", vetor[pos].veiculo_cliente.classe);
    }
}

/**
 * Função que lista todos os clientes introduzidos até ao momento
 *
 * @param vetor vetor de clientes
 * @param num_clientes o número de clientes que existem no vetor
 */
void listar_clientes(Cliente *vetor, int num_clientes) {

    if (num_clientes == 0) {
        printf("Não foram criados clientes até ao momento!\n");
    } else {
        int j;
        for (j = 0; j < num_clientes; j++) {

            printf("ID do cliente: %d\n", vetor[j].id);
            printf("Nome do cliente: %s\n", vetor[j].nome);
            printf("Número do cartão de cidadão: %s\n", vetor[j].num_CC);
            printf("Pontos de via verde: %hd\n", vetor[j].num_ptsviaverde);
            printf("Posição do vetor: %d\n", j);
            printf("\n");
        }
    }
}

/**
 * Função que serve como um menu das funcionalidades correspondente ao "interface"
 * da 1º opção menu principal (Gestão de clientes) 
 * 
 * @param vetor apontador para o vetor de clientes
 * @param num_clientes um apontador do número de clientes que existem no vetor 
 * @param tam_max um apontador do tamanho do vetor de clientes
 */
void menu_gestao_clientes(Cliente** vetor, int *num_clientes, int *tam_max) {

    int o, id;
    do {
        do {
            Ecra_gestao_clientes();
            readInt(&o, 0, 6, "Introduza opção: ");
        } while (o < 0 || o > 6);
        switch (o) {
            case 1:Ecra_criar_cliente();
                criar_cliente(vetor, num_clientes, tam_max);
                break;
            case 2: Ecra_editar_cliente();
                imprime_id_existentes(*vetor, *num_clientes);
                readInt(&id, 1, 10000, "Introduza o ID do cliente que pretende editar: ");
                atualiza_cliente(*vetor, num_clientes, id);
                break;
            case 3: Ecra_remover_cliente();
                imprime_id_existentes(*vetor, *num_clientes);
                readInt(&id, 0, 10000, "Introduza o ID do cliente que pretende remover: ");
                remover_cliente(vetor, num_clientes, tam_max, id);
                break;
            case 4: Ecra_pesquisar_cliente();
                imprime_id_existentes(*vetor, *num_clientes);
                readInt(&id, 0, 10000, "Introduza o ID do cliente que pretende pesquisar: ");
                pesquisar_cliente(*vetor, *num_clientes, id);
                break;
            case 5: Ecra_listar_cliente();
                listar_clientes(*vetor, *num_clientes);
                break;
            default: printf("Escolheu voltar ao menu principal \n");
        }
    } while (o != 0);
}

/**
 * Função que serve como menu para todas as funcionalidades do projeto
 *
 * @param ptrClientes vetor onde estão guardadas todas as informações dos clientes
 * @param num_clientes um apontador do número de clientes que existem no vetor 
 * @param tam_max um apontador do tamanho do vetor de clientes
 */
void menu_principal(Cliente** ptrclientes, int *num_clientes, int *tam_max) {
    int o, id;
    short mes, ano;

    do {
        do {
            Ecra_menu_principal();
            readInt(&o, 0, 5, "Introduza opção: ");
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
                readInt(&id, 1, 1000, "Introduza o ID do cliente a gerar uma fatura: ");
                readShort(&mes, 1, 12, "Introduza o mês da fatura a gerar: ");
                readShort(&ano, 2017, 2019, "Introduza o ano da fatura a gerar: ");
                geracao_fatura_cliente(*ptrclientes, *num_clientes, id, mes, ano);
                break;
            case 4:menu_novas_funcionalidades(ptrclientes, num_clientes, tam_max);
                break;
            default: printf("Escolheu sair, obrigado por utilizar o programa!");
        }
    } while (o != 0);
}
