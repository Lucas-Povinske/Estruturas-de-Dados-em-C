#include <stdio.h>
#include <stdlib.h>

void select (int n, int v[]) {
    int i, j, k, min, t;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++){
            if (v[j] < v[min]){
                min = j;
            }
        }
        t = v[i];
        v[i] = v[min];
		v[min] = t;
    }
}

int main(void){
    int i, n;
    int v[]={64, 25, 12, 22, 11, 22};
    n = sizeof(v)/sizeof(v[0]);

    printf ("Unsorted:\n");

    for (i = 0; i < n; i++){
        printf ("%d\n", v[i]);
    }

    select(n, v);

    printf ("Sorted:\n");

    for (i = 0; i < n; i++){
        printf ("%d\n", v[i]);
    }

    system ("pause");
}
