#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void  main(void)
{
    pid_t pid;
	pid_t ppid;
	uid_t uid;
    uid_t euid;
	gid_t gid;
	gid_t egid;

    fork();
	pid = getpid();
	ppid = getppid();
	uid = getuid();
    euid = geteuid();
	gid = getgid();
 	egid = getegid();
    
    printf("This line is from pid %d\n", pid);
	printf("This line is from ppid %d\n", ppid);
	printf("This line is from uid %d\n",uid);
	printf("This line is from euid %d\n", euid);
	printf("This line is from gid %d\n", gid);
	printf("This line is from egid %d\n", egid);
      
}
