#include<cstdio>
#define MAX_N 100
bool used[MAX_N];
int perm[MAX_N];
//生成｛０，１，２，３，４，．．．，ｎ－１｝的ｎ！中排列
//我觉得首先形成我的工具，我用到排列时，我就可以用到这个代码！
void permutation1(int pos,int n) {
	if (pos==n) {
		/*
		 * 这里编写需要对ｐｅｒｍ进行的操作
		 */
		//最基本的操作就是打印出这个排列
		for (int i=0;i<n;i++) {
			printf("%d",perm[i]);
		}
		printf("\n");
		return;
	}
	//针对ｐｅｒｍ的第ｐｏｓ个位置，究竟使用０～ｎ－１中的哪一个进行循环
	for(int i=0;i<n;i++) {
		if(!used[i]) {
			perm[pos]=i;
			//ｉ已经被使用了，所以把标志设置位ｔｒｕｅ
			used[i]=true;
			/*
				printf("在位置%d加上%d ",pos,i);
				printf("递归之前: ");
			for (int j=0;j<n;j++) {
				printf("%d",perm[j]);
			}
			printf("\t");
			for (int j=0;j<n;j++) {
				if (used[j]) printf("T");
				else printf("F");
			}
			printf("\n");
*/

			permutation1(pos+1,n);
			//返回之后把标志复位
			//我想看一下没有这段代码，结果会怎么？
			//结果是只显示０，１，２，．．．，Ｎ－１
			//就是只遍历一遍！
			used[i]=false;
			/*
				printf("递归之后: ");
			for (int j=0;j<n;j++) {
				printf("%d",perm[j]);
			}
			printf("\t");
			for (int j=0;j<n;j++) {
				if (used[j]) printf("T");
				else printf("F");
			}
			printf("\n");
			*/

		}
	}
	return ;
}
int main() {
	int n;
	printf("请输入一个数字Ｎ，我们将给出｛０，１，２，．．．，Ｎ－１｝的Ｎ！中排列\n");
	scanf("%d",&n);
	//看一下刚开始ｐｅｒｍ［ｎ］与ｕｓｅｄ［ｎ］被赋予的初始值是什么？
	for (int j=0;j<n;j++) {
		printf("%d",perm[j]);
	}
	printf("\t");
	for (int j=0;j<n;j++) {
		if (used[j]) printf("T");
		else printf("F");
	}
	printf("\n------------------------\n");

	permutation1(0,n);
	return 0;
}
