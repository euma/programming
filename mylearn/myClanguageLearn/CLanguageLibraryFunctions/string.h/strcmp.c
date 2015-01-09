/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: strcmp.c
 * 创建日期: 2014年12月11日 星期四 06时41分56秒
 * 程序想法： 
 */
#include<stdio.h>
#include<string.h>

void input() {
}

void solve() {
}
void compareStrings() {
    char a[5] = "abc";
    char b[5] = "acc";
    char c[5] = "adc";
    char d[5] = "adc";
    printf("cmp(%s,%s)=%d\n", a, b, strcmp(a, b));
    printf("cmp(%s,%s)=%d\n", c, b, strcmp(c, b));
    printf("cmp(%s,%s)=%d\n", c, d, strcmp(c, d));
}

int main() {
    input();
    solve();
    compareStrings();
    return 0;
}
