#ifndef _LIB_H_
#define _LIB_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <time.h>
#include <sys/wait.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define QLEN    (3)
#define NO_PACKET_LOSS     (3)
//#define PACKET_LOSS     (30)
#define PACKET_BITERROR (5)
//#define PACKET_BITERROR (50)
//

#define	PACKET_LESS	(3)


#define MAX_ERROR_RATE	(10)
#define MIN_ERROR_RATE	(0)

//#define DEFAULT_TIMEOUT	(5)
#define DEFAULT_TIMEOUT	(1)

#define FINISH_CONNECTION	(0)
#define RESET_CONNECTION	(1)

class Socket
{
	protected:
		int fd;
		int timeout;
		int ustimeout;
	private:
		struct timeval tv;
		int send_count;
		int recv_count;
		char rbuf[4096];
		int rsize;
		int finish;		
		int error_rate;
	public:
		int Send(char *buf,int size);
		int Recv(char *buf,int size);
		void SetConnectStatus(int val);
		int GetConnectStatus();
		void SetErrorRate(int val);
		int GetErrorRate();	
		void ResetTimer( unsigned int sec );
		unsigned int DisplayTimer();
		Socket();
		~Socket();
};

class Server : public Socket
{
	private:
		int sockfd;
		int port;
		struct sockaddr_in sin;	
	public:
		int Open(int serverport);
		int Close();
		Server();
		~Server();
};

class Client : public Socket
{
	private:
		char dest_ip[256];
		int  dest_port;
		struct sockaddr_in sin;
	public:
		int  Connect(char *dest,int port);
		int  DisConnect();
		Client();
		~Client();
};

typedef class Server Server;
typedef	class Client Client;


#endif	/* _LIB_H_ */
