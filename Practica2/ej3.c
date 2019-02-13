#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct 
{
	int * vec ;
	int x;
	int indice ;

} params ;

void * suma(params * aux)
{
	int * vector = aux->vec ;
	int * sum = (int *)malloc(sizeof(int));
	*sum= 0;

	printf("%d %d %d\n",vector[1] , aux-> indice , aux->x );

	for (int i = aux->indice ; i < (aux->x) ; ++i)
	{
		
		*sum +=  vector[i]; 
	}

	printf("%d\n", *sum );
	pthread_exit(sum);
}


int main(int argc , char ** argv)
{
	if(argc!=2)
	{
		printf("argumentos required\n");
		exit(EXIT_FAILURE);
	}

	int v[10]= {1,1,1,1,1,1,1,1,1,2};

	int N = atoi(argv[1]);
	int n = 10/N ;
	int n2 =10%N ;
	int a = n+n2 ;

	int * resultado;
	int s= 0;
	pthread_t thd[N];

	params aux1 ;
	aux1.vec=v;
	aux1.x=n;
	aux1.indice=0;

	printf("%d %d %d\n", aux1.vec[1] , aux1.x , aux1.indice );


	params aux2 ;
	aux2.vec=v;
	aux2.x=a;
	aux2.indice=0;


	for (int i = 0; i < N; ++i)
	{
		if (i==N-1)
		{
			pthread_create(&thd[i] , NULL , (void *) suma , &aux2);
		}
		else
		{
			pthread_create(&thd[i] , NULL , (void *) suma , &aux1);
		}

		sleep(1);
		aux1.indice += n;
		aux2.indice += n;
		//sleep(1);

	}


	for (int i = 0; i < N; ++i)
	{
		pthread_join(thd[i] ,(void **) &resultado );
		s += *resultado;

	}

	printf("resultado : %d\n", s );
}