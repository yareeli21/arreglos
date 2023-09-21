#include<stdio.h>
#include<stdlib.h>

void darDim(int *elem);
int *crearArregloUni(int elem);
void darDatos(int*A,int elem);
void mostrar(int *A, int elem);
void liberar(int *A);
void Mensajes(int msg);
int menu(int *opcion);
void elegir(int buena,int *elem);

void main(){
    int *vector;
    int numElem,opcion,buena;
    buena=menu(&opcion);
    elegir(vector,&numElem);
}
int menu(int opcion){

    printf("Introduzca el numero de lo que desea hacer:\n");
    printf("1. Solicite el número de elementos a guardar en el vector.\n");
    printf("2. Introduzca los elementos al vector.\n");
    printf("3. Ordenar los elementos en orden creciente.\n");
    printf("4. Ordenar los elementos en orden decreciente.\n");
    printf("5. Mostrar los elementos del vector.\n");
    printf("6. Salir");
    scanf("%d",opcion);

    return opcion;
}
void elegir(int buena,int *elem){
    do(
        menu(buena);
        switch (buena){
            case 1: darDim(elem);
        }
    )
}
void darDim(int*elem){
	printf("Dar las dimensiones del arreglo\n");
	scanf("%d",elem);
}

int *crearArregloUni(int elem){
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
	printf("Ingerese los datos del arreglo\n");
	for(i=0; i<elem; i++){
		printf("\nA[%d]=",i+1);
		scanf("%d",&A[i]);
	}
}
void mostrar(int *A,int elem){
	int i;

	printf("Los datos del arreglo son: \n");
	for(i=0; i<elem;i++)
	printf("A[%d]=%d\n",i+1,A[i]);

}

void liberar(int*A){
	free(A);
	Mensajes(1);
}
void Mensajes(int msg){
	char* mensaje[]={"No hay memoria disponible...\n", "Memoria liberada...\n"};

	printf("%s",mensaje[msg]);
}
