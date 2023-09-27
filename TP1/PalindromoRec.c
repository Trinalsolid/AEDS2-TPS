#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ENTRADA 1000
#define TAM   1000

bool isFim(char *string){
    return (strlen(string) >= 3 && string[0] == 'F' && string[1] == 'I' && string[2] == 'M');
}

bool isPalindromo(char* original, int i, int j){
    bool resp = true;

    if(j >= i){
        if(original[i] != original[j]){
            resp = false;
        }
        else{
            resp = isPalindromo(original, i+1, j-1);
        }
    }

    return resp;
}

int main(){
    
    char linha[ENTRADA][TAM];
    int numEntrada = 0;

    do{
        fgets(linha[numEntrada], ENTRADA, stdin);
    }while(isFim(linha[numEntrada++]) == false);
    numEntrada--;
   
    for(int i = 0; i < numEntrada; i++ ){
        if(isPalindromo(linha[i], 0, (strlen(linha[i])-2)) == true){
            printf("SIM\n");
        }else{
            printf("NAO\n");
        }
    }

    return 0;
}