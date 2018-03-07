#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
	int fd= creat("/home/student/Desktop/OS-lab/lab1.txt",S_IRUSR | S_IWUSR |S_IRGRP|S_IROTH);
	if(fd==-1)
        {perror("");}
	int p=chdir("/home/student/Desktop");
printf("chdir operation successful = %d",p);
return 0;
} 
