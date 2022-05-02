#include <stdio.h>

int main(){
    char letra;

    FILE *archivo;
    archivo=fopen("mapa1.txt","r");

    do{
        int car=fgetc(archivo);
        long int pos=ftell(archivo);
        if(car!=EOF){
            printf("%ld %c\n",pos,car);
        }
        else{
            printf("%ld EOF");
        }

    }while(!feof(archivo));



    fclose(archivo);
    return 0;
}
