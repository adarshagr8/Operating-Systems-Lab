#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
int main()
{
  int fd, sz;
  char *c = (char *) calloc(100, sizeof(char));
 
  fd = open("foo.txt", O_RDONLY);
  sz = read(fd, c, 5);
  printf(" %d bytes  were read.\n", sz);
  c[sz] = '\0';
  printf("Those bytes are as follows: %s\n", c);
}
