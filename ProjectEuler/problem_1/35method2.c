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
	int sum3=0;
	for (i=1;i<MAX_N;i++) {
		if (i%3==0) {
			sum3 += i;
		}
	}
	int sum5=0;
	for (i=1;i<MAX_N;i++) {
		if (i%5==0) {
			sum5 += i;
		}
	}
	int sum15=0;
	for (i=1;i<MAX_N;i++) {
		if (i%15==0) {
			sum15 += i;
		}
	}
	int sum=sum3+sum5-sum15;

	printf("sum3 = %d\n",sum3);
	printf("sum5 = %d\n",sum5);
	printf("sum15 = %d\n",sum15);
	printf("sum = %d\n",sum);
}

int main() {
    input();
    solve();
    return 0;
}

