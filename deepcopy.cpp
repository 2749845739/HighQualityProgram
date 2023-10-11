#include "deepcopy.h"
#include <iostream>

int DeepCopy::m_count = 0;

DeepCopy::DeepCopy(int a, int* b): m_a(a), m_b(b)
{
    m_count++;
    m_time = time(0);
}

#if 0
DeepCopy::DeepCopy(const DeepCopy &obj)
{
    this->m_a = obj.m_a;
    this->m_b = new int(*(obj.m_b));
    this->m_count++;
    this->m_time = time(0);
}
#endif


void DeepCopy::show(const DeepCopy& obj)
{
    std::cout << "m_a = " << obj.m_a <<", *(obj.m_b) = " << *(obj.m_b) <<", obj.m_b = "
              << obj.m_b << ", m_count = " << obj.m_count << ", m_time = " << obj.m_time << std::endl;
}

void DeepCopy::deepCopyTest()
{
    DeepCopy deep01(1, new int(2));
    show(deep01);

    DeepCopy deep02 = deep01;
    show(deep02);

    // 修改deep01中的变量
    deep01.m_a = 11;
    *(deep01.m_b) = 22;
    show(deep01);
    show(deep02);

}


