#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void * suma()
{
	int * sum = (int *)malloc(sizeof(int));
	int x , y ;
	x= rand() % 10;
	y= rand() % 10;

	printf("Los numeros son %d y %d \n" , x , y);

	*sum= x+y;

	pthread_exit(sum);

}



int main()
{	
	srand(time(NULL));
	int N=0;
	int total = 0;
	int * a;
	printf("Cuantas hebras quiere?\n");
	scanf( "%d" , &N);

	pthread_t thd[N];


	for (int i = 0; i < N; ++i)
	{
		pthread_create(&thd[i] , NULL , (void *) suma , NULL);
		//sleep(1);
		pthread_join(thd[i], (void** )&a);
		printf("%d\n", *a );
		total= total + (*a) ;

	}


	printf("Suma total : %d\n", total );
	exit(EXIT_SUCCESS);
}