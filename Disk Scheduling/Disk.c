#include<stdio.h>
#include<stdlib.h>
void sort(int req[100],int n)
{
   for(int i=0;i<n-1;i++)
   {
      for(int j=0;j<n-i-1;j++)
      {
         if(req[j]>req[j+1])
         {
            int temp=req[j];
            req[j]=req[j+1];
            req[j+1]=temp;
         }
      }
   }
}
void fcfs(int req[100],int n,int curr)
{
   printf("FCFS\n");
   int tot=abs(curr-req[0]);
   printf("%d\t",curr);
   for(int i=0;i<n;i++)
   {
      printf("%d\t",req[i]);
   }
   for(int i=0;i<n-1;i++)
   {
      tot+=abs(req[i+1]-req[i]);
   }
   printf("\nTotal seek time %d\n",tot);
}
void sstf(int req[100],int n,int curr)
{
   printf("SSTF\n");
   printf("%d\t",curr);
   int done[100]={0},tot=0,pos;
   for(int i=0;i<n;i++)
   {
      int min=999;
      for(int j=0;j<n;j++)
      {
          if(done[j]==0)
          {
             int diff=abs(curr-req[j]);
             if(diff<min)
             {
                min=diff;
                pos=j;
             }
          }
      }
      tot+=abs(req[pos]-curr);
      curr=req[pos];
      done[pos]=1;
      printf("%d\t",curr);
   }
   printf("\nTotal seek time %d\n",tot);
}
void scan(int req[100],int n,int curr,int max)
{
   printf("SCAN\n");
   int temp1[100],temp2[100],j=0,k=0;
   for(int i=0;i<n;i++)
   {
      if(req[i]<curr)
      {
         temp1[j]=req[i];
         j++;
      }
      else if(req[i]>curr)
      {
         temp2[k]=req[i];
         k++;
      }
   }
   sort(temp1,j);
   sort(temp2,k);
   printf("%d\t",curr);
   for(int i=0;i<k;i++)
   {
      printf("%d\t",temp2[i]);
   }
   printf("%d\t",max);
   for(int i=j-1;i>=0;i--)
   {
      printf("%d\t",temp1[i]);
   }
   int tot=abs(max-curr)+abs(max-temp1[0]);
   printf("\nTotal seek time %d\n",tot);
}
void cscan(int req[100],int n,int curr,int max)
{
   printf("CSCAN\n");
   int temp1[100],temp2[100],j=0,k=0;
   for(int i=0;i<n;i++)
   {
      if(req[i]<curr)
      {
         temp1[j]=req[i];
         j++;
      }
      else if(req[i]>curr)
      {
         temp2[k]=req[i];
         k++;
      }
   }
   sort(temp1,j);
   sort(temp2,k);
   printf("%d\t",curr);
   for(int i=0;i<k;i++)
   {
      printf("%d\t",temp2[i]);
   }
   printf("%d\t",max);
   printf("%d\t",0);
   for(int i=0;i<j;i++)
   {
      printf("%d\t",temp1[i]);
   }
   int tot=abs(max-curr)+abs(max-0)+abs(0-temp1[j-1]);
   printf("\nTotal seek time %d\n",tot);
}
void look(int req[100],int n,int curr)
{
   printf("LOOK\n");
   int temp1[100],temp2[100],j=0,k=0;
   for(int i=0;i<n;i++)
   {
      if(req[i]<curr)
      {
         temp1[j]=req[i];
         j++;
      }
      else if(req[i]>curr)
      {
         temp2[k]=req[i];
         k++;
      }
   }
   sort(temp1,j);
   sort(temp2,k);
   printf("%d\t",curr);
   for(int i=0;i<k;i++)
   {
      printf("%d\t",temp2[i]);
   }
   for(int i=j-1;i>=0;i--)
   {
      printf("%d\t",temp1[i]);
   }
   int tot=abs(temp2[k-1]-curr)+abs(temp2[k-1]-temp1[0]);
   printf("\nTotal seek time %d\n",tot);
}
void clook(int req[100],int n,int curr)
{
   printf("CLOOK\n");
   int temp1[100],temp2[100],j=0,k=0;
   for(int i=0;i<n;i++)
   {
      if(req[i]<curr)
      {
         temp1[j]=req[i];
         j++;
      }
      else if(req[i]>curr)
      {
         temp2[k]=req[i];
         k++;
      }
   }
   sort(temp1,j);
   sort(temp2,k);
   printf("%d\t",curr);
   for(int i=0;i<k;i++)
   {
      printf("%d\t",temp2[i]);
   }
   for(int i=0;i<j;i++)
   {
      printf("%d\t",temp1[i]);
   }
   int tot=abs(temp2[k-1]-curr)+abs(temp2[k-1]-temp1[0])+abs(temp1[0]-temp1[j-1]);
   printf("\nTotal seek time %d\n",tot);
}
int main()
{
   int n,req[100],i,curr,max;
   printf("Enter the no of req:");
   scanf("%d",&n);
   printf("Enter the request string:");
   for(i=0;i<n;i++)
   {
      scanf("%d",&req[i]);
   }
   printf("Enter the current position of the head:");
   scanf("%d",&curr);
   printf("Enter the max track of the disk:");
   scanf("%d",&max);
   fcfs(req,n,curr);
   sstf(req,n,curr);
   scan(req,n,curr,max);
   cscan(req,n,curr,max);
   look(req,n,curr);
   clook(req,n,curr);
   return 0;
}
