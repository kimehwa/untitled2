//
// Created by 管晓东 on 2019-07-28.
//
/**
 * 约瑟夫环，首先要把一个链表首位相加，然后进行依次删除
 */

#include "JosefuCircle.h"
#include <iostream>

using namespace std;
struct node {
    long d;
    node *next;
};
long n, m;
node *head, *p, *r;//r一直为尾指针
int main() {
    long i, j, k, l;
    cin >> n >> m;
    head = new node;
    head->d = 1;
    head->next = NULL;
    r = head;
    for (i = 2; i <= n; i++) {//这里只是为了生成一个链表，跟前面的几乎一模一样
        p = new node;
        p->d = i;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    r->next = head;
    r = head;//生成一个首尾相连的链表
    for (i = 1; i <= n; i++) {//在一个环里可以一直
        for (j = 1; j <= m - 2; j++) {//每m个拿出来一个，这里为什么是m-2呢？
            r = r->next;
        }
        cout << r->next->d << " ";//因为这个地方输出了r.next
        r->next = r->next->next;
        r = r->next;
    }
}