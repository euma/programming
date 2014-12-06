#include<stdio.h>
int a,b;
int main() {
	scanf("%d%d",&a,&b);
	int a_origin;
	a_origin=a;
	a=b;//ａ被改变了！
	b=a_origin;
	//现在觉得变量名函数名都要选得好，这对理解代码和写代码都很有帮助
	//变量名要要表达代码想表达的东西，或者叫代码的原意！
	printf("%d %d\n",a,b);
	return 0;
}
