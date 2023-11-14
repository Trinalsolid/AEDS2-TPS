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

class Celula {
	public Jogador elemento; // Elemento inserido na celula.
	public Celula prox; // Aponta a celula prox.


	/**
	 * Construtor da classe.
	 */
	public Celula() {
		
	}

	/**
	 * Construtor da classe.
	 * @param elemento Jogador inserido na celula.
	 */
	public Celula(Jogador elemento) {
      this.elemento = elemento;
      this.prox = null;
	}
}

class Lista {
	private Celula primeiro;
	private Celula ultimo;


	/**
	 * Construtor da classe que cria uma lista sem elementos (somente no cabeca).
	 */
	public Lista() {
		primeiro = new Celula();
		ultimo = primeiro;
	}


	/**
	 * Insere um elemento na primeira posicao da lista.
    * @param x Jogador elemento a ser inserido.
	 */
	public void inserirInicio(Jogador x) {
		Celula tmp = new Celula(x);
      tmp.prox = primeiro.prox;
		primeiro.prox = tmp;
		if (primeiro == ultimo) {                 
			ultimo = tmp;
		}
      tmp = null;
	}


	/**
	 * Insere um elemento na ultima posicao da lista.
    * @param x Jogador elemento a ser inserido.
	 */
	public void inserirFim(Jogador x) {
		ultimo.prox = new Celula(x);
		ultimo = ultimo.prox;
	}


	/**
	 * Remove um elemento da primeira posicao da lista.
    * @return resp Jogador elemento a ser removido.
	 * @throws Exception Se a lista nao contiver elementos.
	 */
	public Jogador removerInicio() throws Exception {
		if (primeiro == ultimo) {
			throw new Exception("Erro ao remover (vazia)!");
		}

        Celula tmp = primeiro;
        primeiro = primeiro.prox;
        Jogador resp = primeiro.elemento;
        tmp.prox = null;
        tmp = null;
		return resp;
	}


	/**
	 * Remove um elemento da ultima posicao da lista.
    * @return resp Jogador elemento a ser removido.
	 * @throws Exception Se a lista nao contiver elementos.
	 */
	public Jogador removerFim() throws Exception {
		if (primeiro == ultimo) {
			throw new Exception("Erro ao remover (vazia)!");
		} 

		// Caminhar ate a penultima celula:
        Celula i;
        for(i = primeiro; i.prox != ultimo; i = i.prox);

        Jogador resp = ultimo.elemento; 
        ultimo = i; 
        i = ultimo.prox = null;
      
		return resp;
	}


	/**
    * Insere um elemento em uma posicao especifica considerando que o 
    * primeiro elemento valido esta na posicao 0.
    * @param x Jogador elemento a ser inserido.
	* @param pos int posicao da insercao.
	* @throws Exception Se <code>posicao</code> invalida.
	*/
    public void inserir(Jogador x, int pos) throws Exception {

        int tamanho = tamanho();

        if(pos < 0 || pos > tamanho){
            throw new Exception("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
        } else if (pos == 0){
            inserirInicio(x);
        } else if (pos == tamanho){
            inserirFim(x);
        } else {
            // Caminhar ate a posicao anterior a insercao
            Celula i = primeiro;
            for(int j = 0; j < pos; j++, i = i.prox);
            
            Celula tmp = new Celula(x);
            tmp.prox = i.prox;
            i.prox = tmp;
            tmp = i = null;
        }
    }


	/**
    * Remove um elemento de uma posicao especifica da lista
    * considerando que o primeiro elemento valido esta na posicao 0.
	* @param posicao Meio da remocao.
    * @return resp Jogador elemento a ser removido.
	* @throws Exception Se <code>posicao</code> invalida.
	*/
	public Jogador remover(int pos) throws Exception {
        Jogador resp;
        int tamanho = tamanho();

		if (primeiro == ultimo){
			throw new Exception("Erro ao remover (vazia)!");

        } else if(pos < 0 || pos >= tamanho){
            throw new Exception("Erro ao remover (posicao " + pos + " / " + tamanho + " invalida!");
        } else if (pos == 0){
            resp = removerInicio();
        } else if (pos == tamanho - 1){
            resp = removerFim();
        } else {
            // Caminhar ate a posicao anterior a insercao
            Celula i = primeiro;
            for(int j = 0; j < pos; j++, i = i.prox);
            
            Celula tmp = i.prox;
            resp = tmp.elemento;
            i.prox = tmp.prox;
            tmp.prox = null;
            i = tmp = null;
        }

		return resp;
	}

	/**
	 * Mostra os elementos da lista separados por espacos.
	 */
	public void mostrar() {
        int cont =0;
		for (Celula i = primeiro.prox; i != null; i = i.prox , cont++) {
			System.out.print("["+ cont +"]");
            i.elemento.mostrar();
		}	
	}

	/**
	 * Calcula e retorna o tamanho, em numero de elementos, da lista.
	 * @return resp Jogador tamanho
	 */
    public int tamanho() {
        int tamanho = 0; 
        for(Celula i = primeiro; i != ultimo; i = i.prox, tamanho++);
        return tamanho;
    }
}

public class questao5{
    public static Lista lista = new Lista();
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
        int contador = 0;
        String entrada = "";
        String opcode = ids.readLine();

        while(contador < Integer.parseInt(opcode)){
            entrada = ids.readLine();

            String[] caso = entrada.split(" ");
            // INSERCOES NA LISTA
            if(caso[0].charAt(0)=='I'){
                if(caso[0].charAt(1)=='I'){
                    // Insere Inicio
                    jogad = new Jogador();
                    TratarString(ler(caso[1]));

                    lista.inserirInicio(jogad);
                }else if(caso[0].charAt(1)=='F'){
                    // Insere fim
                    jogad = new Jogador();
                    TratarString(ler(caso[1]));

                    lista.inserirFim(jogad);
                }else{
                    // Insere posicao
                    jogad = new Jogador();
                    TratarString(ler(caso[2]));

                    lista.inserir(jogad, Integer.parseInt(caso[1]));
                }
            }
            // REMOCEOS NA LISTA
            if(caso[0].charAt(0)=='R'){
                if(caso[0].charAt(1)=='I'){
                    // Remove inicio
                    Jogador tmp = lista.removerInicio();
                    System.out.println("(R) "+ tmp.getNome());

                }else if(caso[0].charAt(1)=='F'){
                    // Remove fim
                    Jogador tmp = lista.removerFim();
                    System.out.println("(R) "+ tmp.getNome());

                }else{
                    // Remove posicao
                    Jogador tmp = lista.remover(Integer.parseInt(caso[1]));
                    System.out.println("(R) "+ tmp.getNome());

                }
            }
            contador++;
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
            lista.inserirFim(jogad);
            
            IdsJogadores = entrada.readLine();
        }

        // SEGUNDA PARTE DA LEITURA
        OpCode(entrada);
        lista.mostrar();
    }
}
