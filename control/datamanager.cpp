#include "datamanager.h"

DataManager* DataManager::m_data = new DataManager;

DataManager* DataManager::GetInstance()
{
    return m_data;
}


void DataManager::setUserName(QByteArray name)
{
    m_user = name;
}

void DataManager::setUserIP(QByteArray ip)
{
    m_ip = ip;
}

void DataManager::setUserport(QByteArray port)
{
    m_port = port;
}

QByteArray DataManager::getUserName()
{
    return m_user;
}

QByteArray DataManager::getUserIP()
{
    return m_ip;
}

QByteArray DataManager::getUserport()
{
    return m_port;
}
