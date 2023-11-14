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

class Pilhaflex {
	private Celula topo;

	/**
	 * Construtor da classe que cria uma fila sem elementos.
	 */
	public Pilhaflex() {
		topo = null;
	}

	public void inserir(Jogador x){
		Celula tmp = new Celula(x);
		tmp.prox = topo;
		topo = tmp;
		tmp = null;
	}

	/**
	 * Remove elemento da pilha (politica FILO).
	 * 
	 * @return Elemento removido.
	 * @trhows Exception Se a sequencia nao contiver elementos.
	 */
	public Jogador remover() throws Exception {
		if (topo == null) {
			throw new Exception("Erro ao remover!");
		}
		Jogador resp = topo.elemento;
		Celula tmp = topo;
		topo = topo.prox;
		tmp.prox = null;
		tmp = null;
		return resp;
	}

	/**
	 * Mostra os elementos separados por espacos, comecando do topo.
	 */
	public void mostrar() {
        int cont=0;
		for (Celula i = topo; i != null; i = i.prox) {
            System.out.print("["+cont+"]");
            i.elemento.mostrar();
            cont++;
		}		
	}

	public void mostraPilha() {
		mostraPilha(topo , 142);
	}

	private void mostraPilha(Celula i , int cont) {
		if (i != null) {
            cont--;
			mostraPilha(i.prox , cont);
            System.out.print("["+cont+"]");
			i.elemento.mostrar();
		}
	}

}


public class questao6{
    public static Pilhaflex pilha = new Pilhaflex();
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

                pilha.inserir(jogad);
            }
            // REMOCEOS NA PILHA
            if(caso[0].charAt(0)=='R'){
                // Remove fim OU desempilha
                Jogador tmp = pilha.remover();
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

            pilha.inserir(jogad);
            
            IdsJogadores = entrada.readLine();
        }

        // SEGUNDA PARTE DA LEITURA
        OpCode(entrada);
        pilha.mostraPilha();
    }
}
