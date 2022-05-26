#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

int main(){
    int nmenu,i,nmapa;
    char texto[N];
    char nombre[N];

    printf("1-Comenzar\n");
    printf("2-Personalización\n");
    printf("3-Salir\n");


    scanf("%i",&nmenu);

    switch(nmenu){
        case 1:
            system("cls");
            printf("Ingresa un nombre:");
            scanf("%Ns",texto);
            for(i=0;i<N;i++){
                nombre[i]=texto[i];
            }
            if(strcmp(texto,nombre)==0){
                printf("tu nombre es: %s\n",nombre);
                printf("Selecciona un mapa\n");
                printf("1 2 3...\n");
                scanf("%i",&nmapa);
                switch(nmapa){
                    case 1:
                        printf("Has elegido el mapa #1");
                    break;
                    case 2:
                        printf("Has elegido el mapa #2");
                    break;
                    case 3:
                        printf("Has elegido el mapa #3");
                    break;
                    default:
                    break;
                }
            }


        break;
        case 2:
            printf("Personalizar");
        break;
        case 3:
            system("cls");
            printf("¿Seguro que quieres salir?\n");
            printf("\t1-Si\t2-Volver\n");
            scanf("%i",&nmenu);
            switch(nmenu){
                case 1:
                break;
                case 2:
                    system("cls");
                    return main();
                break;
                default:
                    return main();
                break;
            }
        break;
        default:
        break;
    }

    return 0;
}

