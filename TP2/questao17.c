#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h> 

typedef struct Jogador{

    int id;
    char nome[100];
    int altura;
    int peso;
    char universidade[100];
    int anoNascimento;
    char cidadeNascimento[100];
    char estadoNascimento[100];

}Jogador;

//--------- chamada dos metodos --------------
void LerJogador(char entradaID[]);
char* replace(char * s);
void TratarString(char entrada[]);
void construir(Jogador *array, int tamHeap);
int getMaiorFilho(Jogador *array, int i, int tamHeap);
void reconstruir(Jogador *array, int tamHeap);
void heapsortParcial(Jogador *array, int n);
void swap(int i, int j);
void Mostrar();
//-----------------------
void id(char id[]);
void Nome(char nome[]);
void Altura(char altura[]);
void Peso(char peso[]);
void Universidade(char universidade[]);
void AnoNascimento(char anoNascimento[]);
void CidadeNascimento(char cidadeNascimento[]);
void EstadoNascimento(char estadoNascimento[]);

// main

Jogador lista[1000];
int contadorjog = 0;
int comp = 0;

int main(){
    
    char Ids[1000];
    scanf("%s",Ids);

    while(strcmp(Ids,"FIM") != 0 ){             
        LerJogador(Ids);
        contadorjog++;
        scanf("%s",Ids);
    }
    heapsortParcial(lista,contadorjog);
    Mostrar();
    return 0;
}

// """SETS""" 

void id(char id[]){
    lista[contadorjog].id = atoi(id);
}
void Nome(char nome[]){
    strcpy(lista[contadorjog].nome,nome);
}
void Altura(char altura[]){
    lista[contadorjog].altura = atoi(altura);
}
void Peso(char peso[]){
    lista[contadorjog].peso = atoi(peso);
}
void AnoNascimento(char anoNascimento[]){
    lista[contadorjog].anoNascimento = atoi(anoNascimento);
}
void Universidade(char universidade[]){
    strcpy(lista[contadorjog].universidade,universidade);
}
void CidadeNascimento(char cidadeNascimento[]){
    strcpy(lista[contadorjog].cidadeNascimento,cidadeNascimento);
}
void EstadoNascimento(char estadoNascimento[]){
    strcpy(lista[contadorjog].estadoNascimento,estadoNascimento);
}

// Heapsort parcial
//=============================================================================

void construir(Jogador *array, int tamHeap){
    for(int i = tamHeap; i > 1 && array[i].altura > array[i/2].altura; i /= 2){
        swap(array + i, array + i/2);
    }
}

int getMaiorFilho(Jogador *array, int i, int tamHeap){
    int filho;
    if (2*i == tamHeap || array[2*i].altura > array[2*i+1].altura){
        filho = 2*i;
    } else {
        filho = 2*i + 1;
    }
    return filho;
}

void reconstruir(Jogador *array, int tamHeap){
    int i = 1;
    while(i <= (tamHeap/2)){
        int filho = getMaiorFilho(array, i, tamHeap);
        if(array[i].altura < array[filho].altura){
            swap(array + i, array + filho);
            i = filho;
        }else{
            i = tamHeap;
        }
    }
}

void heapsortParcial(Jogador *array, int n) {
    int k = 10;
    //Alterar o vetor ignorando a posicao zero
    Jogador arrayTmp[n+1];
    for(int i = 0; i < n; i++){
        arrayTmp[i+1].altura = array[i].altura;
    }

    //Contrucao do heap
    for(int tamHeap = 2; tamHeap <= n; tamHeap++){
        construir(arrayTmp, tamHeap);
    }

    for (int i = k + 1; i <= n; i++){
        if (array[i].altura < array[1].altura){
            swap(i , 1); 
            reconstruir(array , k);
        }
    }

    //Ordenacao propriamente dita
    int tamHeap = k;
    while(tamHeap > 1){
        swap(arrayTmp + 1, arrayTmp + tamHeap--);
        reconstruir(arrayTmp, tamHeap);
    }

    //Alterar o vetor para voltar a posicao zero
    for(int i = 0; i < n; i++){
        array[i] = arrayTmp[i+1];
    }
}

void swap(int i, int j){
   Jogador tmp = lista[i];
   lista[i] = lista[j];
   lista[j] = tmp;
}

//=============================================================================

// LEITURA

void LerJogador(char entradaID[]){

    char entradas[1000];
    char *stringsep;
    char *virgula;
    FILE *caminho = fopen("C:\\Users\\WazX\\Desktop\\aeds2-master\\tps\\entrada e saida\\players.csv","r");
    // C:\\Users\\WazX\\Desktop\\aeds2-master\\tps\\entrada e saida\\players.csv && /tmp/players.csv

    do{
        fgets(entradas,1000,caminho);
        strcpy(entradas , replace(entradas));
        stringsep = strdup(entradas);
        virgula = strtok(stringsep,",");
        if (strcmp(virgula,entradaID) == 0 ){
            TratarString(entradas);
        }  
    }while(!feof(caminho) && strcmp(virgula,entradaID) != 0);
    fclose(caminho);

}

void TratarString(char entrada[]){

    //ID
    strcpy(entrada, strtok(entrada, ",")); 
    id(entrada);    
    //Nome
    strcpy(entrada, strtok(NULL, ","));
    Nome(entrada);
    //ALTURA
    strcpy(entrada, strtok(NULL, ","));
    Altura(entrada);  
    //PESO
    strcpy(entrada, strtok(NULL, ","));
    Peso(entrada);
    //UNIVERSIDADE
    strcpy(entrada, strtok(NULL, ","));
    Universidade(entrada);   
    //ANO DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    AnoNascimento(entrada);
    //CIDADE DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    CidadeNascimento(entrada);
    //ESTADO DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    EstadoNascimento(entrada);
}

// separador de virgulas

char* replace(char s[]){

    char novaentrada[400]="";
    int cont = 0;
    int ult = strlen(s);

    for (int i = 0; i < ult-1; i++){
        if ( s[i] == ',' && s[i-1] == ','){
            strcat(novaentrada,"nao informado");
            cont = strlen(novaentrada);
        }
        novaentrada[cont] = s[i];
        cont++;
    }

    if(novaentrada[strlen(novaentrada)-1] == ','){
        strcat(novaentrada,"nao informado");
    }
    
    char *resp = novaentrada;
    return resp;
}

// CLONE

/*Jogador JogadorClone(const Jogador* const self){
    Jogador clone;

    clone.id = self->nome;
    clone.nome = self->nome;
    clone.altura = self->altura;
    clone.peso = self->peso;
    clone.universidade = self->universidade;
    clone.anoNascimento = self->anoNascimento;
    clone.cidadeNascimento = self->cidadeNascimento;
    clone.estadoNascimento = self->estadoNascimento;
}*/

// MOSTRAR

void Mostrar(){

    for (int i = 0; i < 10; i++){
        printf("[%d", lista[i].id);
        printf("%s"," ## ");
        printf("%s", lista[i].nome);
        printf("%s"," ## ");
        printf("%d", lista[i].altura);
        printf("%s"," ## ");
        printf("%d", lista[i].peso);
        printf("%s"," ## ");
        printf("%d", lista[i].anoNascimento);
        printf("%s"," ## ");
        printf("%s", lista[i].universidade);
        printf("%s"," ## ");
        printf("%s", lista[i].cidadeNascimento);
        printf("%s"," ## ");
        printf("%s", lista[i].estadoNascimento);
        printf("]\n");   

    }
}
