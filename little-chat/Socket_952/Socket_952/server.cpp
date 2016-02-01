/*
  這是一隻 Server 端的連線程式
  class Server 有四個 method

  int Open(int port)
        port : port address
        return value : 0 代表成功
		               非 0 代表失敗
  int Close()
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
#include "server.h"

int main()
{
	int rt;
	char buf[256];
	Server server;

	if(server.Open(3333) != 0)			// 開啟 port address 為 3333 的連接 port，並等待連線
	{
		printf("ERROR: bind port error\n");
	}
	else
	{
		rt = server.Recv(buf,256);		// 接收 256 byte 的資料，rt 存放接收成功的大小
		if(rt == -1)					// 若 rt < 0 代表發生錯誤
			printf("ERROR: timeout\n");
		else if (rt == -2)
			printf("ERROR: signal receive\n");
		else
			printf(buf);

		strcpy(buf,"hello world,too\n");
		server.Send(buf,strlen(buf)+1);	// 將 hello world 送回 client 端
		server.Close();					// 關閉 server 連線
	}
	return 0;
}
