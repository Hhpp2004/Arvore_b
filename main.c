#include "../Arvore_b/biblioteca/arvore_b/arvore.h"

int main(void)
{
    arvore_b *arvore = NULL;
    int ordem = 0;
    arvore = cria_arvore(ordem);
    insere_arvore_b(arvore, 10);
    insere_arvore_b(arvore,90);
    printf("\n");
    em_ordem(arvore->raiz);
    printf("\n");
    return 0;  
}