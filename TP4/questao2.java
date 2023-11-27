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

//########################################################################################################################################

class No {
	public int elemento; 
	public No esq, dir;
	public No2 outro;
	
	public No(int elemento) { 
	   this.elemento = elemento;
	   this.esq = this.dir = null;
	   this.outro = null;
	}
 
	public No(int elemento, No esq, No dir,No2 outro) {
	   this.elemento = elemento;
	   this.esq = esq;
	   this.dir = dir;
	   this.outro = outro;
	}
	
}
 
class No2 {
	public String elemento; 
	public No2 esq; 
	public No2 dir; 
 
	No2(String elemento) {
	   this.elemento = elemento;
	   this.esq = this.dir = null;
	}
 
	No2(String elemento, No2 esq, No2 dir) {
	   this.elemento = elemento;
	   this.esq = esq;
	   this.dir = dir;
	}
}
 
class ArvoreArvore {
	private No raiz; // Raiz da arvore.
 
	public ArvoreArvore() throws Exception {
	    raiz = null;
        // insercao na primeira arvore dos elementos 7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12 e 14.
        inserir(7);
        inserir(3);
        inserir(11);
        inserir(1);
        inserir(5);
        inserir(9);
        inserir(12);
        inserir(0);
        inserir(2);
        inserir(4);
        inserir(6);
        inserir(8);
        inserir(10);
        inserir(13);
        inserir(14);
	}
	
    public void inserir(int x) throws Exception {
	   raiz = inserir(x, raiz);
	}
 
	private No inserir(int x, No i) throws Exception {
        if (i == null) {
            i = new No(x);  
        } else if (x <i.elemento ){
            i.esq = inserir(x, i.esq);
        }else if (x > i.elemento ){
            i.dir = inserir(x, i.dir);
        }else {
            throw new Exception("Erro ao inserir!");
        }
        return i;
	}
	
	public boolean pesquisar(String x){
        if(raiz != null){
            System.out.print(x + " raiz");
	    }
        return pesquisar(x,raiz);
	} 
    
	private boolean pesquisar(String x,No i){
        boolean resp= false;
        if(i != null){    
            resp=pesquisar2(x,i.outro);
            if(resp == false){ 
                System.out.print(" esq");
                resp= pesquisar(x,i.esq);
            }
            if(resp == false){ 
                System.out.print(" dir");
                resp=pesquisar(x,i.dir);
            }
        }
	    return resp;
	}
 
	private boolean pesquisar2(String x, No2 i) {
        boolean resp= false;
        if(i != null){
            if (x.compareTo(i.elemento)==0) {
                resp = true;
            } else{
                System.out.print(" ESQ");
                resp = pesquisar2(x, i.esq);
            
                if(resp == false){
                    System.out.print(" DIR");
                    resp = pesquisar2(x, i.dir);
                }
            }
        }
        return resp;
	}

	public void InserirArvore2(String entrada , int y) throws Exception {
	   inserir2(entrada ,y ,raiz);
	}

	private void inserir2(String entrada , int y, No i) throws Exception {
        if (i.elemento == y) {
            i.outro = inserir3(entrada,i.outro);
        } else if (y < i.elemento ){
            inserir2(entrada,y,i.esq);
        } else if (y > i.elemento ){
            inserir2(entrada,y,i.dir);
        } else {
            throw new Exception("Erro ao inserir!");
        }
	}
   
	private No2 inserir3(String entrada, No2 i)throws Exception{
        if(i == null ){
            i = new No2(entrada);
        }else if(entrada.compareTo(i.elemento)<0){
            i.esq=inserir3(entrada,i.esq);
        }else if(entrada.compareTo(i.elemento)>0)
            i.dir=inserir3(entrada,i.dir);
        else {
            throw new Exception("Erro ao inserir!");
        }

        return i;
	}
}

public class questao2{
    public static Jogador[] jogad = new Jogador[1000];
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

    public static void main(String[] args) throws Exception {

        //tempo inicial do código
        long tempoInicial = System.currentTimeMillis();
        //----------------------------------------------//
        
        // PRIMEIRA PARTE DA LEITURA
        ArvoreArvore arvore = new ArvoreArvore();
        String IdsJogadores = "";
        BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
        IdsJogadores = entrada.readLine();

        while(IdsJogadores.equals("FIM") != true){
            jogad[tamJog] = new Jogador();
            TratarString(ler(IdsJogadores));
            tamJog ++;
            IdsJogadores = entrada.readLine();
        }
        for(int i =0 ; i < tamJog ; i++){
            int valor = jogad[i].getAltura()%15;
            arvore.InserirArvore2(jogad[i].getNome(), valor);
        }
        
        // SEGUNDA PARTE DA LEITURA
        String NomeJogadores = "";
        boolean saida = false;
        NomeJogadores = entrada.readLine();

        while(NomeJogadores.equals("FIM") != true){
            saida = arvore.pesquisar(NomeJogadores);
            if(saida == false){
                System.out.println(" NAO");
            }else{
                System.out.println(" SIM"); 
            }
            NomeJogadores = entrada.readLine();
        }

        //arquivo de Matricula sequencial 
        long tempoFinal = System.currentTimeMillis();
        Arq.openWrite("matrícula_arvoreBinaria.txt");
        Arq.println("695161" + "\t" + (tempoFinal - tempoInicial) + "\t" + contador);
        Arq.close();
    } 
}
