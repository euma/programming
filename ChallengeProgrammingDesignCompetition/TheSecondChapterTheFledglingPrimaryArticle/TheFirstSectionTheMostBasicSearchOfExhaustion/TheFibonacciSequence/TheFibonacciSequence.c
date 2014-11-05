#include<stdio.h>
#include<time.h>
int fib(int n) {
	if (n<=1) return n;
	return fib(n-1)+fib(n-2);
}
int main() {
	int i;
	for (i=0;i<41;i++) {
		printf("fibonacci(%d)=%d\n",i,fib(i));
	}
	printf("Time used = %f\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
