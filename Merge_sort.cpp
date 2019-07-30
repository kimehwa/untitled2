//
// Created by 管晓东 on 2019-07-24.
//

#include "Merge_sort.h"
//#include <iostream>
//using namespace std;
//void mergeSort(int s,int t){
//
////    int r[] = new int[sizeof(a)];
//    if(s==t) return;
//    int mid = (s+t)/2;
//    mergeSort(s,mid);//分解左边的序列
//    mergeSort(mid+1,t);//分解右边的序列
//    int i = s,j=mid+1,k=s;
//    while(i<=mid&&j<=t){
//        if (a[i]<a[j]){
//            r[k]=a[i];
//            k++;i++;
//        }
//    }
//    while (i<mid){
//        r[k]=a[i];
//        i++;
//        k++;
//    }
//    while(j<=t){
//        r[k]=a[j];
//        k++;
//        j++;
//    }
//    for(int i =s;i<=t;i++){
//        a[i]=r[i];
//    }
//
//}
#include<iostream>

using namespace std;
const int maxn = 500000, INF = 0x3f3f3f3f;
/**
 * INF设置为这个16进制的数字是有特殊的含义，它可以作为无穷大使用而不至于出现数据大于无穷大的情况。
 * 另一方面，由于一般的数据都不会大于10^9，所起不会溢出，满足了无穷大加无穷大还是无穷大的需求
 * 2.Inf设置为这个值，如果我们想要将某个数组全部赋值为0通常使用memset函数，但是我们要想将某个数组全部
 * 赋值为无穷大的时候，就不能使用memeset函数而只能自己写循环了，因为memeset是按字节操作的，它能够对数组清
 * 0是因为0的每个字节都是0，所以我们要将无穷大设置为无穷大可以遮掩进行设置
 */
int L[maxn / 2 + 2], R[maxn / 2 + 2];

void merge(int a[], int n, int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[mid + i];
    L[n1] = R[n2] = INF;//将之设置成了无穷大
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {//从小到大进行赋值
        if (L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }
}

void mergesort(int a[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergesort(a, n, left, mid);
        mergesort(a, n, mid, right);
        merge(a, n, left, mid, right);
    }
}

int main() {
    int a[maxn], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a, n, 0, n);
    for (int i = 0; i < n; i++) {
        if (i)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}

