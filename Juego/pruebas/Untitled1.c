#include <stdio.h>

int main(){

    FILE *archivo=fopen("tiempo.txt","r");
    char n[20];
    char c;
    fgets(n,20,archivo);

    for(int i=0;n[i]!='\0';i++){
        if(n[i]=='a'){
            c=fgetc(archivo);
            printf("horas son %c\n",c);
        }
        else if(n[i]=='b'){
            c=fgetc(archivo);
            printf("minutos son %c\n",c);
        }
        else if(n[i]=='c'){
            c=fgetc(archivo);
            printf("segundos son %c\n",c);
        }
    }

    fclose(archivo);

}
