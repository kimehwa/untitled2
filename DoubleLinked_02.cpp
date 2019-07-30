//
// Created by 管晓东 on 2019-07-27.
//

#include "DoubleLinked_02.h"
#include <iostream>

using namespace std;
struct node {
    int data;
    node *pre, *next;
};

void insert(node *head, int i, int x) {
    node *s, *p;
    int j = 0;
    s = new node;
    s->data = x;
    p = head;
    //还是要找到要插入的前一个值
    while (p->next != NULL && j < i) {//这里为啥是j<i呢？前面单链表是i-1;
        p = p->next;
        j++;
    }
    if (p == NULL) {
        cout << "no this position";
    } else {
        s->pre = p->pre;//先用s.pre来保存p.pre
        p->pre = s;//将p.pre进行更新
        s->next = p;
        p->pre->next = s;//这4个的顺利需要必须这么写吗
    }
}

void delete2(node *head, int i) {
    int j = 0;
    node *p = head;
    while (p->next != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        cout << "no this position ";
    } else {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }
}


