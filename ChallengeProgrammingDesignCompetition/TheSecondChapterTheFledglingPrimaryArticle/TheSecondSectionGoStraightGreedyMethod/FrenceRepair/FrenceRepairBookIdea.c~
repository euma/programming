/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: FrenceRepairAllPossible.c
 * 创建日期: 2014年12月28日 星期日 06时38分01秒
 * 程序想法：先实现给定一个排列，我找出所有分割下的花销！ 
 * 以两个最小的，两个最小的方式处理！
 */
#include<stdio.h>
#define MAX_N 20000
//输入数据
int N;
int L[MAX_N];
//内部数据

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
    int i;
    int spending = 0;
    bubbleSort(L, N);
    int overallLength=0;
    for (i = 0; i < N; i++) {
    overallLength+=L[i];
    }
    int theRemainingLength=overallLength;
    for (i = 0; i < N; i++) {
	    if (i<N&&i+1<N) {
	spending += L[0] + L[1]};
	spending += theRemainingLength;
	    }
	    }
    }
    spending -= L[0];
    //printf("spending = %d\n", spending);
    printf("%d\n", spending);
}

int main() {
    input();
    test_input();
    //solve();
    test_cutting();
    return 0;
}
