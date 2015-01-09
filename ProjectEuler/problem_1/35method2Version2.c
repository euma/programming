/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: 35method1.c
 * 创建日期: 2015年01月04日 星期日 06时30分25秒
 * 程序想法： 
 */
#include<stdio.h>
#define MAX_N 1000

void input() {
}

void solve() {
	int i;
	int sum=0;
	for (i=1;i<MAX_N;i++) {
		if (i%3==0) {
			sum += i;
		}
		if (i%5==0) {
			sum += i;
		}
		if (i%15==0) {
			sum -= i;
		}

	}
	printf("sum = %d\n",sum);
}

int main() {
    input();
    solve();
    return 0;
}

