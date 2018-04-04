#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	fork();
	printf("hello\n");
	exit(1);
	printf("world\n");
}
