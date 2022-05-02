#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "milibreria.h"
#define N 30

int main(){
    int nmenu,i,nmapa,person,seleccion;
    char texto[N];
    char nombre[N];

    printf("1-Comenzar\n");
    printf("2-Personalizar\n");
    printf("3-Salir\n");

    scanf("%i",&nmenu);

    switch(nmenu){                                      //Menú
        case 1:                                         //Comenzar
            system("cls");
            printf("Ingresa un nombre:");
            scanf("%s",texto);
            for(i=0;i<N;i++){
                nombre[i]=texto[i];
            }
            if(strcmp(texto,nombre)==0){
                system("cls");
                printf("Selecciona un mapa\n");
                printf("1-2-3...\n");
                scanf("%i",&nmapa);
                switch(nmapa){
                    case 1:
                        system("cls");
                        mapeado(1,31,166,196,298,328,185,33,"mapa1.txt",55,145,108,123,258,70,80);
                    break;
                    case 2:
                        system("cls");
                        mapeado(1,31,166,196,298,328,185,33,"mapa2.txt",266,145,238,255,258,61,80);
                    break;
                    default:
                    break;
                }
            }
        break;
        case 2:                                                 //Personalizar
            system("cls");
            printf("Selecciona a tu personaje");
            printf("\n\t1 +\n\t2 Ñ\n\t3 $\n");
            scanf("%i",&seleccion);
            if(seleccion==1){
                system("cls");
                FILE *prueba=fopen("personaje.txt","w");
                fprintf(prueba,"%c",'+');
                fclose(prueba);
                return main();
            }
            else if(seleccion==2){
                system("cls");
                FILE *prueba=fopen("personaje.txt","w");
                fprintf(prueba,"%c",'Ñ');
                fclose(prueba);
                return main();
            }
            else if(seleccion==3){
                system("cls");
                FILE *prueba=fopen("personaje.txt","w");
                fprintf(prueba,"%c",'$');
                fclose(prueba);
                return main();
            }else{
                return main();
            }
        break;
        case 3:                                         //Salir
            system("cls");
            printf("¿Seguro que quieres salir?\n");
            printf("\t1-Si\n\t2-Volver\n");
            scanf("%i",&nmenu);
            switch(nmenu){
                case 1:
                    return 0;
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
