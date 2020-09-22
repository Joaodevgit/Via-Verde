/**
 * @file Funcoes.h
 * @author Grupo 22-30João Pereira , Bruno Teixeira, Rui Vieira, Carlos Ribeiro.
 * @date 27 7de Novembro de 2018
 * @brief Gestão dos clientes
 * 
 * Local onde são chamadas todas as funcionalidades relativas à gestão dos clientes
 */


#include "Estruturas.h"

#ifndef CLIENTES_H
#define CLIENTES_H

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

    void Ecra_menu_principal();
    void Ecra_gestao_clientes();
    void Ecra_criar_cliente();
    void Ecra_editar_cliente();
    void Ecra_remover_cliente();
    void Ecra_pesquisar_cliente();
    void Ecra_listar_cliente();
    void Ecra_escrita_cliente();
    void Ecra_geracaofatura();
    void ecra_persistenciadados();
    void Ecra_novas_funcionalidades();
    void Ecra_desconto_pontos_viaverde();
    void Ecra_historico_viagens();
    void Ecra_classe_veiculo_simulacao();
    int pesquisa_id_clientes(Cliente *, int, int);
    void simulacao_custo_pontos(short, short);
    void imprime_matrizpontos_A1(Lanco matriz[NUM_PORTAGENS][NUM_PORTAGENS]);
    void velocidade_lanco(Cliente*, int, int, int, int); //a dar errro
    int adicao_pontos_viaverde(Cliente *, int, short, short, int);
    void descontos_pontos_viaverde(Cliente *, int *);
    void menu_novas_funcionalidades(Cliente **, int *, int *);
    void escrever_dados_cliente(Cliente *, int);
    void ler_dados_cliente(Cliente **, int *, int *);
    void criar_cliente(Cliente **, int *, int *);
    Cliente* getCliente(Cliente *, int*, int);
    void atualiza_cliente(Cliente *, int*, int);
    void remover_cliente(Cliente **, int*, int*, int);
    void pesquisar_cliente(Cliente *, int, int);
    void listar_clientes(Cliente *, int);
    void menu_gestao_clientes(Cliente**, int *, int *);
    void menu_principal(Cliente**, int*, int*);


#ifdef __cplusplus
}
#endif

#endif /* CLIENTES_H */

