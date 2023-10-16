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

public class questao18{
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
        for(int i =0 ; i < 10 ; i++){
            System.out.println("["+jogad[i].getId()+" ## "+jogad[i].getNome()+" ## "+jogad[i].getAltura()+" ## "+jogad[i].getPeso()
            +" ## "+ jogad[i].getAnoNascimento()+" ## "+ jogad[i].getUniversidade()+" ## "+jogad[i].getCidadeNascimento()+
            " ## " +jogad[i].getEstadoNascimento()+"]");
        }
    }

    /**
    * Algoritmo de ordenacao Quicksort parcial .
    * @param int esq inicio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
    * @param int k quantidade a ser ordenada
    */
    public static void quicksortParcial(int esq, int dir , int k){
        int i = esq, j = dir;
        Jogador pivo = jogad[(dir+esq)/2];
        while (i <= j){
            while(jogad[i].getEstadoNascimento().compareTo(pivo.getEstadoNascimento()) < 0 || jogad[i].getEstadoNascimento().compareTo(pivo.getEstadoNascimento()) == 0
                && jogad[i].getNome().compareTo(pivo.getNome()) < 0){
                i++; 
            }
            while(jogad[j].getEstadoNascimento().compareTo(pivo.getEstadoNascimento()) > 0 || jogad[j].getEstadoNascimento().compareTo(pivo.getEstadoNascimento()) == 0
                && jogad[j].getNome().compareTo(pivo.getNome()) > 0){
                j--;
            }
            if (i <= j) {
                swap(i, j);
                i++;
                j--;
            }            
        }
        if (esq < j){
            quicksortParcial(esq, j , k);
        }  
        if (i < k && i < dir){
            quicksortParcial(i, dir , k);
        }
    }

    public static void swap(int i, int j) {
        Jogador temp = jogad[i];
        jogad[i] = jogad[j];
        jogad[j] = temp;
    }

    public static void main(String[] args) throws Exception {
        
        String IdsJogadores = "";
        BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
        IdsJogadores = entrada.readLine();

        while(IdsJogadores.equals("FIM") != true){
            jogad[tamJog] = new Jogador();
            TratarString(ler(IdsJogadores));
            tamJog += 1;
            IdsJogadores = entrada.readLine();
        }
        quicksortParcial(0, tamJog-1 , 10);
        mostrar();      
    }
}
