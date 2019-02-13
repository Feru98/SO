
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


void * imprimir(char * cad)
{
	//int i=0;
	for(int i=0 ; i<strlen(cad) ; i++)
	{
		printf("%c-", cad[i] );
		//sleep(1);
		//i++;
	}

	pthread_exit(NULL);
}


int main()
{
	pthread_t thd1 , thd2;

	char c1[]="hola";
	char c2[]="mundo";



	pthread_create(&thd1, NULL, (void *)imprimir ,  &c1 );
	pthread_create(&thd2, NULL, (void *)imprimir ,  &c2 );

	pthread_join(thd1, NULL);
	pthread_join(thd2, NULL);

	exit(EXIT_SUCCESS);
}