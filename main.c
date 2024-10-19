#include "../Arvore_b/biblioteca/arvore_b/arvore.h"

int main(void)
{
    arvore_b *arvore = NULL;

    int vet[] =
    {
        50, 30, 40, 44, 88, 95,
        25, 91, 31, 52, 20, 60,
        70, 74, 78, 79, 22, 28,
        33, 39, 98, 85, 86, 87,
        90, 92, 93, 94, 35, 32,
        84, 99, 105, 110
    };

    int ordem = 7;
    arvore = cria_arvore(ordem);
    
    for(int i = 0;i <= 33;i++)
    {
        insere_arvore_b(arvore,vet[i]);        
    }
    printf("\n");
    em_ordem(arvore->raiz);
    printf("\n");
    return 0;  
}