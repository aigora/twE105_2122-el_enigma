#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libreria.h"
#define N 200
#define M 9

typedef struct{
    char opcion1[N];
    char texto1[N];
    char opcion2[N];
    char texto2[N];
    char opcion3[N];
    char texto3[N];
    char pista[N];
}opciones;

typedef struct{
    char codigo[N];
}cod;

int main(){
    int nmenu,nmapa,seleccion;

    FILE *historia;
    char Historia[N];

    char texto[N];
    char nombre[N];


    char op1p1[N],op2p1[N],op3p1[N],t1p1[N],t2p1[N],t3p1[N];
    char op1p2[N],op2p2[N],op3p2[N],t1p2[N],t2p2[N],t3p2[N];
    char op1p3[N],op2p3[N],op3p3[N],t1p3[N],t2p3[N],t3p3[N];

    //escribir los textos de cada mapa
    opciones T[M+1];
    cod codigos[4];

    //codigos
    strcpy(codigos[1].codigo,"28045");
    strcpy(codigos[2].codigo,"20004");
    strcpy(codigos[3].codigo,"30204");

    //mapa1
    //puzzle1
    strcpy(T[1].opcion1,"Servidor2");
    strcpy(T[1].texto1,"Encontraste el pendrive, tiene pintado en numero 2");
    strcpy(T[1].opcion2,"Servidor1");
    strcpy(T[1].texto2,"No hay nada raro");
    strcpy(T[1].opcion3,"Servidor3");
    strcpy(T[1].texto3,"No hay nada raro");

    //puzzle2
    strcpy(T[2].opcion1,"80");
    strcpy(T[2].texto1,"Correcto. El periodico es parte vital, asi como la ultima del codigo");
    strcpy(T[2].opcion2,"");
    strcpy(T[2].texto2,"");
    strcpy(T[2].opcion3,"");
    strcpy(T[2].texto3,"");

    //puzzle3
    strcpy(T[3].opcion1,"45");
    strcpy(T[3].texto1,"Es parte del codigo");
    strcpy(T[3].opcion2,"");
    strcpy(T[3].texto2,"");
    strcpy(T[3].opcion3,"");
    strcpy(T[3].texto3,"");



    //mapa2
    //puzzle1
    strcpy(T[4].opcion1,"20004");
    strcpy(T[4].texto1,"Correcto");
    strcpy(T[4].opcion2,"");
    strcpy(T[4].texto2,"");
    strcpy(T[4].opcion3,"");
    strcpy(T[4].texto3,"");

    //puzzle2
    strcpy(T[5].opcion1,"2000");
    strcpy(T[5].texto1,"Correcto");
    strcpy(T[5].opcion2,"");
    strcpy(T[5].texto2,"");
    strcpy(T[5].opcion3,"");
    strcpy(T[5].texto3,"");

    //puzzle3
    strcpy(T[6].opcion1,"4");
    strcpy(T[6].texto1,"Correcto");
    strcpy(T[6].opcion2,"");
    strcpy(T[6].texto2,"");
    strcpy(T[6].opcion3,"");
    strcpy(T[6].texto3,"");


    //mapa3
    //puzzle1
    strcpy(T[7].opcion1,"30");
    strcpy(T[7].texto1,"Correcto");
    strcpy(T[7].opcion2,"");
    strcpy(T[7].texto2,"");
    strcpy(T[7].opcion3,"");
    strcpy(T[7].texto3,"");

    //puzzle2
    strcpy(T[8].opcion1,"Puerta");
    strcpy(T[8].texto1,"Esta cerrada");
    strcpy(T[8].opcion2,"Escritorio");
    strcpy(T[8].texto2,"Encuentras un papel con el codigo incompleto _ _ 2 0 _");
    strcpy(T[8].opcion3,"TV");
    strcpy(T[8].texto3,"'La policia tiene rodeado el edificio. Al parecer un policia en cubierto fue capturado'");

    //puzzle3
    strcpy(T[9].opcion1,"Enigma");
    strcpy(T[9].texto1,"Correcto");
    strcpy(T[9].opcion2,"enigma");
    strcpy(T[9].texto2,"Correcto");
    strcpy(T[9].opcion3,"ENIGMA");
    strcpy(T[9].texto3,"Correcto");

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

                        asignarTexto(op1p1,t1p1,T[1].opcion1,T[1].texto1,op2p1,t2p1,T[1].opcion2,T[1].texto2,op3p1,t3p1,T[1].opcion3,T[1].texto3);
                        asignarTexto(op1p2,t1p2,T[2].opcion1,T[2].texto1,op2p2,t2p2,T[2].opcion2,T[2].texto2,op3p2,t3p2,T[2].opcion3,T[2].texto3);
                        asignarTexto(op1p3,t1p3,T[3].opcion1,T[3].texto1,op2p3,t2p3,T[3].opcion2,T[3].texto2,op3p3,t3p3,T[3].opcion3,T[3].texto3);

                        mapeado(1,31,166,196,298,328,185,33,"mapa1.txt",55,145,108,123,258,70,80,"puzzle1-1.txt","puzzle1-2.txt","puzzle1-3.txt",3,1,nombre,10,op1p1,t1p1,op2p1,t2p1,op3p1,t3p1,op1p2,t1p2,op2p2,t2p2,op3p2,t3p2,op1p3,t1p3,op2p3,t2p3,op3p3,t3p3,codigos[1].codigo);
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

                        asignarTexto(op1p1,t1p1,T[4].opcion1,T[4].texto1,op2p1,t2p1,T[4].opcion2,T[4].texto2,op3p1,t3p1,T[4].opcion3,T[4].texto3);
                        asignarTexto(op1p2,t1p2,T[5].opcion1,T[5].texto1,op2p2,t2p2,T[5].opcion2,T[5].texto2,op3p2,t3p2,T[5].opcion3,T[5].texto3);
                        asignarTexto(op1p3,t1p3,T[6].opcion1,T[6].texto1,op2p3,t2p3,T[6].opcion2,T[6].texto2,op3p3,t3p3,T[6].opcion3,T[6].texto3);

                        mapeado(1,31,166,196,298,328,185,33,"mapa2.txt",266,145,238,255,258,61,80,"puzzle2-1.txt","puzzle2-2.txt","puzzle2-3.txt",3,2,nombre,20,op1p1,t1p1,op2p1,t2p1,op3p1,t3p1,op1p2,t1p2,op2p2,t2p2,op3p2,t3p2,op1p3,t1p3,op2p3,t2p3,op3p3,t3p3,codigos[2].codigo);
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

                        asignarTexto(op1p1,t1p1,T[7].opcion1,T[7].texto1,op2p1,t2p1,T[7].opcion2,T[7].texto2,op3p1,t3p1,T[7].opcion3,T[7].texto3);
                        asignarTexto(op1p2,t1p2,T[8].opcion1,T[8].texto1,op2p2,t2p2,T[8].opcion2,T[8].texto2,op3p2,t3p2,T[8].opcion3,T[8].texto3);
                        asignarTexto(op1p3,t1p3,T[9].opcion1,T[9].texto1,op2p3,t2p3,T[9].opcion2,T[9].texto2,op3p3,t3p3,T[9].opcion3,T[9].texto3);

                        mapeado(1,44,185,228,553,596,209,46,"mapa3.txt",338,102,377,403,499,97,131,"puzzle3-1.txt","puzzle3-2.txt","puzzle3-3.txt",3,3,nombre,30,op1p1,t1p1,op2p1,t2p1,op3p1,t3p1,op1p2,t1p2,op2p2,t2p2,op3p2,t3p2,op1p3,t1p3,op2p3,t2p3,op3p3,t3p3,codigos[3].codigo);
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
