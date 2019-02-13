#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>


void abrecalculadora(char * nombre)
{
    printf("Abriendo calculadora\n");
    execlp(nombre , nombre , NULL);
    exit(0);
}

void abregedit(char * nombre ,char ** puntero )
{
    printf("Abriendo txt\n");
    execvp(nombre , puntero);
    exit(0);
}




int main(int argc , char ** argv)
{

if (argc<3)
{
    printf("Faltan argumentos\n");
    exit(EXIT_FAILURE);
}

pid_t child_pid; 
int status, wpid;

for(int i = 0 ; i<2 ; i++)
{


    child_pid = fork();

    if (child_pid == -1)
        {      /* fork() failed */
        perror("fork");
        exit(EXIT_FAILURE);
        }


    if (child_pid == 0 && i==0)
    {       /* This is the child */
        abrecalculadora(argv[1]);
        exit(EXIT_SUCCESS);

    } 

    if (child_pid == 0 && i==1)
    {       /* This is the child */
        abregedit(argv[2], &argv[2]);
        exit(EXIT_SUCCESS);

    } 


}


          for(int i = 0 ; i<2 ; i++)
          {              /* This is the parent */
    
        wpid = wait(&status);


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

   }



        



exit(EXIT_SUCCESS);

}