#include<stdio.h>
#include<sys/stat.h>
int main()
{
	if(chmod("foo.txt", S_IRUSR|S_IRGRP|S_IROTH)==0)
		printf("chmod() executed successfully\n");
	else
		printf("error\n");
}
