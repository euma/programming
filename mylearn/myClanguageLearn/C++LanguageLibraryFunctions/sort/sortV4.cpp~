/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: sort.cpp
 * 创建日期: 2014年12月06日 星期六 09时05分36秒
 * 程序想法：看一下ｓｏｒｔ函数的用法 
 * 按照从大到小的顺序排列！
 * 其实对于这么简单的任务（类型支持“<”、“>”等比较运算符），完全没必要自己写一个类出来。标准库里已经有现成的了，就在functional里，include进来就行了。functional提供了一堆基于模板的比较函数对象。它们是（看名字就知道意思了）：equal_to<Type>、not_equal_to<Type>、greater<Type>、greater_equal<Type>、less<Type>、less_equal<Type>。对于这个问题来说，greater和less就足够了，直接拿过来用：
 * 从这个网址学习的：　http://blog.csdn.net/zzzmmmkkk/article/details/4266888/
 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

void input() {
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
    sort(a, a + 10, greater<int>());
    printarray(a);
    sort(a, a + 10, less<int>());
    printarray(a);
}

int main() {
    input();
    solve();
    return 0;
}
