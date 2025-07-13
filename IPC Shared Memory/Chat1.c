#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/types.h>
struct sh
{
   int turn,exit;
   char msg[128];
};
int main()
{
   int fd=shm_open("/SHARED",O_CREAT|O_RDWR,0644);
   if(fd==-1) return 1;
   int fret=ftruncate(fd,sizeof(struct sh));
   if(fret==-1) return 1;
   struct sh* s=(struct sh*)mmap(NULL,sizeof(struct sh),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
   if(s==MAP_FAILED) return 1;
   //printf("Success!\n");
   if(s->turn!=1||s->turn!=2)
   {
      s->turn=1;
   }
   while(1)
   {
      if(s->turn==-1)
      {
         printf("Chat1 is exiting!\n");
         break;
      }
      while(s->turn==2)
      {
         usleep(100);
      }
      if(strlen(s->msg)>0)
      {
         printf("Chat 2:%s\n",s->msg);
         memset(s->msg,0,sizeof(s->msg));
      }
      printf("Chat 1:");
      fgets(s->msg,sizeof(s->msg),stdin);
      s->msg[strcspn(s->msg,"\n")]='\0';
      if(strcmp(s->msg,"q")==0)
      {
         s->turn=-1;
         break;
      }
      s->turn=2;
   }
   munmap(s,sizeof(struct sh));
   shm_unlink("/SHARED");
   close(fd);
}

