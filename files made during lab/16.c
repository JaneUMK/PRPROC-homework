#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

int main(){
    int again, i, roll;
    float T[12];

    srand(time(0));
    do{
        memset(T, 0, sizeof T);

        for(i = 0; i < 10000; i++){
            roll = ((rand() % 6) + 1) + ((rand() % 6) + 1);
            T[roll - 1] = T[roll - 1] + 1;
        }
        for(i = 1; i < 12; i++){
            T[i] = (T[i] / 10000) * 100;
            printf("\n%i - %.2f%%", i+1, T[i]);
        }

        printf("\nAgain? [0/1]  ");
        scanf("%i", &again);
    } while(again);
    return 0;
}