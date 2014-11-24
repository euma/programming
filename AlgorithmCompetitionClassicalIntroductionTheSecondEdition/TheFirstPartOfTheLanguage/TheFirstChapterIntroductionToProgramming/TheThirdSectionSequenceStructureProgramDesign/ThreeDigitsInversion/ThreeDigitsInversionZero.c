#include<stdio.h>

int main() {

	int threeDigits;
	scanf("%d",&threeDigits);
	if (threeDigits<99 || threeDigits>999) {
		printf("同志你的输入有误，我们需要的是三位整数\n");
	}
	//当(threeDigits%10 == 0),我们就什么都不打印！
	if(threeDigits%10 != 0 )
	printf("%d",threeDigits%10);
	printf("%d",(threeDigits/10)%10);
	printf("%d",threeDigits/100);
	printf("\n");
	return 0;

}
