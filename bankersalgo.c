#include<stdio.h>
#define MAX 25 
int alloc[MAX][MAX],claim[MAX][MAX],resource[MAX],avail[MAX],request[MAX][MAX],need[MAX][MAX],m,n; 
int turn,flag,count=0; 
int finish[10]; 
void main() 
{ 
int i,j,k,temp=0,time=0; 
char ch; 
printf("enter no processes"); 
scanf("%d",&m); 
printf("enter no of resources"); 
scanf("%d",&n); 
printf("\nenter resourse vector\n"); 
for(i=0;i<n;i++) 
scanf("%d",&resource[i]); 
printf("\n enter claim matrix\n"); 
for(i=0;i<m;i++) 
for(j=0;j<n;j++) 
{ 
scanf("%d",&claim[i][j]); 
if(claim[i][j]>resource[j] && time==0) 
{ 
printf("Enter claim for this again\n"); 
i--; 
time=1; 
} 
} 
label: time=0; 
printf("\nenter alocation matrix\n"); 
for(i=0;i<m;i++) 
for(j=0;j<n;j++) 
{ 
scanf("%d",&alloc[i][j]); 
if(alloc[i][j]>claim[i][j] && time==0) 
{ 
printf("Enter allocation of resources for this again\n"); 
i--;time=1; 
} 
need[i][j]=claim[i][j]-alloc[i][j]; 
} 
for(i=0;i<n;i++) 
{ 
for(j=0;j<m;j++) 
temp=temp+alloc[j][i]; 
avail[i]=resource[i]-temp; 
temp=0; 
} 
for(j=0;j<n;j++) 
{ 
if(avail[j]<0) 
{ 
printf("resource allocation exceeds no.of resources:\n"); 
goto label; 
} 
printf("avail[%d]=%d",j,avail[j]); 
} 
for(j=0;j<m;j++) 
finish[j]=-1; 
printf("\n****initial state****\n"); 
do{ 
turn++; 
for(i=0;i<m;i++) 
{ 
flag=0; 
for(j=0;j<n;j++) 
{ 
if((finish[i]==-1)&&(need[i][j]<=avail[j])) 
flag=1; 
else 
{ 
flag=0; 
break; 
} 
} 
if(flag==1) 
{ 
printf("All the resources can be allocated to Process%d\n",i+1); 
printf("process%d is completed\n",i+1); 
finish[i]=1; 
printf("\n\nAvailable resources are:"); 
for(k=0;k<m;k++) 
{ 
avail[k]+=alloc[i][k]; 
printf("%4d",avail[k]); 
} 
printf("\n"); 
count++; 
break; 
} 
} 
}while(count<m&&count==turn); 
if(count==m) 
printf("\n The given state is safe state"); 
else 
printf("\n System is not in safe mode"); 

} 


