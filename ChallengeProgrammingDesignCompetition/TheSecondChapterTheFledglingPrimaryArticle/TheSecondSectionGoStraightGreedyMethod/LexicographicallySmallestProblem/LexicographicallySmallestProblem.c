/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: LexicographicallySmallestProblem.c
 * 创建日期: 2014年12月10日 星期三 14时06分05秒
 * 程序想法：这个问题更侧重与字符的操作 
 */
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 2000
char S[MAX_LENGTH+1];
char T[MAX_LENGTH+1];
int N;

void input() {
	scanf("%d",&N);
	scanf("%s",S);
}

void solve() {
	//printf("string(%s) length = %d\n",S,(int)strlen(S));
	int ti=0;
	int s_start=0;
	int s_end=(int)strlen(S)-1;
	//需要处理
	//S="";令Ｔ［０］＝＇＼０＇可以保证不用进行比较，直接得到Ｔ＝＂＂；
	//s_start=0,s_end=0-1;无法通过ｗｈｉｌｅ语句的判断
	T[0]='\0';
	//S的长度为偶数，可以很好地处理
	while (s_start<s_end) {
		T[ti]=S[s_start];
		s_start++;
		ti++;

		T[ti]=S[s_end];
		s_end--;
		ti++;
	}
	//s_start与s_end相同时，是无法进入ｗｈｉｌｅ的，所以只能在ｗｈｉｌｅ之外处理
	if (s_start==s_end) {
		T[ti]=S[s_end];
		ti++;
	}
	T[ti]='\0';
}

int main() {
    input();
    printf("%d\n",N);
    printf("%s\n",S);
    solve();
    printf("%s\n",T);
    return 0;
}

