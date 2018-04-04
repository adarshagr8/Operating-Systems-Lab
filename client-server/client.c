#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
  
int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr );
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)); 
    printf("Send to server:");
    fgets(buffer,1024,stdin);
    send(sock , buffer , strlen(buffer)+1 , 0 );
    printf("message sent\n");
    valread = read( sock , buffer, 1024);
    printf("From server: %s\n",buffer );
    return 0;
}
