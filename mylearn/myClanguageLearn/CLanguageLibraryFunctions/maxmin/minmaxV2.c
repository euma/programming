/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: minmax.c
 * 创建日期: 2014年12月06日 星期六 06时48分16秒
 * 程序想法：这里使用宏技术来实现ｍｉｎ，ｍａｘ函数！
 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a, b;
#define max(a,b) ( ((a)>(b)) ? (a):(b) )
#define min(a,b) ( ((a)>(b)) ? (b):(a) )

void input() {
    a = 1, b = 2;
}

void solve() {
    printf("min(%d,%d)=%d\n", a, b, min(a, b));
    printf("max(%d,%d)=%d\n", a, b, max(a, b));
}

int main() {
    input();
    solve();
    return 0;
}
