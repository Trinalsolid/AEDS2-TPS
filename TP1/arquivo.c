#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int quantidade;
    double valores = 0.0;

    FILE *arq = NULL;

    arq = fopen("arquivo.txt" , "wb");

    scanf("%d" , &quantidade);

    if (arq != NULL){
        for (int i = 0; i < quantidade; i++){
            scanf("%lf", &valores);
            fwrite(&valores, sizeof(double) , 1 ,arq);    
        }       
    }

    fclose(arq);
    arq = fopen("arquivo.txt" , "r");
    
    double retorno = 0.0;
    if ( arq != NULL){
        for (int i = 1; i <= quantidade; i++){
            fseek(arq , -i*(sizeof(double)) , SEEK_END);
            fread(&retorno, sizeof(double), 1 , arq);
            printf("%g\n" , retorno);
        }
    }  

    fclose(arq);
    return 0;
}