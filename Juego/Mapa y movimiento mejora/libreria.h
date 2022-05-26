#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mapeado(int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,char mapafichero[],int p,int pared_vertical,int pared_hor_iz,int pared_hor_der,int pista1,int pista2,int pista3,char puzzle1[],char puzzle2[],char puzzle3[],int mapmax,int contdemapas,char nombres[],int puntos,char opcion1[],char texto1[],char opcion2[],char texto2[],char opcion3[],char texto3[],char pista[],char codigo[]){
    int techoizda=n1-1,techodcha=n2+1,
        paredizda=n3-1,pareddcha=n4-1,
        sueloizda=n5-1,sueloddcha=n6+1,
        pos=n7-1,valorfila=n8,
        puerta=p-1;

    _Bool apertura;

    char pruebas[100];

    char textoPuerta[100];

    char rankers[50];

    char pregunta[30];
    char letra,textomov[80];
    char fila[80];

    char puzzletexto[80];


    FILE *archivo;
    FILE *archivo1;
    FILE *archivo2;
    FILE *personaje;

    archivo=fopen(mapafichero,"r");
    archivo1=fopen("movimiento.txt","w");
    personaje=fopen("personaje.txt","r");

    int simbolo=fgetc(personaje);

    if(archivo==NULL){
        printf("No se ha encontrado el mapa #%i",contdemapas);
        return -1;
    }
    else{
        do{
            while(fgets(fila,80,archivo)){  //Imprime el mapa contínuamente
                fputs(fila,archivo1);             //por líneas
                printf("%s",fila);
            }


            if(pos==pista1-1){
                system("cls");
                FILE *pista1=fopen(puzzle1,"r");
                    imprimeArchivo(pista1);
                fclose(pista1);

                printf("\n\n");
                char respuesta[20];
                scanf("%s",respuesta);
                Opciones(respuesta,opcion1,opcion2,opcion3,pista,texto1,texto2,texto3,1);
            }

            if(pos==pista2-1){
                system("cls");
                FILE *pista2=fopen(puzzle2,"r");
                    imprimeArchivo(pista2);
                fclose(pista2);

                printf("\n\n");
                char respuesta[20];
                scanf("%s",respuesta);
                Opciones(respuesta,opcion1,opcion2,opcion3,pista,texto1,texto2,texto3,2);
            }

            if(pos==pista3-1){
                system("cls");
                FILE *pista3=fopen(puzzle3,"r");
                    imprimeArchivo(pista3);
                fclose(pista3);

                printf("\n\n");
                char respuesta[20];
                scanf("%s",respuesta);
                Opciones(respuesta,opcion1,opcion2,opcion3,pista,texto1,texto2,texto3,3);

            }


            if(strcmp(pregunta,codigo)==0){             //Desbloquea una puerta secreta
                apertura=1;                                     //si la respuesta es correcta
            }
            else{
                apertura=0;
            }

            if(pos==puerta){                                                       //Se imprime una pista al pasar por
                if(apertura){                                 //encima de una posición al haberla
                    printf("\n________________________");                          //desbloqueado antes
                    printf("\nHas conseguido salir\n");
                    printf("________________________\n");

                        FILE *puntuacion=fopen("tabla.txt","a");

                        fprintf(puntuacion,"%s\t%i\n",nombres,puntos);

                        fclose(puntuacion);

                    pause();

                    if(contdemapas==mapmax){
                        system("cls");
                        FILE *ranking=fopen("tabla.txt","r");
                        while(fgets(rankers,80,ranking)){
                            printf("%s",rankers);
                        }
                        fclose(ranking);
                        return 0;
                    }
                    else{
                        system("cls");
                        return main();
                    }

                }
            }


            fflush(stdin);

            printf("\n\nPresiona espacio para ir al menu.");
            printf("\nPresiona 'A''W''S' o 'D' para moverte o presiona 'f' para salir: ");
            scanf("%c",&letra);

            switch(letra){                                      //Movimiento
                case 'A':
                case 'a':
                    if(pos-1==paredizda){
                        pos=pos;
                    }
                    else if((pos-1==pared_vertical-1)||(pos-1==pared_vertical-1+valorfila)||(pos-1==pared_vertical-1+2*valorfila)){                        //Pared dentro del mapa
                        pos=pos;
                    }
                    else if(pos-1==pared_hor_der-1){
                        pos=pos;
                    }
                    else if((pos-1==puerta+1)||(pos-1==puerta-1)){
                        pos=pos;
                    }
                    else{
                        fseek(archivo1,pos-1,SEEK_SET);
                        fprintf(archivo1,"%c",simbolo);
                        fseek(archivo1,pos,SEEK_SET);
                        fprintf(archivo1,"%c",' ');
                        pos-=1;

                        fseek(archivo1,pos+1,SEEK_SET);
                        fprintf(archivo1,"%c",' ');

                        imprimirSimbolos(archivo1,pista2,pista1,pista3,puerta,apertura);
                    }

                    system("cls");
                    archivo2=fopen("movimiento.txt","r");
                    while(fgets(textomov,80,archivo2)){
                        printf("%s",textomov);
                    }
                    fclose(archivo2);
                break;
                case 'D':
                case 'd':
                    if(pos+1==pareddcha){
                        pos=pos;
                    }
                    else if((pos+1==pared_vertical-1)||(pos+1==pared_vertical-1+valorfila)||(pos+1==pared_vertical-1+2*valorfila)){
                        pos=pos;
                    }
                    else if(pos+1==pared_hor_iz-1){
                        pos=pos;
                    }
                    else if((pos+1==puerta+1)||(pos+1==puerta-1)){
                        pos=pos;
                    }
                    else{
                        fseek(archivo1,pos+1,SEEK_SET);
                        fprintf(archivo1,"%c",simbolo);
                        fseek(archivo1,pos,SEEK_SET);
                        fprintf(archivo1,"%c",' ');
                        pos+=1;

                        fseek(archivo1,pos-1,SEEK_SET);
                        fprintf(archivo1,"%c",' ');

                        imprimirSimbolos(archivo1,pista2,pista1,pista3,puerta,apertura);
                    }

                    system("cls");
                    archivo2=fopen("movimiento.txt","r");
                    while(fgets(textomov,80,archivo2)){
                        printf("%s",textomov);
                    }
                    fclose(archivo2);
                break;
                case 'S':
                case 's':

                    if(pos+valorfila>sueloizda && pos+valorfila<sueloddcha){
                        pos=pos;
                    }
                    else if((pos+valorfila==pared_vertical-1)||(pos+valorfila==pared_vertical-1+2*valorfila)){
                        pos=pos;
                    }
                    else if(pos+valorfila>pared_hor_iz-2 && pos+valorfila<pared_hor_der){
                        pos=pos;
                    }
                    else if((pos+valorfila==puerta-1)||pos+valorfila==puerta+1){
                        pos=pos;
                    }
                    else if((pos==puerta-valorfila) && (apertura==0)){
                            pos=pos;
                            system("cls");
                            FILE *imagenPuerta=fopen("imagenPuerta.txt","r");
                                imprimeArchivo(imagenPuerta);
                            fclose(imagenPuerta);
                            printf("\n\nescribe algo: ");
                            scanf("%s",&pregunta);

                            if(strcmp(pregunta,codigo)==0){
                                system("cls");
                                FILE *puertaAbierta=fopen("puertaAbierta.txt","r");
                                    imprimeArchivo(puertaAbierta);
                                fclose(puertaAbierta);
                                printf("\n________________________________");
                                printf("\nSe ha desbloqueado la puerta");
                                printf("\n________________________________\n");
                            }

                            pause();
                    }
                    else{
                        fseek(archivo1,pos+valorfila,SEEK_SET);
                        fprintf(archivo1,"%c",simbolo);
                        fseek(archivo1,pos,SEEK_SET);
                        fprintf(archivo1,"%c",' ');
                        pos+=valorfila;

                        fseek(archivo1,pos-valorfila,SEEK_SET);
                        fprintf(archivo1,"%c",' ');

                        pareddcha+=valorfila;
                        paredizda+=valorfila;

                        imprimirSimbolos(archivo1,pista2,pista1,pista3,puerta,apertura);
                    }

                    system("cls");
                    archivo2=fopen("movimiento.txt","r");
                    while(fgets(textomov,80,archivo2)){
                        printf("%s",textomov);
                    }
                    fclose(archivo2);
                break;
                case 'W':
                case 'w':
                    if(pos-valorfila>techoizda && pos-valorfila<techodcha){
                        pos=pos;
                    }
                    else if((pos-valorfila==pared_vertical-1)||(pos-valorfila==pared_vertical-1+2*valorfila)){
                        pos=pos;
                    }
                    else if(pos-valorfila>pared_hor_iz-2 && pos-valorfila<pared_hor_der){
                        pos=pos;
                    }
                    else if((pos-valorfila==puerta-1)||pos-valorfila==puerta+1){
                        pos=pos;
                    }
                    else if((pos==puerta+valorfila) && (apertura==0)){
                            pos=pos;
                            system("cls");
                            FILE *imagenPuerta=fopen("imagenPuerta.txt","r");
                                imprimeArchivo(imagenPuerta);
                            fclose(imagenPuerta);
                            printf("\n\nescribe algo: ");
                            scanf("%s",&pregunta);

                            if(strcmp(pregunta,codigo)==0){
                                system("cls");
                                FILE *puertaAbierta=fopen("puertaAbierta.txt","r");
                                    imprimeArchivo(puertaAbierta);
                                fclose(puertaAbierta);
                                printf("\n________________________________");
                                printf("\nSe ha desbloqueado la puerta");
                                printf("\n________________________________\n");
                            }

                            pause();
                    }
                    else{
                        fseek(archivo1,pos-valorfila,SEEK_SET);
                        fprintf(archivo1,"%c",simbolo);
                        fseek(archivo1,pos,SEEK_SET);
                        fprintf(archivo1,"%c",' ');
                        pos-=valorfila;

                        fseek(archivo1,pos+valorfila,SEEK_SET);
                        fprintf(archivo1,"%c",' ');

                        pareddcha-=valorfila;
                        paredizda-=valorfila;

                        imprimirSimbolos(archivo1,pista2,pista1,pista3,puerta,apertura);
                    }

                    system("cls");
                    archivo2=fopen("movimiento.txt","r");
                    while(fgets(textomov,80,archivo2)){
                        printf("%s",textomov);
                    }
                    fclose(archivo2);
                break;
                case ' ':
                    system("cls");
                    return main();
                break;
                default:
                break;
            }

        }while(letra!='f');
    }

    fclose(personaje);
    fclose(archivo);
    fclose(archivo1);
}

