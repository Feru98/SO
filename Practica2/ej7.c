#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t sem = PTHREAD_MUTEX_INITIALIZER ;

void * comprar(int * aux)
{
	pthread_mutex_lock(&sem);

	int a = rand() % 11;
	int b = rand() % 5;

	printf("Decremento %d en %d\n" , b , a);
	aux[b] = aux[b] - a ;

	pthread_mutex_unlock(&sem);

	pthread_exit(NULL);
}

void * vender(int * aux)
{
	pthread_mutex_lock(&sem);
	
	int a = rand() % 11;
	int b = rand() % 5;

	printf("Incremento %d en %d \n", b , a);
	aux[b] = aux[b] + a ;

	//printf("%d\n", aux[b]);

	pthread_mutex_unlock(&sem);
	pthread_exit(NULL);
}



int main()
{
	srand(time(NULL));
	int camisetas[5]= {10 , 10 , 10 ,10 ,10};
	int N = 10;
	int M = 5;
	int e1;
	int e2;
	pthread_t comprador[N];
	pthread_t proveedor[M];

	for (int i = 0; i < N; ++i)
	{
		e1=pthread_create(&comprador[i] , NULL , (void*) comprar , &camisetas);
		if (e1!=0)
		{
			printf("error\n");
			exit(EXIT_FAILURE);
		}
	}

	for (int j = 0; j < M; ++j)
	{
		e2=pthread_create(&proveedor[j] , NULL , (void*) vender , &camisetas);
		if (e1!=0)
		{
			printf("error\n");
			exit(EXIT_FAILURE);
		}
	}



	for (int i = 0; i < N; ++i)
	{
		e1=pthread_join(comprador[i] , NULL );
		if (e1!=0)
		{
			printf("error\n");
			exit(EXIT_FAILURE);
		}
	}

	for (int j = 0; j < M; ++j)
	{
		e2=pthread_join(proveedor[j] , NULL );
		if (e1!=0)
		{
			printf("error\n");
			exit(EXIT_FAILURE);
		}
	}


	for (int i = 0; i < 5; ++i)
	{
		printf("vector[%d] :%d \n" ,i , camisetas[i]);
	}

	pthread_mutex_destroy(&sem);
	exit(EXIT_SUCCESS);
}