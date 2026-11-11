#include <stdio.h>

long long nwd(long long a, long long b){
    long long helper;

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
    long long m, n;

    printf("Input integer m:\t");
    scanf("%lld", &m);
    printf("Input integer n:\t");
    scanf("%lld", &n);

    printf("\n NWD: %lld", nwd(m, n));
    
    return 0;
}