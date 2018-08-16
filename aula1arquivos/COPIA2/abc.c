#include <stdio.h>

#define tamanho 4096

int main(int argc , char **argv){

	// o buffer representa o pedaço de arquivo que tentamos ler em caa operaçao de leitura
	char buffer[tamanho];
	/*a cada operação de leitura leremos um pedaço do arquivo que pode ter tamanho igual ao do buffer 
	OU NÃO, sendo assim qtd , representa o tamanho o que foi EFETIVAMENTE LIDO */
	int qtd;

	// ponteiros de arquivo para os arquivos de entrada e saida 
	FILE *entrada,*saida;


	if(argc !=3){

		/*caimos nesse trecho de código caso o numero de argumentos de linha de comando seja diferente de 3 , como no C o próprio nome
		do programa é um argumento de linha de comando , caímos aqui caso o numero de argumentos passados pelo usuário tenha sido diferente de 2,
		que se referem ao arquivo origem e ao arquivo destino
		*/
		fprintf(stderr,"ERRO NA CHAMADA DO COMANDO");
		fprintf(stderr,"USO CORRETO %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO] /n",argv[0]);

		return 1;
	}

	//tentamos abrir o arquivo de entrada no modo read
	entrada = fopen(argv[1],"r");


	if(entrada == NULL){
		/* caimos aqui caso o ponteiro para o arquivo de origem seja igual a NULL, ou seja 
			caso nao consigamos localizar um arquivo de origem*/
		fprintf(stderr,"arquivo NAO pôde ser aberto para leitura",argv[1]);

		return 1;
	}

	// tentamos abrir o arquivo de saida no modo WRITE
	saida = fopen(argv[2],"w");

	if(saida == NULL){

		/* caimos aqui caso o ponteiro para o arquivo de origem seja igual a NULL, ou seja 
		caso nao consigamos localizar um arquivo de origem*/

		//como BOA PRATICA DE PROGRAMAÇÃO , fechamos o arquivo de entrada
		fclose(entrada);
		fprintf(stderr,"arquivo NAO pode ser aberto para a escrita");
		return 1;
	}

	// tenta ler um pedaço do arquivo , lembrando qtd representa o tamanho do pedaço de arquivo EFETIVAMENTE LIDO
	qtd = fread(buffer,1,tamanho,entrada);

	while(qtd > 0){
		/*enquanto estivermos lendo algo com tamanho MAIOR QUE ZERO, escreva o que foi lido
		  no arquivo e leia outro pedaço
		*/

		fwrite(buffer,1,qtd,saida);
		qtd = fread(buffer,1,tamanho,entrada);
	}

	//fecha os arquivos de entrada e saida
	fclose(entrada);
	fclose(saida);

	//mensagem ao final do programa indicando que tudo correu BEM
	printf("tudo ocorreu bem");
}