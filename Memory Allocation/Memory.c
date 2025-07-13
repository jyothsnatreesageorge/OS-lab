#include<stdio.h>
#include<stdlib.h>
int f1,f2,f3;
void copy(int a[100][2],int b[100][2],int x)
{
   for(int i=0;i<x;i++)
   {
      b[i][0]=a[i][0];
      b[i][1]=a[i][1];
   }
}
void print(int part[100][2],int proc[100][2],int c[100][2],int m,int n)
{
   int i,j;
   printf("Process\nSize\tAlloc\n");
   for(i=0;i<n;i++)
   {
      printf("%d\t%s\n",proc[i][0],(proc[i][1])?"Yes":"No");
   }
   printf("Partition\nSize\tUsed\n");
   for(i=0;i<m;i++)
   {
      printf("%d\t%s\n",part[i][0],(part[i][1])?"Yes":"No");
   }
   printf("Fragmentation\nPart\tUsed\tRem\n");
   for(i=0;i<m;i++)
   {
      printf("%d\t%d\t%d\n",part[i][0],part[i][0]-c[i][0],c[i][0]);
   }
}
int alloc(int part[100][2],int proc[100][2],int m,int n)
{
   int i,j,c[100][2];
   for(i=0;i<m;i++)
   {
      c[i][0]=part[i][0];
   }
   for(i=0;i<m;i++)
   {
      for(j=0;j<n;j++)
      {
         if(proc[j][0]<=part[i][0]&&part[i][1]==0&&proc[j][1]==0)
         {
            c[i][0]=c[i][0]-proc[j][0];
            part[i][1]=1;
            proc[j][1]=1;
            //c[i][0]=c[i][0]-proc[j][0];
            break;
         }
      }
   }
   print(part,proc,c,m,n);
   int in=0,ex=0;
   for(i=0;i<m;i++)
   {
      if(part[i][1]==0)
      {
         ex+=part[i][0];
      }
      else if(c[i][0]<part[i][0])
      {
         in+=c[i][0];
      }
   }
   printf("Total Int frag:%d\nTotal Ext frag:%d\n",in,ex);
   int tot=in+ex;
   return tot;
}
void ff(int part[100][2],int proc[100][2],int m,int n)
{
   printf("\nFIRST FIT\n");
   f1=alloc(part,proc,m,n);
}
void bf(int part[100][2],int proc[100][2],int m,int n)
{
   for(int i=0;i<m-1;i++)
   {
      for(int j=0;j<m-i-1;j++)
      {
         if(part[j][0]>part[j+1][0])
         {
            int temp=part[j][0];
            part[j][0]=part[j+1][0];
            part[j+1][0]=temp;
            temp=part[j][1];
            part[j][1]=part[j+1][1];
            part[j+1][1]=temp;
         }
      }
   }
   printf("\nBEST FIT\n");
   f2=alloc(part,proc,m,n);
}
void wf(int part[100][2],int proc[100][2],int m,int n)
{
   for(int i=0;i<m-1;i++)
   {
      for(int j=0;j<m-i-1;j++)
      {
         if(part[j][0]<part[j+1][0])
         {
            int temp=part[j][0];
            part[j][0]=part[j+1][0];
            part[j+1][0]=temp;
            temp=part[j][1];
            part[j][1]=part[j+1][1];
            part[j+1][1]=temp;
         }
      }
   }
   printf("\nWORST FIT\n");
   f3=alloc(part,proc,m,n);
}
int main()
{
   int proc[100][2],part[100][2],m,n,i,temp1[100][2],temp2[100][2];
   printf("Enter the no of proc:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("Enter proc %d:",i+1);
      scanf("%d",&proc[i][0]);
      proc[i][1]=0;
   }
   printf("Enter the no of part:");
   scanf("%d",&m);
   for(i=0;i<m;i++)
   {
      printf("Enter part %d:",i+1);
      scanf("%d",&part[i][0]);
      part[i][1]=0;
   }
   copy(part,temp1,m);
   copy(proc,temp2,n);
   ff(temp1,temp2,m,n);
   copy(part,temp1,m);
   copy(proc,temp2,n);
   bf(temp1,temp2,m,n);
   copy(part,temp1,m);
   copy(proc,temp2,n);
   wf(temp1,temp2,m,n);
   int min=f1;
   if(f2<min) min=f2;
   else if(f3<min) min=f3;
   if(f1==min&&f2==min&&f3==min) printf("All algos are equally good\n");
   else if(f1==min&&f2==min) printf("First fit and Best Fit are equally good\n");
   else if(f2==min&&f3==min) printf("Best fit and worst fit are equally good\n");
   else if(f1==min&&f3==min) printf("First fit and worst fit are equally good\n");
   else if(f1==min) printf("First fit is the best\n");
   else if(f2==min) printf("Best fit is the best\n");
   else if(f3==min) printf("Worst fit is the best\n");
   return 0;
}
