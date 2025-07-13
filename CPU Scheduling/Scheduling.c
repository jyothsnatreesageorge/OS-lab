#include<stdio.h>
#include<stdlib.h>
struct proc
{
   int pid,at,bt,pr,ct,rt,wt,tt,flag,rem,stat;
}p[50],temp[50],q[50];
void print(struct proc p[],int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      p[i].tt=p[i].ct-p[i].at;
      p[i].wt=p[i].tt-p[i].bt;
   }
   printf("PID\tAT\tBT\tPrio\tCT\tRT\tWt\tTT\n");
   for(i=0;i<n;i++)
   {
      printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].rt,p[i].wt,p[i].tt);
   }
}
void rr(struct proc p[],int n,int t)
{
   printf("Round Robin");
   int i,j,completed=0,curr=0,vis[n],queue[100],f=0,r=0;
   for(i=0;i<n;i++)
   {
      p[i].rem=p[i].bt;
      p[i].flag=0;
      vis[i]=0;
   }
   for(i=0;i<n-1;i++)
   {
      for(j=0;j<n-i-1;j++)
      {
         if(p[j].at>p[j+1].at)
         {
            struct proc temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
         }
      }
   }
   printf("St\tPID\tEt\n");
   while(completed!=n)
   {
      for(i=0;i<n;i++)
      {
         if(p[i].at<=curr&&vis[i]==0&&p[i].rem>0)
         {
            queue[r++]=i;
            vis[i]=1;
         }
      }
      if(f==r)
      {
         curr++;
        continue;
      }
      int ind=queue[f++];
            if(p[ind].flag==0&&p[ind].rem==p[ind].bt)
            {
               p[ind].rt=curr-p[ind].at;
               p[ind].flag=1;
            }
            int st=curr;
            if(p[ind].rem<=t)
            {
               curr+=p[ind].rem;
               p[ind].rem=0;
               p[ind].ct=curr;
               completed++;
            }
            else
            {
               p[ind].rem-=t;
               curr+=t;
            }
            int et=curr;
            printf("%d\t%d\t%d\n",st,p[ind].pid,et);
      for(i=0;i<n;i++)
      {
         if(p[i].at<=curr&&vis[i]==0&&p[i].rem>0)
         {
            queue[r++]=i;
            vis[i]=1;
         }

     }
            if(p[ind].rem>0)
            {
               queue[r++]=ind;
            }
   }
   print(p,n);
}
void fcfs(struct proc p[],int n)
{
   printf("FCFS\n");
    int i,j;
    for(i=0;i<n-1;i++)
   {
      for(j=0;j<n-i-1;j++)
      {
         if(p[j].at>p[j+1].at)
         {
            struct proc temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
         }
      }
   }
   int st,en;
   for(i=0;i<n;i++)
   {
      if(i==0)
      {
         p[i].rt=0;
         p[i].ct=p[i].bt;
         st=0;
         en=p[i].ct;
      }
      else
      {
         p[i].rt=p[i-1].ct-p[i].at;
         p[i].ct=p[i-1].ct+p[i].bt;
         st=p[i-1].ct;
         en=st+p[i].bt;
      }
      printf("%d\t%d\t%d\n",st,p[i].pid,en);
    }
   print(p,n);
}
void sjf(struct proc p[],int n)
{
   printf("SJF\n");
   int tot,i,j,k=0,completed=0,curr=0,min,ind=-1;
   for(i=0;i<n-1;i++)
   {
      for(j=0;j<n-i-1;j++)
      {
         if((p[j].at>p[j+1].at)||(p[j].at==p[j+1].at&&p[j].bt>p[j+1].bt))
         {
            struct proc temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
         }
      }
   }
   for(i=0;i<n;i++)
   {
      p[i].stat=0;
      tot+=p[i].bt;
   }
   while(completed!=n)
   {
      min=tot;
      for(i=0;i<n;i++)
      {
         if(p[i].at<=curr&&p[i].stat==0)
         {
             if(p[i].bt<min)
             {
                min=p[i].bt;
                ind=i;
             }
             else if(p[i].bt==min&&p[i].at<p[ind].at)
             {
               min=p[i].bt;
               ind=i;
             }
         }
      }
      int st,en;
      if(ind==-1)
      {
         curr++;
      }
      else
      {
         st=curr;
         q[k]=p[ind];
         curr+=p[ind].bt;
         p[ind].stat=1;
         completed++;
         en=curr;
      }
      printf("%d\t%d\t%d\n",st,q[k++].pid,en);
   }
   for(i=0;i<n;i++)
   {
      if(i==0)
      {
         q[i].rt=0;
         q[i].ct=q[i].bt;
      }
      else
      {
         q[i].rt=q[i-1].ct-q[i].at;
         q[i].ct=q[i-1].ct+q[i].bt;
      }
   }
   print(q,n);
}
void priority(struct proc p[],int n)
{
   printf("Priority\n");
   int i,j,k=0,curr=0,completed=0,tot,ind=-1,min;
   for(i=0;i<n-1;i++)
   {
      for(j=0;j<n-i-1;j++)
      {
         if((p[j].at>p[j+1].at)||(p[j].at==p[j+1].at&&p[j].bt>p[j+1].bt))
         {
            struct proc temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
         }
      }
   }
   for(i=0;i<n;i++)
   {
      p[i].stat=0;
      tot+=p[i].pr;
   }
   while(completed!=n)
   {
      min=tot;
      for(i=0;i<n;i++)
      {
         if(p[i].at<=curr&&p[i].stat==0)
         {
            if(p[i].pr<min)
            {
               min=p[i].pr;
               ind=i;
            }
            else if(min=p[i].pr&&p[i].at<p[ind].at)
            {
               min=p[i].pr;
               ind=i;
            }
         }
      }
      int st,en;
      if(ind==-1)
      {
         curr++;
      }
      else
      {
         st=curr;
         q[k++]=p[ind];
         curr+=p[ind].bt;
         p[ind].stat=1;
         completed++;
         en=curr;
      }
      printf("%d\t%d\t%d\n",st,p[ind].pid,en);
   }
   for(i=0;i<n;i++)
   {
      if(i==0)
      {
         q[i].rt=0;
         q[i].ct=q[i].bt;
      }
      else
      {
         q[i].rt=q[i-1].ct-q[i].at;
         q[i].ct=q[i-1].ct+q[i].bt;
      }
   }
   print(q,n);
}
void copy(struct proc p[],struct proc temp[],int n)
{
   for(int i=0;i<n;i++)
   {
      temp[i]=p[i];
   }
}
int main()
{
   int n,i,t;
   printf("Enter the number of process:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("Enter the PID,AT,BT,Priority:");
      scanf("%d %d %d %d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].pr);
   }
   printf("Enter the time quantum:");
   scanf("%d",&t);
   copy(p,temp,n);
   fcfs(p,n);
   copy(p,temp,n);
   sjf(p,n);
   copy(p,temp,n);
   priority(temp,n);
   copy(p,temp,n);
   rr(temp,n,t);
   return 0;
}
