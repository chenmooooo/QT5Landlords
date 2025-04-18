#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>

#ifdef Q_OS_WIN
#include <winsock2.h>
#endif


class Tcpsocket : public QObject
{
    Q_OBJECT
public:
    Tcpsocket(QObject* parent = nullptr);
    Tcpsocket(QByteArray ip,unsigned short port,QObject* parent = nullptr);
    ~Tcpsocket();


    bool connectToHost(QByteArray ip,unsigned short port);

    QByteArray recvMsg(int timeout = -1); //单位: 秒

    void sendMsg(QByteArray msg,int timeout = -1);

    void disConnect();

private:
    bool readTimeout(int timeout);
    bool writeTimeout(int timeout);

#ifdef Q_OS_WIN
    SOCKET m_socket;
#endif

#ifdef Q_OS_LINUX
    int m_socket;
#endif

};

#endif // TCPSOCKET_H
