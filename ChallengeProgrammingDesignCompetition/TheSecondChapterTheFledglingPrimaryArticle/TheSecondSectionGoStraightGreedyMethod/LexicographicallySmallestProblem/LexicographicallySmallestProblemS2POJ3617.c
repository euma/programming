/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: LexicographicallySmallestProblemS2.c
 * 创建日期: 2014年12月10日 星期三 14时06分05秒
 * 程序想法：不用删任何代码，只是把打印部分注释掉就可以！
程序测试结果：13716499	docode	3617	Time Limit Exceeded			GCC	2706B	2014-12-16 06:41:48
这正是我所设想的！
 * 打印出所有可能！
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LENGTH 2000
char S[MAX_LENGTH + 1];
char T[MAX_LENGTH + 1];
char minT[MAX_LENGTH + 1];
int N;

void input() {
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++) {
	scanf("%c", &S[i]);
	if (S[i] == '\n')
	    scanf("%c", &S[i]);
    }
    S[i] = '\0';
}

//我想先打印出
//n=3是，
void printarray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
    }
    printf("\n");
}

//问题是这里已经看到我想要的结果了，问题是这里为什么打印了两遍？
//虽然说我得到了正确的，想要的结果，但是我还是没有很彻底，很清晰地理解这个代码！

void dfs(int a[], int i, int n) {
    printf("dfs(%d)\t", i);
    printarray(a, n);
    if (i > 2) {
	printarray(a, n);
	return;
    }
    a[i] = 0;
    dfs(a, i + 1, n);
    a[i] = 1;
    dfs(a, i + 1, n);

}
void test_dfs() {
    int a[3] = { -1, -1, -1 };
    dfs(a, 0, 3);
}

//要看一下ｄｆｓ如何实现！
void printAllPossible(int ti, int s_start, int s_end) {
    if (s_start < s_end) {
	T[ti] = S[s_start];
	printAllPossible(ti + 1, s_start + 1, s_end);

	T[ti] = S[s_end];
	printAllPossible(ti + 1, s_start, s_end - 1);
    } else if (s_start == s_end) {
	T[ti] = S[s_end];
	printAllPossible(ti + 1, s_start, s_end - 1);
    } else {
	T[ti] = '\0';
	printf("%s\n", T);
	return;
    }
}
void countAllPossible(int ti, int s_start, int s_end) {
    if (s_start < s_end) {
	T[ti] = S[s_start];
	countAllPossible(ti + 1, s_start + 1, s_end);

	T[ti] = S[s_end];
	countAllPossible(ti + 1, s_start, s_end - 1);
    } else if (s_start == s_end) {
	T[ti] = S[s_end];
	countAllPossible(ti + 1, s_start, s_end - 1);
    } else {
	T[ti] = '\0';
	//printf("%s\n", T);
	if (strcmp(minT, T) > 0) {
	    strcpy(minT, T);
	}
	return;
    }
}

void test_printAllPossible() {
    int s_start = 0;
    int s_end = (int) strlen(S) - 1;
    printAllPossible(0, s_start, s_end);
}

void test_countAllPossible() {
    int s_start = 0;
    int s_end = (int) strlen(S) - 1;
    countAllPossible(0, s_start, s_end);
    //printf("minT=%s\n", minT);
}

void solve() {
    int s_start = 0;
    int s_end = (int) strlen(S) - 1;
    countAllPossible(0, s_start, s_end);
    printf("%s\n", minT);

}

int main() {
    input();
    //printf("%d\n", N);
    //printf("%s\n--------------------\n", S);
    T[0] = '\0';
    //printAllPossible();
    //printf("%s\n", T);
    //test_dfs();
    strcpy(minT, S);
    //test_printAllPossible();
    //test_countAllPossible();
    solve();
    return 0;
}

