#include<stdio.h>
#include<time.h>
int space=0;
int fib(int n) {
	int i;
	for (i=0;i<=space;i++) {
		printf(" ");
	}
	space++;
	printf("fib(%d)=fib(%d)+fib(%d)\n",n,n-1,n-2);
	if (n<=1) return n;
	return fib(n-1)+fib(n-2);
}
int main() {
		printf("fibonacci(%d)=%d\n",4,fib(4));
	//printf("Time used = %f\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
