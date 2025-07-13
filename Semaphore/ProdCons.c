#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define size 50
int q[size],r=-1,f=-1,b_sem=1,empty=size,full=0;
void wait1(int* sem)
{
   while((*sem)<=0);
   (*sem)--;
}
void signal1(int* sem)
{
   (*sem)++;
}
void enqueue(int item)
{
   if(f==-1)
   {
      f=0;
   }
   r=(r+1)%size;
   q[r]=item;
}
int dequeue()
{
   int item=q[f];
   f=(f+1)%size;
   if(f==((r+1)%size))
   {
      f=r=-1;
   }
   return item;
}
void* Prod(void* args)
{
   int max=*((int*)args);
   int i=0;
   while(i<max)
   {
      wait1(&empty);
      wait1(&b_sem);
      i++;
      printf("Produced:%d\n",i);
      enqueue(i);
      signal1(&b_sem);
      signal1(&full);
   }
   return NULL;
}
void* Cons(void* args)
{
   int max=*((int*)args);
   while(1)
   {
      wait1(&full);
      wait1(&b_sem);
      int item=dequeue();
      printf("Consumed:%d\n",item);
      signal1(&b_sem);
      signal1(&empty);
      if(item==max) break;
   }
   return NULL;
}
int main()
{
   pthread_t prod,cons;
   int max;
   printf("Enter the number of items to be produced:");
   scanf("%d",&max);
   pthread_create(&prod,NULL,Prod,&max);
   pthread_create(&cons,NULL,Cons,&max);
   pthread_join(prod,NULL);
   pthread_join(cons,NULL);
   return 0;
}

