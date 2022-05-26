void mapeado(int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,char mapafichero[],int p,int pared_vertical,int pared_hor_iz,int pared_hor_der,int q,int pista,int puzzle){
    int techoizda=n1-1,techodcha=n2+1,
        paredizda=n3-1,pareddcha=n4-1,
        sueloizda=n5-1,sueloddcha=n6+1,
        pos=n7-1,valorfila=n8,
        puerta=p-1;

    int apertura=0;

    char pregunta[30];
    char letra,texto1[80];
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

    do{

        while(fgets(fila,80,archivo)!=NULL){  //Imprime el mapa contínuamente
            fputs(fila,archivo1);             //por líneas
            printf("%s",fila);
        }

        if(pos==puzzle-1){
            system("cls");

            FILE *puzzle=fopen("puzzle.txt","r");
            printf("________________________\n");
            while(fgets(puzzletexto,80,puzzle)){
                printf("%s",puzzletexto);
            }
            printf("\n________________________\n\n");
            fclose(puzzle);
        }


        if(pos==q-1){                                 //Objeto interactivo que
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

        if(pos==pista-1){                                    //Se imprime una pista al pasar por
            printf("\n________________________");       //encima de una posición
            printf("\nEscribe 'hola'");
            printf("\n________________________");
        }
        
        if(pos==puerta){                                     // Se imprime una pista al pasar
            if(apertura){                                    // por encima de una posición al 
                printf("\n________________________");        //haberla esbloqueado.
                printf("ªnHas conseguido salir\n");
                printf("________________________\n");
                
                    FILE *puntuacion=fopen("tabla.txt","a");
                
                    fprintf(puntuacion,"%s",nombres);
                    fprintf(puntuacion,"%c",'\t');
                    fprintf(puntuacion,"%i",puntos);
                    fprintf(puntuacion,"%c",'\n');
                
                    fclose(puntuacion);
                
                system("pause");
                
                if(contdemapas==mapmax){
                    system("cls");
                    FILE *ranking=fopen("tabla.txt","r");
                    while(fgets(rankers,80,ranking)!=NULL) {
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

        //printf("\n%ld",pos);
        printf("\n\nPresiona espacio para ir al menu.");
        printf("\nPresiona 'A''W''S' o 'D' para moverte o presiona 'f' para salir: ");



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

                    fseek(archivo1,pista-1,SEEK_SET);            //Imprime contínuamente
                    fprintf(archivo1,"%c",'S');             //un símbolo

                    fseek(archivo1,q-1,SEEK_SET);
                    fprintf(archivo1,"%c",'Q');

                    fseek(archivo1,puzzle-1,SEEK_SET);
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

                    fseek(archivo1,pista-1,SEEK_SET);
                    fprintf(archivo1,"%c",'S');

                    fseek(archivo1,q-1,SEEK_SET);
                    fprintf(archivo1,"%c",'Q');

                    fseek(archivo1,puzzle-1,SEEK_SET);
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
                else if((pos+valorfila==puerta-1)||pos+valorfila==puerta+1){
                    pos=pos;
                }
                else if((pos==puerta-valorfila) && (apertura==0)){
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

                    fseek(archivo1,pista-1,SEEK_SET);
                    fprintf(archivo1,"%c",'S');

                    fseek(archivo1,q-1,SEEK_SET);
                    fprintf(archivo1,"%c",'Q');

                    fseek(archivo1,puzzle-1,SEEK_SET);
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

                    fseek(archivo1,pista-1,SEEK_SET);
                    fprintf(archivo1,"%c",'S');

                    fseek(archivo1,q-1,SEEK_SET);
                    fprintf(archivo1,"%c",'Q');

                    fseek(archivo1,puzzle-1,SEEK_SET);
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

                system("cls");
                archivo2=fopen("movimiento.txt","r");
                while(fgets(texto1,80,archivo2)!=NULL){
                    printf("%s",texto1);
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

    fclose(personaje);
    fclose(archivo);
    fclose(archivo1);

    return 0;
}

void bloques(){

}
