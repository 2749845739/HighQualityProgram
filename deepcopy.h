#ifndef DEEPCOPY_H
#define DEEPCOPY_H

#include <ctime>

class DeepCopy
{
public:
    DeepCopy(int a, int* b);
#if 0
    DeepCopy(const DeepCopy& obj); // 自定义拷贝构造函数
#endif
    void show(const DeepCopy& obj);
    void deepCopyTest();

private:
    int m_a;
    int* m_b;
    time_t m_time; // 对象创建时间
    static int m_count; // 创建过的对象的数目
};

#endif // DEEPCOPY_H
