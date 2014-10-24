#include<stdio.h>
int main(){
int a,b;
//scanf函数的返回值是它实际所接收到的变量的个数,如果根本没有变量输入就返回-1,如果有变量输入，那就要看第几个错了，错在第一个就返回0,错在第二个就返回1,依次类推！
//我这里判断如果scanf成功接收了两个参数，那么就继续循环
while (scanf("%d%d",&a,&b)==2) {
printf("%d\n",a+b);
}
return 0;
}
