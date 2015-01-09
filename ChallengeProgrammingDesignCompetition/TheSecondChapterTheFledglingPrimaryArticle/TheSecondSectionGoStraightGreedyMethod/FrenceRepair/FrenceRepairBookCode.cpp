/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: FrenceRepairBookCode.cpp
 * 创建日期: 2014年12月30日 星期二 21时49分02秒
 * 程序想法： 我完全投降，我觉得自己的思路即使写出代码，也偏离正确方向太多！
 * 所以直接看作者的代码！
13753772	docode	3253	Accepted	424K	922MS	G++	1126B	2014-12-31 06:24:42
define MAX_N 是２００００，我写成２０００，少了一个零就出问题了！
 */
#include<cstdio>
#include<algorithm>
#define MAX_N 20000
using namespace std;

typedef long long ll;

//输入
int N,L[MAX_N];

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
	ll ans=0;
	//直到计算到木板为１块时为止
	while(N>1){
		//求出最短的板mii1和次短的板mii2
		int mii1=0,mii2=1;
		//这里有一个疑问，c++的ｓｗａｐ为什么可以不用＆？看能不能找到ｃ＋＋ｓｗａｐ的源代码！可以学习一下！
		//我的办法的可能问题是：板的位置应该不能随意改变，我的排序总是会随意改变板的位置！
		//可能的问题二：如果已经切割的合成板与一个未切割的板长度相同，那么我们应该选择未切割的！
		if(L[mii1]>L[mii2]) swap(mii1,mii2);
		//交换后的结果L[mii1]<L[mii2]
		for (int i=2;i<N;i++) {
			if(L[i]<L[mii1]) {
				mii2=mii1;
				mii1=i;
			}else if(L[i]<L[mii2]) {
				mii2=i;
			}
		}
		//将两块板拼合
		printf("(%d,%d)\n",L[mii1],L[mii2]);

		int t = L[mii1]+L[mii2];
		ans += t;

		if (mii1==N-1)swap(mii1,mii2);
		L[mii1]=t;
		L[mii2]=L[N-1];//这里相当于把L[mii2]丢弃了！
		N--;
		printf("N=%d\t",N);
		for (int i=0;i<N;i++) {
			printf("%d ",L[i]);
		}
		printf("\n");

	}
	printf("%lld\n",ans);
}


int main() {
    input();
    test_input();
    solve();
    return 0;
}
