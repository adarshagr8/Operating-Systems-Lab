#include<stdio.h>
#include<unistd.h>
int main()
{
	if(access("foo.txt", F_OK | R_OK | W_OK)==0)
		printf("access permitted\n");
	else
		printf("not permitted\n");
}
