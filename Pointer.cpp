//
// Created by 管晓东 on 2019-07-25.
//

#include "Pointer.h"
#include <iostream>
using namespace std;
int sum(int a,int b){
    return a+b;
}
typedef int (*LP)(int,int);//定义了一个函数指针变量类型LP
int main(){
    LP p = sum;
    cout<<p(2,5);
    return 0;
}
