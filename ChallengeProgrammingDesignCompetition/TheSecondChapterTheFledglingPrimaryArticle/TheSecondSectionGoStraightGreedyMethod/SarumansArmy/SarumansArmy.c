/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: SarumansArmy.c
 * 创建日期: 2014年12月17日 星期三 07时03分24秒
 * 程序想法：直接写代码了，我的思路就体现在代码中！ 
 * 书中的问题算是解决了，ｐｏｊ中相同的问题，有一些变换，我需要作出改变来实现之！
 * 我根据我对作者代码的分析，我按照我自己的想法来写代码，改进我以前写的代码！
 * 作者的代码成功通过了ｐｏｊ的测试！
 */
#include<stdio.h>
#define MAX_N 1000
//输入
int N;
int R;
int X[MAX_N];
//内部数据
int markX[MAX_N];

void input() {
    scanf("%d", &N);
    scanf("%d", &R);
    int i;
    for (i = 0; i < N; i++) {
	scanf("%d", &X[i]);
    }
}
void test_input() {
    input();
    printf("N=%d\n", N);
    printf("R=%d\n", R);
    printf("X={");
    int i;
    for (i = 0; i < N; i++) {
	printf("%d,", X[i]);
    }
    printf("}\n");

}
void printmarkX(int markX[], int N) {
    int i;
    for (i = 0; i < N; i++) {
	printf("%d:%d ", X[i], markX[i]);
    }
    printf("\n");
}

void solve() {
    int i;
    for (i = 0; i < N; i++) {
	markX[i] = 0;
    }
    int center, leftEdge, rightEdge;
    leftEdge = 0;
    center = 0;
    rightEdge = 0;
    //初步框架有了，但是细节处还需要探讨！
    //while (rightEdge < N && leftEdge < N && center < N) {
    while (leftEdge < N) {
	printf("while (%d,%d,%d)\n", leftEdge, center, rightEdge);
	//find center,从左边缘开始寻找中心！
	//j = leftEdge不排除中心就是左边缘！
	int j;
	for (j = leftEdge; j < N; j++) {
	    if (X[j] - X[leftEdge] <= R)
		center = j;
	}
	markX[center] = 1;
	printmarkX(markX, N);
	//从中心开始寻找右边缘！
	for (j = center; j < N; j++) {
	    if (X[j] - X[center] <= R) {
		rightEdge = j;
	    }
	}
	/*
	if (X[rightEdge] - X[center] == R)
	    leftEdge = rightEdge;//这个处理是错的，我可以用N=6,R=10,X={1,11,21,31,41,51}这个数据来测试其错误性！
	else
	    leftEdge = rightEdge + 1;
	    */
	    leftEdge = rightEdge + 1;
    }

    int count = 0;
    for (i = 0; i < N; i++) {
	if (markX[i]) {
	    printf("%d:%d\t", i, X[i]);
	    count++;
	}
    }

    printf("\ncount=%d\n", count);
}

int main() {
    input();
    test_input();
    solve();
    return 0;
}
