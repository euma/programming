/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: BubbleSortStandardCLanguageCode.c
 * 创建日期: 2014年12月09日 星期二 07时07分45秒
 * 程序想法： 代码已经很熟悉，我只是看一下，ｐｕｔｓ函数可以打印＼ｎ不？
 */

#include <stdio.h>
#define LENGTH 8
int main() {
    int i, j, temp, number[LENGTH] = { 95, 45, 15, 78, 84, 51, 24, 12 };
    for (i = 0; i < LENGTH - 1; i++)
	for (j = 0; j < LENGTH - 1 - i; j++)
		//把大的往后面换！
	    if (number[j] > number[j + 1]) {
		temp = number[j];
		number[j] = number[j + 1];
		number[j + 1] = temp;
	    }			//if end
    for (i = 0; i < LENGTH; i++)
	printf("%d ", number[i]);
    //puts("");
    puts("haha\n");
    return 0;
}				//main end
