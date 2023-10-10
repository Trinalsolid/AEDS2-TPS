import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

class Jogador{

    public static Jogador[] jogad = new Jogador[1000];
    public static int tamJog = 0;

    private int id;
    private String nome;
    private int altura;
    private int peso;
    private String universidade;
    private int anoNascimento;
    private String cidadeNascimento;
    private String estadoNascimento;

    //CONSTRUTORES

    public Jogador(){
        this.id = 0;
        this.nome= "";
        this.altura= 0;
        this.peso= 0;
        this.universidade= "";
        this.anoNascimento= 0;
        this.cidadeNascimento= "";
        this.estadoNascimento= "";
    }

    public Jogador(  int id,String nome,int altura,int peso,
    String universidade,int anoNascimento,String cidadeNascimento,String estadoNascimento){

        this.id = id;
        this.nome= nome;
        this.altura= altura;
        this.peso= peso;
        this.universidade= universidade;
        this.anoNascimento= anoNascimento;
        this.cidadeNascimento= cidadeNascimento;
        this.estadoNascimento= estadoNascimento;
    }

    //GETS

    public int getId() {
        return id;
    }
    public String getNome() {
        return nome;
    }
    public int getAltura() {
        return altura;
    }public int getPeso() {
        return peso;
    }
    public String getUniversidade() {
        return universidade;
    }
    public int getAnoNascimento() {
        return anoNascimento;
    }
    public String getCidadeNascimento() {
        return cidadeNascimento;
    }
    public String getEstadoNascimento() {
        return estadoNascimento;
    }

    //SETS

    public void setId(int id) {
        this.id = id;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setAltura(int altura) {
        this.altura = altura;
    }
    public void setPeso(int peso) {
        this.peso = peso;
    }
    public void setUniversidade(String universidade) {
        this.universidade = universidade;
    }
    public void setAnoNascimento(int anoNascimento) {
        this.anoNascimento = anoNascimento;
    }
    public void setCidadeNascimento(String cidadeNascimento) {
        this.cidadeNascimento = cidadeNascimento;
    }
    public void setEstadoNascimento(String estadoNascimento) {
        this.estadoNascimento = estadoNascimento;
    }

    //CLONE

    public Jogador clone(){

        Jogador clone = new Jogador();

        clone.id = id;
        clone.nome = nome;
        clone.altura = altura;
        clone.peso = peso;
        clone.universidade = universidade;
        clone.anoNascimento = anoNascimento;
        clone.cidadeNascimento = cidadeNascimento;
        clone.estadoNascimento = estadoNascimento;

        return clone;
    }
}

public class questao13{
    public static Jogador[] jogad = new Jogador[1000];
    public static int tamJog = 0;
    
    //LER
    public static String ler(String entradaid) throws Exception {
        String entrada = "";
        BufferedReader arq = new BufferedReader(new InputStreamReader(new FileInputStream("/tmp/players.csv")));

        entrada = arq.readLine();
        while(entrada != null){
            String[] Ids = entrada.split(",");
            if(Ids[0].equals(entradaid) == true){
                return entrada;
            }
            entrada = arq.readLine();
        }
        String saida = "";

        return saida;
    }

    public static void TratarString(String entrada)throws Exception{
        int tam = entrada.length();
        if(entrada.charAt(tam-1) == ','){
            entrada = entrada + "nao informado";
        }
        entrada = entrada.replaceAll(",,", ",nao informado,");
        String[] jogadores = entrada.split(",");

        // ID do jogador
        int id = Integer.parseInt(jogadores[0]);
        jogad[tamJog].setId(id);
        // Nome do jogador
        jogad[tamJog].setNome(jogadores[1]);
        // Altura do jogador
        int altura = Integer.parseInt(jogadores[2]);
        jogad[tamJog].setAltura(altura);
        // Peso do jogador
        int peso = Integer.parseInt(jogadores[3]);
        jogad[tamJog].setPeso(peso);
        // Universidade do jogador
        jogad[tamJog].setUniversidade(jogadores[4]);
        // Ano de nascimento do jogador
        int anoNascimento = Integer.parseInt(jogadores[5]);
        jogad[tamJog].setAnoNascimento(anoNascimento);
        // Cidade do  jogador
        jogad[tamJog].setCidadeNascimento(jogadores[6]);
        // Estado do jogador
        jogad[tamJog].setEstadoNascimento(jogadores[7]);
    }

