/*在/usr/include/time.h中暂未找到time_t的定义*/
#include<stdio.h>
#include<time.h>
int main() {
	time_t biggest=0x7FFFFFFF;
	printf("biggest = %s \n",ctime(&biggest));
	printf("biggest = %s \n",asctime(gmtime(&biggest)));
	printf("current time = %s \n",ctime(&(time())));
	return 0;
}
/*biggest = Tue Jan 19 11:14:07 2038
 * 这是我在测试时输出的结果，1月19日 星期二 11:14:07 2038年

 * 书中是 biggest = Mon Jan 18 19:14:07 2038年
 * 是1月18日 星期一 19：14：07 2038年
 * */
