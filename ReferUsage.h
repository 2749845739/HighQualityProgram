#ifndef REFERUSAGE_H
#define REFERUSAGE_H

#include <QObject>

class ReferUsage : public QObject
{
    Q_OBJECT
public:
    explicit ReferUsage(QObject *parent = nullptr);

    void init();

    void valueTrans(int val);
    void referTrans(int &val);
    void ptrTrans(int *val);

signals:

};

#endif // REFERUSAGE_H
