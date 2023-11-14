#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <math.h>
#include <time.h> 

// CAMINHO GLOBAL PARA OS DOIS METODOS DE LEITURA
const char CAMINHO[] = "/tmp/players.csv";
// C:\\Users\\WazX\\Desktop\\aeds2-master\\tps\\entrada e saida\\players.csv  /tmp/players.csv 

#define MAXTAM 5
#define bool short
#define true 1
#define false 0

int array[MAXTAM+1];   // Elementos da fila circular 
int primeiro;          // Remove do indice "primeiro".
int ultimo;            // Insere no indice "ultimo".
int quantFila = 0;     // quantidade de elementos na fila
int contjog = 0;       // contador dos jogadores
double soma = 0;       // soma dos elementos para inserçao na fila

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

// REGISTRO LISTA SEQUENCIAL

typedef struct Fila{
   Jogador array[MAXTAM + 1]; // Elementos da fila circular
}Fila;

//--------- chamada dos metodos do Jogador --------------
void LerJogador(char entradaID[]);
void LerJogadorLista(char entradaID[]);
void TratarString(char entrada[]);
void TratarStringLista(char entrada[]);
char* replace(char * s);
Jogador JogadorClone(Jogador *jogador);
void Mostrar();
//--------- chamada dos metodos da Fila ----------------
Fila remover(Fila fila);
Fila inserir( Jogador x , Fila fila);
void mostrarfila();
void imprimirRemover(Jogador x);
//--------- chamada do opcode ----------------------------
char OpCode(char entrada[]);
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

int contadorjog = 0;
Jogador jogador;
Fila fila;

int main(){
    
    // PRIMEIRA PARTE DA LEITURA 

    char Ids[1000];
    scanf("%s",Ids);

    while(strcmp(Ids,"FIM") != 0 ){      
        LerJogador(Ids);
        fila = inserir(jogador , fila);
        scanf("%s",Ids);
    }
    
    // SEGUNDA PARTE DA LEITURA 
    int quantidade = 0;
    int contador = 0;

    scanf("%d" , &quantidade);

    while (contador < quantidade){
        scanf(" %[^\n]s", Ids);
        OpCode(Ids);
        contador++;
    } 

    mostrarfila();
    return 0;
}

// opcode

char OpCode(char entrada[]){
    char resp = {' '};

    char *caso;
    char *posicao;
    char *jogadornalista;

    //INSERCOES
    if (entrada[0] == 'I'){
        caso = strtok(entrada ," ");
        jogadornalista = strtok(NULL ," ");
        LerJogador(jogadornalista);
        fila = inserir(jogador , fila);
    }
    // REMOCOES
    if (entrada[0] == 'R'){
        fila = remover(fila);
    }
    
    return resp;
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
    jogador.id = atoi(entrada);
    //Nome  
    strcpy(entrada, strtok(NULL, ","));
    strcpy(jogador.nome, entrada);
    //ALTURA
    strcpy(entrada, strtok(NULL, ","));
    jogador.altura = atoi(entrada);
    //PESO
    strcpy(entrada, strtok(NULL, ","));
    jogador.peso = atoi(entrada);
    //UNIVERSIDADE
    strcpy(entrada, strtok(NULL, ","));
    strcpy(jogador.universidade, entrada);
    //ANO DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    jogador.anoNascimento = atoi(entrada);
    //CIDADE DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    strcpy(jogador.cidadeNascimento, entrada);
    //ESTADO DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    strcpy(jogador.estadoNascimento, entrada);
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
   // printf("%s"," ## ");
    //printf("%d", jog.id);
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
// METODOS FILA CIRCULAR SEQUENCIAL

void start(){
   primeiro = ultimo = 0;
}

Fila inserir( Jogador x , Fila fila) {
    Jogador temp[MAXTAM];

    if (quantFila >= MAXTAM){
        temp[0] = fila.array[0];
        soma = soma - temp[0].altura;
        quantFila--;
        for (int i = 0; i < quantFila; i++)
        {
            fila.array[i] = fila.array[i + 1];
        }
    }
    fila.array[quantFila] = x;
    quantFila++;
    double media = 0;
    soma = soma + x.altura;
    media = soma / quantFila;
    round(media);
    printf("%.0f\n", media);
    return fila;
}


/**
 * Remove um elemento da primeira posicao da fila e movimenta 
 * os demais elementos para o primeiro da mesma.
 * @return resp int elemento a ser removido.
 * @Se a fila estiver vazia.
 */
Fila remover(Fila fila) {
    Jogador temp[MAXTAM];
    if (quantFila == 0){
        printf("Erro ao remover ( Fila vazia )!");
    }else{
        temp[0] = fila.array[0];
        soma = soma - temp[0].altura;
        imprimirRemover(temp[0]);
        quantFila--;
        for (int i = 0; i < quantFila; i++){
            fila.array[i] = fila.array[i + 1];
        }
    }
    return fila;
}

void mostrarfila(){
    for (int i = 0; i < quantFila; i++){
        Mostrar(fila.array[i], i);
    }
}

void imprimirRemover(Jogador x){
   printf("%s%s\n", "(R) ", x.nome);
}
