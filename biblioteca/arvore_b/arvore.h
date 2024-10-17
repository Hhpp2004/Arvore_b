#ifndef ARVORE_H
#define ARVORE_H
#include "../lista/lista_dupla.h"

/*TODO
Aqui temos a cabeça da biblioteca da arvore B, estruturas para salvar os dados.
A finalidade da arvore B é conseguir salvar varios tipos de dados estando fragmentado ou não
e facilitar o algoritmo de pesquisa e reduzindo a complexidade do codigo. Aqui segue a mesma ideia da 
arvore ABB e AVL porem é mais dificil e implementar e entender o seu algoritmo. Abaixo temos três estruturas
que sao usadas para a implementação da arvore B. Como será usado a lista duplamente encadeada as bibliotecas
stdio.h e stdlib.h já foram chamadas no arquivo lista_dupla.h que está sendo chamado aqui, com isso o codigo 
fonte só chamara o arquivo arvore.h
*/

/*TODO a estrutura da pagina deverá guarda a lista duplamente encadeada a quantidade de chaves presente é para 
uma divisão de lista futura,dependendo do valor da ordem da arvore a pagina deverá ter uma variavel livre
para guarda a pagina que está a sua direita. A variavel folha é uma variavel booleana que salvará 1 - False ou
0 - True. A variavel pai é para salvar quem está acima dela.
*/

typedef struct pagina
{
    int folha;
    int qtd_chaves;
    struct pagina *pai;
    struct lista *lista;
    struct pagina *dir;
}pagina;


/*TODO a variavel filho é para criar uma nova pagina e salvar o endereço dela toda vez que passar da quantidade 
de dados na lista. 
*/
typedef struct chave
{
    int valor_chave;
    struct pagina *filho;
}chave;


//TODO Aqui está a estutura da arvore B, ordem para divisão da lista e altura para acompanhar o tamanho.
typedef struct arvore_b
{
    struct pagina *raiz;
    int ordem;
    int altura;
}arvore_b;

//TODO funções que estão implementadas no arquivo arvore.c
arvore_b *cria_arvore(int ordem);
pagina *cria_pagina();
chave *cria_chave(int valor);
int getvalor(no *aux);
void insere_ordenado(lista *l,int valor);
pagina *pesquisa_folha(pagina *pag_aux,int valor);
void insere_pagina(pagina *folha,int valor);
void insere_arvore_b(arvore_b *raiz,int valor);

#endif
