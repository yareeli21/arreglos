//hallar la determinante de A 2x2
#include<stdio.h>
#include<stdlib.h>

int **crearMatriz(int fil,int col);
void darDatos(int **mtz,int fil,int col);
void mostrarM(int **mtz,int fil,int col);
int determinante(int **mtz);
void mostrarD(int deter);
void liberarM(int **mtz,int numElem);
void Mensajes(int msg);

void main(){
    int **mtz;
    int deter;
    mtz=crearMatriz(2,2);
    darDatos(mtz,2,2);
    mostrarM(mtz,2,2);
    deter=determinante(mtz);
    mostrarD(deter);
    liberarM(mtz,2);
}
int **crearMatriz(int fil, int col){
   int **mtz;
   int i;
   mtz=(int**)malloc(fil*sizeof(int*));
   if(mtz==NULL){
    Mensajes(0);
    exit(0);
}
for(i=0;i<fil;i++){
    mtz[i]=(int*)malloc(col*sizeof(int));
}
    return mtz;
}
void darDatos(int **mtz,int fil, int col){
    int i,j;
    printf("Ingrese los datos de la matriz:\n");
    for(i=0;i<fil;i++){
        for(j=0;j<col;j++){
            printf("Dato[%d][%d]=",i+1,j+1);
            scanf("%d",&mtz[i][j]);
        }
    }
}
void mostrarM(int **mtz,int fil, int col){
    int i,j;
    for(i=0;i<fil;i++){
        printf("\n");
        for(j=0; j<col;j++){
            printf("%d\t",mtz[i][j]);
        }
    }
}
int determinante(int **mtz){
    int resultado;
    resultado=(mtz[0][0]*mtz[1][1])-(mtz[1][0]*mtz[0][1]);
    return resultado;
}
void mostrarD(int resul){
    printf("\nEl determinante de la matriz A 2x2 es: %d\n",resul);
}
void liberarM(int **mtz,int fil){
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
