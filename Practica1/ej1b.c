#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>


int main(int argc ,char ** argv )
{

if(argc!=2)
{
    printf("argumentos" );
    exit(EXIT_FAILURE);
}

pid_t child_pid ;
int status , wpid ;
int n=atoi(argv[1]);

printf("la n es %d\n" , n);

for(int i=0 ; i<n ; i++)
{
child_pid = fork();

if(child_pid == -1)
{      /* fork() failed */
    perror("fork");
    printf("Error = %d\n", errno );
    exit(EXIT_FAILURE);
}


else if (child_pid == 0) 
{       /* This is the child */
    /* Child does some work and then terminates */
   
    printf("Soy el hijo: %d y mi padre es: %d \n" , getpid() , getppid() );
    

} 



else
{     

               /* This is the parent */
   
    printf("Soy el padre: %d y mi hijo es: %d \n" , getpid() , child_pid );

        wpid = wait(&status );


    if (wpid > 0) 
    {


        if (WIFEXITED(status)) {
            printf("child exited, status=%d\n", WEXITSTATUS(status));


        } else if (WIFSIGNALED(status)) {
            printf("child killed (signal %d)\n", WTERMSIG(status));


        } else if (WIFSTOPPED(status)) {
            printf("child stopped (signal %d)\n", WSTOPSIG(status));

        } 
    }
    exit(EXIT_SUCCESS);
}
}
    

    // while (!WIFEXITED(status) && !WIFSIGNALED(status));
}