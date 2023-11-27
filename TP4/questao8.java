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

    public Jogador(int id,String nome,int altura,int peso,
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
        System.out.println("["+ getId()+" ## "+ getNome()+" ## "+ getAltura()+" ## "+ getPeso()
            +" ## "+ getAnoNascimento()+" ## "+ getUniversidade()+" ## "+getCidadeNascimento()+
            " ## " +getEstadoNascimento()+" ## "+"]");
    }
}

class HashComRehash {
	Jogador tabela[];
	int m;
	final int NULO = -1;

	public HashComRehash() {
		this(25);
	}

	public HashComRehash(int m) {
		this.m = m;
		this.tabela = new Jogador[this.m];
		for (int i = 0; i < m; i++) {
			tabela[i] = null;
		}
	}

	public int h(int elemento) {
		return elemento % m;
	}

	public int reh(int elemento) {
		return ++elemento % m;
	}

	public boolean inserir(Jogador elemento) {
		boolean resp = false;
		if (elemento != null) {
			int pos = h(elemento.getAltura());
			if (tabela[pos] == null) {
				tabela[pos] = elemento;
				resp = true;
			} else {
				pos = reh(elemento.getAltura());
				if (tabela[pos] == null) {
				tabela[pos] = elemento;
				resp = true;
				}
			}
		}
		return resp;
	}

	public boolean pesquisar(String elemento) {
		boolean resp = false;
		for(int i = 0; i < m ; i++){
			if(tabela[i] != null && tabela[i].getNome().compareTo(elemento) == 0){
				resp = true;
				break;
			}else{
				resp = false;
			}
		}

		return resp;
	}
}

public class questao8{
    public static Jogador jogad = new Jogador();
    public static int tamJog = 0;
    public static int contador = 0;
    
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

    public static void main(String[] args) throws Exception {

        //tempo inicial do código
        long tempoInicial = System.currentTimeMillis();
        //----------------------------------------------//
        
        // PRIMEIRA PARTE DA LEITURA
        HashComRehash tabelaRehash = new HashComRehash();
        String IdsJogadores = "";
        BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
        IdsJogadores = entrada.readLine();

        while(IdsJogadores.equals("FIM") != true){
            jogad = new Jogador();
            TratarString(ler(IdsJogadores));
            tabelaRehash.inserir(jogad);
            
            IdsJogadores = entrada.readLine();
        }
        
        // SEGUNDA PARTE DA LEITURA
        String NomeJogadores = "";
        boolean saida = false;
        NomeJogadores = entrada.readLine();

        while(NomeJogadores.equals("FIM") != true){
            saida = tabelaRehash.pesquisar(NomeJogadores);
            if(saida == false){
                System.out.println(NomeJogadores + " NAO");
            }else{
                System.out.println(NomeJogadores + " SIM"); 
            }
            NomeJogadores = entrada.readLine();
        }

        //arquivo de Matricula sequencial 
        long tempoFinal = System.currentTimeMillis();
        Arq.openWrite("matrícula_hashRehash.txt");
        Arq.println("695161" + "\t" + (tempoFinal - tempoInicial) + "\t");
        Arq.close();
    } 
}
