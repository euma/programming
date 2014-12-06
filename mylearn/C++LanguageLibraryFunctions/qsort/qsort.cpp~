/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: qsort.cpp
 * 创建日期: 2014年12月06日 星期六 09时34分43秒
 * 程序想法：
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

void printarray(int a[]) {
    int i;
    for (i = 0; i < 20; i++)
	cout << a[i] << " ";
    cout << endl;
}
void input() {
}

int compare(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

void solve() {
    int a[20] = { 2, 4, 1, 23, 5, 76, 0, 43, 24, 65 };
    printarray(a);
    qsort((void *) a, 20, sizeof(int), compare);
    printarray(a);
}

int main() {
    input();
    solve();
    return 0;
}

