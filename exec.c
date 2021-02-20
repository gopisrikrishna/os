#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
 pid_t pid, status;
pid=fork();
if(pid<0)
{
perror("fork error");
exit(1);
}
else if(pid ==0)
{
if ( execl("/bin/pwd","pwd",NULL) <0 )
{
perror("child fail to execute pwd");
exit(1);
}
}
if (pid >0)
{
wait(&status);
printf("\n PARENT HERE!!!\n");
printf("child terminated \n");
exit(0);
}
}

