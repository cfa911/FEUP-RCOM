#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>

#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

//get the host ip to open the socket

int get_host_IP(const char *address_name, in_addr_t *IP)
{
	struct hostent *h = gethostbyname(address_name);
	if (h == NULL)
	{
		herror("gethostbyname");
		exit(1);
	}

		 const char * hostIP = inet_ntoa(*((struct in_addr *)h->h_addr)));
		 *IP = inet_addr(hostIP);

		 return 0;
}

//open tcp socket

int open_tcp_socket(in_addr_t hostIP, unsigned int port)
{
	struct sockaddr_in server_addr;
	bzero((char *)&server_addr, sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = hostIP;
	server_addr.sin_port = htons(port);

	const int socketfd = socket(AF_INET, SOCK_STREAM, 0);

	if (connect(socketfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1)
	{
		perror("Connection failed");
		close(socketfd);
		exit(1);
	}

	//Comunicar


	//shutdown(socketfd,SHUT_RDWR);
	//close(socketfd);
	return socketfd;
}
