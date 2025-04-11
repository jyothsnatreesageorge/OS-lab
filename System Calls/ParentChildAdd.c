#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() 
{
    pid_t p = fork();
    if (p < 0) 
    {
        printf("Fork failed!\n");
        exit(1);
    } 
    else if (p == 0) 
    {
        // Child process
        printf("In child process:\n");
        execlp("./ADD","./ADD",NULL);
    } else 
    {
        // Parent process
        wait(NULL); // Parent waits for the child to finish
        printf("In parent process:\n");
    }
    return 0;
}
