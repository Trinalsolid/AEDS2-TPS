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

// REGISTRO LISTA DRUPLA FLEX

typedef struct CelulaDupla{
    Jogador elemento;         // Elemento inserido na celula.
    struct CelulaDupla *prox; // Aponta a celula prox.
    struct CelulaDupla *ant;  // Aponta a celula anterior.
} CelulaDupla;

CelulaDupla *novaCelulaDupla(Jogador elemento){
    CelulaDupla *nova = (CelulaDupla *)malloc(sizeof(CelulaDupla));
    nova->elemento = elemento;
    nova->ant = nova->prox = NULL;
    return nova;
}



CelulaDupla *primeiro;
CelulaDupla *ultimo;

//--------- chamada dos metodos do Jogador --------------
void LerJogador(char entradaID[]);
void LerJogadorLista(char entradaID[]);
void TratarString(char entrada[]);
void TratarStringLista(char entrada[]);
char* replace(char * s);
Jogador JogadorClone(Jogador *jogador);
void Mostrar(Jogador jog);
//--------- chamada dos metodos da Lista Flex ----------------
void start();
void inserirInicio(Jogador x);
void inserirFim(Jogador x);
void inserir(Jogador x, int pos);
Jogador removerInicio();
Jogador removerFim();
Jogador remover(int pos);
void mostrarlista();
int tamanholista();
void quicksortRec(int esq, int dir);
void sort();
void swap(int i, int j);
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
Jogador array[1000];
int contjog = 0;

int main(){
    
    // PRIMEIRA PARTE DA LEITURA 

    char Ids[1000];
    scanf("%s",Ids);

    while(strcmp(Ids,"FIM") != 0 ){      
        LerJogador(Ids);
        contjog++;
        scanf("%s",Ids);
    }
    
    sort();
    start();

    for (int i = 0; i < contjog; i++){
        inserirFim(array[i]);
    }
    
    mostrarlista();
    
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
    array[contjog].id = atoi(entrada);    
    //Nome
    strcpy(entrada, strtok(NULL, ","));
    strcpy(array[contjog].nome ,entrada);
    //ALTURA
    strcpy(entrada, strtok(NULL, ","));
    array[contjog].altura = atoi(entrada);  
    //PESO
    strcpy(entrada, strtok(NULL, ","));
    array[contjog].peso = atoi(entrada); 
    //UNIVERSIDADE
    strcpy(entrada, strtok(NULL, ","));
    strcpy(array[contjog].universidade, entrada); 
    //ANO DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    array[contjog].anoNascimento = atoi(entrada); 
    //CIDADE DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    strcpy(array[contjog].cidadeNascimento, entrada);
    //ESTADO DE NASCIMENTO
    strcpy(entrada, strtok(NULL, ","));
    strcpy(array[contjog].estadoNascimento, entrada);
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

void Mostrar(Jogador jog){
    printf("%s", "[");
    printf("%d", jog.id);
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
    printf("%s", "]\n");
}

//=============================================================================================================
// METODOS LISTA FLEXIVEL

void start(){
    primeiro = novaCelulaDupla(array[0]);
    ultimo = primeiro;
} 

void inserirInicio(Jogador x){
    CelulaDupla *tmp = novaCelulaDupla(x);

    tmp->ant = primeiro;
    tmp->prox = primeiro->prox;
    primeiro->prox = tmp;
    if (primeiro == ultimo){
        ultimo = tmp;
    }else{
        tmp->prox->ant = tmp;
    }
    tmp = NULL;
}

void inserirFim(Jogador x){
    ultimo->prox = novaCelulaDupla(x);
    ultimo->prox->ant = ultimo;
    ultimo = ultimo->prox;

}
void inserir(Jogador x, int pos){
    int tam = tamanholista();

    if (pos < 0 || pos > tam){
        printf("Erro ao remover (posicao %d/%d invalida!", pos, tam);
    }else if (pos == 0){
        inserirInicio(x);
    }else if (pos == tam){
        inserirFim(x);
    }else{
        // Caminhar ate a posicao anterior a insercao
        CelulaDupla *i = primeiro;
        int j;
        for (j = 0; j < pos; j++, i = i->prox);

        CelulaDupla *tmp = novaCelulaDupla(x);
        tmp->ant = i;
        tmp->prox = i->prox;
        tmp->ant->prox = tmp->prox->ant = tmp;
        tmp = i = NULL;
    }
}

Jogador removerInicio(){
    if (primeiro == ultimo){
        printf("Erro ao remover (vazia)!");
    } 
    CelulaDupla *tmp = primeiro;
    primeiro = primeiro->prox;
    Jogador resp = primeiro->elemento;
    tmp->prox = primeiro->ant = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

Jogador removerFim(){
    if (primeiro == ultimo){
        printf("Erro ao remover (vazia)!");
    }
    Jogador resp = ultimo->elemento;
    ultimo = ultimo->ant;
    ultimo->prox->ant = NULL;
    free(ultimo->prox);
    ultimo->prox = NULL;
    return resp;
}

Jogador remover(int pos){
    Jogador resp;
    int tam = tamanholista();

    if (primeiro == ultimo){
        printf("Erro ao remover");
    }else if (pos < 0 || pos >= tam){
        printf("Erro ao remover posicao %d/%d invalida", pos, tam);
    }else if (pos == 0){
        resp = removerInicio();
    }else if (pos == tam - 1){
        resp = removerFim();
    }else{   
        CelulaDupla *i = primeiro->prox;
        int j;
        for (j = 0; j < pos; j++, i = i->prox);
        i->ant->prox = i->prox;
        i->prox->ant = i->ant;
        resp = i->elemento;
        i->prox = i->ant = NULL;
        free(i);
        i = NULL;
    }

    return resp;
}

void mostrarlista(){
    CelulaDupla *i;
    for (i = primeiro->prox; i != NULL; i = i->prox){
        Mostrar(i->elemento);
    }
}

int tamanholista(){
    int tamanho = 0;
    CelulaDupla *i;
    for (i = primeiro; i != ultimo; i = i->prox, tamanho++);
    return tamanho;
}

void quicksortRec(int esq, int dir){
    int i = esq, j = dir;
    Jogador pivo = array[(dir + esq) / 2];
    Jogador temp;
    while (i <= j){
        while (strcmp(array[i].estadoNascimento, pivo.estadoNascimento) < 0 || strcmp(array[i].estadoNascimento, pivo.estadoNascimento) == 0 && strcmp(array[i].nome, pivo.nome) < 0)
            i++;
        while (strcmp(array[j].estadoNascimento, pivo.estadoNascimento) > 0 || strcmp(array[j].estadoNascimento, pivo.estadoNascimento) == 0 && strcmp(array[j].nome, pivo.nome) > 0)
            j--;
        if (i <= j){
            swap(j , i);
            i++;
            j--;
        }
    }
    if (esq < j){
        quicksortRec(esq, j);
    }
    if (i < dir){
        quicksortRec(i, dir);
    }
}

void sort(){
    quicksortRec(0, contjog-1);
}

void swap(int i, int j){
    Jogador temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
