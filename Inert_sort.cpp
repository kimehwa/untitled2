//
// Created by 管晓东 on 2019-07-24.
//

#include "Inert_sort.h"
#include <iostream>

using namespace std;
const int MAXN = 10001;

int main() {
    int n, i, j, k;
    float temp, a[MAXN];
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n; i++) {
        for (j = i - 1; j >= 0; j--) {//内层循环找到需要交换的位置
            if (a[i] > a[j])
                break;
        }
        if (j != i - 1) {//这里是因为需要右推，需要去掉边界
            temp = a[i];//先保存a[i]
            for (k =i - 1; k > j; k--) {
                a[k + 1] = a[k];
            }
            a[k + 1] = temp;//这里递推到了需要交换的位置了，需要插入到比a[i]大的位置
        }
    }
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
