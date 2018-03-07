#include<stdio.h>
#include<signal.h>
#include<unistd.h>
volatile int i=3;
void handle_sigint(int sig)
{
    printf("Caught signal\n");
	--i;
	alarm(4);
}
 
int main()
{
	
    	signal(SIGALRM, handle_sigint);
    	alarm(2);
	while(i)
		sleep(1);
	printf("bye\n");
    	return 0;
}
