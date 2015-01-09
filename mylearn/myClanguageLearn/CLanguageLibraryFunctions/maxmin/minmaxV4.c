/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: minmax.c
 * 创建日期: 2014年12月06日 星期六 06时48分16秒
 * 程序想法：这是ｇｃｃ建议使用的ｍｉｎ的宏定义！
 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a, b;

#define min(X,Y)  \
(__extension__  \
 ({  \
     typeof(X) __x=(X), __y=(Y);   \
        (__x<__y)?__x:__y;  \
	}) \
 ) 
#define max(X,Y)  \
(__extension__  \
 ({  \
     typeof(X) __x=(X), __y=(Y);   \
        (__x>__y)?__x:__y;  \
	}) \
 ) 

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
