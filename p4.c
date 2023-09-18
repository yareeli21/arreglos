#include<stdio.h>
#include<stdlib.h>

int **crearMatriz(int fil,int col);
void darDim(int *fil,int *col);
void darDatos(int **mtz,int fil,int col);
void mostrarM(int **mtz,int fil,int col);
void liberarM(int **mtz,int numElem);
void Mensajes(int msg);
int  menu();//sip
void darEnteros(int *p,int *q);
void elegirCase(int opcion,int **mtz,int **mtz1,int fil,int col,int fil2,int col2, int p, int q);
int **matrizxent(int **mtz,int fil, int col, int entero);//sip
int **suma(int **mtz,int **mtz1,int fil,int col);//sip
void op1(int **mtz,int **mtz1,int fil,int col,int p,int q);//sip
int **resta(int **mtz,int **mtz1,int fil,int col);//sip
void op2(int **mtz,int **mtz1,int fil,int col,int p,int q);//sip
int **mult(int **mtz,int **mtz1,int fil,int col,int fil2,int col2);//sip
void op3(int **mtz,int **mtz1,int fil,int col,int fil2,int col2,int p,int q);//sip

void main(){
    int **matrizA, **matrizB;
    int fil,col,p,q,op;
    printf("Dimensiones para la matriz A\n");
    darDim(&fil,&col);//sip
    printf("Dimensiones para la Matriz B\n");
    darDim(&fil,&col);
    matrizA=crearMatriz(fil,col);//sip
    matrizB=crearMatriz(fil,col);//sip
    darDatos(matrizA,fil,col);//sip
    darDatos(matrizB,fil,col);//sip
    darEnteros(&p,&q);//sip
    printf("Matriz A");
    mostrarM(matrizA,fil,col);//sip
    printf("\n");
    printf("Matriz B");
    mostrarM(matrizB,fil,col);//sip
    op=menu();//sip
    elegirCase(op,matrizA,matrizB,fil,col,fil,col,p,q);
}
int menu(){
int opcion;
    printf("\n1. pA + pB\n");
    printf("2. qA -  pB\n");
    printf("3. pA * qB\n");
    printf("\nDigite la opcion de la operacion que desea hacer:\n");
    scanf("%d",&opcion);
    return opcion;
}
void darEnteros(int *p,int *q){
    printf("\nDar el entero p:\n");
    scanf("%d",p);
    printf("Dar el entero q:\n");
    scanf("%d",q);
}
void darDim(int *fil,int *col){
    printf("# de filas:\n");
    scanf("%d",fil);
    printf("# de columnas:\n");
    scanf("%d",col);
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
void elegirCase(int opcion, int **mtz,int **mtz1, int fil,int col,int fil2,int col2,int p,int q){
  switch (opcion){
      case 1: op1(mtz,mtz1,fil,col,p,q);
              break;
      case 2: op2(mtz,mtz1,fil,col,p,q);
              break;
      case 3:op3(mtz,mtz1,fil,col,fil2,col2,p,q);
             break;
         default:
         printf("Opción no válida.\n");
     }
}
void Mensajes(int msj){
    char *mensaje[]={"No hay memoria disponible...\n","Memoria liberada...\n"};
    printf("%s",mensaje[msj]);
}
void liberarM(int **mtz,int fil){
    int i;
    for(i=0;i<fil;i++){
        free(mtz[i]);
        free(mtz);

        Mensajes(1);
    }
}

//funcion para la multiplicacion de un entero por una matriz
int **matrizxent(int **mtz,int fil, int col, int entero){
  int **m3=crearMatriz(fil,col);
  //la lógica para hacer la operación 
  int i,j;
  for(i=0;i<fil;i++){
     for(j=0;j<col;j++){
        m3[i][j]=mtz[i][j] * entero;;
     }
  }
  return m3;
}

int **suma(int **mtz,int **mtz1,int fil,int col){
   int i,j;
   int **m3=crearMatriz(fil,col);
   for(i=0;i<fil;i++){
      for(j=0;j<col;j++){
        m3[i][j]=mtz[i][j]+mtz1[i][j];
      }
   }
   return m3;
}
//pA + pB
void op1(int **mtz,int **mtz1,int fil,int col,int p,int q){
     int **r1,**r2,**resultado;
     r1=matrizxent(mtz,fil,col,p);
     r2=matrizxent(mtz1,fil,col,p);
     
     resultado=suma(r1,r2,fil,col);
     printf("La matriz final tras la primer operación:\n");
     mostrarM(resultado,fil,col);
     
     liberarM(r1,fil);
     liberarM(r2,fil);
     liberarM(resultado,fil);
}
//resta
int **resta(int **mtz,int **mtz1,int fil,int col){
   int i,j;
   int **m3=crearMatriz(fil,col);
   for(i=0;i<fil;i++){
      for(j=0;j<col;j++){
        m3[i][j]=mtz[i][j]-mtz1[i][j];
      }
   }
   return m3;
}
//funcion para qA - pB
void op2(int **mtz,int **mtz1,int fil,int col,int p,int q){
  int **r1,**r2,**resultado;
  r1=matrizxent(mtz,fil,col,q);
  r2=matrizxent(mtz1,fil,col,p);
     
     resultado=resta(r1,r2,fil,col);
     printf("La matriz final tras la segunda operación:\n");
     mostrarM(resultado,fil,col);
     
     liberarM(r1,fil);
     liberarM(r2,fil);
     liberarM(resultado,fil);

}
//multiplicación
int **mult(int **mtz,int **mtz1,int fil,int col,int fil2,int col2){
  int i,j,k;
  if(col!=fil2){
     printf("No se pueden multiplicar matrices con dimensiones distintas\n");
     return NULL;
  }
  int **m3=crearMatriz(fil,col);
  for(i=0;i<fil;i++){
     for(j=0;j<col2;j++){
       m3[i][j]=0;
       for(k=0;k<col;k++){
         m3[i][j]+=mtz[i][k]*mtz1[k][j];
       }
     }
  }
   return m3;
}
//funcion para pA * qB
void op3(int **mtz,int **mtz1,int fil,int col,int fil2,int col2,int p,int q){
  int **r1,**r2,**resultado;
  r1=matrizxent(mtz,fil,col,p);
  r2=matrizxent(mtz1,fil,col,q);
     
     resultado=mult(r1,r2,fil,col,fil2,col2);
     printf("La matriz final tras la tercera operación:\n");
     mostrarM(resultado,fil,col);
     
     liberarM(r1,fil);
     liberarM(r2,fil);
     liberarM(resultado,fil);

}
