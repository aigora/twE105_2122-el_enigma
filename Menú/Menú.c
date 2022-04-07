#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    printf("1-Comenzar\n");
    printf("2-Salir\n");

    scanf("%i",&n);

    switch(n){
        case 1:
            printf("Comienza el juego\n");
            return 0;
        break;
        case 2:
            system("cls");
            printf("¿Seguro que quieres salir?\n");
            printf("\t1-Si\t2-Volver\n");
            scanf("%i",&n);
            switch(n){
                case 1:
                break;
                case 2:
                    system("cls");
                    return main();
                break;
                default:
                break;
            }
        break;
        default:
        break;
    }

    return 0;
}
