//
// Created by 管晓东 on 2019-07-28.
//

#include <cstdio>
#include "Stack_01.h"
#define n 100;
void push(int s[],int *top,int *x){
    if(*top == n ){
        printf("stackover");
    }else{
        (*top)++;
        s[*top]=*x;
    }
}
void pop(int s[], int *y,int *top){
    if (*top == n){
        printf("stacjover");
    }else{
        *y = s[*top];
        (*top)--;
    }
}