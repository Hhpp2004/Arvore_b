#include "arvore.h"
/*TODO 
Arquivo de implementação das funções 
*/

//TODO função que cria a arvore B
arvore_b *cria_arvore(int ordem)
{
    arvore_b *arvore = malloc(sizeof(arvore_b));
    arvore->altura = 0;
    arvore->ordem = ordem;
    arvore->raiz = NULL;
    return arvore;
}

/*
TODO função que cria a pagina e a lista duplamente encadeada cuja a sua função está no arquivo lista_dupla.c para salvar
os dados. Deverá criar a lista aqui na função de criação da pagina.
*/
pagina *cria_pagina()
{
    pagina *valor = malloc(sizeof(pagina));
    valor->dir = NULL;
    valor->folha = 1;
    valor->lista = cria_lista();
    valor->pai = NULL;
    valor->qtd_chaves = 0;
    return valor;
}


//TODO criação da chave.
chave *cria_chave(int valor)
{
    chave *chave = malloc(sizeof(valor));
    chave->filho = NULL;
    chave->valor_chave = 0;
    return chave;
}

//TODO conversão das variaveis o metodo GET é muito utilizado nas linguagens de orientação a objetos
int getvalor(no *aux)
{
    return ((chave *)aux->info)->valor_chave;
}


//TODO Função que faz a inserção e ordena os dados 
void insere_ordenado(lista *l, int valor)
{
    no *aux = l->inicio;
    chave *chave = cria_chave(valor);

    if (l->inicio == NULL)
    {
        insere_inicio(chave, l);
    }
    else
    {
        if (valor < getvalor(aux))
        {
            insere_inicio(chave, l);
        }
        else
        {
            if (valor > getvalor(aux))
            {
                insere_fim(chave, l);
            }
            else
            {
                no *novo = cria_no(chave);
                while (valor > getvalor(aux))
                {
                    aux = aux->prox;
                }
                novo->ant = aux->ant;
                novo->prox = aux;
                aux->ant = novo;
                novo->ant->prox = novo;
            }
        }
    }
}





void insere_arvore_b(arvore_b *raiz,int valor)
{
    pagina *nova_pag = NULL;
    pagina *pag_aux = raiz->raiz;
    int valor_entrada = 1;
    chave *chave = cria_chave(valor);
    pagina *folha = pesquisa_folha(pag_aux,valor);    
    if(folha == NULL)
    {
        raiz->raiz = cria_pagina();
        insere_ordenado(raiz->raiz->lista,valor);
    }
    else
    {
        while (valor_entrada != 0)
        {
            insere_pagina(folha,valor);
            
        }
        
    }
}