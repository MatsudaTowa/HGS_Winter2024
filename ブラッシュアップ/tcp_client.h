//===========================
//
//TCP通信クラス[tcp_client.h]
// Author 松田永久
//
//============================
#ifndef _TCP_CLIENT_H_ //これが定義されてないとき

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
