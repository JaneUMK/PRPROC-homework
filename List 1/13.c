#include <math.h>
#include <stdio.h>

long double get_pi_slow(long steps);
long double get_pi_fast();

int main() {
  int again;
  long double pi_slow, pi_fast;
  long steps;

  do {
        printf("\nHow many steps?   ");
        scanf("%ld", &steps);

        pi_slow = get_pi_slow(steps);
        pi_fast = get_pi_fast();

        printf("\nSlow   %.15Lf", pi_slow);
        printf("\nFast   %.15Lf", pi_fast);

        printf("\n\nAgain [0/1]\t");
        scanf("%i", &again);
  } while (again);
  return 0;
}

// szereg Leibniza
long double get_pi_slow(long steps){
    long double pi = 1.0;
    long long denom;

    for (long i = 1; i <= steps; i++) {
        if (i % 2 == 0){
            pi += 1.0/((2*i) + 1);
        } else{
            pi -= 1.0/((2*i) + 1);
        }
    }

    return 4 * pi;
}

// John Machin
long double get_pi_fast(){
    return 4.0 * ((4 * (atan(1.0/5)) - atan(1.0/239)));
}
