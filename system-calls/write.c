#include<stdio.h>
#include<string.h>
#include <fcntl.h>
main()
{
  int sz;
  int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC);
  sz = write(fd, "hello geeks\n", strlen("hello geeks\n"));
  printf("returned: %d\n",sz);
  close(fd);
}
