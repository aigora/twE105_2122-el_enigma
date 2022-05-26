#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libreria.h"
#define N 50
#define M 3

typedef struct{
    char opcion1[N];
    char texto1[N];
    char opcion2[N];
    char texto2[N];
    char opcion3[N];
    char texto3[N];
    char pista[N];
    char codigo[N];
}opciones;

int main(){
    int nmenu,nmapa,seleccion;

    FILE *historia;
    char Historia[N];

    char texto[N];
    char nombre[N];

    //escribir los textos de cada mapa
    opciones T[M+1];

    //puzzles mapa1
    strcpy(T[1].opcion1,"opcion1");
    strcpy(T[1].texto1,"texto1");
    strcpy(T[1].opcion2,"52");
    strcpy(T[1].texto2,"texto2");
    strcpy(T[1].opcion3,"opcion3");
    strcpy(T[1].texto3,"texto3");
    strcpy(T[1].pista,"correcto");
    strcpy(T[1].codigo,"codigo");

    printf("1-Comenzar\n");
    printf("2-Personalizar\n");
    printf("3-Salir\n");
    printf("\n\nPresiona solamente numeros: ");

    scanf("%i",&nmenu);

    switch(nmenu){                                      //Menú
        case 1:                                         //Comenzar
            system("cls");
            printf("Ingresa un nombre: ");
            scanf("%s",texto);
            for(int i=0;i<N;i++){
                nombre[i]=texto[i];
            }

            system("cls");
            if(strcmp(texto,nombre)==0){
                system("cls");
                printf("Selecciona un mapa\n");
                printf("\t1\n\t2\n\t3\n");
                scanf("%i",&nmapa);
                switch(nmapa){
                    case 1:
                        system("cls");
                        historia=fopen("historia1.txt","r");
                            if(historia==NULL){
                                printf("No se encontro el archivo de la historia\n\n");
                                return -1;
                            }
                            else{
                                while(fgets(Historia,300,historia)){
                                    printf("%s",Historia);
                                }                                               //techo izda, techo drcha, pared izda, pared drcha, suelo izda, suelo drcha, posicion, valor de la fila, nombre del mapa
                                printf("\n\n");                                 //posicion de la puerta, pos de pared vertical superior, pos de pared horizontal izda, pos pared horizontal drcha
                            }                                                   //pos de la respuesta 1, de la respuesta 2, de la respuesta 3, nombres de los archivos de las pistas 1,2 y 3
                        fclose(historia);                                       //textos del archivo de la pista 1, de la pista 2, de la pista 3
                                                                                //mapas maximos creados, numero de mapa actual, nombre para la tabla(se pide al comenzar el juego), puntos otorgados por mapa
                        pause();                                                //textos de opcion1, opcion2, opcion3, opcionCorrecta, pista y el codigo
                        system("cls");
                        mapeado(1,31,166,196,298,328,185,33,"mapa1.txt",55,145,108,123,258,70,80,"puzzle11.txt","puzzle21.txt","puzzle31.txt",3,1,nombre,10,T[1].opcion1,T[1].texto1,T[1].opcion2,T[1].texto2,T[1].opcion3,T[1].texto3,T[1].pista,T[1].codigo);
                    break;
                    case 2:
                        system("cls");
                        historia=fopen("historia2.txt","r");
                            if(historia==NULL){
                                printf("No se encontro el archivo de la historia\n\n");
                                return -1;
                            }
                            else{
                                while(fgets(Historia,300,historia)){
                                    printf("%s",Historia);
                                }
                                printf("\n\n");
                            }
                        fclose(historia);

                        pause();
                        system("cls");

                        mapeado(1,31,166,196,298,328,185,33,"mapa2.txt",266,145,238,255,258,61,80,"puzzle12.txt","puzzle22.txt","puzzle32.txt",3,2,nombre,20,T[1].opcion1,T[1].texto1,T[1].opcion2,T[1].texto2,T[1].opcion3,T[1].texto3,T[1].pista,T[1].codigo);
                    break;
                    case 3:
                        system("cls");
                        historia=fopen("historia3.txt","r");
                            if(historia==NULL){
                                printf("No se encontro el archivo de la historia\n\n");
                                return -1;
                            }
                            else{
                                while(fgets(Historia,300,historia)){
                                    printf("%s",Historia);
                                }
                                printf("\n\n");
                            }
                        fclose(historia);

                        pause();
                        system("cls");

                        mapeado(1,44,185,228,553,596,209,46,"mapa3.txt",338,102,377,403,499,97,131,"puzzle13.txt","puzzle23.txt","puzzle33.txt",3,3,nombre,30,T[1].opcion1,T[1].texto1,T[1].opcion2,T[1].texto2,T[1].opcion3,T[1].texto3,T[1].pista,T[1].codigo);
                    break;
                    default:
                    break;
                }
            }
        break;
        case 2:                                                 //Personalizar
            system("cls");
            printf("Selecciona a tu personaje");
            printf("\n\t1 +\n\t2 Ñ\n\t3 $\n\t4 aprieta una tecla\n\nPresiona cualquier otro numero para volver al menu: ");
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
            }
            else{
                system("cls");
                char c=getchar();
                FILE *prueba=fopen("personaje.txt","w");
                fprintf(prueba,"%c",c);
                fclose(prueba);
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
            system("cls");
            return main();
        break;
    }

    return 0;
}
