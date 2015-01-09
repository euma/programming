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
    int n3=0;
    if (MAX_N % 3 ==0) { n3=MAX_N/3-1;}
    else { n3=MAX_N/3;}
    int n5=0;
    if (MAX_N % 5 ==0) { n5=MAX_N/5-1;}
    else { n5=MAX_N/5;}
    int n15=0;
    if (MAX_N % 15 ==0) { n15=MAX_N/15-1;}
    else { n15=MAX_N/15;}

    printf("计算sum3：%d\n", sum1n(n3));
    printf("计算sum5：%d\n", sum1n(n5));
    printf("计算sum15：%d\n", sum1n(n15));
    printf("计算形式二：%d\n",
	   3*sum1n(n3) + 5*sum1n(n5) - 15*sum1n(n15));
}

int main() {
    input();
    solve();
    return 0;
}
