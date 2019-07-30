//
// Created by 管晓东 on 2019-07-29.
//

#include "Queue_c.h"
#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    MyCircularQueue(int k) {//初始化链表
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % size;//这样完成了一个循环队列的结构了撒
        data[tail] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }

    bool isEmpty() {
        return head == -1;
    }

    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};
int main(){
}