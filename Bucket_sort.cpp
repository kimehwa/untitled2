//
// Created by 管晓东 on 2019-07-24.
//

#include "Bucket_sort.h"
#include <iostream>

using namespace std;

int main() {
    /**
     * 输入n个1-100之间的整数，用桶排序有小到大排序输出
     */
    int b[101], n, i, j, k;
    memset(b, 0, sizeof(b));//初始化函数，把b数组内的所有的位置都填充为0
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> k;
        b[k]++;//将所有等于k的值全部装入第k个桶中
    }
    for (i = 0; i < 100; i++) {//依次遍历起每个桶
        while (b[i] > 0) {//每一个桶有多个数字要重复输出
            cout << i << " ";
            b[i]--;
        }
    }
    cout << endl;
}