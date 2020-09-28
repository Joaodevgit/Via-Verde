/*
 * @file Structures.h
 * @author João Pereira
 * @date 27/11/2018
 * @brief Structures
 * 
 * Header where the structures that will be needed to model the data throughout the project development
 * 
 */
#ifndef STRUCTURES_H
#define STRUCTURES_H

#define NUM_PORTAGENS 6
#define MAX_VIAGENS 100
#define MAX_STR 100
#define MAX_MAT 10
#define MAX_NIB 21
#define MAX_CC 8

#ifdef __cplusplus
extern "C" {
#endif
 
    //Structure associated to tolls link concept

    typedef struct {
        float preco;
        float dist;
        short pontos;
    } Lanco;

    //Structure associated to toll concept

    typedef struct {
        short porticoEntrada;
        short porticoSaida;
        float custo;
    } Portico;

    //Structure associated to date

    typedef struct {
        short ano;
        short mes;
        short dia;
    } Data;

    //Structure associated to date (time)

    typedef struct {
        short hora;
        short minutos;
    } Hora;

    //Structure associated to  concept

    typedef struct {
        char matricula[MAX_MAT];
        char marca[MAX_STR + 1];
        char modelo[MAX_STR + 1];
        short classe;
        int velocidade;
    } Veiculo;

    //Structure associated to trip concept

    typedef struct {
        Portico info_lanco;
        Data dataEntrada;
        Hora horaSaida;
    } Viagem;

    //Structure associated to customer concept

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

#endif /* STRUCTURES_H */

