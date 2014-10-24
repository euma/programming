#include<stdio.h>
#include<time.h>
int main() {
	time_t current;
	current=time(NULL);
	time_t biggest=0x7FFFFFFF;
	double dt=difftime(biggest,current);
	printf("%lf seconds\n",dt);
	printf("%lf years\n",dt/(60*60*24*356));
	time_t new=(time_t)dt;
	printf("different time %s from 1970 1 1\n",ctime(&new));

	return 0;
}
