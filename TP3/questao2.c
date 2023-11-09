#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h> 

// CAMINHO GLOBAL PARA OS DOIS METODOS DE LEITURA
const char CAMINHO[] = "/tmp/players.csv";
// C:\\Users\\WazX\\Desktop\\aeds2-master\\tps\\entrada e saida\\players.csv  /tmp/players.csv 

#define MAXTAM 1000
#define bool short
#define true 1
#define false 0

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

typedef struct Lista{

    Jogador array[MAXTAM];  

}Lista;

//--------- chamada dos metodos do Jogador --------------
void LerJogador(char entradaID[]);
void LerJogadorLista(char entradaID[]);
void TratarString(char entrada[]);
void TratarStringLista(char entrada[]);
char* replace(char * s);
Jogador JogadorClone(Jogador *jogador);
void Mostrar();
//--------- chamada dos metodos da Lista ----------------
void inserirInicio(Jogador x); 
void inserirFim(Jogador x);
void inserir(Jogador x, char posicao[]);
Jogador removerInicio();
Jogador removerFim();
Jogador remover(char posicao[]);
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

Jogador jogador;
Lista lista;
int contadorjog = 0;

int main(){
    
    // PRIMEIRA PARTE DA LEITURA 

    char Ids[1000];
    scanf("%s",Ids);

    while(strcmp(Ids,"FIM") != 0 ){      
        LerJogador(Ids);
        contadorjog++;
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

    Mostrar();
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
        if (entrada[1] == 'I'){
            // Insere Inicio
            caso = strtok(entrada ," ");
            jogadornalista = strtok(NULL ," ");
            LerJogadorLista(jogadornalista);
            inserirInicio(jogador);
        }else if (entrada[1] == 'F'){
            // Insere Fim
            caso = strtok(entrada , " ");
            jogadornalista = strtok(NULL , " ");
            LerJogadorLista(jogadornalista);
            inserirFim(jogador);

        }else{
            // Insere Posicao
            caso = strtok(entrada , " ");
            posicao = strtok(NULL , " ");
            jogadornalista = strtok(NULL , " ");

            LerJogadorLista(jogadornalista);
            inserir(jogador , posicao);
        }
    }
    // REMOCOES
    if (entrada[0] == 'R'){
        if (entrada[1] == 'I'){
            // Remove Inicio
            jogador = removerInicio();
            printf("%s %s\n", "(R)", jogador.nome);

        }else if (entrada[1] == 'F'){
            // Remove Fim
            jogador = removerFim();
            printf("%s %s\n", "(R)", jogador.nome);

        }else{
            // Remove Posicao
            caso = strtok(entrada , " ");
            posicao = strtok(NULL , " ");
            jogador = remover(posicao);
            printf("%s %s\n", "(R)", jogador.nome);
        }
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

void LerJogadorLista(char entradaID[]){

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
            TratarStringLista(entradas);
        }  
    }while(!feof(caminho) && strcmp(virgula,entradaID) != 0);
    fclose(caminho);

}

void TratarString(char entrada[]){
    //ID
    strcpy(entrada, strtok(entrada, ",")); 
    lista.array[contadorjog].id = atoi(entrada);    
    //Nome
    strcpy(entrada, strtok(NULL, ","));
    strcpy(lista.array[contadorjog].nome ,entrada);
    //ALTURA
    strcpy(entrada, strtok(NULL, ","));
    lista.array[contadorjog].altura = atoi(entrada);  
    //PESO
    strcpy(entrada, strtok(NULL, ","));
    lista.array[contadorjog].peso = atoi(entrada); 
    //UNIVERSIDADE
    strcpy(entrada, strtok(NULL, ","));
    strcpy(lista.array[contadorjog].universidade, entrada); 
    //ANO DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    lista.array[contadorjog].anoNascimento = atoi(entrada); 
    //CIDADE DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    strcpy(lista.array[contadorjog].cidadeNascimento, entrada);
    //ESTADO DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    strcpy(lista.array[contadorjog].estadoNascimento, entrada);
}