    //MOSTRAR

    public static void mostrar(){
        for(int i =0 ; i < tamJog ; i++){
            System.out.println("["+jogad[i].getId()+" ## "+jogad[i].getNome()+" ## "+jogad[i].getAltura()+" ## "+jogad[i].getPeso()
            +" ## "+ jogad[i].getAnoNascimento()+" ## "+ jogad[i].getUniversidade()+" ## "+jogad[i].getCidadeNascimento()+
            " ## " +jogad[i].getEstadoNascimento()+"]");
        }
    }

    // Desempate por universidade

    public static void Desempate(){
        Jogador tmp;

        for(int i=0 ; i <tamJog ; i++ ){
            for(int j=i+1 ; j <tamJog ; j++ ){
                if(jogad[i].getUniversidade().compareTo(jogad[j].getUniversidade()) == 0){
                    if(jogad[i].getNome().compareTo(jogad[j].getNome())>0){
                        tmp = jogad[i];
                        jogad[i] = jogad[j];
                        jogad[j] = tmp;
                    }
                }else{
                    j = tamJog;
                }
            }
        }
    }

    public static void sort() {
        mergesort(0, tamJog-1);
    }
  
    /**
    * Algoritmo de ordenacao Mergesort.
    * @param int esq inicio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
    */
    public static void mergesort(int esq, int dir) {
        if (jogad != null && esq < dir && dir >= 0 && esq < jogad.length && jogad.length != 0){
           int meio = (esq + dir) / 2;
           mergesort(esq, meio);
           mergesort(meio + 1, dir);
           intercalar(esq, meio, dir);
        }
    }
  
    /**
    * Algoritmo que intercala os elementos entre as posicoes esq e dir
    * @param int esq inicio do array a ser ordenado
    * @param int meio posicao do meio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
    */ 
    public static void intercalar(int esq, int meio, int dir){
        Jogador[] tmp = new Jogador[jogad.length];

        for(int i = esq ; i<= dir ; i++){
            tmp[i] = jogad[i];
        }
        
        int n1 = esq;
        int n2 = meio+1;
        int n3 = esq;

        while(n1 <= meio && n2 <= dir){
            if(tmp[n1].getUniversidade().compareTo(tmp[n2].getUniversidade()) <= 0){
                jogad[n3] = tmp[n1];
                n1++;
            }else{
                jogad[n3] = tmp[n2];
                n2++;
            }
            n3++;
        }

        while(n1 <= meio){
            jogad[n3] = tmp[n1];
            n1++;
            n3++;
        }

        while (n2 <= dir) {
            jogad[n3] = jogad[n2];
            n2++;
            n3++;
        }
    }


    public static void main(String[] args) throws Exception {

        //tempo inicial do código
        long tempoInicial = System.currentTimeMillis();
        //----------------------------------------------//
        
        String IdsJogadores = "";
        BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
        IdsJogadores = entrada.readLine();

        while(IdsJogadores.equals("FIM") != true){
            jogad[tamJog] = new Jogador();
            TratarString(ler(IdsJogadores));
            tamJog += 1;
            IdsJogadores = entrada.readLine();
        }
        sort(); 
        Desempate();
        mostrar();

        //arquivo de Matricula mergesort
        long tempoFinal = System.currentTimeMillis();
        Arq.openWrite("matrícula_mergesort.txt");
        Arq.println("695161" + "\t" + (tempoFinal - tempoInicial) + "\t");
        Arq.close();
    }
}
