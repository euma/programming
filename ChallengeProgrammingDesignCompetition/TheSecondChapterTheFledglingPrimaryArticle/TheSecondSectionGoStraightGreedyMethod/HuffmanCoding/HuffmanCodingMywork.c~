/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: HuffmanCodingMywork.c
 * 创建日期: 2015年01月06日 星期二 11时11分46秒
 * 程序想法：
 * 我需要一步一步地实现霍夫曼编码
 * 第一步，给出需要压缩的字符串，第二步，显示需要压缩的字符串！
 * 我们直接来看示例，如果我们需要来压缩下面的字符串：
 * 要实现对文件的压缩，办法有一行一行的读取，一行一行地压缩，
 * 也可以规定一次读取的字符的多少，然后以那个多少来处理！
 * 为一个实际的文件进行霍夫曼编码压缩不是我现在要实现的！我先初步掌握霍夫曼编码本身比较重要！
 * 第二步，统计出现的字符，以及其出现的次数！
 * 第三步，按出现频率排序数组！
 *
 *  “beep boop beer!”  
 */
#include<stdio.h>
#include<string.h>
#define N 100
int main() {
	char needToCompressString[N]="beep boop beer!";
	printf("need to compress string is \n\t%s\n",needToCompressString);
	char appearedCharacter[N];
	int compressLength=strlen(needToCompressString);
	//我不想详细统计上面数组的大小，只是给出一个最大上界，这里具体细节我可以不去处理，最重要的还是看懂霍夫曼编码本身！
	printf("need to compress string length is \n\t%d\n",compressLength);
	int i;
	int j;
	int appearedCharacterLength=0;
	//一步一步走，先找到出现的字符，在计算字符的出现频率！把这两步合起来现在还比较困难，放在以后实现！
	//或者说我两种方式都要实现，只不过要先实现最简单的方式，或者工作任务最单一的方式！
	for (i=0;i<compressLength;i++) {
		int whichAppear=0;
		int find=0;
		for (j=0;j<appearedCharacterLength;j++) {
			if (appearedCharacter[j]==needToCompressString[i]) {
				whichAppear=j;
				find=1;
				break;
			}
		}
		if (!find) {
			appearedCharacter[appearedCharacterLength]=needToCompressString[i];
			appearedCharacterLength++;
			printf("new one add :%d\n", appearedCharacterLength-1);
		} else {

			printf("which one find :%d\n",whichAppear);
			appearedCharacter[whichAppear]=needToCompressString[i];
		}
		for (j=0;j<appearedCharacterLength;j++) {
			printf("%d: %c\t",j,appearedCharacter[j]);
		}
		printf("\n");

	}
	for (j=0;j<appearedCharacterLength;j++) {
		printf("%d: %c\t",j,appearedCharacter[j]);
	}
	printf("\n");
	int appearedCharacterFrequency[N];
	for (j=0;j<appearedCharacterLength;j++) {
		appearedCharacterFrequency[j]=0;
	}

	for (i=0;i<compressLength;i++) {
		for (j=0;j<appearedCharacterLength;j++) {
			if (appearedCharacter[j]==needToCompressString[i]) {
				appearedCharacterFrequency[j]++;
				break;
			}
		}
	}
	for (j=0;j<appearedCharacterLength;j++) {
		printf("%d: %c :%d\t",j,appearedCharacter[j], appearedCharacterFrequency[j]);
	}
	printf("\n");
	for (i = 0; i < appearedCharacterLength - 1; i++) {
		for (j = 0; j < appearedCharacterLength - 1 - i; j++) {
			if ( appearedCharacterFrequency[j]>appearedCharacterFrequency[j+1]){
				int temp = appearedCharacterFrequency[j];
				appearedCharacterFrequency[j]=appearedCharacterFrequency[j+1];
				appearedCharacterFrequency[j+1]=temp;

				char tempchar = appearedCharacter[j];
				appearedCharacter[j]=appearedCharacter[j+1];
				appearedCharacter[j+1]=tempchar;

			}
		}
	}

	for (j=0;j<appearedCharacterLength;j++) {
		printf("%d: %c :%d\t",j,appearedCharacter[j], appearedCharacterFrequency[j]);
	}
	printf("\n");

	return 0;
}
