#ifndef MEMORYLEAK_H
#define MEMORYLEAK_H

#include <QObject>

class MemoryLeak : public QObject
{
    Q_OBJECT
public:
//    explicit MemoryLeak(QObject *parent = nullptr);
    explicit MemoryLeak(char* pszData = nullptr);
    ~MemoryLeak();
    MemoryLeak(const MemoryLeak& other);
    MemoryLeak& operator = (const MemoryLeak& other);
    void show(char* data);
    void test();


signals:

private:
    char* m_pszData;
    int m_numShow;

};

#endif // MEMORYLEAK_H
