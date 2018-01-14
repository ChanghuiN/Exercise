//
// Created by ChanghuiN on 2018/1/14.
//

#ifndef EXERCISE_STACKWITHMIN_H
#define EXERCISE_STACKWITHMIN_H


#include <stack>

template<typename T> class StackWithMin {
public:
    StackWithMin(void) {}

    virtual ~StackWithMin(void) {}

    T &top(void);

    const T &top(void) const;

    void push(const T &value);

    void pop(void);

    const T &min(void) const;

    bool empty() const;

    size_t size() const;

private:
    std::stack<T> m_data;     // 数据栈，存放栈的所有元素
    std::stack<T> m_min;      // 辅助栈，存放栈的最小元素
};


#endif //EXERCISE_STACKWITHMIN_H
