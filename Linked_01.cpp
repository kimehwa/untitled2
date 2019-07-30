//
// Created by 管晓东 on 2019-07-27.
//

#include "Linked_01.h"
#include <iostream>

using namespace std;
struct Node {
    int data;
    Node *next;
};
Node *head, *p, *r;//r指向链表的当前最后一个节点，可以称为尾指针
int x;

int main() {
    cin >> x;
    head = new Node;
    r = head;
    while (x != -1) {
        p = new Node;
        p->data = x;
        p->next = NULL;//将p点放入尾指针的后面
        r->next = p;
        r = p;//每次r都是保存最后一个尾指针
        cin >> x;
    }
    p = head->next;//头指针没有数据，从第一个节点开始就可以了
    while (p->next != NULL) {//这里来进行遍历的
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data << endl;//前面的遍历遍历不出来最后一个结果
    system("pause");
}

void get(Node *head, int i) {//得到一个节点
    Node *p;
    int j = 1;
    p = head->next;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p != NULL && j == i) {
        cout << p->data;
    } else {
        cout << "i not exsit";
    }
}

//插入一个节点
void insert(Node *head, int i, int x) {
    Node *p, *s;
    int j = 0;
    p = head;
    while (p != NULL && j < i - 1) {//这里要找到待插入的前一个节点
        p = p->next;
        j++;
    }
    if (p == NULL) {
        cout << "No this position";
    } else {
        s = new Node;
        s->data = x;
        s->next = p->next;//让p的下一个位置被s连接
        p->next = s;//这里p的下一个位置连接s
    }
}

//删除一个节点跟插入一个节点类似
void delete1(Node *head, int i) {
    Node *p, *s;
    int j = 0;
    p = head;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL) {
        cout << "No this position";
    } else {
        s = p->next;//s来负责先保存p的下一个节点
        p->next = s->next;
        free(s);
    }
}