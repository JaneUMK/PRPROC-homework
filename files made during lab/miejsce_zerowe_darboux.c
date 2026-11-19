#include <stdio.h>
#include <math.h>

long double f(long double x){
    // return (x*x) - sin(x);
    return log(x) + x;
}

int main(){
    int again;
    long double xstart, xend, xhelper, errormargin = 0.0000000001;

    do {
        printf("\nStart?   ");
        scanf("%Lf", &xstart);
        printf("\nEnd?   ");
        scanf("%Lf", &xend);

        if(xstart > xend){
            //xhelper to help swap
            xhelper = xstart;
            xstart = xend;
            xend = xhelper;
        }
        if(f(xstart) * f(xend) < 0){
            while(1) {
                //xhelper as the middle and root
                if(fabs(xstart - xend) <= errormargin){
                    xhelper = xstart;
                    break;
                }
                xhelper = (xstart + xend)/2.0;
                if(f(xstart) * f(xhelper) < 0){
                    xend = xhelper;
                }else{
                    xstart = xhelper;
                }
            }
            printf("\nRoot found in %.10Lf\ff(%.10Lf) = %.10Lf", xhelper, xhelper, f(xhelper));
        }else printf("No roots found, try different bounds");

        printf("\nGo again?[0/1]\t");
        scanf("%d", &again);
    }while (again);
    return 0;
}
