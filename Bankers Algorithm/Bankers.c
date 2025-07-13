#include<stdio.h>
#include<stdlib.h>
int main()
{
   int n,m,avail[100],max[100][100],alloc[100][100],need[100][100],req[100],work[100],finish[100],i,j,proc;
   printf("Enter the no of proc:");
   scanf("%d",&n);
   printf("Enter res types:");
   scanf("%d",&m);
   for(i=0;i<n;i++)
   {
       finish[i]=0;
   }
   printf("Enter no of each res\n");
   for(i=0;i<m;i++)
   {
      scanf("%d",&avail[i]);
   }
   for(i=0;i<n;i++)
   {
      printf("Enter max res for proc %d:",i+1);
      for(j=0;j<m;j++)
      {
         scanf("%d",&max[i][j]);
      }
   }
   for(i=0;i<n;i++)
   {
      printf("Enter alloc res for proc %d:",i+1);
      for(j=0;j<m;j++)
      {
         scanf("%d",&alloc[i][j]);
      }
   }
   char ch;
   printf("Is there any req?");
   scanf(" %c",&ch);
   if(ch=='y')
   {
      printf("Enter proc req for res:");
      scanf("%d",&proc);
      printf("Enter the req\n");
      for(i=0;i<m;i++)
      {
         scanf("%d",&req[i]);
      }
      for(i=0;i<m;i++)
      {
         avail[i]-=req[i];
         alloc[proc][i]+=req[i];
      }
   }
   for(i=0;i<n;i++)
   {
      for(j=0;j<m;j++)
      {
         need[i][j]=max[i][j]-alloc[i][j];
      }
   }
   printf("MAX\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<m;j++)
      {
         printf("%d\t",max[i][j]);
      }
      printf("\n");
   }
   printf("ALLOC\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<m;j++)
      {
         printf("%d\t",alloc[i][j]);
      }
      printf("\n");
   }
   printf("NEED\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<m;j++)
      {
         printf("%d\t",need[i][j]);
      }
      printf("\n");
   }
   printf("AVAIL\n");
   for(i=0;i<m;i++)
   {
      printf("%d\t",avail[i]);
   }
   printf("\n");
   for(i=0;i<m;i++)
   {
      work[i]=avail[i];
   }
   int count=0,found=0,safe[n];
   while(count<n)
   {
       found=0;
       for(i=0;i<n;i++)
       {
          if(finish[i]==0){
          for(j=0;j<m;j++)
          {
             if(need[i][j]>work[j]) break;
          }
          if(j==m)
          {
              for(int k=0;k<m;k++)
              {
                  work[k]+=alloc[i][k];
              }
              found=1;
              safe[count++]=i;
              finish[i]=1;
          }
       }
     }
       if(found==0)  break;
   }
   if(count<n) printf("Deadlock\n");
   else
   {
      for(i=0;i<n;i++)
      {
         printf("P%d\t",safe[i]);
      }
      printf("\n");
   }
   return 0;
}
