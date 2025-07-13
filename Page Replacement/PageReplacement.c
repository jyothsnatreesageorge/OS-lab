#include<stdio.h>
#include<stdlib.h>
void reset(int fra[100],int m)
{
   for(int i=0;i<100;i++)
   {
      fra[i]=-1;
   }
}
void display(int fra[100],int m)
{
   for(int i=0;i<m;i++)
   {
      if(fra[i]==-1)
      {
         printf("-\t");
      }
      else
      {
         printf("%d\t",fra[i]);
      }
   }
   printf("\n");
}
void fifo(int ref[100],int fra[100],int m,int n)
{
   int f=0,r=0,found,hit=0,miss=0;
   for(int i=0;i<n;i++)
   {
      found=0;
      for(int j=0;j<m;j++)
      {
         if(ref[i]==fra[j])
         {
            found=1;
            hit++;
            break;
         }
      }
      if(found==0)
      {
         miss++;
         if(r<m)
         {
            fra[r]=ref[i];
            r=(r+1)%m;
            display(fra,m);
         }
         else
         {
            fra[f]=ref[i];
            f=(f+1)%m;
            display(fra,m);
         }
      }
   }
   printf("No of page hits:%d\n",hit);
   printf("No of page miss:%d\n",miss);
}
void lru(int ref[100],int fra[100],int m,int n)
{
   int found=0,r=0,i,j,hit=0,miss=0,time[100],track[m],curr=0,min,ind=0;
   for(i=0;i<100;i++)
   {
      time[i]=0;
   }
   for(i=0;i<m;i++)
   {
      track[i]=-1;
   }
   for(i=0;i<n;i++)
   {
      found=0;
      for(j=0;j<m;j++)
      {
         if(ref[i]==fra[j])
         {
            hit++;
            found=1;
            curr++;
            time[ref[i]]=curr;
            break;
         }
      }
      if(found==0)
      {
         miss++;
         if(r<m)
         {
            curr++;
            fra[r]=ref[i];
            track[r]=ref[i];
            time[track[r]]=curr;
            r++;
            display(fra,m);
         }
         else
         {
            min=time[track[0]];
            for(int k=0;k<m;k++)
            {
               if(time[track[k]]<min)
               {
                  min=time[track[k]];
                  ind=k;
               }
            }
            curr++;
            fra[ind]=ref[i];
            track[ind]=ref[i];
            time[track[ind]]=curr;
            display(fra,m);
         }
      }
   }
   printf("No of page hits:%d\n",hit);
   printf("No of page miss:%d\n",miss);
}
void lfu(int ref[100],int fra[100],int m,int n)
{
   int r=0,i,j,k,l,ind=0,time[100],track[m],curr=0,hit=0,miss=0,found=0,count[100];
   for(i=0;i<100;i++)
   {
      time[i]=0;
      count[i]=0;
   }
   for(i=0;i<m;i++)
   {
      track[i]=-1;
   }
   for(i=0;i<n;i++)
   {
      found=0;
      for(j=0;j<m;j++)
      {
         if(ref[i]==fra[j])
         {
            hit++;
            //curr++;
            //time[ref[i]]=curr;
            //track[l++]=ref[i];
            count[ref[i]]++;
            found=1;
            break;
         }
      }
      if(found==0)
      {
         miss++;
         if(r<m)
         {
            curr++;
            fra[r]=ref[i];
            track[r]=ref[i];
            time[track[r]]=curr;
            count[track[r]]++;
            r++;
            display(fra,m);
         }
         else
         {
            //int min=0;
            for(int k=0;k<m;k++)
            {
               if((count[track[k]]<count[track[ind]])||(count[track[k]]==count[track[ind]]&&time[track[k]]<time[track[ind]]))
               {
                 //min=count[k];
                 ind=k;
               }
            }
            curr++;
            fra[ind]=ref[i];
            count[ref[i]]++;
            track[ind]=ref[i];
            time[track[ind]]=curr;
            display(fra,m);
         }
      }
   }
   printf("No of page hits:%d\n",hit);
   printf("No of page miss:%d\n",miss);
}
void mfu(int ref[100],int fra[100],int m,int n)
{
   int r=0,i,j,k,l,ind=0,time[100],track[m],curr=0,hit=0,miss=0,found=0,count[100];
   for(i=0;i<100;i++)
   {
      time[i]=0;
      count[i]=0;
   }
   for(i=0;i<m;i++)
   {
      track[i]=-1;
   }
   for(i=0;i<n;i++)
   {
      found=0;
      for(j=0;j<m;j++)
      {
         if(ref[i]==fra[j])
         {
            hit++;
            //curr++;
            //time[ref[i]]=curr;
            //track[l++]=ref[i];
            count[ref[i]]++;
            found=1;
            break;
         }
      }
      if(found==0)
      {
         miss++;
         if(r<m)
         {
            curr++;
            fra[r]=ref[i];
            track[r]=ref[i];
            time[track[r]]=curr;
            count[track[r]]++;
            r++;
            display(fra,m);
         }
         else
         {
            //int min=0;
            for(int k=0;k<m;k++)
            {
               if((count[track[k]]>count[track[ind]])||(count[track[k]]==count[track[ind]]&&time[track[k]]<time[track[ind]]))
               {
                 //min=count[k];
                 ind=k;
               }
            }
            curr++;
            fra[ind]=ref[i];
            count[ref[i]]++;
            track[ind]=ref[i];
            time[track[ind]]=curr;
            display(fra,m);
         }
      }
   }
   printf("No of page hits:%d\n",hit);
   printf("No of page miss:%d\n",miss);
}
int main()
{
   int ref[100],fra[100],m,n,i;
   printf("Enter the no of pages:");
   scanf("%d",&n);
   printf("Enter the ref string:");
   for(i=0;i<n;i++)
   {
      scanf("%d",&ref[i]);
   }
   printf("Enter the no of frames:");
   scanf("%d",&m);
   reset(fra,m);
   fifo(ref,fra,m,n);
   reset(fra,m);
   lru(ref,fra,m,n);
   reset(fra,m);
   lfu(ref,fra,m,n);
   reset(fra,m);
   mfu(ref,fra,m,n);
   return 0;
}
