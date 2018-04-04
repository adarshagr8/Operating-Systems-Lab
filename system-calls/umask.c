#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>

int main()
{
 int fd = open("hi.txt",O_CREAT);
 int k = umask(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IWOTH);
  printf("%d\n",k);
}

   
