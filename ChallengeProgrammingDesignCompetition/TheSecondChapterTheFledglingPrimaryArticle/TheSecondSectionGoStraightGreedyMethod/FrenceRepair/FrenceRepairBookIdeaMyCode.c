/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: FrenceRepair.c
 * 创建日期: 2014年12月26日 星期五 06时12分34秒
 * 程序想法：作者没有排序，我用排序的办法把作者的思路实现一下！
 * 我需要自己制造几个数据来测试一下，看看程序哪里出问题了！
13755215	docode	3253	Wrong Answer			GCC	1843B	2015-01-01 06:00:51
我实在找不出来我的程序错在哪里了！
 */
#include<stdio.h>
#define MAX_N 20000
//输入数据
int N;
int L[MAX_N];

void swap(int *Aj, int *Aj1) {
    int originAj = (*Aj);
    *Aj = (*Aj1);
    *Aj1 = originAj;
}
void printarray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
	printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int n) {
    int swapped;
    do {
	swapped = 0;
	int i;
	//这里依然是每一次都从头开始比较，调换次序
	for (i = 1; i <= n - 1; i++) {
	    //printarray(A, n);
	    if (A[i - 1] > A[i]) {
		swap(&A[i - 1], &A[i]);
		swapped = 1;
	    }
	    //printarray(A, n);
	}
	//这里调换一次就让ｎ减一，这是一个我没有见过的处理办法！
	n = n - 1;
	//printf("a round end n=%d\n", n);
    } while (swapped);
}
void input() {
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++) {
	scanf("%d", &L[i]);
    }
}
void test_input() {
    printf("N=%d\n", N);
    int i;
    for (i = 0; i < N; i++) {
	printf("L[%d]=%d\n", i, L[i]);
    }
}

void solve() {
    int spending = 0;
    bubbleSort(L, N);
    int start = 0;
    printf("N=%d\n", N);
    printarray(L, N);
    while (start < N - 1) {
	printf("%d:(%d,%d)\n", start, L[start], L[start + 1]);
	spending += (L[start] + L[start + 1]);
	L[start + 1] = (L[start] + L[start + 1]);
	//printf("相加:"); printarray(L, N);
	int j;
	for (j = start + 1; j < N - 1; j++) {
	    //printf("(%d,%d)", start + 1, j); printarray(L, N);
//直接调整相邻项！
	    if (L[j + 1] < L[j]) {
		swap(&L[j + 1], &L[j]);
	    }
	}
	//printf("调整位置:");
	start++;
	printf("start=%d\n", start);
	for (j = start; j < N; j++) {
	    printf("%d ", L[j]);
	}
	printf("\n");

    }
    //printf("spending = %d\n", spending);
    printf("%d\n", spending);
}

int main() {
    input();
    //test_input();
    solve();
    return 0;
}
