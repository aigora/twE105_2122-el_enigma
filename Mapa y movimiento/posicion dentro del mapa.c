#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char fila[80];
}est;

int main(){
    int i;
    int paredizda=24,pareddcha=33;
    char letra,texto1[80];
    long int pos=28;

    est texto;

    FILE *archivo;
    FILE *archivo1;
    FILE *archivo2;

    archivo=fopen("archivo.txt","r");
    archivo1=fopen("archivo1.txt","w");


    do{

        while(fgets(texto.fila,10,archivo)!=NULL){
                fputs(texto.fila,archivo1);
                printf("%s",texto.fila);
        }

        fflush(stdin);
        printf("\n%ld",pos);
        printf("\nPresiona 'A''W''S''D' para moverte o presiona 'f' para salir: ");

        scanf("%c",&letra);
        switch(letra){
            case 'a':
                if(pos-1==paredizda){
                    pos=pos;
                }
                else{
                    fseek(archivo1,pos-1,SEEK_SET);
                    fprintf(archivo1,"%c",'A');
                    fseek(archivo1,pos,SEEK_SET);
                    fprintf(archivo1,"%c",' ');
                    pos-=1;

                    fseek(archivo1,pos+1,SEEK_SET);
                    fprintf(archivo1,"%c",' ');
                }

                system("cls");
                archivo2=fopen("archivo1.txt","r");
                while(fgets(texto1,80,archivo2)!=NULL){
                    printf("%s",texto1);
                }
                fclose(archivo2);
            break;
            case 'd':
                if(pos+1==pareddcha){
                    pos=pos;
                }
                else{
                    fseek(archivo1,pos+1,SEEK_SET);
                    fprintf(archivo1,"%c",'A');
                    fseek(archivo1,pos,SEEK_SET);
                    fprintf(archivo1,"%c",' ');
                    pos+=1;

                    fseek(archivo1,pos-1,SEEK_SET);
                    fprintf(archivo1,"%c",' ');
                }

                system("cls");
                archivo2=fopen("archivo1.txt","r");
                while(fgets(texto1,80,archivo2)!=NULL){
                    printf("%s",texto1);
                }
                fclose(archivo2);
            break;
            case 's':

                if(pos+12>48 && pos+12<59){
                    pos=pos;
                }
                else{
                    fseek(archivo1,pos+12,SEEK_SET);
                    fprintf(archivo1,"%c",'A');
                    fseek(archivo1,pos,SEEK_SET);
                    fprintf(archivo1,"%c",' ');
                    pos+=12;

                    fseek(archivo1,pos-12,SEEK_SET);
                    fprintf(archivo1,"%c",' ');

                    pareddcha+=12;
                    paredizda+=12;
                }

                system("cls");
                archivo2=fopen("archivo1.txt","r");
                while(fgets(texto1,80,archivo2)!=NULL){
                    printf("%s",texto1);
                }
                fclose(archivo2);
            break;
            case 'w':

                if(pos-12>0 && pos-12<11){
                    pos=pos;
                }
                else{
                    fseek(archivo1,pos-12,SEEK_SET);
                    fprintf(archivo1,"%c",'A');
                    fseek(archivo1,pos,SEEK_SET);
                    fprintf(archivo1,"%c",' ');
                    pos-=12;

                    fseek(archivo1,pos+12,SEEK_SET);
                    fprintf(archivo1,"%c",' ');

                    pareddcha-=12;
                    paredizda-=12;
                }

                system("cls");
                archivo2=fopen("archivo1.txt","r");
                while(fgets(texto1,80,archivo2)!=NULL){
                    printf("%s",texto1);
                }
                fclose(archivo2);
            break;
            default:
            break;
        }

    }while(letra!='f');

    fclose(archivo);
    fclose(archivo1);

    return 0;
}
