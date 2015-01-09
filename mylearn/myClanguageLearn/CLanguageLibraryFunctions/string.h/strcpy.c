/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: strcpy.c
 * 创建日期: 2014年12月11日 星期四 06时34分56秒
 * 程序想法： 我在这里实现复制一个字符串的工作！
 */
#include<stdio.h>
#include<string.h>

void input() {
}

void solve() {
}
void copyTheString() {
	char a[8]="abc";
	char b[8];
	strcpy(b,a);
	printf("a=%s\n",a);
	printf("b=%s\n",b);
}

int main() {
    input();
    solve();
copyTheString() ;
    return 0;
}

