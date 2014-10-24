#include<stdio.h>
#define MAX_N 100
int
main ()
{
 
  int a, b;
  int n;
  scanf ("%d", &n);
  int i;//C不允许把i放在这里！gcc是允许的！
  //从程序运行看，c编译的代码用了15毫秒，gcc编译的代码用了0毫秒，
  //从这可以看出，最好用gcc编译，不然会有15倍的时间差，对于时间
  //要求较高的编程竞赛，必须选最小运行时间的编译器！
  
  for (i = 0; i < n; i++)
    {
      scanf ("%d%d", &a, &b);
      printf ("%d\n", a + b);
    }
  return 0;
}
