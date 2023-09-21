#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//función para crear el arreglo dinámico, necesitaremos 3
int *crearA(int numElem);
//función para pedir el número de los datos de cada vector
void tamanoA(int *numElem);
void darDatos(int*A,int elem);
void mostrar(int *A,int *B,int *C,int elem);
int productoM(int *A,int *B,int *C);
void liberar(int **A, int numD, int numV);
void Mensajes(int msg);

void main(){
int *vector1,*vector2,*vector3; //el arreglo que contendrá todos los demás arreglos pequeños, o sea, los vectores
int numElem, volumen;
tamanoA(&numElem);
vector1=crearA(numElem);
darDatos(vector1,numElem);
vector2=crearA(numElem);
darDatos(vector2,numElem);
vector3=crearA(numElem);
darDatos(vector3,numElem);
mostrar(vector1,vector2,vector3,numElem);
volumen=productoM(vector1,vector2,vector3);
printf("Volumen del paralelepipedo es:%d \n",volumen);

}

void tamanoA(int *numElem){
  printf("Ingrese el tamano de cada vector (recordemos que son 3 coordenadas):\n");
  scanf("%d",numElem);
}

//para crear el arreglo
int *crearA(int elem){
	int *A;
	A=(int*)malloc(elem*sizeof(int));
	if(A==NULL){
		Mensajes(0);
		exit(0);
	}
	return A;
}

void darDatos(int*A, int elem){
	int i;
	printf("Ingrese los datos del vector\n");
	for(i=0; i<elem; i++){
		printf("\nA[%d]=",i+1);
		scanf("%d",&A[i]);
	}
}
void mostrar(int *A,int *B,int *C,int elem){
	int i;
	
	printf("Los datos del vector 1 son: \n");
	for(i=0; i<elem;i++)
	printf("A[%d]=%d\n",i+1,A[i]);
	getchar();
	printf("Los datos del vector 2 son: \n");
	for(i=0; i<elem;i++)
	printf("B[%d]=%d\n",i+1,A[i]);
	getchar();
	printf("Los datos del vector 3 son: \n");
	for(i=0; i<elem;i++)
	printf("C[%d]=%d\n",i+1,A[i]);
	getchar();
}

void Mensajes(int msg){
	char* mensaje[]={"No hay memoria disponible...\n", "Memoria liberada...\n"};
	
	printf("%s",mensaje[msg]);
}

int productoM(int *A,int *B,int *C){
    int volumen;
	volumen=(A[0]*B[1]*C[2]+B[0]*C[1]*A[2]+C[0]*A[1]*B[2])-(A[2]*B[1]*C[0]+B[2]*C[1]*A[0]+C[2]*A[1]*B[0]);

    return volumen;
}

