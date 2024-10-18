#include "arvore.h"
/*TODO
Arquivo de implementação das funções
Como boa pratica de programação todas as funções devem ser
feitas em ordem de chamar como exemplo
encontra_folha tem que ser implementada primeiro e
acima da função de insere_arvore
*/

// TODO função que cria a arvore B
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

// TODO criação da chave.
chave *cria_chave(int valor)
{
    chave *chave = malloc(sizeof(valor));
    chave->filho = NULL;
    chave->valor_chave = 0;
    return chave;
}

/*
TODO conversão das variaveis o metodo GET é
muito utilizado nas linguagens de orientação a objetos
Todas as funções com o metodo get será para conversão de
tipo de variavel.
*/
int getvalor(no *aux)
{
    return ((chave *)aux->info)->valor_chave;
}

pagina *getfilho(no *aux)
{
    return ((chave *)aux->info)->filho;
}

// TODO Função que faz a inserção e ordena os dados
void insere_ordenado(lista *l, chave *valor)
{
    no *aux = l->inicio;
    no *novo_no;

    // TODO verificanco se tem dados na lista para a primeira inserção
    if (l->inicio == NULL)
    {
        insere_inicio(valor, l);
    }
    /*
    TODO caso tenha valor salvo será feito a inserção
    já ordenando os valores
    */
    else
    {
        if (valor->valor_chave < getvalor(aux))
        {
            insere_inicio(valor, l);
        }
        else
        {
            if (valor->valor_chave < getvalor(aux))
            {
                insere_inicio(valor, l);
            }
            else if (valor->valor_chave > getvalor(aux))
            {
                insere_fim(valor, l);
            }
            else
            {
                while (valor->valor_chave > getvalor(aux))
                {
                    aux = aux->prox;
                }
                novo_no = cria_no(valor);
                novo_no->prox = aux;
                novo_no->ant = aux->ant;
                aux->ant = novo_no;
                novo_no->ant->prox = novo_no;
            }
        }
    }
}
/*
TODO a função encontra folha é uma função de achar todas
as folhas para fazer a inserção.
primeiro verifico se a pagina é folha, depois percorro a
lista para achar um valor menor do que os valores que estão
já alocados na lista, caso não encontre a pagina é salva
a direita caso contrario a propria pagina salva o valor na lista dentro da pagina.
*/
pagina *encontra_folha(pagina *raiz, int valor)
{
    pagina *aux = raiz;
    if (raiz == NULL)
    {
        return NULL;
    }
    else
    {
        // TODO valor 1 para folha e 0 para não folha
        while (aux->folha != 1)
        {
            no *aux_lista = aux->lista->inicio;
            while (aux_lista != NULL && valor > getvalor(aux_lista))
            {
                aux_lista = aux_lista->prox;
            }
            if (aux_lista == NULL)
            {
                aux = aux->dir;
            }
            else
            {
                aux = getfilho(aux_lista);
            }
        }
        return aux;
    }
}

// TODO função de inserção na pagina
void insere_pagina(pagina *folha, chave *valor)
{
    insere_ordenado(folha->lista, valor);
    folha->qtd_chaves++;
}

/*
TODO função de retirada do ultimo dado de dentro da lista
depois da divisão da lista
*/

chave *ultima_chave(pagina *folha)
{
    no *ultima_chave = retira_fim(folha->lista);
    chave *valor = ultima_chave->info;
    free(ultima_chave);
    folha->qtd_chaves--;
    return valor;
}

/*TODO
Aqui temos a função de divisão da pagina
-> Será importante a biblioteca math.h para arredondar
a divisão para baixo para a quantidade de valores dentro
da lista;
*/

pagina *divide_pagina(pagina *p)
{
    pagina *nova_pagina = cria_pagina();
    int qtd_pagina = ceil(p->qtd_chaves / 2);
    lista *nova_lista = NULL;
    chave *ultima_chave = NULL;

    nova_lista = divide_lista(p->lista, qtd_pagina);
    nova_pagina->lista = nova_lista;
    nova_pagina->qtd_chaves = p->qtd_chaves - qtd_pagina;
    nova_pagina->pai = p->pai;
    nova_pagina->folha = p->folha;
    p->qtd_chaves = qtd_pagina;

    ultima_chave = p->lista->fim->info;

    if (p->pai != NULL)
    {
        no *aux = p->pai->lista->inicio;
        while (aux != NULL && getfilho(aux) != p)
        {
            aux = aux->prox;
        }
        /*TODO caso não tenha estourado a pagina,
        as novas paginas são salvas nos filhos
        caso contrario será necessario utilizar a
        variavel direito da pagina.
        */
        if (aux != NULL)
        {
            ((chave *)aux->prox)->filho = nova_pagina;
        }
        else
        {
            p->pai->dir = nova_pagina;
        }
    }
    /*TODO caso a pagina não seja folha
    pecorremos a lista para salvar a pagina nova no pai
    */
    if (p->folha == 0)
    {
        no *aux = nova_pagina->lista->inicio;
        while (aux != NULL)
        {
            getfilho(aux)->pai = nova_pagina;
            aux = aux->prox;
        }
        nova_pagina->dir->pai = nova_pagina;
        p->dir = ultima_chave->filho;
    }
    return nova_pagina;
}

/*TODO função para criar uma nova raiz*/

pagina *cria_raiz(pagina *folha, pagina *nova_pagina, chave *valor)
{
    pagina *nova_raiz = cria_pagina();
    nova_raiz->dir = nova_pagina;
    insere_inicio(valor, nova_raiz->lista);
    valor->filho = folha;
    nova_raiz->folha = 0;
    nova_raiz->qtd_chaves++;
    folha->pai = nova_raiz;
    nova_pagina->pai = nova_raiz;
    return nova_raiz;
}

/*TODO função para fazer inserção na arvore B*/
void insere_arvore_b(arvore_b *a, int valor)
{
    pagina *pag_aux = a->raiz;
    // TODO o spoj não reconhece a biblioteca stdbool.h
    int valor_insere = 1;
    chave *novo = cria_chave(valor);
    pagina *folha = encontra_folha(pag_aux, valor);
    pagina *nova_pagina = NULL;

    if (folha == NULL)
    {
        a->raiz = cria_pagina();
        insere_pagina(a->raiz, novo);
    }
    else
    {
        while (valor_insere)
        {
            // TODO entrada dos valores dentro da lista
            insere_pagina(folha, novo);
            /*TODO a quantidade de dados dentro da lista
            tem que ser menor que a ordem da arvore, aqui
            temos a verificação da quantidade, caso esse
            valor passe da ordem será necessario chamar a
            função de divisão da lista criada e implementa
            nos arquivos da lista duplamente encadeada.
            */
            if (folha->qtd_chaves < a->ordem)
            {
                valor_insere = 0;
            }
            else
            {
                nova_pagina = divide_pagina(folha);
                novo = ultima_chave(folha);
                if (a->raiz == folha)
                {
                    a->raiz = cria_raiz(folha, nova_pagina, novo);
                    valor_insere = 0;
                }
                else
                {
                    folha = folha->pai;
                }
            }
        }
    }
}

/*TODO função de mostrar todos os dados salvos*/
void em_ordem(pagina *raiz)
{
    no *aux = NULL;
    if (raiz != NULL)
    {
        aux = raiz->lista->inicio;
        while (aux != NULL)
        {
            em_ordem(((chave *)aux->info)->filho);
            printf("%d ", ((chave *)aux->info)->valor_chave);
            aux = aux->prox;
        }
        em_ordem(raiz->dir);
    }
}