//===========================
//
//TCP通信クラス[tcp_client.cpp]
// Author 松田永久
//
//============================
#include "tcp_client.h"
CTcpClient::CTcpClient()
{
	m_Socket = INVALID_SOCKET;
}

CTcpClient::~CTcpClient()
{
}

bool CTcpClient::Init(const char* pIpAddress, int nPortNum)
{
	//ソケット生成
	m_Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_Socket == INVALID_SOCKET)
	{
		return false;
	}
	//接続先の設定
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(nPortNum);
	addr.sin_addr.S_un.S_addr = inet_addr(pIpAddress);
	//サーバーに接続
	if (connect(m_Socket, (struct sockaddr*)&addr, sizeof(addr)) != 0)
	{
		return false;
	}

	return true;
}

int CTcpClient::Send(char* pSendData, int nSendDataSize)
{
	if (m_Socket == INVALID_SOCKET)
	{
		return 0;
	}
	//送信処理
	int nSendByte = 0; //send関数の返値で送信したバイト数を取得
	nSendByte = send(m_Socket,pSendData,nSendDataSize,0);
	return nSendByte;
}

int CTcpClient::Recv(char* pRecvData, int nRecvDataSize)
{
	if (m_Socket == INVALID_SOCKET)
	{
		return 0;
	}
	//受信処理
	int nRecvByte = 0;
	nRecvByte = recv(m_Socket,pRecvData,nRecvDataSize,0);
	if (nRecvByte <= 0)
	{
		Uninit(); //切断されたら終了
	}
	return nRecvByte;
}

void CTcpClient::Uninit()
{
	if (m_Socket == INVALID_SOCKET)
	{
		return;
	}
	//サーバーとの切断
	closesocket(m_Socket);
}
