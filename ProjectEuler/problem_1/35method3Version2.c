/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: 35method3.c
 * 创建日期: 2015年01月04日 星期日 06时40分09秒
 * 程序想法：我用数学公式１＋２＋３＋．．．＋ｎ＝ｎ（ｎ＋１）／２ 
 * 计算出一个式子！
 */
#include<stdio.h>
#define MAX_N 1000

void input() {
}
int sum1n(int n) {
    return (n * (n + 1)) / 2;
}

void solve() {
    //(3+6+...+3m)+(5+10+...+5k)+(15+30+...+15l)
    //=3(1+2+...+m)+5(1+2+...+k)+15(1+2+...+l)
    //=3(m(m+1)/2)+5(k(k+1)/2)+15(l(l+1)/2)
    //m=n/3,k=n/5,l=n/15
    int n=MAX_N-1;//使用９９９
    printf("计算sum3：%d\n", sum1n(n/3));
    printf("计算sum5：%d\n", sum1n(n/5));
    printf("计算sum15：%d\n", sum1n(n/15));
    printf("计算形式二：%d\n",
	   3*sum1n(n/3) + 5*sum1n(n/5) - 15*sum1n(n/15));
}

int main() {
    input();
    solve();
    return 0;
}
