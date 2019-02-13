#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int x;
	int * vec;
	int  m[3][3] ;

}params;



void * mult(params * aux)
{
	int  a ;
	int b = aux->x ;
	int c ;
	int *sum = (int *)malloc (sizeof(int));
	for (int i = 0; i < 3; ++i)
	{
		c = aux->vec[i];
		printf("%d %d\n", b ,c);
		a=(aux->m[b][i])*c ;
		printf("%d\n", aux->m[b][i]);
		*sum += a ;
		//printf("%d\n", *sum);
	}

	pthread_exit(sum);
}


int main()
{
	int v[3] = {1 , 2 , 3};
	params aux[3] ;
	aux[0].x=0 ;
	aux[0].vec=v ;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			aux[0].m[i][j]= 1 ;
			printf("%d\n" , aux[0].m[i][j]);
		}
	}

	aux[2]=aux[0];
	aux[1]=aux[0];
	aux[2].x=1;
	aux[1].x=2;


	

	pthread_t thd[3];
	int error;
	int * r;
	int resultado[3] ;

	for (int i = 0; i < 3; ++i)
	{
		error= pthread_create(&thd[i], NULL , (void *) mult , &aux[i] );
		if(error!=0)
		{
			printf("error en el create\n");
			exit(EXIT_FAILURE);
		}
		sleep(1);
		
	}

	for (int i = 0; i < 3; ++i)
	{
		error= pthread_join(thd[i],(void**) &r );
		if(error!=0)
		{
			printf("error en el join\n");
			exit(EXIT_FAILURE);
		}

		resultado[i] = *r ;
		
	}

	printf("v = %d , %d , %d \n" ,resultado[0] ,resultado[1], resultado[2]);
}