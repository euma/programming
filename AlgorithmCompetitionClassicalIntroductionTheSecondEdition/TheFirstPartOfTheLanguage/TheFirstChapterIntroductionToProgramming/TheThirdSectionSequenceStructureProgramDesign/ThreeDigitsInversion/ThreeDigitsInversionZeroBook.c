#include<stdio.h>

int main() {

	int threeDigits;
	scanf("%d",&threeDigits);
	if (threeDigits<99 || threeDigits>999) {
		printf("同志你的输入有误，我们需要的是三位整数\n");
	}
	//这是书中的思路，我只是凭借我的记忆把它写下来！
	int ans;
	ans= (threeDigits%10)*100+((threeDigits/10)%10)*10+ threeDigits/100;
	printf("%d\n",ans);
	return 0;

}
