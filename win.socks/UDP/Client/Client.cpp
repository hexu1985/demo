// Client.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#define  BUF_SZIE	 64
#include "winsock2.h"
// #pragma comment(lib, "ws2_32.lib")

int main(int argc, char* argv[])
{
	
	WSADATA        wsd;				//WSADATA����
	SOCKET         s;				//�׽���
	SOCKADDR_IN    servAddr;		//��������ַ
	char			buf[BUF_SZIE];	//�������ݻ�����
	
	//��ʼ���׽��ֶ�̬��
	if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
	{
		printf("WSAStartup failed!\n");
		return 1;
	}

	//�����׽���
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s == INVALID_SOCKET)
	{
		printf("socket() failed; %d\n", WSAGetLastError());
		WSACleanup();//�ͷ��׽�����Դ
		return 1;
	}
	
	//��ֵ��MyUDP��
	ZeroMemory(buf, BUF_SZIE);
	strcpy(buf, "MyUDP");
	
	//��������ַ
	servAddr.sin_family =AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons((short)5000);
	int	nServAddlen  = sizeof(servAddr);

	//��������
	if(sendto(s, buf, BUF_SZIE, 0, (SOCKADDR*)&servAddr, nServAddlen) == SOCKET_ERROR)
	{
		printf("recvfrom() failed: %d\n", WSAGetLastError());
		closesocket(s);	//�ر��׽���
		WSACleanup();	//�ͷ��׽�����Դ
		return 1;
	}
	
	closesocket(s);		//�ر��׽���	  
	WSACleanup();		//�ͷ��׽�����Դ
	return 0;
}

