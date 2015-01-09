/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: LexicographicallySmallestProblemBook.cpp
 * 创建日期: 2014年12月16日 星期二 07时16分45秒
 * 程序想法： 这是书中给出的代码！
程序运行结果：13719333	docode	3617	Accepted	336K	0MS	G++	1346B	2014-12-17 05:36:09
 */
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_N 2000
//输入
int N;
char S[MAX_N + 1];
//内部数据
int number=0;

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
	//剩余的字符串为S[a],S[a+1],...,S[b]
    int a = 0, b = N - 1;
    while (a <= b) {
	    if(number !=0 && number % 80 ==0) putchar('\n');
	    number++;
	//将从左起和从右起的字符串比较
	bool left = false;
	//这里我觉得a+i<=b-i,会更好一些！
	//这里我就实现我的这个更好！
	for (int i = 0; a + i <= b-i; i++) {
	    if (S[a + i] < S[b - i]) {
		left = true;
		break;
	    } else if (S[a + i] > S[b - i]) {
		left = false;
		break;
	    }
	}//做一个统一的比较，而不是分各种情况来比较！
	if (left)
	    putchar(S[a++]);
	else
	    putchar(S[b--]);
    }
    putchar('\n');
}
int main() {
    //test_input();
    input();
    //printf("\n%s\n--------------------\n", S);
    solve();
    return 0;
}
