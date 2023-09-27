class Ciframento {

    public static boolean isFim(String s){
        return( s.length()== 3 && s.charAt(0)== 'F' && s.charAt(1)== 'I' && s.charAt(2)== 'M' );
    }

    public static String ciframento(int chave , String cifra){
        StringBuilder ciframento = new StringBuilder();
        int tamanho = cifra.length();

        for(int i =0 ; i <tamanho ; i++){
            int Stringcifrada = ((int)cifra.charAt(i))+(chave);
            
            while(Stringcifrada >164){
                Stringcifrada -= 32;
            }

            if(isFim(cifra)){
                break;
            }
            ciframento.append((char)Stringcifrada);
        }
        return ciframento.toString();
    }

    public static void main(String[] args) {
        String[] entrada = new String[1000];

        do {
            entrada[0] = MyIO.readLine();
            ciframento(3, entrada[0]);
            MyIO.println(""+ ciframento(3, entrada[0]));
        } while (isFim(entrada[0])==false);
    }    
}
