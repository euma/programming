#include<stdio.h>
int main(void) {
int a,b,c;
int x=scanf("%d%d%d",&a,&b,&c);
printf("%d\n",x);
return 0;
}
//测试结果是没有输入它会返回一个负一，表示没有任何读取，应该是到达文件末尾了！
//有输入，但是输入的第一个就是错的，那么会返回0,表示想读取，但是没有一个符合要求
//有输入，但是输入的第二个是错的，这是，返回1,表示已经成功读取了一个！