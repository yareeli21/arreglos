#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void darDim(int *fil);
int **crearMatriz(int fil,int col);
void darDatos(int **mtz,int fil,int col);
void mostrarM(int **mtz,int fil,int col);
float promC(int **mtz,int n,int col);
int mayorF(int **mtz,int n,int fil);
int posF(int **mtz,int n,int fil);
float *crearA(int numElem);
void darDatosA(float *Ar,int **A,int **B, int elem);
void mostrar(float *A,int elem);
void liberarM(int **mtz,int **mtz1,float *A,int numElem);
void Mensajes(int msg);

void main(){
    int n;
    int **mA,**mB;
    float *array;
    darDim(&n);
    int m=n;
    mA=crearMatriz(n,m);
    mB=crearMatriz(n,m);
    darDatos(mA,n,m);
    darDatos(mB,n,m);
    mostrarM(mA,n,m);
    printf("\n");
    mostrarM(mB,n,m);
    array=crearA(n);
    darDatosA(array,mA,mB,n);
    mostrar(array,n);
    liberarM(mA,mB,array,n);
}
void darDim(int *n){
   printf("Valor de n es:\n");
   scanf("%d",n);
}
int **crearMatriz(int n, int m){
   int **mtz;
   int i;
   mtz=(int**)malloc(n*sizeof(int*));
   if(mtz==NULL){
    Mensajes(0);
    exit(0);
}
for(i=0;i<n;i++){
    mtz[i]=(int*)malloc(m*sizeof(int));
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
float promC(int **mtz,int n,int col){
        int suma=0;
        int i;
    for(i=0;i<n;i++){
        suma+=mtz[i][col];
    }
    return (float)suma/n;
}
int mayorF(int **mtz,int n,int fil){
    int mayor=mtz[fil][0];
    int i;
    for(i=0;i<n;i++){
        if(mtz[fil][i]>mayor){
            mayor=mtz[fil][i];
        }
    }
    return mayor;
}
int posF(int **mtz,int n,int fil){
    int mayor=mtz[fil][0];
    int i;
    int pos=0;
    for(i=0;i<n;i++){
        if(mtz[fil][i]>mayor){
            mayor=mtz[fil][i];
            pos=i;
        }
    }
    return i;
}

float *crearA(int n){
	float *A;
	A=(float*)malloc(n*sizeof(float));
	if(A==NULL){
		Mensajes(0);
		exit(0);
	}
	return A;
}
void darDatosA(float *Ar,int **A,int **B, int n){
	int i,mayor,pos;
    float promedio;
	//printf("Ingreese los datos del arreglo\n");
	for(i=0; i<n; i++){
		promedio=promC(A,n,i);
        mayor=mayorF(B,n,i);
        pos=posF(B,n,i);
        Ar[i]=pow((promedio*mayor),pos+pos);
	}
}
void mostrar(float *A,int n){
	int i;

	printf("\nLos datos del arreglo son: \n");
	for(i=0; i<n;i++)
	printf("A[%d]=%.2f\n",i+1,A[i]);

}

void liberarM(int **mA,int **mB,float *C,int fil){
    int i;
 for (int i = 0; i < fil; i++) {
        free(mA[i]);
        free(mB[i]);
    }
    free(mA);
    free(mB);
    free(C);
    Mensajes(1);

}
void Mensajes(int msj){
    char *mensaje[]={"\nNo hay memoria disponible...\n","\nMemoria liberada...\n"};
    printf("%s",mensaje[msj]);
}
