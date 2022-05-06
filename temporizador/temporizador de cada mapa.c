#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <threads.h>

void delay( float seconds);


int main()
{
    int horas, minutos, segundos;
    scanf("%i %i %i", &horas, &minutos, &segundos);
    printf("Toca cualquier tecla para iniciar la partida: ");
    system("pause ->NUL");
    while(1)
    {
        segundos--;
        if((segundos == -1) && (minutos > 0)){
            segundos = 59;
            minutos--;

        }
        if((segundos == -1) && (minutos == 0) && (horas > 0)){
                minutos = 59;
                segundos = 59;
                horas--;
            }


        system("cls");
        if(((segundos < 10) && (segundos >= 0)) && ((minutos < 10) && (minutos >= 0)) && ((horas < 10) && (horas >= 0)))
            printf("\t\t\t\t\t\t[ 0%i:0%i:0%i ]", horas, minutos, segundos);
        else if(((segundos < 10) && (segundos >= 0)) && ((minutos < 10) && (minutos >= 0)))
            printf("\t\t\t\t\t\t[ %i:0%i:0%i ]", horas, minutos, segundos);
        else if(((minutos < 10) && (minutos >= 0)) && ((horas < 10) && (horas >= 0)))
            printf("\t\t\t\t\t\t[ 0%i:0%i:%i ]", horas, minutos, segundos);
        else if(((segundos < 10) && (segundos >= 0)) && ((horas < 10) && (horas >= 0)))
            printf("\t\t\t\t\t\t[ 0%i:%i:0%i ]", horas, minutos, segundos);
        else if(((horas < 10) && (horas >= 0)))
            printf("\t\t\t\t\t\t[ 0%i:%i:%i ]", horas, minutos, segundos);
        else if(((segundos < 10) && (segundos >= 0)))
            printf("\t\t\t\t\t\t[ %i:%i:0%i ]", horas, minutos, segundos);
        else if(((minutos < 10) && (minutos >= 0)))
            printf("\t\t\t\t\t\t[ %i:0%i:%i ]", horas, minutos, segundos);

        else
            printf("\t\t\t\t\t\t[ %i:%i:%i ]", horas, minutos, segundos);

        //printf("\t\t\t\t\t\t[ %i:%i:%i ]", horas, minutos, segundos);
        delay(1);

        if((segundos == 0) && (minutos == 0) && (horas == 0))
            break;
    }
    printf(" \nSE ACABO EL TIEMPO. HAS PERDIDO\n");

    return 0;
}
void delay( float seconds)
{
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

