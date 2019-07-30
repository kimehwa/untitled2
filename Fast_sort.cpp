//
// Created by 管晓东 on 2019-07-24.
//

#include "Fast_sort.h"
#include <iostream>
using namespace std;
/**
 * 快速排序的缺点是需要一个栈空间来实现递归。每一趟排序都将记录
 * 均匀的分割成长度接近的两个子序列，那么栈的最大深度为log（n+1）。
 */
void qsort(int,int);
int a[101];
int main(){
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    qsort(1,n);
    for(i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void qsort(int l,int r){//这个比java的要简单一些 ，快速排序
    int i,j,mid,p;
    i=l;
    j=r;
    mid =a[(l+r)/2];
    do{
        while (a[i]<mid)
            i++;
        while (a[j]>mid)
            j--;
        if (i<=j){
            p=a[i];
            a[i]=a[j];
            a[j]=p;
            i++;
            j--;
        }
    }while(i<=j);
    if (l<j) qsort(l,j);
    if(i<r) qsort(i,r);

}
