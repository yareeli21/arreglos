#include<stdio.h>
#include<stdlib.h>

int **crearMatriz(int fil,int col);
void darDatos(int **mtz,int fil,int col);
void mostrarM(int **mtz,int fil,int col);
void darDim(int *fil,int *col);
int *crearA(int numElem);
void mostrarA(int *A, int numELem);
void liberarM(int **mtz,int numElem);
void liberarA(int *A);
void Mensajes(int msg);
void sumaF(int **mtz, int fil,int col);
void sumaC(int**mtz,int fil,int col);

void main(){
 int **matriz;
 int fil, col;
 darDim(&fil,&col);
 matriz=crearMatriz(fil,col);
 darDatos(matriz,fil,col);
 mostrarM(matriz,fil,col);
 sumaF(matriz,fil,col);
 sumaC(matriz,fil,col);
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
void darDim(int *fil,int *col){
    printf("# de filas:\n");
    scanf("%d",fil);
    printf("# de columnas:\n");
    scanf("%d",col);
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
void sumaF(int **mtz, int fil,int col){
    int i,j;
    int suma;
    int *A;
    A=crearA(fil);
    for(i=0; i<fil; i++){
        suma=0;
        for(j=0;j<col;j++){
            suma +=mtz[i][j];
        }
        //agregando los valores de la suma de cada fila al arreglo
        A[i]=suma;
    }
    printf("\n");
    printf("Valores de la suma de cada fila de la matriz:\n");
    mostrarA(A,fil);
    liberarA(A);
}
void sumaC(int **mtz, int fil,int col){
    int i,j;
    int suma;
    int *A;
    A=crearA(col);
    for(j=0; j<col; j++){
        suma=0;
        for(i=0;i<fil;i++){
            suma +=mtz[i][j];
        }
        //agregando los valores de la suma de cada fila al arreglo
        A[j]=suma;
    }
    printf("\n");
    printf("Valores de la suma de cada columna de la matriz:\n");
    mostrarA(A,col);
    liberarA(A);
}
void liberarM(int **mtz,int fil){
    int i;
    for(i=0;i<fil;i++){
        free(mtz[i]);
        free(mtz);

        Mensajes(1);
    }
}
void liberarA(int  *A){
    free(A);
    Mensajes(1);
}
void Mensajes(int msj){
    char *mensaje[]={"No hay memoria disponible...\n","Memoria liberada...\n"};
    printf("%s",mensaje[msj]);
}
int *crearA(int numElem){
    int *A;
    A=(int*)malloc(numElem*sizeof(int));
    if(A==NULL){
        Mensajes(0);
        exit(0);
    }
}
void mostrarA(int *A, int numElem){
    int i;
    printf("Los valores del arreglo son: \n");
    for(i=0;i<numElem;i++){
        printf("A[%d]=%d\n",i+1,A[i]);
    }
}
