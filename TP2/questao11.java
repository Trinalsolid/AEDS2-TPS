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

public class questao11{
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

    // Desempate por nome

    public static void Desempate(int n){
        Jogador tmp;

        for(int i=0 ; i <n ; i++ ){
            for(int j=i+1 ; j <n ; j++ ){
                if(jogad[i].getAltura() == jogad[j].getAltura()){
                    if(jogad[i].getNome().compareTo(jogad[j].getNome())>0){
                        tmp = jogad[i];
                        jogad[i] = jogad[j];
                        jogad[j] = tmp;
                    }
                }else{
                    j = n;
                }
            }
        }
    }

    public static void CountSort() {
        //Array para contar o numero de ocorrencias de cada elemento
        int[] count = new int[getMaior(jogad,tamJog) + 1];
        Jogador[] ordenado = new Jogador[tamJog];
  
        //Inicializar cada posicao do array de contagem 
        for (int i = 0; i < count.length; count[i] = 0, i++);
  
        //Agora, o count[i] contem o numero de elemento iguais a i
        for (int i = 0; i < tamJog; count[jogad[i].getAltura()]++, i++);
  
        //Agora, o count[i] contem o numero de elemento menores ou iguais a i
        for(int i = 1; i < count.length; count[i] += count[i-1], i++);
  
        //Ordenando
        for(int i = tamJog-1; i >= 0; ordenado[count[jogad[i].getAltura()]-1] = jogad[i], count[jogad[i].getAltura()]--, i--);
  
        //Copiando para o array original
        for(int i = 0; i < tamJog; jogad[i] = ordenado[i], i++);
    }
  
    /**
    * Retorna o maior elemento do array.
    * @return maior elemento
    */
    public static int getMaior(Jogador temp[] , int n) {
        int maior = temp[0].getAltura();
        String nome = temp[0].getNome();
        for (int i = 0; i < n; i++) {
            if(maior < temp[i].getAltura()){
                maior = temp[i].getAltura();
            }
        }
        return maior;	
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
        CountSort();
        Desempate(tamJog);
        mostrar();

        //arquivo de Matricula countingsort
        long tempoFinal = System.currentTimeMillis();
        Arq.openWrite("matrícula_countingsort.txt");
        Arq.println("695161" + "\t" + (tempoFinal - tempoInicial) + "\t" );
        Arq.close();
    }
}
