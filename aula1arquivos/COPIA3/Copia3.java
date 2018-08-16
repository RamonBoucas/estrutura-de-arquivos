import java.io.*;

public class Copia3 {

	public static void main(String[] args){

		InputStream entrada = null;
		OutputStream saida = null;

		int c =0;

		if(args.length !=2 ){

			System.err.println("erro na chamada do comando");
			System.err.println("USO CORRETO [ARQUIVO ORIGEM] [ARQUIVO DESTINO] /n");

			System.exit(1);
		}

		try{
			entrada = new FileInputStream(args[0]);
		}catch(IOException e){
			System.err.println("Arquivo " + args[0] + " não pode ser aberto para leitura\n");
            System.exit(1);
		}

		try{
			saida = new FileOutputStream(args[1]);
		}catch(IOException e){
			System.err.println("Arquivo " + args[1] + " não pode ser aberto para escrita\n");
            System.exit(1);
		}


		try{
			c = entrada.read();

			while(c != -1){
				saida.write(c);
				c = entrada.read();
			}

			entrada.close();
			saida.close();
		}catch(IOException ex){
			System.err.println("erro ao copiar o arquivo");
		}

		System.out.println("a copia de arquivo foi feita com sucesso");

	}
	
}