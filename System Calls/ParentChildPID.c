#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    pid_t p=fork();
    if(p<0)
    {
        printf("Fork failed!");
        exit(0);
    }
    if(p==0)
    {
      pid_t pp=getppid();
      printf("The parent process ID is %d\n",pp);
      pid_t cp=getpid();
      printf("The Child process ID is %d\n",cp);
    }
    else
    {
        pid_t cp=wait(NULL);
        printf("The ID of the child process is %d\n",cp);
    }
    return 0;
}
