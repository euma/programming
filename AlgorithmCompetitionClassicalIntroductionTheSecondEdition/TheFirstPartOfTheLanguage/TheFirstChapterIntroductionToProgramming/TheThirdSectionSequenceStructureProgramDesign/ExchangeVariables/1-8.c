#include<stdio.h>
int main(){
  int a, b, t;
  scanf("%d%d", &a, &b);
  //这里的代码是很简洁，但是却需要更多的理解，需要理解ｔ的含义
  //三个语句的各自含义，我的变量名字法，更好！
  t = a;
  a = b;
  b = t;
  printf("%d %d\n", a, b);
  return 0;
}
