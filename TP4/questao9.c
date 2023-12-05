#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>


#define bool   short
#define true   1
#define false  0

// CAMINHO GLOBAL PARA OS DOIS METODOS DE LEITURA
const char CAMINHO[] = "/tmp/players.csv";
// C:\\Users\\WazX\\Desktop\\aeds2-master\\tps\\entrada e saida\\players.csv  /tmp/players.csv

// REGISTRO JOGADOR

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

// REGISTRO HASH INDIRETA

// tamanho da tabela hash indireta
#define TAMANHO_TABELA 25

typedef struct Celula {
    Jogador* elemento;
    int tamanho;
}Celula;

typedef struct TabelaHash{
    Celula tabela[TAMANHO_TABELA];
}TabelaHash;

//--------- chamada dos metodos do Jogador ---------------
void LerJogador(char entradaID[]);
void TratarString(char entrada[]);
char* replace(char * s);
Jogador JogadorClone(Jogador *jogador);
void Mostrar();
//--------- chamada dos metodos da arvore AVL ------------
int hashIndireto(int altura);
void inicializarTabelaHash(TabelaHash* tabela);
void inserirNaTabela(TabelaHash* tabela, Jogador jogador);
bool buscarNaTabela(TabelaHash tabela, char nome[]);
void freehash(TabelaHash* tabela);
//--------------------------------------------------------
void id(char id[]);
void Nome(char nome[]);
void Altura(char altura[]);
void Peso(char peso[]);
void Universidade(char universidade[]);
void AnoNascimento(char anoNascimento[]);
void CidadeNascimento(char cidadeNascimento[]);
void EstadoNascimento(char estadoNascimento[]);

// main

Jogador array[1000];
int contadorjog = 0;

int main(){
    TabelaHash tabela;
    inicializarTabelaHash(&tabela);
    
    // PRIMEIRA PARTE DA LEITURA 
    char Ids[1000];
    scanf("%s",Ids);

    while(strcmp(Ids,"FIM") != 0 ){      
        LerJogador(Ids);
        contadorjog++;
        scanf("%s",Ids);
    }

    for (int i = 0; i < contadorjog; i++) {
        inserirNaTabela(&tabela, array[i]);
    }

    // Busca por jogadores na tabela hash
    char nomejog[100];
    scanf(" %[^\n]s", nomejog);

    while (strcmp(nomejog, "FIM") != 0) {
        printf("%s", nomejog);
        bool resp = buscarNaTabela(tabela, nomejog);
        if (resp == false) {
            printf(" NAO\n");
        } else {
            printf(" SIM\n");
        }

        scanf(" %[^\n]s", nomejog);
    }
    
    
    return 0;
}

// LEITURA

void LerJogador(char entradaID[]){

    char entradas[1000];
    char *stringsep;
    char *virgula;
    FILE *caminho = fopen(CAMINHO,"r");
    
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
    array[contadorjog].id = atoi(entrada);    
    //Nome
    strcpy(entrada, strtok(NULL, ","));
    strcpy(array[contadorjog].nome ,entrada);
    //ALTURA
    strcpy(entrada, strtok(NULL, ","));
    array[contadorjog].altura = atoi(entrada);  
    //PESO
    strcpy(entrada, strtok(NULL, ","));
    array[contadorjog].peso = atoi(entrada); 
    //UNIVERSIDADE
    strcpy(entrada, strtok(NULL, ","));
    strcpy(array[contadorjog].universidade, entrada); 
    //ANO DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    array[contadorjog].anoNascimento = atoi(entrada); 
    //CIDADE DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    strcpy(array[contadorjog].cidadeNascimento, entrada);
    //ESTADO DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    strcpy(array[contadorjog].estadoNascimento, entrada);
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

/*Jogador JogadorClone(Jogador *jogador){
    Jogador *clone = (Jogador *) malloc(sizeof(Jogador));

    clone -> id = jogador -> id;
    clone -> nome = (char *) calloc(100, sizeof(char));
    strcpy(clone -> nome , jogador -> nome);

    clone -> altura = jogador -> altura;
    clone -> peso = jogador -> peso;
    clone -> universidade = (char *) calloc(100, sizeof(char));
    strcpy(clone -> universidade , jogador -> universidade);

    clone -> anoNascimento = jogador -> anoNascimento;
    clone -> cidadeNascimento = (char *) calloc(100, sizeof(char));
    strcpy(clone -> cidadeNascimento , jogador -> cidadeNascimento);

    clone -> estadoNascimento = (char *) calloc(100, sizeof(char));
    strcpy(clone -> estadoNascimento , jogador -> estadoNascimento);
}*/

// MOSTRAR

void Mostrar(Jogador jog , int pos){
    printf("%s%d%s", "[", pos, "]");
    //printf("%s"," ## ");
    //printf("%d", listajog.array[i].id);
    printf("%s"," ## ");
    printf("%s", jog.nome);
    printf("%s"," ## ");
    printf("%d", jog.altura);
    printf("%s"," ## ");
    printf("%d", jog.peso);
    printf("%s"," ## ");
    printf("%d", jog.anoNascimento);
    printf("%s"," ## ");
    printf("%s", jog.universidade);
    printf("%s"," ## ");
    printf("%s", jog.cidadeNascimento);
    printf("%s"," ## ");
    printf("%s", jog.estadoNascimento);
    printf(" ##\n");   
}

//=============================================================================================================
// METODOS HASH INDIRETA

// Função de hash com altura do jogador
int hashIndireto(int altura) {
    return altura % TAMANHO_TABELA;
}

// Inicializa a tabela hash
void inicializarTabelaHash(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela->tabela[i].elemento = NULL;
        tabela->tabela[i].tamanho = 0;
    }
}

// Insere um jogador na tabela hash
void inserirNaTabela(TabelaHash* tabela, Jogador jogador) {
    int pos = hashIndireto(jogador.altura);
    
    // Verifica se o elemento da lista ja existe , se nao , cria um
    if (tabela->tabela[pos].elemento == NULL) {
        tabela->tabela[pos].elemento = (Jogador*)malloc(sizeof(Jogador));
    }else{
        // Realoca a lista de jogadores para incluir mais um
        tabela->tabela[pos].elemento = (Jogador*)realloc(tabela->tabela[pos].elemento,(tabela->tabela[pos].tamanho + 1) * sizeof(Jogador));
    }

    // Adiciona o jogador à lista
    tabela->tabela[pos].elemento[tabela->tabela[pos].tamanho] = jogador;
    tabela->tabela[pos].tamanho++;
}

// Busca por um jogador na tabela hash
bool buscarNaTabela(TabelaHash tabela, char nome[]) {
    bool resp = false;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        for (int j = 0; j < tabela.tabela[i].tamanho; j++) {
            if (strcmp(tabela.tabela[i].elemento[j].nome, nome) == 0) {
                resp = true; 
            }
        }
    }
    return resp; 
}

void freehash(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        free(tabela->tabela[i].elemento);
    }
}