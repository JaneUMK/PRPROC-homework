#include <stdio.h>

int main(){
    float x, lambda;
    int again, n = 1000, k;

    do
    {
        printf("\nInput lambda:   ");
        scanf("%f", &lambda);

        x = 0.15;
        for (k=0; k<=n; k++){
            printf("\n%d:   x = %f", k, x);
            x = lambda * x * (1 - x);
        }

        printf("\nAgain? [0/1]  ");
        scanf("%i", &again);
    } while (again);
    

    return 0;
}