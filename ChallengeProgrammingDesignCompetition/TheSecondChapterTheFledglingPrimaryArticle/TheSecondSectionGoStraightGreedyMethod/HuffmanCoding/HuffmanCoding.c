/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: HuffmanCoding.c
 * 创建日期: 2015年01月06日 星期二 10时28分40秒
 * 程序想法：http://blog.csdn.net/world7th/article/details/1535452 
 * 实现这个网页上的代码！
 * 霍夫曼编码是一种被广泛应用而且非常有效的数据压缩技术，根据待压缩数据的特征，一个可压缩掉20%~90%。这里考虑的数据指的是字符串序列。要理解霍夫曼编码，先要理解霍夫曼树，即最优二叉树，是一类带权路径长度最短的树。
 *
 * 路径是指从树中一个结点到另一个结点之间的通路，路径上的分支数目称为路径长度。
 * 就是从一个节点到另一个节点经过了几个其他节点！两个节点相邻，路径长度可以规定为０，也可以规定为１，以此为基础来确立两种路径长度！
 *
 * 树的路径长度是从树根到每一个叶子之间的路径长度之和。也就是总的节点的数目．这不一定是总的节点之和！
 *
 * 结点的带权路径长度为从该结点到树根之间的路径长度与该结点权的乘积，树的带权路径长度为树中所有叶子结点的带权路径长度之和.
 *
 * 霍夫曼树是指所有叶子结点的二叉树中带权路径长度最小的二叉树.
 *
 * 当给定了n个叶子结点的权值后，构造出的最优二叉树的结点数目m就确定了，即m=2n-1?,所以可用一维结构树组来存储最优二叉树
 */
#include<stdio.h>
#define MAXLEAFNUM 50          /*最优二叉树中最大叶子树目*/



struct node{

	char ch;         /*当前结点表示的字符，对于非叶子结点，此域不用*/

	int weight;             /*当前结点的权值*/

	int parent;              /*当前结点的父结点的下标，为0时表示无父结点*/

	int lchild,rchild;      /*当前结点的左，右孩子结点的下标，为0时表示无孩子结点*/

}HuffmanTree[2 * MAXLEAFNUM];



typedef char *HuffmanCode[MAXLEAFNUM + 1];
void createHTree(HuffmanTree HT, char *c, int *w, int n)
{

	/*数组c[0..n-1]和w[0..n-1]存放了n个字符及其概率，构造霍夫树HT*/

	int i, s1, s2;

	if (n <= 1)

		return;



	/*根据n个权值构造n棵只有根结点的二叉树*/

	for (i=1; i<=n; i++)

	{

		HT[i].ch = c[i-1];

		HT[i].weight = w[i-1];

		HT[i].parent = HT[i].lchild = HT[i].rchild = 0;    

	}



	for (; i<2*n; ++i)

	{

		HT[i].parent = 0;

		HT[i].lchild = 0;

		HT[i].rchild = 0;

	}



	/*构造霍夫曼树*/

	for (i=n+1; i<2*n; i++)

	{

		/*从HT[1..i-1]中选择parent为0且weight最小的两棵树，其序号为s1和s2*/

		select(HT,i-1,s1,s2);

		HT[s1].parent = i;

		HT[s2].parent = i;

		HT[i].lchild = s1;

		HT[i].rchild = s2;

		HT[i].weight = HT[s1].weight + HT[s2].weight;

	}

}



void HuffmanCoding(HuffmanTree HT, HuffmanCode HC, int n)

{

	/* n个叶子结点在霍夫曼树HT中的下标为1~n,*/

	/*第i（1<= i <= n）个叶子的编码存放HC[i]中*/

	char *cd;

	int i,start,c,f;

	if (n<=1)

		return;



	/*分配n个字节的内存，用来存放当前得到的编码*/

	/*n个叶子结点最大的编码长度为n所以分配n个字节*/

	cd = (char*)malloc(n)

		cd[n-1] = '\0';



	for (i=1; i<=n; i++)

	{

		start = n -1;

		for (c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)

			/*从叶子结点开始查找编码*/

			/*叶子结点的父结点的左子树为叶子结点，则编码为0*/

			/*否则就为父结点的右子树，则编码为1*/

			if (HT[f].lchild = = c) cd[--start] = ‘0’;

			else cd[--start] = ‘1’;

		/*分配内存，分配内存的字节数为当前得到的字符编码数*/

		HC[i] = (char*)malloc(n-start);

		strcpy(HC[i], &cd[start]);

	}

	free(cd);

}
void Decoding(HuffmanTree HT, int n, char *buff)

{

	/*利用具有n个叶子结点的最优二叉树（存储在数组HT中）进行译码，叶子的下标*/

	/*为1~n，buff指向数据文件的编码序列*/

	int p = 2*n -1; /*指向根结点*/

	while (*buff)

	{

		if ((*buff) = = ‘0’) p = HT[p].lchild; /*进入左分支*/

		else p = HT[p].rchild; /*进入右分支*/



		/*到达一个叶子结点*/

		if（HT[p].lchild = = 0 && HT[p].rchild = = 0）

		{

			printf(“%c”, HT[p].ch);

			p = 2*n – 1; /*回到根结点*/

		}

		buff++;

	}

}

void input() {
}

void solve() {
}

int main() {
	input();
	solve();
	return 0;
}

