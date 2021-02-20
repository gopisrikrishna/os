#include<stdio.h>  
 #include<string.h>  
 int main(void)  
 {  
   //VARIABLE DECLARATION  
   char pn[20][20], c[20][20]; //PN-PROGRAM NAMES  
   int n,i,j,at[20], bt[20], wt[20],tat[20], ct[20]; //bt-BURST TIME ; wt-WAITING TIME; tat-TURN AROUND TIME  
   int twt=0, ttat=0, temp1, temp2;  
   printf("Enter number of processes:");  
   scanf("%d", &n);  
 //TAKING INPUT VALUES i.e., PROCESS-NAMES, ARRIVAL-TIMES AND BURST-TIMES  
 printf("Enter <Process-name> <Arrival-time> <Burst-time> for processes:\n", (i+1));  
   for(i=0; i<n; i++)  
       scanf("%s%d%d",&pn[i],&at[i],&bt[i]);  
 //SORT THE PROCESSES ACCORDING TO ARRIVAL TIMES  
  for(i=0;i<n;i++)  
  {  
      for(j=i+1; j<n;j++)  
      {  
           if(at[i]>at[j])  
           {  
                temp1 = bt[i];  
                temp2 = at[i];  
                bt[i] = bt[j];  
                at[i] = at[j];  
                bt[j] = temp1;  
                at[j] = temp2;  
                strcpy(c[i],pn[i]);  
                strcpy(pn[i],pn[j]);  
                strcpy(pn[j],c[i]);  
           }  
      }  
      if(i==0) 
      ct[0]=at[0]+bt[0];  
      if(i>0)  
      {  
     if(at[i]>ct[i-1])  
                ct[i]=at[i]+bt[i];  
           else  
                ct[i]=ct[i-1]+bt[i];  
      }  
  }  
 //CALCULATING WAITING TIME & TAT  
 wt[0]=0;  
 tat[0]=ct[0]-at[0];  
 for(i=1;i<n;i++)  
 {  
      tat[i] = ct[i]-at[i];  
      wt[i] = tat[i]-bt[i];  
      twt += wt[i];  
      ttat += tat[i];  
 }  
 //PRINTING THE VALUES AFTER ALL PREOCESSES COMPLETED  
      printf("S.N.\tPN\tAT\tBT\tCT\tWT\tTAT\n");  
      for(i=0; i<n; i++)  
           printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",(i+1),pn[i],at[i],bt[i],ct[i],wt[i],tat[i]);  
      printf("Total waiting time:%d\n", twt);  
      printf("Total Turn Around Time:%d", ttat);  
 }  

