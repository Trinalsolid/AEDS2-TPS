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

// REGISTRO PILHA FLEXIVEL

typedef struct Celula {
	Jogador elemento;       // Elemento inserido na celula.
	struct Celula* prox;    // Aponta a celula prox.
}Celula;

Celula* novaCelula(Jogador elemento) {
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL;
   return nova;
}

Celula* topo; // Sem celula cabeca.

//--------- chamada dos metodos do Jogador ---------------
void LerJogador(char entradaID[]);
void TratarString(char entrada[]);
char* replace(char * s);
Jogador JogadorClone(Jogador *jogador);
void Mostrar();
//--------- chamada dos metodos da pilha flexivel---------
void inserir(Jogador x);
void remover();
void mostrar();
void mostrarpilharec(Celula* i , int pos ); 
//--------- chamada do opcode ----------------------------
void OpCode(char entrada[]);
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
int contadorjog = 0;

int main(){
    
    // PRIMEIRA PARTE DA LEITURA 
    start();
    char Ids[1000];
    scanf("%s",Ids);

    while(strcmp(Ids,"FIM") != 0 ){      
        LerJogador(Ids);
        inserir(jogador);
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

    mostrar();
    return 0;
}

// opcode

void OpCode(char entrada[]){
    char *caso;
    char *posicao;
    char *jogadornalista;

    //INSERCAOS
    if (entrada[0] == 'I'){
        // Insere fim
        caso = strtok(entrada ," ");
        jogadornalista = strtok(NULL ," ");
        LerJogador(jogadornalista);
        inserir(jogador);
    }
    // REMOCAOS
    if (entrada[0] == 'R'){
        remover();
    }
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
    strcpy(jogador.nome ,entrada);
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
// METODOS PILHA FLEXIVEL
/**
 * Cria uma fila sem elementos.
 */
void start () {
   topo = NULL;
}

/**
 * Insere elemento na pilha (politica FILO).
 * @param x int elemento a inserir.
 */
void inserir(Jogador x) {
   Celula* tmp = novaCelula(x);
   tmp->prox = topo;
   topo = tmp;
   tmp = NULL;
}

/**
 * Remove elemento da pilha (politica FILO).
 * @return Elemento removido.
 */
void remover() {
    
    if(topo == NULL) {
        printf("Erro ao remover!");
    }

   Jogador resp = topo->elemento;
   printf("%s %s\n", "(R)", topo->elemento.nome);
   Celula* tmp = topo;
   topo = topo->prox;
   tmp->prox = NULL;
   free(tmp);
   tmp = NULL;
}


/**
 * Mostra os elementos separados por espacos, comecando do topo.
 */
void mostrar() {
    mostrarpilharec(topo, 142);
}

void mostrarpilharec(Celula* i , int pos ){
    if (i != NULL){
        mostrarpilharec(i->prox , --pos);
        Mostrar(i->elemento , pos);
    }
    
}

