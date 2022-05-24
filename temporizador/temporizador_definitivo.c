#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(float seconds);


int main()
{
    int minutos = 5, segundos = 0;
    if((minutos == 1))
        printf("Falta %i minuto\n", minutos);
    else
        printf("Faltan %i minutos\n", minutos);

    while(((segundos != 0) || (minutos != 0)))
    {
        segundos--;
        if((segundos == -1) && (minutos > 0)){
            segundos = 59;
            minutos--;

        }
        if(segundos == 0)
        {
            if(minutos == 1)
                printf("Falta %i minuto\n", minutos);
            else
                printf("Faltan %i minutos\n", minutos);
        }
        delay(1);
     }
    printf(" \nSE ACABO EL TIEMPO. HAS PERDIDO\n");

    return 0;
}
void delay(float seconds)
{
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
