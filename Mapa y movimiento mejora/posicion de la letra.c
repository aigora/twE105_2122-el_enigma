#include <stdio.h>

int main(){
    int pos=20;
    char letra;

    FILE *archivo;
    archivo=fopen("mapa2.txt","r");

    do{
        int car=fgetc(archivo);
        long pos=ftell(archivo);
        scanf("%c",&letra);
        switch(letra){
            case 'a':
                if(car=='#'){
                    pos=pos;
                }else{
                    pos=pos-1;
                }
            break;
            case 'd':
                if(car=='#'){
                    pos=pos;
                }else{
                    pos=pos+1;
                }
            break;
            default:
            break;
        }

        printf("%i",pos);

    }while(!feof(archivo));



    fclose(archivo);
    return 0;
}
