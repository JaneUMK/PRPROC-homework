#include <stdio.h>

//technicznie rzecz biorąc jest to metoda Newtona/Newtona-Raphsona - heron jest jej przypadkiem dla pierwiastków drugiego stopnia
void heron(long double to_root, int root, int steps){
    long double starting_point, power_helper;
    
    printf("\n\nBeginning heron:\n");
    
    if (starting_point * starting_point <= 2) {
        starting_point = 1.0;
    } else starting_point = to_root/2.0;

    for (int i = 1; i<=steps; i++) {
        power_helper = 1.0;
        for (int j = 1; j<root; j++) {
            power_helper = power_helper * starting_point;
        }
        starting_point = (1.0/root) * (((root - 1) * starting_point) + (to_root/power_helper));

        printf("Step %d:   %Lf\n", i, starting_point);
    }
}

int main(){
    int again, steps, root;
    long double to_root;
    do {
        printf("\nRoot of what number?\t");
        scanf("%Lf", &to_root);
        printf("\nWhat root?\t");
        scanf("%d", &root);
        printf("\nHow many steps?\t");
        scanf("%d", &steps);
        
        heron(to_root, root, steps);

        printf("\nGo again?[0/1]\t");
        scanf("%d", &again);
    }while (again);
    return 0;
}
