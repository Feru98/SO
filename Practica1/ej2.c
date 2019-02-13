#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int main()
{



pid_t hijo1,hijo2,nieto1,nieto2,bisnieto;
int status, wpid;


	

hijo1 = fork();

if(hijo1==-1){

    perror("fork");
    exit(EXIT_FAILURE);
}


else if(hijo1==0){      /* This is the child */
    
  printf("soy el hijo %d y mi padre es %d\n",getpid() , getppid() );
  exit(EXIT_SUCCESS);
}

else{

    hijo2=fork();

    if(hijo2==-1){

    perror("fork");
    exit(EXIT_FAILURE);
    }


    else if(hijo2==0){      /* This is the child */
    
    //printf("soy el hijo %d y mi padre es %d\n",getpid() , getppid() );

            nieto1=fork();

            if(nieto1==-1){

            perror("fork");
            exit(EXIT_FAILURE);
            }


            else if(nieto1==0){      /* This is the child */
    
             printf("soy el hijo %d y mi padre es %d\n",getpid() , getppid() );
             exit(EXIT_SUCCESS);
            }

            else{

                        nieto2=fork();
                        if(nieto2==-1){

                        perror("fork");
                        exit(EXIT_FAILURE);
                        }


                        else if(nieto2==0){      /* This is the child */
                        

                                bisnieto=fork();

                                if(bisnieto==-1){

                                perror("fork");
                                exit(EXIT_FAILURE);
                                }

                                else if(bisnieto==0){      /* This is the child */
    
                                printf("soy el hijo %d y mi padre es %d\n",getpid() , getppid() );
                                exit(EXIT_SUCCESS);
                                }


                        sleep(2);
                        printf("soy el hijo %d y mi padre es %d\n",getpid() , getppid() );
                        exit(EXIT_SUCCESS);
                        }

                        else{
                            sleep(5);
                            printf("soy el hijo %d y mi padre es %d\n",getpid() , getppid() );
                            exit(EXIT_SUCCESS);
                        }


            }
     
    }
    sleep(7);
    printf("soy el padre %d\n", getpid());
        /*
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
        */


}
 



 exit(EXIT_SUCCESS);

}












