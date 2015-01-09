/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: SarumansArmy.c
 * 创建日期: 2014年12月17日 星期三 07时03分24秒
 * 程序想法：直接写代码了，我的思路就体现在代码中！ 
 * 书中的问题算是解决了，ｐｏｊ中相同的问题，有一些变换，我需要作出改变来实现之！
 * 这里解决ｐｏｊ问题
 * 对数据需要排序？
 * 首先要测试读取格式！
 * 这里我把我最新学到的冒泡算法放进来排序！
 */
#include<stdio.h>
#define MAX_N 1000
//输入
int N;
int R;
int X[MAX_N];
//内部数据
int markX[MAX_N];
void swap(int *Aj, int *Aj1) {
    int originAj = (*Aj);
    *Aj = (*Aj1);
    *Aj1 = originAj;
}

//本题中只有一千个数字，用冒泡排序足够了！
void bubbleSort(int A[], int n) {
    int newn;
    do {
	newn = 0;
	int i;
	//这里依然是每一次都从头开始比较，调换次序
	for (i = 1; i <= n - 1; i++) {
	    if (A[i - 1] > A[i]) {
		swap(&A[i - 1], &A[i]);
		newn = i;
	    }
	}
	n = newn;
    } while (n);
}
int oneCaseInput() {
    scanf("%d%d", &R, &N);
    if (N == (-1) && R == (-1))
	return 0;
    int i;
    for (i = 0; i < N; i++) {
	scanf("%d", &X[i]);
    }
    return 1;
}
void test_oneCaseInput() {
    while (oneCaseInput()) {
	printf("R=%d\t", R);
	printf("N=%d\n", N);
	printf("X={");
	int i;
	for (i = 0; i < N; i++) {
	    printf("%d,", X[i]);
	}
	printf("}\n");
    }

}
void printmarkX(int markX[], int N) {
    int i;
    for (i = 0; i < N; i++) {
	printf("%d:%d\t", X[i], markX[i]);
    }
    printf("\n");
}

void solveOneCase() {
    int i;
    for (i = 0; i < N; i++) {
	markX[i] = 0;
    }
    //从开头出发，先找到在Ｒ范围内，离开头最远的点！
    //printmarkX(markX, N);
    bubbleSort(X, N);
    int markx = 0;
    int j;
    for (j = 1; j < N; j++) {
	if (X[j] - X[0] <= R)
	    markx = j;
    }
    //这里会出现两种情况，一种是没有找到，一种是找到了
    //对于第一种情况的处理，由于我已经令markx的初值为i,所以会标记ｉ本身！ 对于第二种情况，将标记最远的点
    markX[markx] = 1;
    //这时要寻找下一个标记点
    //如果markx是最后一个点，我们就不用处理了
    //printmarkX(markX, N);
    while (markx < N) {
	int k;
	int find = 0;
	for (k = markx + 1; k < N; k++) {
	    if (X[k] - X[markx] > R) {
		markx = k;
		markX[k] = 1;
		find = 1;
		//printmarkX(markX, N);
		break;
	    }
	}
	if (!find)
	    break;
    }
    int count = 0;
    for (i = 0; i < N; i++) {
	if (markX[i])
	    count++;
    }
    //printf("\ncount=%d\n", count);
    printf("%d\n", count);
}

void solve() {
    while (oneCaseInput()) {
	solveOneCase();
    }
}


int main() {
    //test_oneCaseInput();
    solve();
    return 0;
}
