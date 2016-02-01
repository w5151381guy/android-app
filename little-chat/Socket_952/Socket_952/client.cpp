/*
  這是一隻 Client 端的連線程式
  class Client 有四個 method

  int Connect(char *ip,int port)
	ip : ip address 
	port : port address
	return value : < 0 代表錯誤
  int DisConnect()
	return value : 0
  int Send(char *buf,int size)
	buf : 要送出的資料
	size : 要送出資料的大小
	return value : 成功送出的資料大小
  int Recv(char *buf,int size)
	buf : 要接收資料空間
	size : 要接收資料空間最大容量
	return value : 成功接收的資料大小
		           -1 代表 timeout
		           -2 代表程式收到系統訊息
*/

#include "lib.h"
#include "client.h"

int main()
{
	char buf[256];
	int rt,size;

	Client client;								// Client socket Class

	if(client.Connect("127.0.0.1",3333) < 0)	// 建立連線到 127.0.0.1 port 3333
	{
		printf("ERROR: cannot connect to remote host\n");
	}
	else
	{
		strcpy(buf,"hello world\n");			
		size = client.Send(buf,strlen(buf)+1);	// 將 hello world 送到 server 端
		rt = client.Recv(buf,256);				// 接收 256 byte 的資料，rt 存放接收成功的大小
		if(rt == -1)							// 若 rt < 0 代表發生錯誤
			printf("ERROR: timeout\n");
		else if (rt == -2)
			printf("ERROR: signal receive\n");
		else
			printf(buf);

		client.DisConnect();					// 關閉 Client 連線
	} 
	return 0;
}
