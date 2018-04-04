#include<stdio.h>
#include<unistd.h>
int main()
{
	link("my.txt","po.txt");
	unlink("po.txt");
}
