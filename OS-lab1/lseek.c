
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include<stdio.h>
int main()
{
        int file=0;
        file=open("foo.txt",O_RDONLY);
 
        char buffer[19]="\0";
        read(file,buffer,2);
        printf("%s\n",buffer);
 
        lseek(file,10,SEEK_CUR);
 
        read(file,buffer,2);
        printf("%s\n",buffer);
 
        return 0;
}
