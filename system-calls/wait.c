#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
 
int main()
{
	fork();
    	printf("hello\n");
    	wait(NULL);
    	printf("world\n");
    	printf("Bye\n");
    	return 0;
}
