/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: minmax.c
 * 创建日期: 2014年12月06日 星期六 06时48分16秒
 * 程序想法：这里看一下，ｃ语言自带了ｍｉｎ函数没有
 * 结论是ｃ语言中没有现成的ｍｉｎ，需要自己实现！
 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a, b;

int max(int a,int b) {
	return a>b?a:b;
}
int min(int a,int b) {
	return a<b?a:b;
}
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
