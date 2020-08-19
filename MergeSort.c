#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int esq, int meio, int dir){

    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    //Criar vetores temporarios
    int ESQ[n1], DIR[n2];

    //Copiar dados para vetores ESQ[] e DIR[]
    for (i = 0; i < n1; i++){
        ESQ[i] = v[esq + i];
    }

    for (j = 0; j < n2; j++){
        DIR[j] = v[meio + 1 + j];
    }

    //Juntar os vetores de volta a arr[esq..dir]
    i = 0; // Indice inicial do primeiro subvetor
    j = 0; // Indice inicial do segundo subvetor
    k = esq; // Indice inicial do subvetor "mergido"
    while (i < n1 && j < n2) {
        if (ESQ[i] <= DIR[j]) {
            v[k] = ESQ[i];
            i++;
        }
        else {
            v[k] = DIR[j];
            j++;
        }
        k++;
    }

    //Copiar os elementos que sobraram de ESQ[], se existir algum
    while (i < n1) {
        v[k] = ESQ[i];
        i++;
        k++;
    }

    //Copiar os elementos que sobraram de DIR[], se existir algum
    while (j < n2) {
        v[k] = DIR[j];
        j++;
        k++;
    }
}

//esq é para o índice esquerdo e dir para o índice direito do sub-vetor de v para ser organizado
void mergeSort(int v[], int esq, int dir)
{
    if (esq < dir) {
        // Mesmo que (esq+dir)/2, mas evita overflow para um esq maior

        int meio = esq + (dir - esq) / 2;

        // Organizar primeira e segunda metades
        mergeSort(v, esq, meio);
        mergeSort(v, meio + 1, dir);

        merge(v, esq, meio, dir);
    }
}

//Imprime
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

//Main
int main()
{
    int v[] = { 123, 732, 13, 50, 32, 7 };
    int tam = sizeof(v) / sizeof(v[0]);

    printf("O vetor e igual a: \n");
    printArray(v, tam);

    mergeSort(v, 0, tam - 1);

    printf("\nVetor organizado e igual a: \n");
    printArray(v, tam);
    return 0;
}
