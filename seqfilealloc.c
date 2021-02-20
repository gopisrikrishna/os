#include<stdio.h>
#define MAX 100 /*no.of blocks in a disk*/ 
struct file /* declaration of structure*/ 
{ 
char name[20]; 
int start; 
int len; 
}p[20]; 
main() 
{ 
int disk[MAX],i,count=-1,flag; 
char ch; 
for(i=0;i<MAX;i++) 
disk[i]=0; 
do 
{ 
count++; 
printf("\n enter file name:"); 
scanf("%s",&p[count].name); 
printf("\n Enter the starting block & length of file:"); 
scanf("%d%d",&p[count].start,&p[count].len); 
for(i=p[count].start;i<(p[count].start+p[count].len);i++) 
if(disk[i]==0) /*checking whether required set of blocks are free */ 
flag=1; 
else 
{ 
printf("Block already allocated."); 
flag=0; 
break; 
} 
if(flag==1) /*if required set of blocks are free*/ 
{ 
for(i=p[count].start;i<(p[count].start+p[count].len);i++) 
{ 
disk[i]=1; 
printf("\n%d->%d",i,disk[i]); 
} 
printf("\n the file is allocated to disk"); 
} 
printf("\n do you have another file:"); 
fflush(stdin); 
ch=getchar(); 
}while(ch=='y'); 
} 

