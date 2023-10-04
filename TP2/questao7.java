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

public class questao7{
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

    public static void Selecao(){
        for(int i=0 ; i < (tamJog-1) ;i++){
            int pos = i;
            Jogador temp = jogad[i];
            String menorjog = temp.getNome();

            for(int j = (i+1) ; j < tamJog; j++){
                if(jogad[pos].getNome().compareTo(jogad[j].getNome()) > 0){
                    menorjog = jogad[j].getNome();
                    pos = j;
                }
            }
            jogad[i] = jogad[pos];
            jogad[pos] = temp;
        }
    }

    public static int Insercao(){
        int contOpe = 0;
        for(int i = 1; i < tamJog ; i++){
            Jogador temp = jogad[i];
            int j = i-1;

            while((j >= 0) && (jogad[j].getNome().compareTo(temp.getNome()) > 0) ){
                jogad[j+1]=jogad[j];
                j--;
            }
            jogad[j+1] = temp;
            contOpe++;
        }
        for(int i = 1; i < tamJog; i++){
            Jogador temp = jogad[i];
            int j = i-1;

            while((j >= 0) && (jogad[j].getAnoNascimento() > temp.getAnoNascimento())){
                jogad[j+1]=jogad[j];
                j--;
            }
            jogad[j+1] = temp;
            contOpe++;
        }
        return contOpe;
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
        int operacoes = Insercao();
        mostrar();

        //arquivo de Matricula sequencial 
        long tempoFinal = System.currentTimeMillis();
        Arq.openWrite("matrícula_sequencial.txt");
        Arq.println("695161" + "\t" + (tempoFinal - tempoInicial) + "\t" + operacoes);
        Arq.close();
    }
}
