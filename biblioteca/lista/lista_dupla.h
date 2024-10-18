#ifndef LISTA_H
#define LISTA_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
TODO Estrutura para os dados da lista variaveis são do tipo de ponteiro void para receber
qualquer tipo de dados, para os dados serem salvos é passar o endereço da variavel de entrada.
Para isso acontecer sugiro que crie uma vetor de string com pelo menos 100 de espaço para receber 
qualquer tipo de dados, se entrar números float ou int deverá fazer tratamento desse dado e conversão 
de tipo para antes de ser salvo.
Esse codigo foi reapreveitado no meu GitHub: Hhpp2004
Repositorio: https://github.com/Hhpp2004/lista_dupla.git
*/

typedef struct no
{
    void *info;
    struct no *prox;
    struct no *ant;
}no;

typedef struct lista
{
    struct no *inicio;
    struct no *fim;
}lista;

//TODO funções declaradas que estão implementas no arquivo lista_dupla.c
lista *cria_lista();
no *cria_no(void *valor);
void insere_inicio(void *valor,lista *l);
void insere_fim(void *valor,lista *l);
void mostra(lista *l);
lista *libera_lista(lista *l);
no *retira_inicio(lista *l);
no *retira_fim(lista *l);
lista *divide_lista(lista *l,int num);    

#endif