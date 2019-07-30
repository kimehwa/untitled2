//
// Created by 管晓东 on 2019-07-29.
//
/**
 * 这个是通过栈来实现的，现在的问题是如何实现逆波兰的序列
 */

#include "Houzhui_02.h"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;
int stack[101];
char s[256];

int comp(char s[256]) {
    int i = 0, top = 0, x, y;
    while (i <= strlen(s) - 2) {
        switch (s[i]) {
            case '+':
                stack[--top] += stack[top + 1];
                break;
            case '-':
                stack[--top] -= stack[top + 1];
                break;
            case '*':
                stack[--top] *= stack[top + 1];
                break;
            case '/':
                stack[--top] /= stack[top + 1];
            default:
                x = 0;
                while (s[i] != ' ') {
                    x = x * 10 + s[i++] - '0';
                }
                stack[++top] = x;
                break;
        }
                i++;
    }
        return stack[top];
}

int main() {
    printf("input a string(@over):");
    gets(s);
    printf("result = %d", comp(s));
    return 0;
}