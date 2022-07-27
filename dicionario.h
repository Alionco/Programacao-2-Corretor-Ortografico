// GRR20196992 Lucas Alionço Perez


#define MAX 500

#define TAM_DIC 275503
#define TAM_MAX_PALAVRA 50

int carregaDicionario(char **dic);

int ordenaDicionario(const void* a, const void* b);

int leEntrada(char **dic);

int verificaPalavra(char *palavraNormal, char *palavraMin, char **dic);

int buscaBinaria (char* palavraMin, char** dic, int ini, int fim);