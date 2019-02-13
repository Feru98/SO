#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc , char ** argv)
{

if(argc!=2)
{
	printf("Argument required");
	exit(EXIT_FAILURE);
}

pid_t child_pid;
int status, wpid;
int n=atoi(argv[1]);


for (int i = 0; i < n; ++i)
{
	

child_pid = fork();


switch(child_pid)
{

case -1: 

    perror("fork");
    exit(EXIT_FAILURE);
break;



case 0:       /* This is the child */
    
  printf("soy el hijo %d y mi padre es %d\n",getpid() , getppid() );
 break; 


default:

		wpid = wait( &status );

		if (wpid == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }


        if (WIFEXITED(status)) {
            printf("child exited, status=%d\n", WEXITSTATUS(status));


        } else if (WIFSIGNALED(status)) {
            printf("child killed (signal %d)\n", WTERMSIG(status));


        } else if (WIFSTOPPED(status)) {
            printf("child stopped (signal %d)\n", WSTOPSIG(status));
        }


        exit(EXIT_SUCCESS); 
 }



}

 

}












