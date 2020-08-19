#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista* prox;
} cel;

cel *lst;

void insere (int x, cel **lst){
    cel *n;
    n = malloc(sizeof (cel));
    n->valor = x;
    n->prox = *lst;
    *lst = n;
}

cel *buscaendereco (int x, cel **p){
    cel *b = *p, *a;
    if (b->prox == NULL && b->valor == x){
        return b;
    }
    while (b != NULL && b->valor != x){
        a = b;
        if (b->prox == NULL){
            b = b->prox;
            return b;
        }
        if (b->prox->valor == x && b->prox->prox == NULL){
            cel *n, *t;
            n = (cel*)malloc(sizeof(cel));
            n->valor = NULL;
            n->prox = NULL;
            t = b;
            t->prox = n;
            return a;
        }
        b = b->prox;
    }
    return b;
}

void imprime(cel *lst){
    int i = 1;
    cel *p;

    for (p = lst; p!= NULL; p = p->prox){
        printf ("%d ->%d\n", i++, p->valor);
    }
    if (i == 1){
        printf("Esta lista esta vazia\n");
    }
}


int remover(cel *b){
    int y;
    if (b != NULL){
        cel *r = b->prox;
        if (b->prox == NULL){
            y = b->valor;
            lst = NULL;
            return y;
        }
        else if (b->prox->prox == NULL && b->prox->valor == NULL){
            y = b->prox->valor;
            b->prox = NULL;
            free(r);
            return y;
        }
        b->valor = r->valor;
        b->prox = r->prox;
        free(r);
        return y;
    }
    else{
        printf("Esse numero nao existe!\n");
    }
}

void main(){

    int vet[5] = {123,456,789,101,131};
    int y;

    lst = NULL;

    for(int i = 0; i < 5; i++){
        insere(vet[i], &lst);
    }

    imprime(lst);

    int x;

    printf("Informe um numero pra remover: ");
    scanf("%d", &x);

    y = remover(buscaendereco(x, &lst));

    imprime(lst);
    printf("Informe um numero pra remover: ");
    scanf("%d", &x);
    remover(buscaendereco(x, &lst));

    imprime(lst);

    printf("Informe um numero pra remover: ");
    scanf("%d", &x);
    remover(buscaendereco(x, &lst));

    imprime(lst);

    printf("Informe um numero pra remover: ");
    scanf("%d", &x);
    remover(buscaendereco(x, &lst));

    imprime(lst);

    system("pause");

}

