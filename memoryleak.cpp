#include "memoryleak.h"
#include <QDebug>

//MemoryLeak::MemoryLeak(QObject *parent)
//    : QObject{parent}
//{

//}

MemoryLeak::MemoryLeak(char *pszData):m_pszData(nullptr), m_numShow(0)
{
    qDebug() << "MemoryLeak(char *pszData)";
    // 1
    show(pszData);

    int nLen = static_cast<int>(std::strlen(pszData));
    qDebug() << "nLen " << nLen;

    // be sure to apply for an additional byte to place '/0',
    // otherwise it will exceed the bounds during the deconstruction process
    m_pszData = new char[nLen + 1];
    // 仅仅分配了内存块，但是没有具体string数据，长度还是不确定的  data: ??????????
    qDebug() << "1std::strlen(m_pszData) " << static_cast<int>(std::strlen(m_pszData)); // 10
    // 2
    show(m_pszData);

    // 指针m_pszData的大小 8
    qDebug() << "2sizeof(m_pszData) " << sizeof(m_pszData);
    // 指针m_pszData指向的第一个字符的大小 1
    qDebug() << "2sizeof(*m_pszData) " << sizeof(*m_pszData);

    memset(m_pszData, 0, nLen + 1);
    // 全部置为0，没有字符数据， strlen = 0,  data: ""
    qDebug() << "2std::strlen(m_pszData) " << static_cast<int>(std::strlen(m_pszData)); // 0
    // 3
//    show(m_pszData);
    memcpy(m_pszData, pszData, nLen + 1);
    // 有了具体数据 First, strlen = 5, data: First
    qDebug() << "3std::strlen(m_pszData) " << static_cast<int>(std::strlen(m_pszData)); // 5
    // 4
//    show(m_pszData);
}

MemoryLeak::~MemoryLeak()
{
    qDebug() << "\n~MemoryLeak()";
    if(m_pszData){
        delete m_pszData;
        m_pszData = nullptr;  // ?
    }
}

MemoryLeak::MemoryLeak(const MemoryLeak &other)
{
    qDebug() << "\nMemoryLeak(const MemoryLeak &other)" << other.m_pszData;
    m_pszData = nullptr;
    m_numShow = 10;
    qDebug() << "other.m_numShow" << other.m_numShow;
    qDebug() << "this->m_numShow" << this->m_numShow;
    // 11
    this->show(other.m_pszData);

    int nLen = static_cast<int>(std::strlen(other.m_pszData));
    if(nLen > 0){
        this->m_pszData = new char[nLen +1];
        memset(m_pszData, 0, static_cast<int>(sizeof(m_pszData)));
    }

    if(this->m_pszData != nullptr){
        memcpy(this->m_pszData, other.m_pszData, static_cast<int>(sizeof((this->m_pszData))));
    }

    // 12
    this->show(m_pszData);

}

MemoryLeak &MemoryLeak::operator =(const MemoryLeak &other)
{
    qDebug() << "\nMemoryLeak::operator =";
    // 7
    show(other.m_pszData);

    if (&other == this)
        return *this;

    memcpy(this->m_pszData, other.m_pszData, static_cast<int>(sizeof(*(other.m_pszData))));
    // 8
    show(other.m_pszData);
    return *this;

}

void MemoryLeak::show(char* data)
{
    m_numShow += 1;
    qDebug() << "\nshow" << m_numShow;
    if(nullptr != data){
        qDebug() << "data:" << data;  // First
        qDebug() << "&data" << &data; // 0x9f7daffa68
        qDebug() << "*data" << *data; // F
        qDebug() << "sizeof(data)" << sizeof(data); // 8
        qDebug() << "sizeof(*data)" << sizeof(*data); // 1
    }else{
        qDebug() << "nullptr == data";
    }


    if(nullptr != m_pszData){
        // can't use this
        qDebug() << "m_pszData:" << m_pszData;
        qDebug() << "&m_pszData" << &m_pszData;
        qDebug() << "*m_pszData" << *m_pszData;
        qDebug() << "sizeof(m_pszData)" << sizeof(m_pszData);
        qDebug() << "sizeof(*m_pszData)" << sizeof(*m_pszData);
        qDebug() << "std::strlen(m_pszData) " << static_cast<int>(std::strlen(m_pszData));
    }else{
        qDebug() << "nullptr == m_pszData";
    }

}

void MemoryLeak::test()
{
    qDebug() << "test:";
    std::string str = "First";
    char* strChar = str.data();
    int len =  static_cast<int>(std::strlen(strChar));
    qDebug() << "len:" << len;

//    char* m_char = new char[len + 1];
    char* m_char;
    m_char = new char[len + 1];
    qDebug() << "sizeof(m_char):" << sizeof(m_char);
    qDebug() << "std::strlen(m_char)" << static_cast<int>(std::strlen(m_char));
    delete[] m_char;
}
