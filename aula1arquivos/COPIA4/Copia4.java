import java.io.*;

public class Copia4{
	
	public static final int TAMANHO = 4096;
	
	public static void main(String[] args) {
		
		InputStream entrada = null;
		OutputStream saida = null;
		
		byte buffer[] = new byte[TAMANHO];
		
		// representa a quantidade total de bytes lidos
		int qtd;
		
		long inicio = System.currentTimeMillis();
		
		if(args.length !=2) {
			  System.err.println("Erro na chamada do comando.");
	          System.err.println("Uso: java Copia4 [ARQUIVO ORIGEM] [ARQUIVO DESTINO].");
	          System.exit(1);	
		}
		
		
		try {
			entrada = new FileInputStream(args[0]);
		}catch (IOException e) {
			System.err.println("o arquivo" + args[0] + "nao pode ser aberto para leitura");
			System.exit(1);
		}
		
		try {
			saida = new FileOutputStream(args[1]);
		}catch (IOException e) {
			System.err.println("o arquivo" + args[1] + "nao pode ser aberto para gravação");
			System.exit(1);
		}
		
		
		
		try {
		
		/* recebe a quantiidade de bytes que foram lidos do arquivo de entrada e guardados no BUFFER */
		qtd = entrada.read(buffer);
		
		
		while(qtd > 0) {
			/* escreve,os bytes que estão guardados no aray, começando na posição do array indicada(no caso , a posição 0)
			 *  e se extendendo pela quantidade de próximas posições indicadas(no caso todas as posiçoes do array).
			 *  O lugar onde a escrita ocorre é o arquivo de saida
			 */
			saida.write(buffer,0,qtd);
			qtd = entrada.read(buffer);
		}
		
		//fecha os arquvos de entrada e saida
		entrada.close();
		saida.close();
		
		
		}catch (IOException e) {
			// em caso de qualquer erro na operação de leitura
			System.err.println("erro ao copiar o arquivo");
		}
		
		
		long fim = System.currentTimeMillis();
		
		System.out.println("tempo gasto na copia" + (fim-inicio));
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
}