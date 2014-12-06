/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: minmax.cpp
 * 创建日期: 2014年12月06日 星期六 07时20分22秒
 * 程序想法： 使用ａｌｇｏｒｉｔｈｍ自带的ｍｉｎｍａｘ函数！
 */
#include<cstdio>
#include<algorithm>
using namespace std;

int a,b;

void input() {
	a=8;
	b=2;
}

void solve() {
	printf("min(%d,%d)=%d\n",a,b,min(a,b));
	printf("max(%d,%d)=%d\n",a,b,max(a,b));
}

int main() {
    input();
    solve();
    return 0;
}

