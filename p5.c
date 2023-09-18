/* hacer un programa que dada una matriz R de nxm con elementos de tipo caracter proporcionados por el usuario, obtenga la matriz traspuesta
RT e imprima el contenido de ambas matrices*/
#include<stdio.h>
#include<stdlib.h>

void darDim(int *fil,int *col);
char **crearMatriz(int fil,int col);
void darDatos(char **mtz,int fil,int col);
void mostrarM(char **mtz,int fil,int col);
void Mtrans(char **mtz,int fil,int col);
void liberarM(char **mtz,int numElem);
void Mensajes(int msg);

void main(){

    char **mtz1;
    int fil,col;
    darDim(&fil,&col);
    mtz1=crearMatriz(fil,col);
    darDatos(mtz1,fil,col);
    mostrarM(mtz1,fil,col);
    //liberarM(mtz1,fil);
    Mtrans(mtz1,fil,col);

}
void darDim(int *fil,int *col){
    printf("# de filas:\n");
    scanf("%d",fil);
    printf("# de columnas:\n");
    scanf("%d",col);
}
char **crearMatriz(int fil, int col){
   char **mtz;
   int i;
   mtz=(char**)malloc(fil*sizeof(char*));
   if(mtz==NULL){
    Mensajes(0);
    exit(0);
}
for(i=0;i<fil;i++){
    mtz[i]=(char*)malloc(col*sizeof(char));
}
    return mtz;
}
void darDatos(char **mtz,int fil, int col){
    int i,j;
    printf("Ingrese los datos de la matriz:\n");
    getchar();
    for(i=0;i<fil;i++){
        for(j=0;j<col;j++){
            printf("Dato[%d][%d]=",i+1,j+1);
            scanf("%c",&mtz[i][j]);
            getchar();
        }
    }
}
void mostrarM(char **mtz,int fil, int col){
    int i,j;
    for(i=0;i<fil;i++){
        printf("\n");
        for(j=0; j<col;j++){
            printf("%c\t",mtz[i][j]);
        }
    }
}
void Mtrans(char **mtz,int fil,int col){
    char **RT=crearMatriz(fil,col);
    int i,j;
    for(i=0;i<fil;i++){
        for(j=0;j<col;j++){
            RT[j][i]=mtz[i][j];
        }
    }
    printf("\nLa matriz transpuesta es:\n");
    mostrarM(RT,fil,col);
    liberarM(RT,fil);
}
void liberarM(char **mtz,int fil){
    int i;
    for(i=0;i<fil;i++){
        free(mtz[i]);
        free(mtz);

        Mensajes(1);
    }
}
void Mensajes(int msj){
    char *mensaje[]={"\nNo hay memoria disponible...\n","\nMemoria liberada...\n"};
    printf("%s",mensaje[msj]);
}