void TratarStringLista(char entrada[]){
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

void Mostrar(){
    for (int i = 0; i < contadorjog; i++){
        printf("%s%d%s", "[", i, "]");
        //printf("%s"," ## ");
        //printf("%d", listajog.array[i].id);
        printf("%s"," ## ");
        printf("%s", lista.array[i].nome);
        printf("%s"," ## ");
        printf("%d", lista.array[i].altura);
        printf("%s"," ## ");
        printf("%d", lista.array[i].peso);
        printf("%s"," ## ");
        printf("%d", lista.array[i].anoNascimento);
        printf("%s"," ## ");
        printf("%s", lista.array[i].universidade);
        printf("%s"," ## ");
        printf("%s", lista.array[i].cidadeNascimento);
        printf("%s"," ## ");
        printf("%s", lista.array[i].estadoNascimento);
        printf(" ##\n");   

    }
}

//=============================================================================================================
// METODOS LISTA SEQUENCIAL

/**
 * Insere um elemento na primeira posicao da lista e move os demais
 * elementos para o fim da 
 * @param x int elemento a ser inserido.
 */
void inserirInicio(Jogador x) {
    int i;

    //validar insercao
    if(contadorjog >= MAXTAM){
        printf("Erro ao inserir!");
        exit(1);
    } 

    //levar elementos para o fim do array
    for(i = contadorjog; i > 0; i--){
        lista.array[i] = lista.array[i-1];
    }

    lista.array[0] = x;
    contadorjog++;
}


/**
 * Insere um elemento na ultima posicao da 
 * @param x int elemento a ser inserido.
 */
void inserirFim(Jogador x) {

   //validar insercao
   if(contadorjog >= MAXTAM){
      printf("Erro ao inserir!");
      exit(1);
   }

   lista.array[contadorjog] = x;
   contadorjog++;
}


/**
 * Insere um elemento em uma posicao especifica e move os demais
 * elementos para o fim da 
 * @param x int elemento a ser inserido.
 * @param pos Posicao de insercao.
 */
void inserir(Jogador x, char posicao[]) {
    int i;
    int pos = atoi(posicao);

    //validar insercao
    if(contadorjog >= MAXTAM || pos < 0 || pos > contadorjog){
        printf("Erro ao inserir!");
        exit(1);
    }

    //levar elementos para o fim do array
    for(i = contadorjog; i > pos; i--){
        lista.array[i] = lista.array[i-1];
    }

    lista.array[pos] = x;
    contadorjog++;
}


/**
 * Remove um elemento da primeira posicao da lista e movimenta 
 * os demais elementos para o inicio da mesma.
 * @return resp int elemento a ser removido.
 */
Jogador removerInicio() {
    int i; 
    Jogador resp;

    //validar remocao
    if (contadorjog == 0) {
        printf("Erro ao remover!");
        exit(1);
    }

    resp = lista.array[0];
    contadorjog--;

    for(i = 0; i < contadorjog; i++){
        lista.array[i] = lista.array[i+1];
    }

    return resp;
}

/**
 * Remove um elemento da ultima posicao da 
 * @return resp int elemento a ser removido.
 */
Jogador removerFim(){

    //validar remocao
    if (contadorjog == 0) {
        printf("Erro ao remover!");
        exit(1);
    }

    return lista.array[--contadorjog];
}


/**
 * Remove um elemento de uma posicao especifica da lista e 
 * movimenta os demais elementos para o inicio da mesma.
 * @param pos Posicao de remocao.
 * @return resp int elemento a ser removido.
 */
Jogador remover(char posicao[]) {
    int i;
    int pos = atoi(posicao);
    Jogador resp;

    //validar remocao
    if (contadorjog == 0 || pos < 0 || pos >= contadorjog) {
        printf("Erro ao remover!");
        exit(1);
    }

    resp = lista.array[pos];
    contadorjog--;

    for(i = pos; i < contadorjog; i++){
        lista.array[i] = lista.array[i+1];
    }

    return resp;
}


