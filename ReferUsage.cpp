#include "ReferUsage.h"
#include <QDebug>

ReferUsage::ReferUsage(QObject *parent)
    : QObject{parent}
{
    //    init();
    int data = 5;
    valueTrans(data);
    referTrans(data);
    ptrTrans(&data);
}

void ReferUsage::init()
{
    qDebug() << "ReferUsage::init()";
    int i = 5;
    int j = 6;
    int &k = i;
    k = j;
}

void ReferUsage::valueTrans(int val)
{
    val +=10;
    qDebug() << val;
}

// the essence of reference(val) is "int*"
void ReferUsage::referTrans(int &val)
{
    val +=10;
}

void ReferUsage::ptrTrans(int *val)
{
    *val +=10;
}


