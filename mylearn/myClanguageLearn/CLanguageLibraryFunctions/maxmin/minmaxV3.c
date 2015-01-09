/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: minmax.c
 * 创建日期: 2014年12月06日 星期六 06时48分16秒
 * 程序想法：这里使用了较为复杂的宏技术，这是在ｋｅｒｎｅｌ．ｈ中使用的ｍｉｎ与ｍａｘ定义！
 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a, b;
/*
 * min()/max() macros that also do
 * strict type-checking.. See the
 * "unnecessary" pointer comparison.
 */
//这里ｔｙｐｅｏｆ函数就是获取变量的数据类型！用于定义新变量的数据类型！
#define min(x,y) ({ \
 typeof(x) _x = (x); \
 typeof(y) _y = (y); \
 (void) (&_x == &_y);  \
 _x < _y ? _x : _y; })
#define max(x,y) ({ \
 typeof(x) _x = (x); \
 typeof(y) _y = (y); \
 (void) (&_x == &_y);  \
 _x > _y ? _x : _y; })

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
