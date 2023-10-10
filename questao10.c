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
void quicksortRec(int esq, int dir);
void sort();
void Quick();
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
    clock_t t; 
    t = clock();
    
    char Ids[1000];
    scanf("%s",Ids);

    while(strcmp(Ids,"FIM") != 0 ){             
        LerJogador(Ids);
        contadorjog++;
        scanf("%s",Ids);
    }
    sort();
    Quick();
    Mostrar();

    // arquivo de matricula========================================================
    t = clock() - t; 

    FILE *arq;
    arq = fopen("matrícula_quicksort.txt", "a");
    fprintf(arq, "695161 \t %ld \t %d ", t , comp);
    fclose(arq);
    //=============================================================================
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

// Quicksort

//=============================================================================
void quicksortRec(int esq, int dir){
    int i = esq, j = dir;
    Jogador pivo = lista[(dir + esq) / 2];
    while (i <= j){
        while (strcmp(lista[i].estadoNascimento, pivo.estadoNascimento) < 0){
            i++;
        }
        while (strcmp(lista[j].estadoNascimento, pivo.estadoNascimento) > 0){
            j--;
        }
        if (i <= j){
            swap(i , j);
            i++;
            j--;
        }
    }
    if (esq < j){
        comp++; 
        quicksortRec(esq, j);
    }
    if (i < dir){
        comp++;
        quicksortRec(i, dir);
    } 
}

void sort(){
   quicksortRec(0, contadorjog - 1);
}

void Quick(){
    Jogador temp;
    for (int i = 0; i < contadorjog; i++){
        if (strcmp(lista[i].estadoNascimento, lista[i + 1].estadoNascimento) == 0){
            for (int j = i + 1; j < contadorjog; j++){
                if (strcmp(lista[i].estadoNascimento, lista[j].estadoNascimento) == 0){
                    if (strcmp(lista[i].nome, lista[j].nome) > 0){
                        temp = lista[i];
                        lista[i] = lista[j];
                        lista[j] = temp;
                    }
                }else{
                    j = contadorjog;
                }
            }
        }
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
    FILE *caminho = fopen("/tmp/players.csv","r");
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

    for (int i = 0; i < contadorjog; i++){
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
