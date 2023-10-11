/* * * * * * * * * * * * * * * * * * * * *
*   File:     rect.h
*   Author:   yue.wang
*   Company:  fuqing
*   Time:     2023-08-22
*   Brief:    used for test costum copy constructor、deepCopy
* * * * * * * * * * * * * * * * * * * * * */

#ifndef RECT_H
#define RECT_H

class Rect
{
public:
    Rect();
#if 1
    Rect(const Rect& r); // 自定义拷贝构造函数
#endif
    ~Rect();

private:
    int m_width;
    int m_height;
    int *m_p;
};

#endif // RECT_H
