#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t pid = fork();
//pid = fork();

if (pid == 0)
{
printf("pid=%d\n" ,getpid()); //return pid of calling process
printf("\n I'm the child process \n");
}
else if (pid > 0)
{
printf("pid=%d \n",getpid()); //return pid of calling process
printf("\n I'm the parent process. My child pid is %d \n",pid);
}
else
{
printf("error in fork\n");
}
}



