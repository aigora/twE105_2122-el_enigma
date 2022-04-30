void mapeado(int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,char mapafichero[],int puerta){
    int techoizda=n1-1,techodcha=n2+1,
        paredizda=n3-1,pareddcha=n4-1,
        sueloizda=n5-1,sueloddcha=n6+1,
        pos=n7-1,valorfila=n8;

    //paredes dentro del mapa
    int pared_vertical=152,
        pared_hor_iz=235,
        pared_hor_der=255;


    int apertura=0;

    char pregunta[30];
    char letra,texto1[80];
    char fila[80];

    FILE *archivo;
    FILE *archivo1;
    FILE *archivo2;
    FILE *personaje;

    archivo=fopen(mapafichero,"r");
    archivo1=fopen("movimiento.txt","w");
    personaje=fopen("personaje.txt","r");

    int simbolo=fgetc(personaje);


    do{

        while(fgets(fila,80,archivo)!=NULL){  //Imprime el mapa contínuamente
            fputs(fila,archivo1);             //por líneas
            printf("%s",fila);
        }

        if(pos==113){                               //Objeto interactivo que
            printf("\n________________________");   //almacena una cadena de caracteres
            printf("\nHas encontrado algo");
            printf("\n________________________");
            printf("\nEscribe un texto:");
            scanf("%s",pregunta);
        }

        if(strcmp(pregunta,"hola")==0){             //Desbloquea una puerta secreta
            printf("\n________________________");   //si la respuesta es correcta
            printf("\nLa clave es ...");
            printf("\n________________________");

            apertura=1;
        }
        else{
            fseek(archivo1,50,SEEK_SET);
            fprintf(archivo1,"%c",' ');
            printf("\nPuertas sin desbloquear = 1");
            apertura=0;
        }

        if(pos==puerta){                                    //Se imprime una pista al pasar por
            if(apertura==1){                                //encima de una posición al haberla
                printf("\n________________________");       //desbloqueado antes
                printf("\nHas conseguido salir\n");
                printf("________________________\n");
                system("pause");
                system("cls");
                return main();
            }
        }

        if(pos==60){                                    //Se imprime una pista al pasar por
            printf("\n________________________");       //encima de una posición
            printf("\nEscribe 'hola'");
            printf("\n________________________");
        }


        fflush(stdin);

        printf("\n%ld",pos);
        printf("\n\nPresiona 'A''W''S''D' para moverte o presiona 'f' para salir: ");


        scanf("%c",&letra);
        switch(letra){                                      //Movimiento
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

                    fseek(archivo1,60,SEEK_SET);            //Imprime contínuamente
                    fprintf(archivo1,"%c",'S');             //un símbolo

                    if(apertura==0){
                        fseek(archivo1,puerta,SEEK_SET);
                        fprintf(archivo1,"%c",'P');
                    }
                    else if(apertura==1){
                        fseek(archivo1,puerta,SEEK_SET);
                        fprintf(archivo1,"%c",' ');
                    }
                }

                system("cls");
                archivo2=fopen("movimiento.txt","r");
                while(fgets(texto1,80,archivo2)!=NULL){
                    printf("%s",texto1);
                }
                fclose(archivo2);
            break;
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

                    fseek(archivo1,60,SEEK_SET);
                    fprintf(archivo1,"%c",'S');

                    if(apertura==0){
                        fseek(archivo1,puerta,SEEK_SET);
                        fprintf(archivo1,"%c",'P');
                    }
                    else if(apertura==1){
                        fseek(archivo1,puerta,SEEK_SET);
                        fprintf(archivo1,"%c",' ');
                    }
                }

                system("cls");
                archivo2=fopen("movimiento.txt","r");
                while(fgets(texto1,80,archivo2)!=NULL){
                    printf("%s",texto1);
                }
                fclose(archivo2);
            break;
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
                else if(pos+valorfila==puerta-1){
                    pos=pos;
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

                    fseek(archivo1,60,SEEK_SET);
                    fprintf(archivo1,"%c",'S');

                    if(apertura==0){
                        fseek(archivo1,puerta,SEEK_SET);
                        fprintf(archivo1,"%c",'P');
                    }
                    else if(apertura==1){
                        fseek(archivo1,puerta,SEEK_SET);
                        fprintf(archivo1,"%c",' ');
                    }
                }

                system("cls");
                archivo2=fopen("movimiento.txt","r");
                while(fgets(texto1,80,archivo2)!=NULL){
                    printf("%s",texto1);
                }
                fclose(archivo2);
            break;
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

                    fseek(archivo1,60,SEEK_SET);
                    fprintf(archivo1,"%c",'S');


                    if(apertura==0){
                        fseek(archivo1,puerta,SEEK_SET);
                        fprintf(archivo1,"%c",'P');
                    }
                    else if(apertura==1){
                        fseek(archivo1,puerta,SEEK_SET);
                        fprintf(archivo1,"%c",' ');
                    }
                }

                system("cls");
                archivo2=fopen("movimiento.txt","r");
                while(fgets(texto1,80,archivo2)!=NULL){
                    printf("%s",texto1);
                }
                fclose(archivo2);
            break;
            default:
            break;
        }

    }while(letra!='f');

    fclose(personaje);
    fclose(archivo);
    fclose(archivo1);

    return 0;
}

void bloques(){

}
