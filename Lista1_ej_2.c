#include <stdio.h>
#include <stdlib.h>
void darDim(int *elem);
int *crearArregloUni(int elem);
int **crearMatriz(int fil, int col);
void darDatosMtz(int **mtz, int fil, int col);
void mostrarMtz(int **mtz, int fil, int col);
void liberarMtz(int **mtz, int fil);
void liberar(int *A);
void mostrar(int *A, int elem);
void Mensajes(int msg);
void logica(int **A, int *B, int n);
void main()
{
    int n, **mtz, *array;
    darDim(&n);
    array = crearArregloUni(n);
    mtz = crearMatriz(n, n);
    darDatosMtz(mtz, n, n);
    mostrarMtz(mtz, n, n);
    logica(mtz, array, n);
    mostrar(array, n);
    liberarMtz(mtz, n);
    liberar(array);
}
void Mensajes(int msg)
{
    char *mensaje[] = {"No hay memoria disponible...\n",
                       "Memoria liberada...\n"};
    printf("%s", mensaje[msg]);
}
int **crearMatriz(int fil, int col)
{
    int **mtz;
    mtz = (int **)malloc(fil * sizeof(int));
    if (mtz == NULL)
    {
        Mensajes(0);
        exit(0);
    }
    for (int i = 0; i < fil; i++)
        mtz[i] = (int *)malloc(col * sizeof(int));
    return mtz;
}
void darDatosMtz(int **mtz, int fil, int col)
{
    printf("Ingrese los datos de la Matriz:\n");
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Dato[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &mtz[i][j]);
        }
    }
}
void mostrarMtz(int **mtz, int fil, int col)
{
    printf("Los datos de la Matriz son:\n");
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", mtz[i][j]);
        }
        printf("\n");
    }
}
void liberarMtz(int **mtz, int fil)
{
    for (int i = 0; i < fil; i++)
        free(mtz[i]);
    free(mtz);
    Mensajes(1);
}
void darDim(int *elem)
{
    printf("Dar la dimensión del arreglo: ");
    scanf("%d", elem);
}
int *crearArregloUni(int elem)
{
    int *A;
    A = (int *)malloc(elem * sizeof(int));
    if (A == NULL)
    {
        Mensajes(0);
        exit(0);
    }
    return A;
}
void mostrar(int *A, int elem)
{
    printf("Los datos del arreglo son: \n");
    for (int i = 0; i < elem; i++)
    {
        printf("A[%d] = %d\n", i + 1, A[i]);
    }
}
void liberar(int *A)
{
    free(A);
    Mensajes(1);
}
void logica(int **A, int *B, int n)
{
    int suma;
    for (int i = 0; i < n; i++)
    {
        suma = 0;
        if (i % 3 == 0)
        {
        }
        else if (i % 3 == 1)
        {
            for (int k = i - 1; k < n; k++)
            {
                suma += A[k][i];
            }
        }
        else
        {
            for (int k = 0; k < n; k++)
            {
                suma += A[i][k];
            }
        }
        B[i] = suma;
    }
}