void imprimirSimbolos(FILE *archivo1,int pista1,int pista2,int pista3,int puerta,_Bool apertura){

    fseek(archivo1,pista1-1,SEEK_SET);
    fprintf(archivo1,"%c",'?');

    fseek(archivo1,pista2-1,SEEK_SET);
    fprintf(archivo1,"%c",'?');

    fseek(archivo1,pista3-1,SEEK_SET);
    fprintf(archivo1,"%c",'?');

    if(apertura==0){
        fseek(archivo1,puerta,SEEK_SET);
        fprintf(archivo1,"%c",'P');
    }
    else if(apertura==1){
        fseek(archivo1,puerta,SEEK_SET);
        fprintf(archivo1,"%c",' ');
    }
}

void imprimeArchivo(FILE *archivo){
    char texto[100];

    while(fgets(texto,100,archivo)){
        printf("%s",texto);
    }
}

void Opciones(char eleccion[],char opcion1[],char opcion2[],char opcion3[],char pista[],char texto1[],char texto2[],char texto3[],int n){
    switch(n){
        case 1:
            if(strcmp(eleccion,opcion1)==0){
                printf("%s\n",pista);
            }
            else if(strcmp(eleccion,opcion2)==0){
                printf("%s\n",texto2);
            }
            else if(strcmp(eleccion,opcion3)==0){
                printf("%s\n",texto3);
            }
        break;
        case 2:
            if(strcmp(eleccion,opcion1)==0){
                printf("%s\n",texto1);
            }
            else if(strcmp(eleccion,opcion2)==0){
                printf("%s\n",pista);
            }
            else if(strcmp(eleccion,opcion3)==0){
                printf("%s\n",texto3);
            }
        break;
        case 3:
            if(strcmp(eleccion,opcion1)==0){
                printf("%s\n",texto1);
            }
            else if(strcmp(eleccion,opcion2)==0){
                printf("%s\n",texto2);
            }
            else if(strcmp(eleccion,opcion3)==0){
                printf("%s\n",pista);
            }
        break;
    }

}

void pause(){
    printf("Presiona 'Enter' u otra tecla para continuar");
    getchar();

    char c=getchar();
    while(c!='\n'){
        c=getchar();
    }
}
