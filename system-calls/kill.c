#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	pid_t p=getpid();
	int i= kill(p,SIGINT);
	if(i==-1)
        {printf("error\n");}
	printf("%d\n",i);
}
