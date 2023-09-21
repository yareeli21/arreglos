#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void darDim(int*elem);
char *crearA(int numElem);
void escribir(char*pal);
void mostrar(char *pal);
void ordenar(char *pal,char *pal2);
void liberar(char *pal1,char *pal2);
void Mensajes(int msg);
void main(){

    char *pal,*pal2;
    pal=crearA(100);
    escribir(pal);
    pal2=crearA(100);
    ordenar(pal,pal2);
    liberar(pal,pal2);

}

char *crearA(int elem){
	char *pal;
	pal=(char*)malloc(elem*sizeof(char));
	if(pal==NULL){
		Mensajes(0);
		exit(0);
	}
	return pal;
}
void escribir(char*pal){
	printf("Digite una cadena\n");
		scanf("%s",pal);
}

void ordenar(char *pal,char *pal2){
    int n=strlen(pal);
 int lon,i,j;
    char temp;
    lon=strlen(pal);
    //se va a comparar cada letra con todas las de la misma palabra
    for(i=0;i<lon;i++){//i es para la primera letra
        for(j=i+1;j<lon;j++){//j es para la siguiente y que se pueda hacer la comparación
            if(pal[i]>pal[j]){//condición, i[0] se comparará con cada j[i+1], o sea, toda la palabra
                temp=pal[i];//una variable temporal
                pal[i]=pal[j];
                pal[j]=temp;
            }
        }
    }
    strcpy(pal2,pal);
    printf("La palabra ordenada es:\n %s\n",pal2);
}

void liberar(char *A,char *B){
	free(A);
    free(B);
	Mensajes(1);
}
void Mensajes(int msg){
	char* mensaje[]={"No hay memoria disponible...\n", "Memoria liberada...\n"};

	printf("%s",mensaje[msg]);
}
