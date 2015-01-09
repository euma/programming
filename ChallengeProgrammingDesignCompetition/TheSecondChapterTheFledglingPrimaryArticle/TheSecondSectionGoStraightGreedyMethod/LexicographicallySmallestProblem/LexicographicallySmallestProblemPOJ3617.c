/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: LexicographicallySmallestProblemS2.c
 * 创建日期: 2014年12月10日 星期三 14时06分05秒
 * 程序想法：S2代表第二步！
 * 运行结果：13713793	docode	3617	Accepted	364K	16MS	GCC	3530B	2014-12-15 06:59:51
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
void test_input() {
    input();
    printf("%d\n", N);
    int i;
    for (i = 0; i < N; i++) {
	printf("%d:%c\n", i, S[i]);
    }

    printf("\n%s\n--------------------\n", S);

}

void solve() {

    int ti = 0;
    int s_start = 0;
    int s_end = (int) strlen(S) - 1;
    T[0] = '\0';
    //printf("out while(%d<%d)ti=%d\n", s_start, s_end, ti);
    while (s_start < s_end) {
	//printf("while(%d<%d)\n", s_start, s_end);
	if (S[s_start] < S[s_end]) {
	    T[ti] = S[s_start];
	    //printf("<-------------%d:%c from %d:%c\n", ti, T[ti], s_start, S[s_start]);
	    //printf("%d:%c\t",s_start, S[s_start]);
	    s_start++;
	    ti++;
	} else if (S[s_start] > S[s_end]) {
	    T[ti] = S[s_end];
	    //printf(">=============%d:%c from %d:%c\n", ti, T[ti], s_end, S[s_end]);
	    //printf("%d:%c\t",s_end, S[s_end]);
	    s_end--;
	    ti++;

	} else {
	    //这里来一个判断变量，表示是否添加最前面的！
	    int is_start = 1;
	    //这里错了，for (i = s_start - 1; i <= s_end - 1; i++) {,我想要的是
	    // for (i = s_start + 1; i <= s_end - 1; i++) {因为我需要从开头的后一个要＋１，以及结束的前一个要－１,另外ｉ不能循环到结尾，而是循环到中间，因为我是从两头同时开始比较的！这样看来用ｗｈｉｌｅ好，因为我不必关心ｉ循环到中间的那个位置停止，其实这个位置也可以计算出来，就是（头＋尾）／２
	    // 这里ｉ只需要进展到二分之一！
	    // 我觉得建立一个ｎｅｗ＿ｓｔａｒｔ，ｎｅｗ＿ｅｎｄ比较好！
	    // 或者叫ｉｎｎｅｒ＿ｓｔａｒｔ，ｉｎｎｅｒ＿ｅｎｄ比较好！
	    // 这里我觉得用ｗｈｉｌｅ比用ｆｏｒｉ好，因为这使得代码直接表达了我想要表达的意思！
	    int new_start = s_start + 1;
	    int new_end = s_end - 1;
	    while (new_start < new_end) {
		//printf("new_start=%d,new_end=%d\t compare %c,%c\n",
		//new_start, new_end, S[new_start], S[new_end]);
		//确实这里需要两个ｂｒｅａｋ,这里我给出一个反例，DBECFD
		if (S[new_start] < S[new_end]) {
		    break;
		}
		if (S[new_start] > S[new_end]) {
		    is_start = 0;
		    break;
		    //对这里应该加一个ｂｒｅａｋ，
		    //不然无法正确处理这样的情况
		    //ABDAECA
		    //但是我测试的结论是，好像不用关心这个测试
		    //直接选一个就行
		    //这样一来，我觉得我需要测试四种代码，直接选前面的，直接选后面的，用ｂｒｅａｋ，不用ｂｒｅａｋ
		}

		new_start++;
		new_end--;
	    }
	    if (is_start) {
		T[ti] = S[s_start];
		//printf("compare<---------------------%d:%c from %d:%c\n", ti, T[ti], s_start,
		//printf("%d:%c\t",s_start, S[s_start]);
		s_start++;
		ti++;
	    } else {
		T[ti] = S[s_end];
		//printf("compare>=====================%d:%c from %d:%c\n", ti, T[ti], s_end, S[s_end]);
		//printf("%d:%c\t",s_end, S[s_end]);
		s_end--;
		ti++;
	    }
	}

	/*
	   printf("while(%d<%d)ti=%d\n", s_start, s_end, ti);

	   int j;
	   //j<=ti中等号是必须的，因为我打印的是未改变前的ｔｉ,等号有和没有作用一样！
	   for (j = 0; j <= ti; j++) {
	   printf("%c", T[j]);
	   }
	   printf("\n");
	 */

    }
    if (s_start == s_end) {
	T[ti] = S[s_end];
	//printf("%d:%c\n",s_end, S[s_end]);
	//s_end--;
	ti++;
    }

    T[ti] = '\0';
    //printf("T=%s\n", T);

    int i;
    //这里可以用ｓｔｒｌｅｎ（T)来代替ｔｉ，不过用
    //ｔｉ更方便！
    for (i = 0; i < ti; i++) {
	if (i != 0 && i % 80 == 0)
	    printf("\n");
	printf("%c", T[i]);
    }
    printf("\n");
}
int main() {
    //test_input();
    input();
    //printf("\n%s\n--------------------\n", S);
    solve();
    return 0;
}
