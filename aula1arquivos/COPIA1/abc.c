#include <stdio.h>

/*programa feito dia 5 de agosto de 2018 por ramon bouças
OBJETIVO: receber um arquivo de origem e copiar tal arquivo BYTE A bYTE PARA UM ARQUIVO DE DESTINO , que , se nao existir,será criado 
*/

/*atenção argc significa a quantidade de "argumentos de linha de comando" , lembrando que o C considera o proprio nome do programa como um argumento de linha de comando
e o argv sao os argumentos de linha de comando em si */
int main(int argc,char** argv){

// para acessar arquivos trabalhamos com ponteiros de arquivo
FILE *entrada,*saida;

/*essa variavel irá armazenar cada byte lido do arquivo, ela é do tipo int  e nao do tipo byte
,pois ao tentar ler o próximo byte de um arquivo , pode-se receber não só qualquer byte, como também
o valor -1 , caso nao haja próximo byte*/
int c = 0;


if(argc !=3){

	/*caimos nesse trecho de código caso o numero de argumentos de linha de comando seja diferente de 3 , como no C o próprio nome
	do programa é um argumento de linha de comando , caímos aqui caso o numero de argumentos passados pelo usuário tenha sido diferente de 2,
	que se referem ao arquivo origem e ao arquivo destino
	*/
	fprintf(stderr,"ERRO NA CHAMADA DO COMANDO");
	fprintf(stderr,"USO CORRETO %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO] /n",argv[0]);

	return 1;
}
	
	//tenta abrir o arquivo de origem no modo READ
	entrada = fopen(argv[1],"r");

	if(entrada == NULL){

		/* caimos aqui caso o ponteiro para o arquivo de origem seja igual a NULL, ou seja 
			caso nao consigamos localizar um arquivo de origem*/
		fprintf(stderr,"arquivo NAO pôde ser aberto para leitura",argv[1]);
		return 1;
	}

	//tenta abrir o arquivo de destino no modo WRITE
	saida = fopen(argv[2],"w");

	if(saida == NULL){
		/*caimos aqui caso o ponteiro do arquivo de saida seja NULL, ou seja , caso nao tenhamos conseguido abrir o arquivo de saida
		como BOA PRÁTICA de programação , fechamos o arquivo de entrada*/

		fclose(entrada);
		fprintf(stderr,"arquivo NÃO pôde ser aberto para gravação",argv[2]);
		return 1;

	}
 
 	/*estamos requisitando UM BYTE do arquivo de entrada , esse byte pode ser um BYTE QUALQUER,e caso 
 	  NÃO se consiga ler o byte,será recebido o valor -1*/
	c = fgetc(entrada);

	while(c != EOF){
		/*enquanto nao chegarmos no fim do arquivo de entrada
		escreva o byte no arquivo de SAÍDA e leia mais um byte do arquivo de entrada
		*/
		fputc(c,saida);
		c = fgetc(entrada);
	}

	// ao final do programa, fecha os arquivos de entrada e de saida
	fclose(entrada);
	fclose(saida);

	//ao final do programa , dá uma mensagem informando que tudo correu como esperado
	fprintf(stdout,"tudo bem",argv[0]);
	return 0;
}

















 