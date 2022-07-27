// GRR20196992 Lucas Alionço Perez

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "dicionario.h"

int main() {

	setlocale(LC_ALL, "pt_BR.iso88591");
	
	char* dicionario[TAM_DIC];
	carregaDicionario(dicionario); // carrega o dicionario na memoria em um vetor de strings

	leEntrada(dicionario); // le cada palavra da entrada, até encontrar espaço e tambem faz a verificacao

	return 1;
}