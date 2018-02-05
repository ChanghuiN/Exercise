//
// Created by ChanghuiN on 2018/1/23.
//

#ifndef EXERCISE_QUEUE_H
#define EXERCISE_QUEUE_H


#include <stack>


template <typename T> class CQueue {

public:
    CQueue(void);
    ~CQueue(void);

    // 在队列末尾添加一个结点
    void appendTail(const T& node);

    // 删除队列的头结点
    T deleteHead();

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void) {}

template <typename T> CQueue<T>::~CQueue(void) {}

template <typename T> void CQueue<T>::appendTail(const T &node) {
    stack1.push(node);
}

template <typename T> T CQueue<T>::deleteHead() {
    if (stack2.size() == 0) {
        while (stack1.size() > 0) {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if (stack2.size() == 0)
        throw "queue is empty";

    T head = stack2.top();
    stack2.pop();

    return head;
}


#endif //EXERCISE_QUEUE_H
