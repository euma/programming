/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: sort.cpp
 * 创建日期: 2014年12月06日 星期六 09时05分36秒
 * 程序想法：看一下ｓｏｒｔ函数的用法 
 * 按照从大到小的顺序排列！
 * 从这个网址学习的：　http://blog.csdn.net/zzzmmmkkk/article/details/4266888/
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

void input() {
}

bool compare(int a,int b) {
	return a>b;
}
void printarray(int a[]) {
    int i;
    for (i = 0; i < 20; i++)
	cout << a[i] << " ";
    cout << endl;

}

void solve() {
    int a[20] = { 2, 4, 1, 23, 5, 76, 0, 43, 24, 65 };
    printarray(a);
    sort(a, a + 10,compare);
    printarray(a);
}

int main() {
    input();
    solve();
    return 0;
}
