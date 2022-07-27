// GRR20196992 Lucas Alionço Perez


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#include "dicionario.h"

int carregaDicionario(char **dic) {

	FILE* dicionario;

	dicionario = fopen("/usr/share/dict/brazilian", "r");

	if(!dicionario) {
		dicionario = fopen("brazilian", "r");
		if(!dicionario){
			perror("Dicionário não carregado");
			return 0;
		}
	}

	char palavra[TAM_MAX_PALAVRA];

	int i = 0;

	fgets(palavra, TAM_MAX_PALAVRA, dicionario);

	while(! feof(dicionario)) {

		dic[i] = malloc (TAM_MAX_PALAVRA * sizeof(char)); // recebe cada palavra do dicionário
		strcpy(dic[i], palavra);
		dic[i][strcspn (dic[i], "\n")] = '\0';

		for(int j = 0; j < strlen(dic[i]); j++) {
			dic[i][j] = tolower(dic[i][j]); // deixa o dicionario minusculo
		} 

		fgets(palavra, TAM_MAX_PALAVRA, dicionario);
		i++;
	}

	qsort(dic, TAM_DIC, sizeof(char*), ordenaDicionario); // ordena o dicionário 

	fclose(dicionario); 

	return 1;
}

int ordenaDicionario(const void* a, const void* b) { // função usada para qsort

    return strcmp(*(const char**)a, *(const char**)b); 

}

int leEntrada(char **dic) {

	unsigned char c;

	c = getchar();

	while(!feof(stdin)) { // algoritmo da pagina do prof. Maziero

		while((isalpha(c) == 0) && (!feof(stdin))) {
			putchar(c);
			c = getchar();
		} // loop termina quando encontra uma letra

		char *palavraMin = malloc (sizeof(char));
		char *palavraNormal = malloc (sizeof(char));

		int i = 0;

		while((isalpha(c) != 0) && (!feof(stdin))) {

			palavraNormal[i] = c;
			palavraMin[i] = c;
			c = getchar();
			i++;

		} // loop termina quando encontra uma não-letra e com uma palavra armazenada

		if(!feof(stdin)) {
			verificaPalavra(palavraNormal, palavraMin, dic);
		}

		palavraMin[0] = '\0';
		palavraNormal[0] = '\0'; // reinicia as strings para receberem novas palavras

	}



	return 1;
}


int verificaPalavra(char *palavraNormal, char *palavraMin, char **dic) {


	for(int i = 0; palavraMin[i] != '\0'; i++){ // deixa a palavra em minusculo para comparacao
		palavraMin[i] = tolower(palavraMin[i]);
	}

	int palavraEncontrada = buscaBinaria(palavraMin, dic, 0, TAM_DIC); // busca binaria da palavra no vetor dicionario

	if(palavraEncontrada) {
		printf("%s", palavraNormal);
	} else {
		printf("[%s]", palavraNormal);
	}

	return 1;
}

int buscaBinaria (char* palavraMin, char** dic, int ini, int fim) {

	int meio, achou;

	if(ini > fim) {
		return 0;
	}
	meio = (ini + fim) / 2;
	achou = strcmp(palavraMin, dic[meio]);
	if(achou == 0) {
		return 1;
	} else if(achou < 0){
		return buscaBinaria(palavraMin, dic, ini, meio-1);
	} else {
		return buscaBinaria(palavraMin, dic, meio+1, fim);
	}

}