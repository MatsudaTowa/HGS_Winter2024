//===========================
//
//TCP�ʐM�N���X[tcp_client.cpp]
// Author ���c�i�v
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
	//�\�P�b�g����
	m_Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_Socket == INVALID_SOCKET)
	{
		return false;
	}
	//�ڑ���̐ݒ�
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(nPortNum);
	addr.sin_addr.S_un.S_addr = inet_addr(pIpAddress);
	//�T�[�o�[�ɐڑ�
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
	//���M����
	int nSendByte = 0; //send�֐��̕Ԓl�ő��M�����o�C�g�����擾
	nSendByte = send(m_Socket,pSendData,nSendDataSize,0);
	return nSendByte;
}

int CTcpClient::Recv(char* pRecvData, int nRecvDataSize)
{
	if (m_Socket == INVALID_SOCKET)
	{
		return 0;
	}
	//��M����
	int nRecvByte = 0;
	nRecvByte = recv(m_Socket,pRecvData,nRecvDataSize,0);
	if (nRecvByte <= 0)
	{
		Uninit(); //�ؒf���ꂽ��I��
	}
	return nRecvByte;
}

void CTcpClient::Uninit()
{
	if (m_Socket == INVALID_SOCKET)
	{
		return;
	}
	//�T�[�o�[�Ƃ̐ؒf
	closesocket(m_Socket);
}
