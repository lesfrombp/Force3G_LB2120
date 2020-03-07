/*
Name: Robert Ehrlish
Date:3/6/2020
Description: This program will

*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <unistd.h>

int main (int argc, char **argv){
        int sockfd;
        int len = sizeof(struct sockaddr);
        struct sockaddr_in servaddr;

        sockfd=socket(AF_INET, SOCK_STREAM, 0);
        bzero(&servaddr,sizeof(servaddr));

        servaddr.sin_family=AF_INET;
        servaddr.sin_port=htons(5510); // Server port number

        inet_pton(AF_INET,"192.168.5.1",&(servaddr.sin_addr));

        connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

        char *force3G = "AT$QCNSP=2,0,2";//Command to force 3G
        write(sockfd, force3G, strlen(force3G));

        char buffer[1024];
        read(sockfd, buffer, sizeof(buffer));
        printf("%s", buffer);
}
