/*
  �o�O�@�� Server �ݪ��s�u�{��
  class Server ���|�� method

  int Open(int port)
        port : port address
        return value : 0 �N���\
		               �D 0 �N����
  int Close()
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
#include "server.h"

int main()
{
	int rt;
	char buf[256];
	Server server;

	if(server.Open(3333) != 0)			// �}�� port address �� 3333 ���s�� port�A�õ��ݳs�u
	{
		printf("ERROR: bind port error\n");
	}
	else
	{
		rt = server.Recv(buf,256);		// ���� 256 byte ����ơArt �s�񱵦����\���j�p
		if(rt == -1)					// �Y rt < 0 �N��o�Ϳ��~
			printf("ERROR: timeout\n");
		else if (rt == -2)
			printf("ERROR: signal receive\n");
		else
			printf(buf);

		strcpy(buf,"hello world,too\n");
		server.Send(buf,strlen(buf)+1);	// �N hello world �e�^ client ��
		server.Close();					// ���� server �s�u
	}
	return 0;
}
