/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: FrenceRepair.c
 * 创建日期: 2014年12月26日 星期五 06时12分34秒
 * 程序想法：先计算ｎ块木板的全部可能开销 
 *　我使用自己的数据
 总是先切出当前最大的那个板！
 一种办法是做到最大的，开销就是最大的加剩下的长度
 接着在剩下的里找最大的，剩下这块板的当前开销就是最大的加剩下的长度，当前总开销就是已经求出的最大的，加剩下的最大的，加剩下的长度
 办法二
 直接借助排序算法，先排列，
 我用数学方法计算出来的ｓｐｅｎｄｉｎｇ＝n*A1+(n-1)*A2+...+2*An-1+1*An-A1
 ={n,n-1,...,2,1}*{A1,A2,...,An}-A1;
排序算法从文件BubbleSortOptimizing.c复制过来！
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
    int i;
    int spending = 0;
    bubbleSort(L, N);
    for (i = 0; i < N; i++) {
	spending += L[i] * (N - i);
    }
    spending -= L[0];
    //printf("spending = %d\n", spending);
    printf("%d\n", spending);
}

int main() {
    input();
    //test_input();
    solve();
    return 0;
}
