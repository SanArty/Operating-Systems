#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

// GROUP F
// RYAN ISENNOCK
// risenno@ostatemail.okstate.edu

int main(int argc, char *argv[])
{
    printf("\n          MINI PROJECT OPERATING SYSTEMS");
    printf("\n          Team F");
    printf("\n          Spring 2021");
    printf("\n\nFinal Program: 03/27/2021");
    printf("\n\nGROUP MEMBERS:");
    printf("\nAyrton Ledesma");
    printf("\nRasheed Abid");
    printf("\nRyan Isennock\n");
    printf("\nPlease enter the employee's information as it is requested!\n");

    int sockfd;
    int portNumber;
    int num;
    struct sockaddr_in serverAddress;
    struct hostent *server;

    char name[256];
    char jobTitle[256];
    char status[256];

    if(argc < 3)
    {
        exit(0);
    }

    portNumber = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        return 1;
    }

    server = gethostbyname(argv[1]);

    if(server == NULL)
    {
        exit(0);
    }

    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serverAddress.sin_addr.s_addr,server->h_length);
    serverAddress.sin_port = htons(portNumber);

    if(connect(sockfd, &serverAddress, sizeof(serverAddress)) < 0)
    {
        return 2;
    }

    int counter = 0;

    //Receiving input from user up to a fixed amount of times. 100 in this case. and sending it to SocketConnection Using pipe
    while(counter < 100){
        printf("\nNAME:     ");
        bzero(name, 256);
        fgets(name, 255,stdin);
        name[strlen(name)-1] = '\0';

        //Writing user's input to SocketConnection
        num = write(sockfd, name, strlen(name));
        if(num < 0)
        {
            return 3;
        }

        printf("JOBTITLE: ");
        bzero(jobTitle, 256);
        fgets(jobTitle, 255,stdin);

        //Writing user's input to SocketConnection
        num = write(sockfd, jobTitle, strlen(jobTitle));
        if(num < 0)
        {
            return 4;
        }

        printf("STATUS:   ");
        bzero(status, 256);
        fgets(status, 255,stdin);
        printf("\n");

        //Writing user's input to SocketConnection
        num = write(sockfd, status, strlen(status));
        if(num < 0)
        {
            return 5;
        }
        counter++;
    }
    return 0;
}
