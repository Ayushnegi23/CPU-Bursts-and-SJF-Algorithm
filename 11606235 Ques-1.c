#include<stdio.h>
#include<stdlib.h>
 int main()
{
      int temp,i,j,lim, sm=0,pos;
      float avgwt, avgtt;
      int bt[20], pro[20], wt[20], tt[20];
      printf("\nEnter the Total Number of Processes you wounld like to enter:\t");
      scanf("%d", &lim); 
      for(i=0;i<limit;i++)
      {
            printf("Enter the Burst Time For the Process[%d]:\t", i+1);
            scanf("%d", &bt[i]);
            pro[i]=i+1;
      }
      for(i=0;i<lim;i++)
      {
            pos=i;
            for(j=i+1;j<lim;j++)
            {
                  if(bt[j]<bt[pos])
                  {
                        pos=j;
                  }
            }
            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;
            temp=pro[i];
            pro[i]=pro[pos];
            pro[pos]=temp;
      } 
      wt[0]=0;
      for(i=1;i<lim;i++)
      {
            wt[i]=0;
            for(j=0;j<i;j++)
            {
                  wt[i]=wt[i]+bt[j];
            } 
            sm=sm+wt[i];
      }
      avgwt=(float)sm/lim;
      sm=0;
      printf("\nProcess ID is\t\tBurst Timeis\t Waiting Timeis\t\nTurnaround Time is\t\n");
      for(i=0;i<lim;i++)
      {
            tt[i]= bt[i] +wt[i];
            sm=sm+tt[i];
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n",pro[i], bt[i],wt[i],tt[i]);
      }
      avgtt=(float)sm/lim;
      printf("\nAverage Waiting Time is:\t%f\n",avgwt);
      printf("\nAverage Turnaround Time is:\t%f\n",avgtt);
      return 0;
}
