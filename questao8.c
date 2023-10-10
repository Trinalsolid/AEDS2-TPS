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
void insercaoPorCor(int n, int cor, int h);
void shellsort(int n);
void sort();
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
int contador = 0;

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
    shellsort(contadorjog);
    sort();
    Mostrar();

    // arquivo de matricula========================================================
    t = clock() - t; 
    
    FILE *arq;
    arq = fopen("matrícula_shellsort.txt", "a");
    fprintf(arq, "695161 \t %ld \t %d", t , contador);
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

// Shell sort 

//=============================================================================
void insercaoPorCor(int n, int cor, int h){
    for (int i = (h + cor); i < n; i+=h) {
        Jogador tmp = lista[i];
        int j = i - h;
        while ((j >= 0) && ((lista[j].peso > tmp.peso || (lista[j].peso == tmp.peso && strcmp(lista[j].nome, tmp.nome)>0 )))) {
            lista[j + h] = lista[j];
            j-=h;
            contador++;
        }
        lista[j + h] = tmp;
    }
}

void shellsort(int n) {
    Jogador tmp; 
   
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(lista[i].altura == lista[j].altura){
                if( strcmp(lista[i].nome,lista[j].nome)>0){
                   tmp=lista[i];
                   lista[i]=lista[j];
                   lista[j]=tmp;
                }
            }else{
                j=n;     
            }
        }
    }
}

void sort(){
    int h = 1;
   
    do{
        h = (h * 3) + 1;
    }while (h < contadorjog);

    do{
        h /= 3;
        for (int cor = 0; cor < h; cor++){
            insercaoPorCor(contadorjog, cor, h);
            contador++;
        }
    } while (h != 1);
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
