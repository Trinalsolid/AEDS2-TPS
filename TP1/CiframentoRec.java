class CiframentoRec {

    public static boolean isFim(String s){
        return( s.length()== 3 && s.charAt(0)== 'F' && s.charAt(1)== 'I' && s.charAt(2)== 'M' );
    }

    public static String ciframento(String entrada, String saida){
        return(ciframentoRec(entrada, saida, 0));
    }

    public static String ciframentoRec(String entrada, String saida, int tam){
               
        int chave = 3;
        if(entrada.length() > tam){
            saida += (char)(entrada.charAt(tam) + chave);
            return ciframentoRec(entrada, saida, tam + 1);
        }

        return saida;
    }

    public static void main(String[] args) {

        String[] entrada = new String[1000];
        int numEntrada = 0;

        do {
            entrada[numEntrada] = MyIO.readLine();
        } while (isFim(entrada[numEntrada++]) == false);
        numEntrada--;
        
        String nova = "";

        for(int i = 0; i < numEntrada; i++){
            MyIO.println(ciframento(entrada[i], nova)); 
        }
        
    }
   
}
