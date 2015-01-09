/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: LexicographicallySmallestProblemS2.c
 * 创建日期: 2014年12月10日 星期三 14时06分05秒
 * 程序想法：S2代表第二步！
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
void input2() {
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++) {
	scanf("%[A-Z]", &S[i]);
    }
    S[i] = '\0';
}
void test_input() {
    //input();
    input2();
    printf("%d\n", N);
    int i;
    for (i = 0; i < N; i++) {
	printf("%d:%c\n", i, S[i]);
    }

    printf("\n%s\n--------------------\n", S);

}
int main() {
    test_input();
    return 0;
}
