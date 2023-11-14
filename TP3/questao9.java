
class Celula{
    int elemento;
    Celula dir , esq , sup , inf;

    public Celula(){
        this(0);
    }

    public Celula(int elemento){
        this.elemento = elemento;
        dir = esq = sup = inf = null;
    }
}

class Matriz{
    int linha , coluna;
    Celula inicio;

    public Matriz(int linha , int coluna){
        this.linha = linha;
        this.coluna = coluna;

        //Inicializando a matriz
        int cont = 0;
        Celula i , j;
        int lin , col;

        inicio = new Celula(cont++);

        //Cria as primeiras colunas da matriz
        for(j = inicio , col = 1 ; col < coluna ; j = j.dir , col++   ){
            j.dir = new Celula(0);
            j.dir.esq = j;
        }
        //Cria o restante das linhas para cada coluna
        for(i = inicio , lin = 1 ; lin < linha ; i = i.inf , lin++   ){
            i.inf = new Celula(0);
            i.inf.sup = i;
            for(j = i.inf , col = 1 ; col < coluna ; j = j.dir , col++   ){
                j.dir = new Celula();
                j.dir.esq = j;
                j.dir.sup = j.sup.dir;
                j.sup.dir.inf = j.dir;
            }
        }
    }

    public void Inserir(){
        for( Celula i = inicio ; i != null ; i = i.inf){
            for( Celula j  = i ; j != null ; j = j.dir){
                j.elemento = MyIO.readInt();
            }
        }
    }

    public void DiagonaPrincipal(){
        if(linha == coluna && linha > 0){
            Celula i = inicio;

            System.out.print(i.elemento + " ");
            while (i.dir != null) {
                i = i.dir.inf;
                System.out.print( i.elemento + " ");
            }
        }
    }

    public void DiagonalSecundaria(){
        if(linha == coluna && linha > 0){
            Celula i = inicio;

            while (i.dir != null) {
                i = i.dir;
            }
            System.out.print(i.elemento + " ");

            while (i.esq != null) {
                i = i.esq.inf;
                System.out.print( i.elemento + " ");
            }
        }
    }

    public Matriz somaMatriz(Matriz m1){     
        return somaMatriz(this , m1);
    }

    public Matriz somaMatriz(Matriz m1 , Matriz m2){
        Matriz resp = null;
        if (m1.linha == m2.linha && m1.coluna == m2.coluna ) {
            resp = new Matriz(m1.linha, m1.coluna);

            Celula ColunaResp = resp.inicio;
            Celula Colunam1 = m1.inicio; 
            Celula Colunam2 = m2.inicio;

            for(int i = 0; i < linha ; i++){

                Celula LinhaResp = ColunaResp;
                Celula Linham1 = Colunam1; 
                Celula Linham2 = Colunam2;

                for(int j = 0; j < coluna; j++){
                    LinhaResp.elemento = Linham1.elemento + Linham2.elemento;
                    LinhaResp = LinhaResp.dir;
                    Linham1 = Linham1.dir; 
                    Linham2 = Linham2.dir;
                }
                ColunaResp = ColunaResp.inf;
                Colunam1 = Colunam1.inf; 
                Colunam2 = Colunam2.inf;
            }
        }
        return resp;
    }

    public Matriz MultiplicacaoMatriz(Matriz a , Matriz b){
        Matriz resp = null;

        if(linha == coluna) {
            resp = new Matriz(a.linha, b.coluna);

            // linhas de cada matriz
            Celula Iresp = resp.inicio;
            Celula Im1 = a.inicio; 
            Celula Im2 = b.inicio;

            for(int i = 0; i < linha ; i++){

                Celula Jresp = Iresp;
                Celula Jm1 = Im1; 
                Celula Jm2 = Im2;

                for(int j = 0; j < b.coluna ; j++){

                    Celula tmp1 = Jm1;
                    Celula tmp2 = Jm2;

                    for(int k = 0; k < b.coluna ; k++){
                        Jresp.elemento = Jresp.elemento + (Jm1.elemento * Jm2.elemento);
                        Jm1 = Jm1.dir; 
                        Jm2 = Jm2.inf;
                        
                    }
                    Jresp = Jresp.dir;
                    Jm1 = tmp1; 
                    Jm2 = tmp2;
                }
                Iresp = Iresp.inf;
                Im1 = Im1.inf;
            }
        }
        return resp;
    }

    public void Mostrar(){
        for( Celula i = inicio ; i != null ; i = i.inf){
            for( Celula j  = i ; j != null ; j = j.dir){
                System.out.print(j.elemento + " ");
            }
            System.out.println("");
        }
    }
}

public class questao9{

    public static void main(String[] args) {
        int quantidade = MyIO.readInt();

        for(int i = 0 ; i < quantidade ; i++){

            int linhas, colunas;
            linhas = MyIO.readInt();
            colunas = MyIO.readInt();
            // Matriz 1
            Matriz matriz1 = new Matriz(linhas, colunas);
            matriz1.Inserir();
            matriz1.DiagonaPrincipal();
            System.out.println(" diagonal ");
            matriz1.DiagonalSecundaria();
            System.out.println("diagonal ");
            // Matriz 2
            int lin , col;
            lin = MyIO.readInt();
            col = MyIO.readInt();
            Matriz matriz2 = new Matriz(lin, col);
            matriz2.Inserir();
            // Matriz de resposta
            Matriz resp = new Matriz(lin, col);
            resp = matriz1.somaMatriz(matriz1 , matriz2);
            resp.Mostrar();
            // Matriz 2 de resposta
            Matriz resp2 = new Matriz(lin, col);
            resp2 = matriz1.MultiplicacaoMatriz(matriz1 , matriz2);
            resp2.Mostrar();
        }
    }
    
}