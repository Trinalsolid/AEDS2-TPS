#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isfim(char *string){
    return ( string[0] == 'F' && string[1] == 'I' && string[2] == 'M');
}

bool palindromo(char *entrada ){
    bool resp = true;
    int tamanho = strlen(entrada)-1;

    for (int i = 0; i < tamanho/2; i++){
        if(entrada[i] != entrada[tamanho-i-1] ){
            resp = false;
            i = tamanho;
        }
    }
    return resp;
}

int main(){
    char entrada[1000];
    bool verifica;

    fgets(entrada , 1000 , stdin);

    while( !isfim(entrada) ){
        verifica = palindromo(entrada);
        if (verifica){
            printf("SIM\n");
        }else{
            printf("NAO\n");
        }
        fgets(entrada , 1000 , stdin );
    }

    return 0;
}