#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(){
    int i, inside, again;
    long point_count;
    float x, y;
    srand(time(0));

    do{
        inside = 0;
        printf("\nHow many points?  ");
        scanf("%ld", &point_count);

        for(i = 0; i < point_count; i++){
            x = (float)rand() / (float)RAND_MAX;
            y = (float)rand() / (float)RAND_MAX;
            if ((x * x) + (y * y) <= 1){
                inside++;
            }
        }
        printf("\nPI is around %f", 4 * ((float)inside/point_count));

        printf("\nAgain? [0/1]  ");
        scanf("%i", &again);
    } while(again);
    return 0;
}