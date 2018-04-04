#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    char *args[]={"./EXEC",NULL};
    execl(args[0],args);
   	printf("hi\n");
    return 0;
}
