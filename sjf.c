#include<stdio.h>  
 #include<string.h>  
 int main(void)  
 {  
 //VARIABLE DECLARATION  
   char pn[20][20], c[20][20]; //PN-PROGRAM NAMES C-A TEMPORARY ARRAY  
      int n,i,j,at[20], bt[20], wt[20],ct[20],tat[20]; //bt-BURST TIME ; wt-WAITING TIME; tat-TURN AROUND TIME  
      int temp1, temp2, count=0,twt=0,ttat=0;
      printf("Enter number of processes:");  
      scanf("%d", &n);  
      printf("Enter PN, AT, BT:\n");  
 //TAKING INPUT VALUES i.e., PROCESS-NAMES, ARRIVAL-TIMES AND BURST-TIMES  
      for(i=0; i<n; i++)  
           scanf("%s%d%d",&pn[i],&at[i],&bt[i]);  
 //SCHEDULING THE PROCESSES ACCORDING TO SJF  
   for(i=0 ; i<n; i++)  
   {  
           for(j=i+1; j<n; j++)  
  if ( ( (i==0||count<1)&&(at[i]>at[j]||(at[i]==at[j]&&bt[i]>bt[j])) )  
                ||      (count == 1 && ct[i-1]>=at[j])  
         //IF WE GOT MORE THAN ONE PROCESS IN MAIN MEMORY, SORT THEM BY BURST TIMES  
                ||      ((ct[i-1]>=at[j]&&bt[i]>bt[j])) //|| (ct[i-1]<at[i]&&ct[i-1]>=at[j]))  
                  )  
                     //SWAPPING PROCESSES  
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
     if(i==0 || count<1)  
       ct[i] = at[i] + bt[i];  
     else  
       ct[i] = ct[i-1] + bt[i];  
       
     wt[i] = ct[i] - (at[i] + bt[i]);  
     tat[i] = ct[i] - at[i];  
     count = 0 ;  
     for(j=i+1; j<n; j++)  
       if(ct[i]>=at[j])  
         count++;  
   }  
 //PRINTING THE VALUES AFTER ALL PREOCESSES COMPLETED  
      printf("S.N.\tProcess-Name\tArrival-Time\tBurst-Time\tCT\tWT\tTAT\n");  
      for(i=0; i<n; i++)  
           printf("%d\t\t%s\t\t%d\t\t%d\t%d\t%d\t%d\n",(i+1),pn[i],at[i],bt[i],ct[i],wt[i],tat[i]);  
 for(i=0;i<n;i++)
 {
     twt+=wt[i];
     ttat+=tat[i];
 }
printf("Total waiting time:%d\n", twt);  
      printf("Total Turn Around Time:%d\n", ttat);  
      printf("avg waiting time:%d\n",twt/n);
      printf("avg turnaround time:%d\n",ttat/n);

 } 



