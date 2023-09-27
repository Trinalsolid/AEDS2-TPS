class palindromorec{
    public static boolean isFim(String s){
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static boolean palindromo(String s){
        return palindromoRec(s , 0 , (s.length()-1));
    }   

    public static boolean palindromoRec(String s , int i , int j){
        boolean resp = true;
       
        if(j >= i){
            if(s.charAt(i) != s.charAt(j)){
                resp = false;
            }else{
                resp = palindromoRec(s, i+1, j-1);             
            }
        }

        return resp;
    }

    public static void main(String[] args) {

        String[] entrada = new String[1000];

        do{
            entrada[0] = MyIO.readLine();
            if(palindromo(entrada[0])){
                System.out.println("SIM");
            }else{
                System.out.println("NAO");
            }
        } while (isFim(entrada[0]) == false);
 
    }
}
