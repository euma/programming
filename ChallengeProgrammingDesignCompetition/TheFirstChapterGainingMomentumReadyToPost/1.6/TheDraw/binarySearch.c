#include<stdio.h>
int main() {
	int a[7]={1,4,40,43,45,55,99};
	int target=55;
	int start=0;int end=7;
	while(start<=end) {
		int mid=(start+end)/2;
		if (a[mid]>target) {
			end=mid-1;
		} else if (a[mid]<target) {
			start=mid+1;
		} else {
			printf("we find! it's at %d\n And it's %d\n",mid,a[mid]);
			break;
		}
	}
	return 0;
}
//0,7,3
//4,7,5
