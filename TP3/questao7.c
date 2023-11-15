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

// REGISTRO FILA DUPLA FLEXIVEL

typedef struct Celula{
   Jogador elemento;    // Elemento inserido na celula.
   struct Celula *prox; // Aponta a celula prox.
   struct Celula *ant;  // Aponta a celula anterior.
} CelulaDupla;

CelulaDupla *novaCelula(Jogador elemento)
{
   CelulaDupla *nova = (CelulaDupla *)malloc(sizeof(CelulaDupla));
   nova->elemento = elemento;
   nova->ant = nova->prox = NULL;
   return nova;
}

//FILA PROPRIAMENTE DITA
CelulaDupla *primeiro;
CelulaDupla *ultimo;

//--------- chamada dos metodos do Jogador --------------
void LerJogador(char entradaID[]);
void TratarString(char entrada[]);
char* replace(char * s);
Jogador JogadorClone(Jogador *jogador);
void Mostrar();
bool isFim(char s[]);
//--------- chamada dos metodos da Fila circular ----------------
void start(Jogador x);
void inserir(Jogador x);
void remover();
void mostrarfila();
void imprimirRemover(Jogador x);
void mostrarRec();
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
int contadorJ =0;
Jogador jogador;
Jogador array[1000];

int main(){
    
    start(array[0]);
    int maior = 0 , contador = 0;

    char temp[100];
    char Ids[1000];

    fgets(Ids , 1000 , stdin);
    Ids[strlen(Ids)-1] ='\0';

    int numero = 0;

    while(isFim(Ids) != true){      
        strcpy(temp , Ids);
        LerJogador(temp);
        inserir(array[contadorjog]);
        contadorjog++;
        fgets(Ids , 1000 , stdin);
        Ids[strlen(Ids)-1] ='\0';
        contador++;
    }

    // SEGUNDA PARTE DA ENTRADA

    contador = 0;
    int contador2 = 0;
    char novaentrada[1000];
    int quantidade;
    scanf("%d\n",&quantidade);
    char aux[10] , id[10];

    for (int i = 0; i < quantidade + 1 ; i++){

        fgets(novaentrada , 1000 , stdin);
        novaentrada[strlen(novaentrada) - 1] ='\0';

        for (int j = 0; j < strlen(novaentrada); j++){
            // OPCODE 
            if (novaentrada[0] == 'I'){
                if (contador == 0){
                    if (novaentrada[j] != ' '){
                        aux[contador2] = novaentrada[j];
                        contador2++;
                    }else if(novaentrada[0] == 'I'){
                        contador++;
                        contador2 = 0 ;
                    }
                }else if(contador == 1){
                    id[contador2] = novaentrada[j];
                    contador2++;
                }
            }
            if (novaentrada[0] == 'R'){
                remover();
            }            
        }
        int temp2 = 0;
        temp2 = atoi(id);    
        LerJogador(id);
        memset(id, 0, sizeof(id));
        contador = 0, contador2 = 0;
        if (novaentrada[0] == 'I'){
            inserir(array[contadorjog]);
        }
    }
    mostrarfila();

    return 0;
}

// opcode

/*char OpCode(char entrada[]){
    char resp = {' '};

    char *caso;
    char *posicao;
    char *jogadornalista;

    //INSERCOES
    if (entrada[0] == 'I'){
        caso = strtok(entrada ," ");
        jogadornalista = strtok(NULL ," ");
        LerJogador(jogadornalista);
        inserir(array[cont]);
    }
    // REMOCOES
    if (entrada[0] == 'R'){
        remover();
    }
    
    return resp;

}*/

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
    strcpy(array[contadorjog].nome, entrada);
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

/**
 * Cria uma fila sem elementos (somente no cabeca).
 */
void start(Jogador x){
    primeiro = novaCelula(x);
    ultimo = primeiro;
}

/**
 * Insere elemento na fila (politica FIFO).
 * @param x int Elemento a inserir.
 */
void inserir(Jogador x){

    if (quantFila >= MAXTAM){
        CelulaDupla *tmp = primeiro;

        if (tmp->elemento.altura == 0){
            tmp = primeiro->prox;
            soma = soma - tmp->elemento.altura;
            quantFila--;
            primeiro = primeiro->prox->prox;
            tmp->prox = primeiro->ant = NULL;
        }else{
            soma = soma - tmp->elemento.altura;
            quantFila--;
            primeiro = primeiro->prox;
            tmp->prox = primeiro->ant = NULL;
        }
    }

    ultimo->prox = novaCelula(x);
    ultimo->prox->ant = ultimo;
    ultimo = ultimo->prox;

    quantFila++;
    double media = 0;
    soma = soma + x.altura;
    media = soma / quantFila;

    int temp2 = 0;
    temp2 = round(media);

    printf("%d\n", temp2);
}


/**
 * Remove elemento da fila (politica FIFO).
 * @return Elemento removido.
 */
void remover(){

    if (primeiro == ultimo){
        printf(" Erro ao remover ");
    }

    CelulaDupla *tmp = primeiro;
    soma = soma - tmp->elemento.altura;
    imprimirRemover(tmp->elemento);

    primeiro = primeiro->prox;
    tmp->prox = primeiro->ant = NULL;

    quantFila--;
    tmp = NULL;
}

/**
 * Mostra os elementos na fila
 */
void mostrarfila(){
    int j = 0;
    CelulaDupla *i;
    for (i = primeiro; i != NULL; i = i->prox){
        Mostrar(i->elemento, j);
        j++;
    } 
}

void imprimirRemover(Jogador x){
    printf("%s%s\n", "(R) ", x.nome);
}
void mostrarRec(){
    int j=0;
    CelulaDupla* i;
    for (i = primeiro; i != NULL; i = i->prox) {
        Mostrar(i->elemento,j);
        j++;
    }
}

bool isFim(char s[]){
	bool resp = false;
	if (strlen(s) >= 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M'){
		resp = true;
	}
	return resp;
}