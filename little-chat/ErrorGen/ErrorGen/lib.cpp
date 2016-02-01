#include "lib.h"

/******************************************************************/
/*  class Socket                                                  */
/******************************************************************/

Socket::Socket()
{
	fd = 0;
	send_count = 0;
	recv_count = 0;
	rsize = 0;
	timeout = 10;
	srand(time(NULL));
}

Socket::~Socket()
{
	if(fd > 0)
		close(fd);
}

int Socket::Send(char *buf,int size)
{
		int r_size;
	char tmp[4096];

	if(fd <= 0)
		return 0;
	
	memset(tmp,0x00,size);
	memcpy(tmp,buf,size);
	send_count++;
	
	r_size = send(fd,tmp,size,0);
	if(r_size == size)
		return size;
	else
		return -1;
}

int Socket::Recv(char *buf,int size)
{
	int r_size,nfds;
	fd_set rset;

	tv.tv_sec = timeout;
	tv.tv_usec = 0;
	
	if(fd <= 0)
		return 0;
	FD_ZERO(&rset);
	FD_SET(fd, &rset);
	nfds = fd;
	nfds = select(nfds+1, &rset, NULL, NULL, &tv );
	if(nfds == 0)
		return -1;
	else if(nfds < 0)
		return -2;	
	
	recv_count++;
#ifdef	NO_PACKET_LOSS 
	r_size = recv(fd,buf,size,0);	
#else
	int	index;
	int error_rate = 4 ; //The ratio of generating an error message
	if( rand()%10 >= error_rate ){
		r_size = recv(fd,buf,size,0);
	}else{
//		printf("======Receive Error Packet======\n");
		r_size = recv(fd,rbuf,size,0);
		if(r_size > 0){
			for(int i=0;i<10;i++){
				//index = rand()%r_size;
				// make error for header olny
				index = rand()%4;
				rbuf[index] = (~rbuf[index]);
			}
		}
		memcpy(buf, rbuf , size );
	}

#endif
	
	// no received , return timeout
	if( !r_size )
		return -1;	
	
	return r_size;
}


Server::Server()
{
	sockfd = 0;
	port = 0;
}

Server::~Server()
{
	if(sockfd > 0)
		close(sockfd);
}

int Server::Open(int serverport)
{
	int rt;
	socklen_t value;

	if(sockfd > 0)
		return -1;

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(serverport);

	//sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	port = serverport;

	if((rt = bind(sockfd, (struct sockaddr *) &sin, sizeof(sin))) < 0)
		return rt;
	if((rt = listen(sockfd, QLEN)) < 0)
		return rt;
	
	value = sizeof(sin);
	if((rt = accept(sockfd, (struct sockaddr *) &sin, &value)) < 0)
		return rt;
	fd = rt;
	return 0;
}

int Server::Close()
{
	if(sockfd > 0)
		close(sockfd);
	sockfd = 0;
	if(fd > 0)
		close(fd);
	fd = 0;
	return 0;
}

Client::Client()
{
	dest_port = 0;
	memset(dest_ip,0,256);
}

Client::~Client()
{
	
}

int Client::Connect(char *dest,int port)
{
	int sock;
	struct hostent *host;
	if(fd > 0)
                return -1;

	dest_port = port;
	memset((char *) &sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	if((host = gethostbyname(dest)) == NULL)
		sin.sin_addr.s_addr = inet_addr(dest);
	else
		memcpy(&sin.sin_addr.s_addr, host->h_addr, host->h_length);

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return sock;
	if(connect(sock, (struct sockaddr *) & sin, sizeof(sin)) < 0)
		return -1;
	fd = sock;
	return 0;

}

int Client::DisConnect()
{
	if(fd > 0)
		close(fd);
	fd = 0;
	return 0;
}
