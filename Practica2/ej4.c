#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void * count(char ** file)
{
	FILE * f;
	char  aux[100];
	f=fopen(*file , "r");

	int * a=(int *)malloc(sizeof(int));
	*a = 0;

	while(fgets(aux , 100 , f)!=NULL)
	{
		//printf("hola\n");
		*a=(*a)+1;
	}

	//printf("%d\n", *a);
	pthread_exit(a);
}



int main(int argc , char ** argv)
{
	if(argc < 2 )
	{
		printf("faltan argumentos\n");
		exit(EXIT_FAILURE);
	}

	int N = argc -1 ;
	int error;
	int * sum;
	int resultado= 0;

	pthread_t thd[N];

	for (int i = 0; i < N ; ++i)
	{
		error=pthread_create(&thd[i], NULL , (void *) count , &argv[i+1]);
		if(error!=0)
		{
			printf("error en el create\n");
			exit(EXIT_FAILURE);
		}
	}


	for (int i = 0; i < N; ++i)
	{
		error=pthread_join(thd[i],(void **) &sum);
		if(error!=0)
		{
			printf("error en el create\n");
			exit(EXIT_FAILURE);
		}

		resultado += *sum ;
	}

	printf("result : %d\n", resultado );
}