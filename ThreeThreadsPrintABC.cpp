#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int isMyTurn = 0;

void* printA(void* arg){
	for(int i = 0; i < 10; ++i){
		pthread_mutex_lock(&mutex);
		while(isMyTurn != 0){
			pthread_cond_wait(&cond, &mutex);
		}
		printf("A\n");
		sleep(1);
		isMyTurn = 1;
		//pthread_cond_signal(&cond);
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
		//pthread_cond_signal(&cond);
		//pthread_cond_broadcast(&cond);
	}
}

void* printB(void* arg){
	for(int i = 0; i < 10; ++i){
		pthread_mutex_lock(&mutex);
		while(isMyTurn != 1){
			pthread_cond_wait(&cond, &mutex);
		}
		printf("B\n");
		sleep(1);
		isMyTurn = 2;
		//pthread_cond_signal(&cond);
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
		//pthread_cond_signal(&cond);
		//pthread_cond_broadcast(&cond);
	}
}

void* printC(void* arg){
	for(int i = 0; i < 10; ++i){
		pthread_mutex_lock(&mutex);
		while(isMyTurn != 2){
			pthread_cond_wait(&cond, &mutex);
		}
		printf("C\n");
		sleep(1);
		isMyTurn = 0;
		//pthread_cond_signal(&cond);
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mutex);
		//pthread_cond_signal(&cond);
		//pthread_cond_broadcast(&cond);
	}
}

int main(){
	pthread_t threadA, threadB, threadC;
	pthread_create(&threadA, NULL, &printA, NULL);
	pthread_create(&threadB, NULL, &printB, NULL);
	pthread_create(&threadC, NULL, &printC, NULL);
	pthread_join(threadA, NULL);
	pthread_join(threadB, NULL);
	pthread_join(threadC, NULL);
}