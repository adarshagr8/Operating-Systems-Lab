#include<stdio.h>
#include<unistd.h>
int main()
{
	if(link("my.txt","po.txt")==0)
		printf("link() executed successfully\n");
	else
		printf("error\n");
}
