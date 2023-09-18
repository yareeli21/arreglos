#include<stdio.h>
#include<stdlib.h>

//función para crear el arreglo dinámico, necesitaremos 3
int **crearA(int numD, int numV);
//función para pedir el número de los datos de cada vector
void darNum(int *numD, int *numV);
void darDatos(int **vect,int numD, int numV);
void mostrarA(int **vect,int numD, int numV);
int productM(int **vect, int numD, int numV);
void liberar(int **A, int numD, int numV);
void Mensajes(int msg);

void main(){
int **array; //el arreglo que contendrá todos los demás arreglos pequeños, o sea, los vectores
int numV,numD, volumen;
darNum(&numD,&numV);
array=crearA(numD,numV);
darDatos(array,numD, numV);
volumen=productM(array,numD,numV);
mostrarA(array,numD, numV);
liberar(array,numD,numV);

}

void darNum(int *numD,int *numV){
printf("Ingrese el tamaño del arreglo principal (el número de vectores que se usarán):\n");
scanf("%d",numV);
printf("Ingrese el tamaño del cual será cada vector(cuantas coordenadas tendrá cada vecttor)\n");
scanf("%d",numD);
}
void darDatos(int **array,int numD, int numV){
int i,j;
for(i=0; i<numV; i++){
printf("Elementos del vector %d:\n",i+1);
   for(j=0; j<numD;j++){
   printf("Coordenada %d:\n",j+1);
   scanf("%d",&array[i][j]);
     }
  }
}
//creación del arreglo grandote
int **crearA(int numD, int numV){
  int **A;
  int i;
  
  A=(int**)malloc(numV*sizeof(int*));
  if(A==NULL){
     Mensajes(0);
     exit(0);
  }
  //se le agregarán los otros arreglos dinámicos
  for(i=0; i<numV; i++){
  A[i]=(int*)malloc(numD*sizeof(int));
  if(A[i]==NULL){
     Mensajes(0);
     exit(0);
  }
  }
  return A;//se regresa el arreglo con varios arreglos
}
void liberar(int **A,int numD, int numV){
 int i,j;	
   for(i=0; i<numD; i++){
     free(A[i]);
   }	
	free(A);
	Mensajes(1);
}
void Mensajes(int msg){
	char* mensaje[]={"No hay memoria disponible...\n", "Memoria liberada...\n"};
	
	printf("%s",mensaje[msg]);
}
void mostrarA(int **array, int numD, int numV){
   int i,j;
   printf("Los datos de cada vector\n");
   for(i=0;i<numV;i++){
    printf("Vector %d\n",i+1);
    printf("\n");
    for(j=0;j<numD;j++){
      printf("%d\t",array[i][j]);
    }
    printf("\n");
   }
}
//función para obtener el volumen de un paralelepípedo tras usar un arreglo principal de arreglos dinámicos, donde cada arreglo pequeño es un vector
int productM(int **vect, int numV,numD){
    int i,j;
    if(numV =! 3){
    printf("Deben de ser 3 vectores, intenta de nuevo");
    return 0;
    }
    for(i=0; i<numV; i++){
    int productocruz=1;
      for(j=0; j<numD;j++){
       productocruz *= vect[j][i];
       }
       volumen += productocruz;
    }
    return volumen;
}

