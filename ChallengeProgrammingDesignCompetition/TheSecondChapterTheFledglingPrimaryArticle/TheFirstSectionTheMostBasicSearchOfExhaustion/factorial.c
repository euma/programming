#include<stdio.h>
int fact(int n) {
	if (n==0) return 1;
	return n*fact(n-1);
}
int main() {
	int i;
	for (i=0;i<10;i++)
	printf("factorial(%d)=%d\n",i,fact(i));
	return 0;
}
