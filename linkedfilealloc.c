#include<stdio.h>
#define MAX 100 
struct file /* declaration of structure*/ 
{ 
char name[20]; 
int start; 
int len; 
int next[20]; 
}p[20]; 
main() 
{ 
int disk[MAX],i,count=-1,flag; 
int free=MAX, l,j; 
char ch; 
for(i=0;i<MAX;i++) 
disk[i]=0; 
do 
{ 
count++; /*no.of processes*/ 
printf("\n enter file name:"); 
scanf("%s",&p[count].name); 
printf("\n Enter the starting block & length of file:"); 
scanf("%d%d",&p[count].start,&p[count].len); 
if(disk[p[count].start]==0&&free<=p[count].len) /*if starting block is not allocated*/ 
{ 
for(i=0;i<p[count].len;i++) 
p[count].next[i]=-1; /*initial value of next array*/ 
p[count].next[0]=p[count].start; /*first block is first*/ 
disk[p[count].start]=1; 
l=1; 
while(l<p[count].len-1)/*repeats while loop until we get required free blocks*/ 
{ 
j=rand()%MAX; 
if(disk[j]==0) 
{ 
p[count].next[l]=j; /*next block for the process*/ 
disk[j]=1; 
printf("j%d ",j); 
l++; 
} 
} 
if(l==p[count].len-1) 
{ 
printf("The file is allocated on the disk"); 
for(i=0;i<(p[count].len-1);i++) 
printf("\n%d->1",p[count].next[i]); /*printing allocated blocks*/ 
} 
} 
else 
printf("The file is not allocated on the disk"); 
printf("\n do you have another file:"); 
fflush(stdin); 
ch=getchar(); 
}while(ch=='y'); 
}


