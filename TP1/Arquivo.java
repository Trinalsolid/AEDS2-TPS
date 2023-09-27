import java.io.RandomAccessFile;

class Arquivo {
    
    public static void lerReais(int valor) throws Exception{
        
        RandomAccessFile arq = new RandomAccessFile("valores.txt", "rw");
        double value = 0.0;

        for(int i = 0; i < valor; i++){
            value = MyIO.readDouble();
            arq.writeDouble(value);
        }

        arq.close();
    }

    public static void printaReais(int valor) throws Exception{

        RandomAccessFile arq = new RandomAccessFile("valores.txt", "r");

        int a = 0;
        double b = 0.00;

        for(int i = 0; i < valor; valor--){

            arq.seek((valor-1)*8);
            b = arq.readDouble();
            a = (int)b;

            if(b == (long) b){
                MyIO.println(a);
            }else{
                MyIO.println(b);
            }

        }

        arq.close();
    }

    public static void main(String[] args) throws Exception{
        int num = Integer.parseInt(MyIO.readLine());
        lerReais(num);
        printaReais(num);
    }

}
