#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int valor;
    struct pilha* prox;
} p;

typedef struct top{
    struct p* topo;
} cel;

int tam;

void ini(cel *plh){
    plh->topo = NULL;
    tam = 0;
}

int vazio(cel *plh){
    if(plh->topo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

p *alocar(){
    p *n=(p*) malloc(sizeof(p));

    if(n == 0){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
        printf("Novo elemento: "); scanf("%d", &n->valor);
        return n;
    }

}



void liberar(cel *plh){

    if(vazio(plh) == 0){
        p *l, *c;
        c = plh->topo;

    while(c != NULL){
        l = c->prox;
        free(c);
        c = l;
        }
    }
}


void imprime(cel *plh){
    if(vazio(plh) != 0){
        printf("Pilha vazia!\n\n");
        return;
    }

    p *t = plh->topo;
    printf("Pilha:");

    while(t != NULL){
        printf("%5d", t->valor);
        t = t->prox;
    }
    printf("\n        ");

    int i;

    for(i = tam ; i > 0; i--){
        printf("  ^  ");
    }
    printf("\nOrdem:");

    for(i = tam ; i > 0; i--){
        printf("%5d", i);
    }

    printf("\n\n");

}

void push(cel *plh){

    p *n = alocar();

    n->prox = plh->topo;
    plh->topo = n;
    tam++;
}


int *pop(cel *plh){

    p *t;
    int x;

    if(plh->topo == NULL){
        printf("Pilha ja vazia\n\n");
        return NULL;
    }
    else{
        t = plh->topo;
        plh->topo = t->prox;
        x = t->valor;
        free(t);
        tam--;
        return x;
    }
}


void main(){
    cel *plh = (cel*) malloc(sizeof(cel));
    if(plh == 0){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
        ini(plh);
        int op, y;
        do{
            printf("Escolha uma opcao:\n0-) Sair\n1-) Zerar\n2-) Imprimir\n3-) Push\n4-) Pop\nSua opcao: ");
            scanf("%d", &op);
            int n;
            switch(op){
                case 0:
                liberar(plh);
                break;

                case 1:
                liberar(plh);
                ini(plh);
                break;

                case 2:
                imprime(plh);
                break;

                case 3:
                push(plh);
                break;

                case 4:
                y = pop(plh);
                if(y != NULL){
                    printf("Retirado: %3d\n\n", y);
                }
                break;

                default:
                printf("Comando nao existente!\n\n");
            }
        }while(op != 0);

        free(plh);
        system("pause");
    }
}
