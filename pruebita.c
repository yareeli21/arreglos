#include<stdio.h>
#include<stdlib.h>

int** crearMatriz(int,int);
void darDimM(int*,int*);
void darDatosMtz(int**,int,int);
void liberarMtz(int**,int);
void mostrarMtz(int**,int,int);
void Mensajes(int);
void darDimU(int*);
int*creaArregloU(int);
void mostrarU(int*,int);
void liberarU(int*);
void multiDiagonalP(int**,int);
void multiDiagonalS(int**,int);

void darDimM(int* fil, int* col){
	printf("Indique el numero de filas\n");
	scanf("%d",fil);
	printf("Indique el numero de columnas\n");
	scanf("%d",col);
};

int** crearMatriz(int fil, int col){
	int** mtz,i;
	mtz=(int**)malloc(fil*sizeof(int));
	if(mtz==NULL){
		Mensajes(0);
		exit(0);
	}
	for(i=0;i<fil;i++)
		mtz[i]=(int*)malloc(sizeof(int)*col);
	return mtz;
};
void Mensajes(int msg){
	char *mensaje[]={"No hay memoria disponible ... \n", "Memoria liberada ... \n"};
	printf("%s",mensaje[msg]);
};

void darDatosMtz(int** mtz,int fil, int col){
	int i,j;
	
	printf("Ingrese los datos de la Matriz\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			printf("Dato[%d][%d]= ",i+1,j+1);
			scanf("%d",&mtz[i][j]);
		}
}
};

void mostrarMtz(int **mtz,int fil, int col){
	int i,j;
		
	printf("los datos de la matriz zon: \n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++)
			printf("\t%d",mtz[i][j]);
		printf("\n");
	}
}

void liberarMtz(int** mtz,int fil){
	int i;
	for(i=0;i<fil;i++)
		free(mtz[i]);
	free(mtz);
	
	Mensajes(1);
}
   
void darDimU(int*elem){ 
   printf("Dar la dimension del arreglo\n");
   scanf("%d",elem);
}
   
int* creaArregloU(int elem){
   
   int *A;
   A=(int*)malloc(elem*sizeof(int));
   if(A==NULL){
      Mensajes(0);
      exit(0);
   }
      return A;
}
      
void mostrarU(int*A, int elem){
    int i;
    printf("Los datos del arreglo son:\n");
    for(i=0;i<elem;i++){
      printf("A[%d]=%d\n",i+1,A[i]);
    }
}
      
void liberarU(int*A){ 
     free(A);
     Mensajes(1);
}
void multiDiagonalP(int** mtz,int n){
	int k,x=0,*diagP, temporal=1;
	k=n;
	diagP = creaArregloU(n);
	for(int i=0;i<n;i++){
		x=i;
		for(int j=0;j<k;j++){
			temporal=temporal*(mtz[x][j]);
			x++;
		}
		*(diagP+i)=temporal;
        temporal=1;
		k--;
	}
    mostrarU(diagP,n);
    liberarU(diagP);
};

void multiDiagonalS(int** mtz,int n){
int x=0,*diagS,k=n, temporal=1;
    diagS = creaArregloU(n);
	for(int i=0;i<n;i++){
		x=0;
		for(int j=k-1;j>=0;j--){
			temporal=temporal*(mtz[x][j]);
			x++;
		}
		*(diagS+i)=temporal;
        temporal=1;
        k--;
    }
    mostrarU(diagS,n);
    liberarU(diagS);
};
int main(){
	int fil,col, **mtz;
	darDimM(&fil,&col);
	mtz=crearMatriz(fil,col);
	darDatosMtz(mtz,fil,col);
	mostrarMtz(mtz,fil,col);
    multiDiagonalP(mtz,fil);
	multiDiagonalS(mtz,fil);
	liberarMtz(mtz,fil);
    return 0;
};