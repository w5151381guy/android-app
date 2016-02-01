/*
  �o�O�@�� Client �ݪ��s�u�{��
  class Client ���|�� method

  int Connect(char *ip,int port)
	ip : ip address 
	port : port address
	return value : < 0 �N����~
  int DisConnect()
	return value : 0
  int Send(char *buf,int size)
	buf : �n�e�X�����
	size : �n�e�X��ƪ��j�p
	return value : ���\�e�X����Ƥj�p
  int Recv(char *buf,int size)
	buf : �n������ƪŶ�
	size : �n������ƪŶ��̤j�e�q
	return value : ���\��������Ƥj�p
		           -1 �N�� timeout
		           -2 �N��{������t�ΰT��
*/

#include "lib.h"
#include "client.h"

int main()
{
	char buf[256];
	int rt,size;

	Client client;								// Client socket Class

	if(client.Connect("127.0.0.1",3333) < 0)	// �إ߳s�u�� 127.0.0.1 port 3333
	{
		printf("ERROR: cannot connect to remote host\n");
	}
	else
	{
		strcpy(buf,"hello world\n");			
		size = client.Send(buf,strlen(buf)+1);	// �N hello world �e�� server ��
		rt = client.Recv(buf,256);				// ���� 256 byte ����ơArt �s�񱵦����\���j�p
		if(rt == -1)							// �Y rt < 0 �N��o�Ϳ��~
			printf("ERROR: timeout\n");
		else if (rt == -2)
			printf("ERROR: signal receive\n");
		else
			printf(buf);

		client.DisConnect();					// ���� Client �s�u
	} 
	return 0;
}
