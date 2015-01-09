/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: AandB.c
 * 创建日期: 2015年01月03日 星期六 06时26分54秒
 * 程序想法： 
 */
#include<stdio.h>

int a, b;
void input() {
    scanf("%d%d", &a, &b);
}

void solve() {
    printf("%d", a + b);
}

int main() {
    input();
    solve();
    return 0;
}
