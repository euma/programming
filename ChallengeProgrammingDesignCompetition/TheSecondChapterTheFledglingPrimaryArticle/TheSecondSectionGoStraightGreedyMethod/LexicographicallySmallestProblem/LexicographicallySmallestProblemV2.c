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
    scanf("%s", S);
}

void solve() {

    int ti = 0;
    int s_start = 0;
    int s_end = (int) strlen(S) - 1;
    T[0] = '\0';
    printf("out while(%d<%d)ti=%d\n",s_start,s_end,ti);
    while (s_start < s_end) {
	if (S[s_start] < S[s_end]) {
	    T[ti] = S[s_start];
	    s_start++;
	    ti++;
	} else if (S[s_start] > S[s_end]) {
	    T[ti] = S[s_end];
	    s_end--;
	    ti++;

	} else {
	    int i;
	    //这里来一个判断变量，表示是否添加最前面的！
	    int is_start = 1;
	    for (i = s_start - 1; i <= s_end - 1; i++) {
		if (S[i] > S[s_end - i]) {
		    is_start = 0;
		}
	    }
	    if (is_start) {
		T[ti] = S[s_start];
		s_start++;
		ti++;
	    } else {
		T[ti] = S[s_end];
		s_end--;
		ti++;
	    }
	}
    printf("while(%d<%d)ti=%d\n",s_start,s_end,ti);
    int j;
    //j<=ti中等号是必须的，因为我打印的是未改变前的ｔｉ,等号有和没有作用一样！
    for (j=0;j<=ti;j++) {
	    printf("%c",T[j]);
    }
    printf("\n");

    }
    if (s_start == s_end) {
	T[ti] = S[s_end];
	//s_end--;
	ti++;
    }

    T[ti] = '\0';
    printf("T=%s\n", T);
}
int main() {
    input();
    printf("%d\n", N);
    printf("%s\n--------------------\n", S);
    solve();
    return 0;
}
