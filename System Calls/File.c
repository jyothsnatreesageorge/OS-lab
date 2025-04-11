#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
        char filename[100],content[100];
        int s;
        printf("Enter the filename:");
        scanf("%s",filename);
        getchar();
        int fd=open(filename,O_CREAT|O_RDWR,0644);
        if(fd==-1)
        {
                printf("Error in opening the file!");
                exit(1);
        }
        else
        {
                //printf("File Descriptor :%d\n",fd);
                printf("Enter the content to be written into the file:");
                scanf("%[^\n]%*c",content);
                int len=strlen(content);
                s=write(fd,content,len);
                close(fd);
                int fd2=open(filename,O_RDONLY);
                if(fd2==-1)
                {
                        printf("Error in opening the file!");
                        exit(1);
                }
                else
                {
                        char buffer[100];
                        int s1;
                        s1=read(fd2,buffer,len);
                        buffer[len]='\0';
                        printf("The contents of the file are\n\n%s",buffer);
                        close(fd2);
                }
        }
        return 0;
}

