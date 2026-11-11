#include <stdio.h>
#include <stdlib.h>

long long nwd(long long a, long long b){
    long long helper;
    a = llabs(a);
    b = llabs(b);
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

long long nww(long long a, long long b){
    return llabs(a) * (llabs(b) / nwd(a, b));
}

int main(){
    long long m, n;

    printf("Input integer m:\t");
    scanf("%lld", &m);
    printf("Input integer n:\t");
    scanf("%lld", &n);

    if (m == 0 && n == 0) {
        printf("\nCannot compute with two zeroes");
    }else{
        printf("\nNWD: %lld", nwd(m, n));
        printf("\nNWW: %lld", nww(m, n));
    }
    
    return 0;
}