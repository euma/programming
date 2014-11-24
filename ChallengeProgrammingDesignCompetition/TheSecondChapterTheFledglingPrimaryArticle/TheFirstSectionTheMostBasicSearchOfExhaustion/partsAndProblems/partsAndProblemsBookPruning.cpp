//书中的算法是在判断语句的条件中调用函数本身
//这让我看到了递归函数新的结构！
#include<cstdio>
#define MAX_N 20
//输入
int a[MAX_N];
int n,k;

//已经从前i项得到了和sum，然后对于i项之后的进行分支
//这里完全展示的就是一个判断！
bool dfs(int i,int sum) {
	//如果前n项都计算过了，则返回sum是否与k相等
	if(i==n) return sum==k;
	//不加上a[i]的情况
	if(dfs(i+1,sum)) return true;
	//加上a[i]的情况
	if(dfs(i+1,sum+a[i])) return true;
	//无论是否加上a[i]都不能凑成k就返回false
	return false;
}
void solve() {
	if(dfs(0,0)) printf("Yes\n");
	else printf("No\n");
}
void input(){
	scanf("%d",&n);
	int i;
	for (i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
}
int main() {
	input();
	solve();
	return 0;
}
