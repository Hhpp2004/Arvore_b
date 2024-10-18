#include "lista_dupla.h"
#include "../arvore_b/arvore.h"

/*
TODO
Será necessario a biblioteca lista_dupla.h para o funcionamento do codigo
Criar uma lista duplamente encadeada para salvar os dados
Esse codigo foi reapreveitado no meu GitHub Hhpp2004
Repositorio: https://github.com/Hhpp2004/lista_dupla.git
*/ 
lista *cria_lista()
{
    lista *dupla = (lista *)malloc(sizeof(lista));
    dupla->inicio = NULL;
    dupla->fim = NULL;
    return dupla;
}
/*
TODO criação de no para inserção na lista
as variaveis são do tipo ponteiro void para receber qualquer tipo de dados 
*/
no *cria_no(void *valor)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->info = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

/*
TODO funções de inserção da lista duplamente encadeada
*/
void insere_inicio(void *valor, lista *l)
{
    no *novo = cria_no(valor);
    if (l->inicio == NULL)
    {
        l->fim = novo;
        l->inicio = novo;
    }
    else
    {
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
}

void insere_fim(void *valor, lista *l)
{
    no *novo = cria_no(valor);
    no *aux = l->inicio;
    if (l->fim == NULL)
    {
        l->fim = novo;
        l->inicio = novo;
    }
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
        l->fim = novo;
    }
}

/*
TODO função para os mostrar os dados na lista, será necessario conversão de tipo para acessar os 
dados.
*/
void mostra(lista *l)
{
    no *aux = l->inicio;
    while (aux != NULL)
    {
        printf("%i ", ((chave *)aux->info)->valor_chave);
        aux = aux->prox;
    }
}


//TODO retirar dados da lista
no *retira_inicio(lista *l)
{
    no *aux_3 = NULL;
    no *aux = l->inicio;
    if (aux != NULL)
    {
        aux_3 = aux;
        no *aux2 = aux->prox;
        if (aux != NULL)
        {
            l->inicio = aux2;
            aux2->ant = NULL;
            free(aux);
        }
    }
    return aux_3;
}

no *retira_fim(lista *l)
{
    no *aux = l->fim;
    no *aux_2 = l->fim->ant;

    if (aux != NULL)
    {
        aux_2->prox = NULL;
        l->fim = aux_2;
        free(aux);
    }
    return aux_2;
}

/*
TODO caso necessario fazer a limpeza da lista
*/
lista *libera_lista (lista *l)
{
    no *aux;
    while(l->inicio != NULL)
    {
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
    free(l);
    return NULL;
}

/*
TODO dependendo da ordem da arvore B, deverá dividir a quantidade
que está dentro da lista e será passado para uma outra lista duplamente encadeado que está salvo dentro
da arvore B, elá é criada e salva dentro da pagina, o processo de listagem funicona do mesmo jeito. Essa 
função divide a lista e sobe o dado para a outra.
*/ 
lista *divide_lista(lista *l, int num)
{
    int cont = 1;
    no *aux = NULL;
    lista *lista_2 = cria_lista();
    if(l->fim != NULL && l->inicio != NULL)
    {
        while (aux != NULL && cont <= num)
        {
            cont++;
            aux = aux->prox;
        }
        lista_2->inicio = aux->prox;      
        lista_2->fim = l->fim;
        lista_2->inicio->ant = NULL;
        l->fim = aux->ant;
        l->fim->prox = NULL;
    }
    return lista_2;
}