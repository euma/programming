#include<stdio.h>
int main(){
int a,b;
//EOF的-1,是end of file的缩写。
//这里不到文件结束，就继续做加法！
while (scanf("%d%d",&a,&b)!=EOF) {
printf("%d\n",a+b);
}
return 0;
}
