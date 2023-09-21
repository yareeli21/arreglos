#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SolicitaTexto(char texto[50]);
void mostrar(char texto[50], int sum[10]);
void contador(int sum[10]);

int main(){
    char texto [50]; int sum[] ={0,0,0,0,0,0,0,0,0,0};

    SolicitaTexto(texto);
    mostrar(texto, sum);
    contador(sum);

}
void SolicitaTexto(char texto[50]){
printf("Escribe una palabra con números: ");
scanf("%[^\n]", texto);
}
void mostrar(char texto[50], int sum[10]){
   int tam;
   tam= strlen(texto);

    printf("Los dígitos encontrados fueron: ");
    for(int i=0; i<tam; i++){
        switch(texto[i]){
            case'0':
                sum[0] ++;
                printf("0 ");
                break;
            case '1':
                sum[1] ++;
                printf("1 ");
                break;
            case'2':
            sum[2] ++;
            printf("2 ");
              break;
            case'3':
            sum[3] ++;
            printf("3 ");
               break;
            case'4':
            sum[4] ++;
            printf("4 ");
               break;
            case'5':
            sum[5] ++;
            printf("5 ");
               break;
            case'6':
            sum[6] ++;
            printf("6 ");
               break;
            case'7':
            sum[7] ++;
            printf("7 ");
               break;
            case'8':
            sum[8] ++;
            printf("8 ");
               break;
            case'9':
            sum[9] ++;
            printf("9 ");
               break;
            default:
            break;



        }
    }
}

void contador(int sum[10]){
    printf("Aparece ");
    for (int i = 0; i < 10; i++){
        if  (sum[i] == 0){
            continue;
        }

        printf("%d-%d ", i, sum[i]);

    }

}
