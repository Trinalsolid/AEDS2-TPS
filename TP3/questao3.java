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

    //MOSTRAR

    public void mostrar(){
        System.out.println(" ## "+ getNome()+" ## "+ getAltura()+" ## "+ getPeso()
            +" ## "+ getAnoNascimento()+" ## "+ getUniversidade()+" ## "+getCidadeNascimento()+
            " ## " +getEstadoNascimento()+" ## ");
    }
}

class Pilha {
    private Jogador[] array;
    private int n;


    /**
    * Construtor da classe.
    */
    public Pilha(){
        this(1000);
    }


    /**
    * Construtor da classe.
    * @param tamanho Tamanho da Pilha.
    */
    public Pilha (int tamanho){
        array = new Jogador[tamanho];
        n = 0;
    }


    /**
    * Insere um elemento na primeira posicao da Pilha e move os demais
    * elementos para o fim da Pilha.
    * @param x int elemento a ser inserido.
    * @throws Exception Se a Pilha estiver cheia.
    */
    public void inserirInicio(Jogador x) throws Exception {

        //validar insercao
        if(n >= array.length){
            throw new Exception("Erro ao inserir!");
        } 

        //levar elementos para o fim do array
        for(int i = n; i > 0; i--){
            array[i] = array[i-1];
        }

        array[0] = x;
        n++;
    }


    /**
    * Insere um elemento na ultima posicao da Pilha.
    * @param x int elemento a ser inserido.
    * @throws Exception Se a Pilha estiver cheia.
    */
    public void inserirFim(Jogador x) throws Exception {

        //validar insercao
        if(n >= array.length){
            throw new Exception("Erro ao inserir!");
        }

        array[n] = x;
        n++;
    }


    /**
    * Insere um elemento em uma posicao especifica e move os demais
    * elementos para o fim da Pilha.
    * @param x int elemento a ser inserido.
    * @param pos Posicao de insercao.
    * @throws Exception Se a Pilha estiver cheia ou a posicao invalida.
    */
    public void inserir(Jogador x, int pos) throws Exception {

        //validar insercao
        if(n >= array.length || pos < 0 || pos > n){
            throw new Exception("Erro ao inserir!");
        }

        //levar elementos para o fim do array
        for(int i = n; i > pos; i--){
            array[i] = array[i-1];
        }

        array[pos] = x;
        n++;
    }


    /**
    * Remove um elemento da primeira posicao da Pilha e movimenta 
    * os demais elementos para o inicio da mesma.
    * @return resp int elemento a ser removido.
    * @throws Exception Se a Pilha estiver vazia.
    */
    public Jogador removerInicio() throws Exception {

        //validar remocao
        if (n == 0) {
            throw new Exception("Erro ao remover!");
        }

        Jogador resp = array[0];
        n--;

        for(int i = 0; i < n; i++){
            array[i] = array[i+1];
        }

        return resp;
    }


    /**
    * Remove um elemento da ultima posicao da Pilha.
    * @return resp int elemento a ser removido.
    * @throws Exception Se a Pilha estiver vazia.
    */
    public Jogador removerFim() throws Exception {

        //validar remocao
        if (n == 0) {
            throw new Exception("Erro ao remover!");
        }

        return array[--n];
    }


    /**
    * Remove um elemento de uma posicao especifica da Pilha e 
    * movimenta os demais elementos para o inicio da mesma.
    * @param pos Posicao de remocao.
    * @return resp int elemento a ser removido.
    * @throws Exception Se a Pilha estiver vazia ou a posicao for invalida.
    */
    public Jogador remover(int pos) throws Exception {

        //validar remocao
        if (n == 0 || pos < 0 || pos >= n) {
            throw new Exception("Erro ao remover!");
        }

        Jogador resp = array[pos];
        n--;

        for(int i = pos; i < n; i++){
            array[i] = array[i+1];
        }

        return resp;
    }


    /**
    * Mostra os elementos da Pilha separados por espacos.
    */
    public void mostrar (){
        for(int i = 0; i < n; i++){
            System.out.print("["+ i +"]");
            array[i].mostrar();           
        }  
    }

}

public class questao3{
    public static Pilha pilha = new Pilha();
    public static Jogador jogad = new Jogador();
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
        jogad.setId(id);
        // Nome do jogador
        jogad.setNome(jogadores[1]);
        // Altura do jogador
        int altura = Integer.parseInt(jogadores[2]);
        jogad.setAltura(altura);
        // Peso do jogador
        int peso = Integer.parseInt(jogadores[3]);
        jogad.setPeso(peso);
        // Universidade do jogador
        jogad.setUniversidade(jogadores[4]);
        // Ano de nascimento do jogador
        int anoNascimento = Integer.parseInt(jogadores[5]);
        jogad.setAnoNascimento(anoNascimento);
        // Cidade do  jogador
        jogad.setCidadeNascimento(jogadores[6]);
        // Estado do jogador
        jogad.setEstadoNascimento(jogadores[7]);
    }

    public static void OpCode(BufferedReader ids)throws Exception{
        int cont = 0;
        String entrada = "";
        String opcode = ids.readLine();

        while(cont < Integer.parseInt(opcode)){
            entrada = ids.readLine();

            String[] caso = entrada.split(" ");
            // INSERCOES NA PILHA
            if(caso[0].charAt(0)=='I'){
                // Insere fim OU empilha 
                jogad = new Jogador();
                TratarString(ler(caso[1]));

                pilha.inserirFim(jogad);
            }
            // REMOCEOS NA PILHA
            if(caso[0].charAt(0)=='R'){
                // Remove fim OU desempilha
                Jogador tmp = pilha.removerFim();
                System.out.println("(R) "+ tmp.getNome());
            }
            cont++;
        }
    }

    public static void main(String[] args) throws Exception {
        
        // PRIMEIRA PARTE DA LEITURA

        String IdsJogadores = "";
        BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
        IdsJogadores = entrada.readLine();

        while(IdsJogadores.equals("FIM") != true){
            jogad = new Jogador();
            TratarString(ler(IdsJogadores));
            pilha.inserirFim(jogad);
            
            IdsJogadores = entrada.readLine();
        }

        // SEGUNDA PARTE DA LEITURA
        OpCode(entrada);
        pilha.mostrar();
    }
}
