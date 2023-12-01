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

// REGISTRO ARVORE AVL

typedef struct Node{ 
    Jogador elemento; 
    struct Node *esq; 
    struct Node *dir; 
    int fator; 
}Node; 

//--------- chamada dos metodos do Jogador ---------------
void LerJogador(char entradaID[]);
void TratarString(char entrada[]);
char* replace(char * s);
Jogador JogadorClone(Jogador *jogador);
void Mostrar();
//--------- chamada dos metodos da arvore AVL ------------
int fator(struct Node *N);
int max(int a, int b);
struct Node* newNode(Jogador elemento); 
struct Node *rotacaoDir(struct Node *y); 
struct Node *rotacaoEsq(struct Node *x);
int getBalance(struct Node *N);
struct Node* inserir(struct Node* node, Jogador elemento);
bool pesquisar(char *x , struct Node* root);
bool pesquisarRec(char *x, struct Node* root);
void preOrder(struct Node *root);
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
    struct Node *root = NULL; 
    
    // PRIMEIRA PARTE DA LEITURA 
    char Ids[1000];
    scanf("%s",Ids);

    while(strcmp(Ids,"FIM") != 0 ){      
        LerJogador(Ids);
        contadorjog++;
        scanf("%s",Ids);
    }

    for (int i = 0; i < contadorjog; i++){
        root = inserir(root , array[i]);
    }

    //printf("VALORES ORDENADOS A PARTIR DE AGORA\n");
    //preOrder(root);

    // SEGUNDA PARTE DA ENTRADA

    char nomejog[100];
    scanf(" %[^\n]s",nomejog);

    while(strcmp(nomejog,"FIM") != 0 ){
        printf("%s" , nomejog);
        int resp = pesquisar(nomejog , root);       
        if(resp == 0){
            printf(" NAO\n");
        }else{
            printf(" SIM\n"); 
        }
        
        scanf(" %[^\n]s",nomejog);
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
// METODOS ARVORE AVL 
  
// A utility function to get the fator of the tree 
int fator(struct Node *N) { 
    if (N == NULL){
        return 0; 
    } 
    return N->fator; 
} 
  
// A utility function to get maximum of two integers 
int max(int a, int b) { 
    return (a > b)? a : b; 
} 
  
/* Helper function that allocates a new node with the given elemento and 
NULL esq and dir pointers. */
struct Node* newNode(Jogador elemento) { 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    node->elemento = elemento; 
    node->esq  = NULL; 
    node->dir  = NULL; 
    node->fator = 1;  // new node is initially added at leaf 
    return(node); 
} 
  
// A utility function to dir rotate subtree rooted with y 
// See the diagram given above. 
struct Node *rotacaoDir(struct Node *y){ 
    struct Node *x = y->esq; 
    struct Node *T2 = x->dir; 
  
    // Perform rotation 
    x->dir = y; 
    y->esq = T2; 
  
    // Update heights 
    y->fator = max(fator(y->esq), fator(y->dir)) + 1; 
    x->fator = max(fator(x->esq), fator(x->dir)) + 1; 
  
    // Return new root 
    return x; 
} 
  
// A utility function to esq rotate subtree rooted with x 
// See the diagram given above. 
struct Node *rotacaoEsq(struct Node *x){ 
    struct Node *y = x->dir; 
    struct Node *T2 = y->esq; 
  
    // Perform rotation 
    y->esq = x; 
    x->dir = T2; 
  
    //  Update heights 
    x->fator = max(fator(x->esq), fator(x->dir)) + 1; 
    y->fator = max(fator(y->esq), fator(y->dir)) + 1; 
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of node N 
int getBalance(struct Node *N){ 
    if (N == NULL){
        return 0; 
    } 
    return fator(N->esq) - fator(N->dir); 
} 
  
// Recursive function to insert a elemento in the subtree rooted 
// with node and returns the new root of the subtree. 
struct Node* inserir(struct Node* node, Jogador elemento) { 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL){
        return(newNode(elemento)); 
    }else if (strcmp(elemento.nome, node->elemento.nome) < 0){
        node->esq = inserir(node->esq, elemento); 
    }else if (strcmp(elemento.nome, node->elemento.nome) > 0){
        node->dir = inserir(node->dir, elemento); 
    }else{// Equal elementos are not allowed in BST 
        return node; 
    } 
  
    /* 2. Update fator of this ancestor node */
    node->fator = 1 + max(fator(node->esq),fator(node->dir)); 
  
    /* 3. Get the balance factor of this ancestor 
    node to check whether this node became 
    unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // esq esq Case strcmp(elemento.nome, node->esq->elemento.nome) < 0
    if (balance > 1 && strcmp(elemento.nome, node->esq->elemento.nome) < 0){
        return rotacaoDir(node); 
    } 
  
    // dir dir Case strcmp(elemento.nome, node->dir->elemento.nome) > 0
    if (balance < -1 && strcmp(elemento.nome, node->dir->elemento.nome) > 0){
        return rotacaoEsq(node); 
    } 
  
    // esq dir Case strcmp(elemento.nome, node->esq->elemento.nome) > 0
    if (balance > 1 && strcmp(elemento.nome, node->esq->elemento.nome) > 0) { 
        node->esq =  rotacaoEsq(node->esq); 
        return rotacaoDir(node); 
    } 
  
    // dir esq Case strcmp(elemento.nome,  node->dir->elemento.nome) < 0
    if (balance < -1 && strcmp(elemento.nome,  node->dir->elemento.nome) < 0){ 
        node->dir = rotacaoDir(node->dir); 
        return rotacaoEsq(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
}

bool pesquisar(char *x, struct Node *root) {
    printf(" raiz");
    return pesquisarRec(x, root);
}

/**
 * Metodo privado recursivo para pesquisar elemento.
 * @param x Elemento que sera procurado.
 * @param i No em analise.
 * @return <code>true</code> se o elemento existir,
 * <code>false</code> em caso contrario.
 */
bool pesquisarRec(char *x, struct Node *root) {
    bool resp;
    if(root == NULL) {
        resp = false;
    } else if (strcmp(x , root->elemento.nome) == 0) {
        resp = true;
    } else if (strcmp(x , root->elemento.nome) < 0) {
        printf(" esq");
        resp = pesquisarRec(x, root->esq);
    } else {
        printf(" dir");
        resp = pesquisarRec(x, root->dir);
    }
    return resp;
}
  
// A utility function to print preorder traversal 
// of the tree. 
// The function also prints fator of every node 
void preOrder(struct Node *root){ 
    if(root != NULL){ 
        printf("%s\n", root->elemento.nome); 
        preOrder(root->esq); 
        preOrder(root->dir); 
    } 
} 