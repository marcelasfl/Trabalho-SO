#pragma once
#include <time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int linha;
	int coluna;
} Thread;

int count = 0; /* este dado eh compartilhado pela(s) thread(s) */
int count2 = 0; /*contador dos primos*/ 
int contador_primos_total = 0;
int i, j;
int matriz[10000][10000];
pthread_mutex_t mutex;



void imprimir_matriz(int matriz[10000][10000]) {
	for (i = 0; i < 10000; i++) {
		for (j = 0; j < 10000; j++)
			printf("%5d ", matriz[i][j]);
		printf("\n");

	}
}

void matriz_aleatoria(int matriz[10000][10000]) {
	srand(time(NULL));

	for (i = 0; i < 10000; i++) {
		for (j = 0; j < 10000; j++) {
			matriz[i][j] = rand() % 4000;
		}
	}

	imprimir_matriz(matriz);

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

void* runner(void* param) { /* threads chamam essa funcao */
	Thread* t = (Thread*)param;
	int linha = t->linha;
	int coluna = t->coluna;
	printf("O bloco que está sendo processado é: [%d, %d]\n", linha, coluna);
	for (int i = linha; i < linha + 100; i++) {
		for (int j = coluna; j < coluna + 100; j++) {
			if (isPrime(matriz[i][j])) {
				count2++;
			}
		}
		pthread_mutex_lock(&mutex);
		contador_primos_total += count2;
		printf("A quantidade de primos nesse bloco são: [%d, %d]: %d\n", linha, coluna, count2);
		pthread_mutex_unlock(&mutex);
		pthread_exit(0);
	}
	
}
int main(int argc, char* argv[]) {
	int matriz[10000][10000];
	Thread thread[8];
	pthread_t tid[8]; /* o identificador da thread */
	pthread_attr_t attr;  /*os atributos da thread*/
	pthread_attr_init(&attr); /* ajusta os atributos padrao da thread */
	pthread_mutex_init(&mutex, NULL);
	matriz_aleatoria(matriz[10000][10000]);
	clock_t beginSerial;
	clock_t endSerial;
	clock_t beginParalelo;
	clock_t endParalelo;
	
	for (int i = 1; i <= 8; i++) {
		pthread_create(&tid[i], &attr, runner, argv[1]); /* cria a thread */
		pthread_join(tid[i], NULL);
	} /* espera pelo termino da thread */
	
	

	for (int a = 0; a < 10000; a += 100) {
		for (int b = 0; b < 10000; b += 100) {
			thread[count].linha = a;
			thread[count].coluna = b;
			pthread_create(&tid[count2], NULL, runner, &thread[count2]);
			count++;
			

		}
	}
	for (int i = 0; i < 8; i++) { //Uma thread esperar a outra
		pthread_join(tid[i], NULL);
	}

	
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);
	
}

