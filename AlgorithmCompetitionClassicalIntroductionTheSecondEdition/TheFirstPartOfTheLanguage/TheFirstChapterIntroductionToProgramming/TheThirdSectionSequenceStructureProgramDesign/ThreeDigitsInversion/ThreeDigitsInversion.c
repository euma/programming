#include<stdio.h>

int main() {

	int threeDigits;
	scanf("%d",&threeDigits);
	if (threeDigits<99 || threeDigits>999) {
		printf("同志你的输入有误，我们需要的是三位整数\n");
	}
	printf("%d",threeDigits%10);
	printf("%d",(threeDigits/10)%10);
	printf("%d",threeDigits/100);
	printf("\n");
	return 0;

}
