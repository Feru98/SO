#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>



int main(int argc , char ** argv)
{


pid_t child_pid ;
int status , wpid ;
FILE * f;

f=fopen(argv[1], "w");


child_pid = fork();

if (child_pid == -1) {      /* fork() failed */
    perror("fork");
    exit(EXIT_FAILURE);
}


if (child_pid == 0) {       /* This is the child */
    printf("soy el hijo \n");
    fprintf(f, "%s\n", "------" );

    exit(EXIT_SUCCESS);
}

else {                    /* This is the parent */
        
        sleep(1);
        fprintf(f, "%s\n", "++++++" );
        wpid = wait( &status);

      
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

            fclose(f);
            exit(EXIT_SUCCESS);
       
        }

}
}