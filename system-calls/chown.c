#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pwd.h>

int main()
{
    int fd;
    fd=open("chown.txt",O_RDONLY|O_CREAT);
      printf("other user id=%d other user name=%s\n",getuid()+1,getpwuid(getuid()+1)->pw_name);
      if(chown("chown.txt",getuid()+1,getgid()+1)==0)
       printf("successfully changed owner\n");
      else
       printf("error\n");
   return 0;
}
