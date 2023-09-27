class Is {
    public static boolean isFim(String s){
        return( s.length()== 3 && s.charAt(0)== 'F' && s.charAt(1)== 'I' && s.charAt(2)== 'M' );
    }

    public static boolean vogal(String s){
        boolean vogal = true;
        int tamanho = s.length();

        for(int i=0 ; i<tamanho ; i++){
            if(s.charAt(i) !='A' && s.charAt(i) !='E' && s.charAt(i) !='I' && s.charAt(i) !='O' &&s.charAt(i) !='U' &&
            s.charAt(i) !='a' && s.charAt(i) !='e' && s.charAt(i) !='i' && s.charAt(i) !='o' && s.charAt(i) !='u' ){
                vogal = false;
                s.length();
            }
        }

        if(vogal){
            MyIO.println("SIM NAO NAO NAO");
            return vogal;
        }else{
            return inteiros(s);
        }
    }
    public static boolean consoante(String s){
        boolean consoante = true;

        for(int i=0 ; i<s.length() ; i++){
            if(s.charAt(i) =='A' || s.charAt(i) =='E' || s.charAt(i) =='I' || s.charAt(i) =='O' ||s.charAt(i) =='U' ||
            s.charAt(i) =='a' || s.charAt(i) =='e' || s.charAt(i) =='i' || s.charAt(i) =='o' || s.charAt(i) =='u' ){
                consoante = false;
                s.length();
            }
        }

        if(consoante){
            MyIO.println("NAO SIM NAO NAO");
            return consoante;
        }else{
            return vogal(s);
        }
    }
    public static boolean inteiros(String s){
        boolean inteiro = true;

        for(int i=0; i < s.length();i++){
            if(s.charAt(i) < '0' || s.charAt(i) > '9'){
                inteiro = false;
                i = s.length();
            }
        }

        if(inteiro){
            MyIO.println("NAO NAO SIM NAO");
            return inteiro;
        }else{
            return reais(s);
        }

    }
    public static boolean reais(String s){
        boolean reais = true;
        boolean teste = false;

        for(int i=0; i < s.length() ; i++){
            if( s.charAt(i) == ',' || s.charAt(i) == '.'){
                reais = true;
            }else if( s.charAt(i) < '0' || s.charAt(i) > '9'){
                reais = false;
                i = s.length();
            }
        }

        if(reais && teste){
            reais = true;
            MyIO.println("NAO NAO NAO SIM");
        }else{
            reais = false;
            MyIO.println("NAO NAO NAO NAO");
        }

        return reais;
    }

    public static void main(String[] args) {
        String entrada = MyIO.readLine();
        boolean resp = false;

        while(!isFim(entrada)){
            resp = consoante(entrada);
            entrada = MyIO.readLine();
        }
        
    }    
}
