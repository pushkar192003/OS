#include<stdio.h>
 int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nenter the brust time\n");
    for(i=0;i<n;i++){
    	printf("p[%d]:",i+1);
    	scanf("%d",&bt[i]);
        p[i]=i+1;
    	}
  
   //sorting of burst times
    for(i=0;i<n;i++)
    {
        
        for(j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1]){
            
        temp=bt[j];
        bt[j]=bt[j+1];
        bt[j+1]=temp;
  
  
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
    
    
   
            }
        }

    }
    wt[0]=0;            
  
   
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

          
  
        total+=wt[i];
    }
  
    avg_wt=(float)total/n;      
    total=0;
  
    printf("\nProcess    bursttime	wt	tat     completion time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        printf("\np[%d]\t    %d\t\t %d\t %d\t %d",p[i],bt[i],wt[i],tat[i],(tat[i]));
    }
  	
    avg_tat=(float)total/n;    
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}