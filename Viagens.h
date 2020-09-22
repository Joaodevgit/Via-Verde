/**
 * @file Viagens.h
 * @author Grupo 22-30 João Pereira , Bruno Teixeira, Rui Vieira, Carlos Ribeiro.
 * @date 27 de Novembro de 2018
 * @brief Gestão das viagens
 * 
 * Local onde são chamadas todas as funcionalidades relativas à gestão dos clientes
 */

#include "Estruturas.h"
#include <stdbool.h>

#ifndef VIAGENS_H
#define VIAGENS_H

#ifdef __cplusplus
extern "C" {
#endif



#define MAX_CLIENTES 50  
#define MAX_STR 100
#define MAX_MAT 10
#define MAX_NIB 21
#define MAX_CC 8

#define TAM_INICIAL 3
#define TAM_INCREMENTO 3
#define TAM_DECREMENTO 3  

    void Ecra_gestao_viagens();
    void Ecra_acrecentar_viagem();
    void Ecra_gestao_lancos();
    void Ecra_pesquisa_viagem();
    void Ecra_consulta_distancias_precos_classes_A1();
    void Ecra_gestao_precos();
    void Ecra_edicao_parportico_preco();
    void Ecra_edicao_geral_precos();
    int pesquisa_id_viagens(Cliente *, int, int);
    int pesquisa_mes_viagens(Cliente *, int, int, short);
    void imprime_matriculas_existentes(Cliente*, int);
    void imprime_id_existentes(Cliente*, int);
    int pesquisa_viagem_matricula(Cliente *, int, char[]);
    void pesquisa_viagem_veiculo(Cliente *, int, char []);
    int pesquisa_viagem_lanco(Cliente *, int, int, short, short);
    void pesquisa_viagem_par_porticos(Cliente *, int, int, short, short);
    int pesquisa_data_viagens(Cliente *, int, int, short, short, short);
    void pesquisa_viagem_data(Cliente *, int, int, short, short, short);
    void menu_gestao_pesquisa_viagens(Cliente *, int);
    bool preencheMatrizpontos(Lanco *, char *, bool);
    bool preencheMatriz(Lanco *, char *, bool);
    void imprime_matrizdistancias_precos_A1(Lanco matriz[NUM_PORTAGENS][NUM_PORTAGENS]); // pode se fazer matriz [][]?
    void carrega_lancos();
    void menu_consulta_lancos();
    void adicionar_viagem(Cliente *, int, int);
    void historico_viagens(Cliente *, int, int);
    void menu_edicao_par_portico_preco(short, short);
    void menu_edicao_geral_precos();
    void gestaodeviagens(Cliente*, int);
    void menu_gestao_precos();
    void menu_gestao_lancos();
    void geracao_fatura_cliente(Cliente *, int, int, short, short);
    void menu_gestao_viagens(Cliente*, int);


#ifdef __cplusplus
}
#endif

#endif /* VIAGENS_H */

