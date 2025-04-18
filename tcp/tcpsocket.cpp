#include "tcpsocket.h"


Tcpsocket::Tcpsocket(QObject *parent)
{
#ifdef Q_OS_WIN
    WSADATA data;
    WSAStartup(MAKEWORD(2,2),&data);
#endif
}

Tcpsocket::Tcpsocket(QByteArray ip, unsigned short port, QObject *parent)
    :Tcpsocket(parent)
{
    connectToHost(ip,port);
}

Tcpsocket::~Tcpsocket()
{
#ifdef Q_OS_WIN
    WSACleanup();
#endif
}

bool Tcpsocket::connectToHost(QByteArray ip, unsigned short port)
{
    m_socket = socket(AF_INET,SOCK_STREAM,0);
    if(m_socket < 0 )
        return false;
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip.data());

    int ret = ::connect(m_socket,reinterpret_cast<struct sockaddr*>(&addr),sizeof(addr));
    if(ret)
        return false;
    return true;
}

QByteArray Tcpsocket::recvMsg(int timeout)
{

}

void Tcpsocket::sendMsg(QByteArray msg, int timeout)
{

}

void Tcpsocket::disConnect()
{
    if(m_socket)
    {
#ifdef Q_OS_WIN
        closesocket(m_socket);
#endif
#ifdef Q_OS_LINUX
        close(m_socket);
#endif
    }
}

bool Tcpsocket::readTimeout(int timeout)
{
    if(timeout==-1)
    {
        return true; //
    }

    int nfds=0;
#ifdef Q_OS_WIN
    nfds=0;
#endif
#ifdef Q_OS_LINUX
    nfds=m_socket;
#endif
    fd_set rdset;
    FD_ZERO(&rdset);
    FD_SET(m_socket,&rdset);
    struct timeval tmout;
    tmout.tv_sec = timeout;
    tmout.tv_usec = 0;
    int ret = select(nfds,&rdset,NULL,NULL,&tmout);

    if(ret)
        return true;

    return false;
}

bool Tcpsocket::writeTimeout(int timeout)
{
    if(timeout==-1)
    {
        return true; //
    }

    int nfds=0;
#ifdef Q_OS_WIN
    nfds=0;
#endif
#ifdef Q_OS_LINUX
    nfds=m_socket;
#endif
    fd_set wset;
    FD_ZERO(&wset);
    FD_SET(m_socket,&wset);
    struct timeval tmout;
    tmout.tv_sec = timeout;
    tmout.tv_usec = 0;
    int ret = select(nfds,NULL,&wset,NULL,&tmout);

    if(ret)
        return true;

    return false;
}
