#include<sys/ioctl.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include <pwd.h>
#include <sys/stat.h>
#include <linux/cdrom.h>
#include<stdio.h>
#include<string.h>
int main(){

	// Path to CD-ROM drive
    char *dev = "/dev/cdrom";
    int fd = open(dev, O_RDONLY | O_NONBLOCK);

    if(fd == -1){
        printf("Failed to open '%s'\n", dev);
        exit(1);
    }

    printf("fd :%d\n", fd);

    // Eject the CD-ROM tray 
    ioctl (fd, CDROMEJECT);
    sleep(2);

}
