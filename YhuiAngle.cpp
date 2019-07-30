//
// Created by 管晓东 on 2019-07-25.
//

#include "YhuiAngle.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a[11][11];
    a[1][1] = 1;

    for (int i = 2; i <= 10; ++i) {//这里的++i和i++有什么区别
        //根据上面的for循环的语法定义 ++i 和 i++的结果是一样的，都要等代码块执行完毕才能执行语句3，但是性能是不同的。在大量数据的时候++i的性能要比i++的性能好原因：
        //
        //i++由于是在使用当前值之后再+1，所以需要一个临时的变量来转存。
        //
        //而++i则是在直接+1，省去了对内存的操作的环节，相对而言能够提高性能
        a[i][1] = 1;
        a[i][i] = 1;
        for (int j = 2; j <= i - 1; ++j) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for (int i = 1; i <= 10; ++i) {
        if (i != 10)
            cout << setw(30 - 3 * i) << " ";//控制每一行的起始位置，即空格位置
        for (int j = 1; j <= i; ++j) {
            cout << setw(6) << a[i][j];
        }
        cout << endl;
    }
    return 0;


}
