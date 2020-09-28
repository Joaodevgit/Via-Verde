/*
 * @file Estruturas.h
 * @author Grupo 22-30 João Pereira , Bruno Teixeira, Rui Vieira, Carlos Ribeiro.
 * @date 27 de Novembro de 2018
 * @brief Estruturas
 * 
 * Local onde vão ser criadas as estruturas que irei precisar para modelar os dados ao longo do projeto
 * 
 */
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define NUM_PORTAGENS 6
#define MAX_VIAGENS 100
#define MAX_STR 100
#define MAX_MAT 10
#define MAX_NIB 21
#define MAX_CC 8

#ifdef __cplusplus
extern "C" {
#endif
 
    //Estrutura associada ao conceito de lanço

    typedef struct {
        float preco;
        float dist;
        short pontos;
    } Lanco;

    //Estrutura associada ao conceito de pórtico

    typedef struct {
        short porticoEntrada;
        short porticoSaida;
        float custo;
    } Portico;

    //Estrutura associada à data

    typedef struct {
        short ano;
        short mes;
        short dia;
    } Data;

    // Estrutura associada a data

    typedef struct {
        short hora;
        short minutos;
    } Hora;

    //Estrutura associada ao conceito de veículo

    typedef struct {
        char matricula[MAX_MAT];
        char marca[MAX_STR + 1];
        char modelo[MAX_STR + 1];
        short classe;
        int velocidade;
    } Veiculo;

    //Estrutura associada ao conceito de viagem

    typedef struct {
        Portico info_lanco;
        Data dataEntrada;
        Hora horaSaida;
    } Viagem;

    //Estrutura associada ao conceito de cliente

    typedef struct {
        int id;
        char nome[MAX_STR + 1];
        int NIF;
        char num_CC[MAX_CC + 1];
        char NIB[MAX_NIB + 1];
        char morada[MAX_STR + 1];
        short num_ptsviaverde;
        Veiculo veiculo_cliente;
        Viagem viagem_cliente[MAX_VIAGENS];
        int num_viagens;
    } Cliente;


#ifdef __cplusplus
}
#endif

#endif /* ESTRUTURAS_H */

