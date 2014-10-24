#include<stdio.h>
#define MAX_N 1000000
int x[MAX_N];//数组放在main函数的外面会好一些，main函数里用的是栈空间
//在main函数外用的是外部存储空间，一般栈空间都比较小，外部存储空间比较大！
/*理解了书中的思路后，我用自己的代码来实现一下*/
int main() {
	int L,n,i;//这里x数组应该可以采用动态分配空间的办法，我这里直接分配空间只是一个简单处理，我只是想先去实现整个程序中最重要的部分，这里可以以后更改。
	//先处理一组数据，问题中直接给出了两组数据
	scanf("%d%d",&L,&n);
	for (i=0;i<n;i++) {
		scanf("%d",&x[i]);
	}
	int earliestTime=-1,latestTime=-1;
	for (i=0;i<n;i++) {
		if (x[i]>L/2) {
			if (L-x[i]>earliestTime) earliestTime=L-x[i];
			if (x[i]>latestTime) latestTime=x[i];
		} else {
			if (x[i]>earliestTime) earliestTime=x[i];
			if (L-x[i]>latestTime) latestTime=L-x[i];
		}
	}
	printf("%d %d\n",earliestTime,latestTime);
	return 0;
}
