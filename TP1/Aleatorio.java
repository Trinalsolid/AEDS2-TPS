import java.util.Random;

class Aleatorio{

    public static boolean isFim(String s){
        return(s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

	public static String trocaletra(String s, char a, char b){
		String resp = "";
        // procura o valor de A e troca com o de B
		for(int i = 0; i < s.length(); i++){
			if(s.charAt(i) == a){
				resp += b;
			}else{
				resp += s.charAt(i);
			}
		}
		return resp;
	}

	public static void main(String[] args){

		String[] entrada = new String[1000];
		int numEntrada = 0;
		char letra1, letra2;

		Random gerador = new Random();
		gerador.setSeed(4);

		do{
			entrada[numEntrada] = MyIO.readLine();
		}while(!(isFim(entrada[numEntrada++])));
		numEntrada--;
		
		for(int i = 0; i < numEntrada; i++){
			
			letra1 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
			letra2 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));

			MyIO.println(trocaletra(entrada[i], letra1, letra2)); 
		}

	}

}
