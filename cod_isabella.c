#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* struct com os atributos linha e coluna */
typedef struct {
	int linha;
	int coluna;
} Thread;

int count = 0; /* este dado eh compartilhado pela(s) thread(s) */
void* runner(void* param); /* threads chamam essa funcao */
int i, j;

/* criando a matriz aleatória */
void matriz_aleatoria(int matriz[10000][10000]) {
	srand(time(NULL));

	for (i = 0; i < 10000; i++) {
		for (j = 0; j < 10000; j++) {
			matriz[i][j] = rand() % 4000;
		}
	}

	imprimir_matriz(matriz);
	return matriz;
}

void imprimir_matriz(int mat1[10000][10000]) {
	for (i = 0; i < 10000; i++) {
		for (j = 0; j < 10000; j++)
			printf("%5d ", mat1[i][j]);
		printf("\n");

	}
}

int isPrime(int num) {
	if (num < 2) {
		return 0;
	}

	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			return 0;
		}
	}

	return 1;
}
/* atribui aos atributos a posição que a linha e a coluna devem processar */
void* runner(void* param) { 
	Thread* t = (Thread*)param;
	int linha = t->linha;
	int coluna = t->coluna;
	pthread_exit(0);
}
int main(int argc, char* argv[]) {
	int matriz[10000][10000];
	Thread thread[8]; /* chamando struct */
	pthread_t tid[8]; /* o identificador da thread */
	pthread_attr_t attr;  /*os atributos da thread*/
	pthread_mutex_t mutex; /* criando mutex */
	pthread_attr_init(&attr); /* ajusta os atributos padrao da thread */
	pthread_mutex_init(&mutex, NULL);
	matriz_aleatoria(matriz[10000][10000]);
	clock_t beginSerial = 0;
	clock_t endSerial = 0;
	clock_t beginParalelo = 0;
	clock_t endParalelo = 0;
	

	for (int i = 1; i <= 8; i++) {
		pthread_create(&tid[i], &attr, runner, argv[1]); /* cria a thread */
		pthread_join(tid[i], NULL);
	} /* espera pelo termino da thread */
	
	pthread_exit(NULL);

	/* atribuindo qual macrobloco será atribuido a thread */
	for (int a = 0; a < 10000; a += 100) {
		for (int b = 0; b < 10000; b += 100) {
			thread[count].linha = a;
			thread[count].coluna = b;
			count++;
			

		}
	}
	for (int i = 0; i < 8; i++) { //Uma thread esperar a outra
		pthread_join(tid[i], NULL);
	}
	pthread_exit(0);

	
}
