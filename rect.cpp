#include "rect.h"
#include <iostream>
#include "assert.h"

Rect::Rect(): m_width(0), m_height(0)
{
    std::cout << "Rect::Rect()" << std::endl;
    int a = 9;
    m_p = &a;
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof(m_p)" << sizeof(m_p) << std::endl;
}

#if 1
Rect::Rect(const Rect &r)
{
    this->m_width = r.m_width;
    this->m_height = r.m_height;
    // 重新动态分配空间
    this->m_p = new int(100);
    *(this->m_p) = *(r.m_p);
}
#endif

Rect::~Rect()
{
    std::cout << "m_p = " << m_p << std::endl;
    delete m_p;
    m_p = nullptr; // 以防止野指针的出现。
}
