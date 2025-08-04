//===========================
//
//TCP�ʐM�N���X[tcp_client.h]
// Author ���c�i�v
//
//============================
#ifndef _TCP_CLIENT_H_ //���ꂪ��`����ĂȂ��Ƃ�

#define _TCP_CLIENT_H_
#include "main.h"

class CTcpClient
{
public:
	CTcpClient();
	~CTcpClient();
	bool Init(const char* pIpAddress,int nPortNum);
	int Send(char* pSendData,int nSendDataSize);
	int Recv(char* pRecvData,int nRecvDataSize);
	void Uninit();
private:
	SOCKET m_Socket;
};
#endif
