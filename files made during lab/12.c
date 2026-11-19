#include <stdio.h>
#include <math.h>

int nwd(int a, int b){
    int helper;
    a = abs(a);
    b = abs(b);
    if (b > a) {
        helper = a;
        a = b;
        b = helper;
    }
    while (b != 0){
        helper = b;
        b = a % b;
        a = helper;
    }
    return a;
}

int main(){
    int again, p, q, r, bound_lower, bound_higher, count;

    do {
        count = 0;
        printf("Enter bounds 'bound1 bound2'   ");
        scanf("%i %i", &bound_lower, &bound_higher);

        if(bound_higher < bound_lower){
            int bound_swap = bound_lower;
            bound_lower = bound_higher;
            bound_higher = bound_swap;
        }

        for (p = bound_lower; p <= bound_higher - 1; p++){
            for( q = p + 1; q <= bound_higher; q++){
                if(nwd(p, q) == 1){
                    r = sqrt((p * p) + (q * q));
                    if((r*r) == (p*p) + (q*q) && r <= bound_higher){
                        count++;
                        printf("\n%i: %i^2 + %i^2 = %i^2", count, p, q, r);
                    }
                }
            }
        }
        printf("\n\nFound %i of them", count);
        
        printf("\nGo again?[0/1]\t");
        scanf("%d", &again);
    }while (again);
    return 0;
}
