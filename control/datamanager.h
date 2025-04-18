#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QByteArray>

//thread safe
class DataManager
{
public:
    static DataManager* GetInstance();

    DataManager(const DataManager&) = delete ;
    DataManager& operator=(const DataManager&) = delete;

    void setUserName(QByteArray name);
    void setUserIP(QByteArray ip);
    void setUserport(QByteArray port);

    QByteArray getUserName();
    QByteArray getUserIP();
    QByteArray getUserport();

private:
    DataManager() = default;

    static DataManager* m_data;


    QByteArray m_user;
    QByteArray m_ip;
    QByteArray m_port;

};

#endif // DATAMANAGER_H
