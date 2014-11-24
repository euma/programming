#include<stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  printf("%d%d%d\n", n%10, n/10%10, n/100);
  //我没必要修改作者的代码，只在有新想法，要验证时，添加一些代码！
  return 0;
}
