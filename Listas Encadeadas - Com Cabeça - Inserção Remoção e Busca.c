#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int valor;
    struct lista* prox;
} cel;

void insere (int x, cel *p){
    cel *n;
    n = malloc (sizeof (cel));
    n->valor = x;
    n->prox = p->prox;
    p->prox = n;
}

cel *buscanumero (int x, cel *lst){
    cel *b;
    int i = 1;
    b = lst->prox;
    while (b != NULL && b->valor != x){
        i++;
        if (b->prox == NULL){
            i = 0;
        }
        b = b->prox;
    }
    return i;
}

cel *buscaendereco (int x, cel *lst){
    cel *b;
    b = lst->prox;
    while (b != NULL && b->valor != x){
        b = b->prox;
    }
    return b;
}

void imprime(cel *lst){
    int i = 1;
    cel *p;
    for (p = lst->prox; p != NULL; p = p->prox){
        printf ("%d ->%d\n", i++, p->valor);
    }
}

void remover(int x, cel *lst){
    if (lst->prox->valor != x){
        cel *p;
        for (p = lst->prox; p != NULL; p = p->prox){
            if (p->prox->valor == x){
                break;
            }
        }
        cel *r;
        r = p->prox;
        p->prox = r->prox;
        free(r);
    }
    else{
        cel *r;
        r = lst->prox;
        lst->prox = lst->prox->prox;
        free(r);
    }
}

void main(){

    int vet[5] = {123,456,789,101,131};

    cel *lst;

    lst = malloc(sizeof(cel));
    lst -> valor = NULL;
    lst -> prox = NULL;

    for(int i = 0; i < 5; i++){
        insere(vet[i], lst);
    }

    imprime(lst);

    int x = 234;

    printf("Informe um numero pra buscar: ");
    scanf("%d", &x);


    if (buscanumero(x, lst) != 0){
        printf("O numero %d e o item %d da lista\n", x, buscanumero(x, lst));
    }
    else{
        printf("O numero %d nao existe dentro da lista\n", x);
    }

    printf("Informe um numero pra remover: ");
    scanf("%d", &x);

    remover(x, lst);

    imprime(lst);
}

