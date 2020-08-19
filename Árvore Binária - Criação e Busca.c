#include <stdio.h>
#include <stdlib.h>

 typedef struct arv {
   int valor;
   struct arv* esq;
   struct arv* dir;
} cel;

//Criar novo nó:
cel *novo(int v){
    cel *t =  (cel*) malloc(sizeof(cel));
    t->valor = v;
    t->esq = t->dir = NULL;
    return t;
}


//Tipos de ordens de impressão:
void erd(cel *raiz){

    if (raiz != NULL){
        erd(raiz->esq);
        printf("%d \n", raiz->valor);
        erd(raiz->dir);
    }
}

void red(cel *raiz){
    if (raiz != NULL){
        printf("%d \n", raiz->valor);
        red(raiz->esq);
        red(raiz->dir);
    }
}

void edr(cel *raiz){

    if (raiz != NULL){
        edr(raiz->esq);
        edr(raiz->dir);
        printf("%d \n", raiz->valor);
    }
}

//Inserção de nova célula, no estilo Menor Esquerda e Maior Direita:
cel* inserir(cel* no, int v){

    if (no == NULL){
        return novo(v);
    }

    if (v < no->valor){
        no->esq = inserir(no->esq, v);
    }
    else if (v > no->valor){
        no->dir = inserir(no->dir, v);
    }

    return no;
}

//Busca de um elemento:
cel *busca(cel *raiz, int v){

    if (raiz == NULL || raiz->valor == v){
       return raiz;
    }

    if (raiz->valor < v){
       return busca(raiz->dir, v);
    }

    return busca(raiz->esq, v);
}

//Main
void main(){

    cel *raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    printf("Impressao Em Ordem (ERD):\n");
    erd(raiz);

    printf("\nImpressao Pre Ordem (RED):\n");
    red(raiz);

    printf("\nImpressao Pos Ordem (EDR):\n");
    edr(raiz);
    printf("\n\n");

    cel *b = busca(raiz, 50);

    //Buscar um elemento:
    if (b != NULL){
        printf("Numero %d encontrado!\n", b->valor);
    }
    else{
        printf("Nao encontrado!\n");
    }

    system("pause");
}
