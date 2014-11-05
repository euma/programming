/*这里用数组记录中间结果！*/
#include<stdio.h>
#include<time.h>
#define MAX_N  150
//const int MAX_N = 150;//由const定义的是变量，用define定义的宏是常量
int memo[MAX_N + 1];
int
fib (int n)
{
  if (n <= 1)
    return n;
  if (memo[n] != 0)
    return memo[n];
  //return memo[n] = fib (n - 1) + fib (n - 2);
  //看一下，互换位置后，程序会不会运行慢了。
  //Time used = 0.001921
  //Time used = 0.001723
  //时间上只是慢了一点，可能是f(n-1)能提前计算出一些f(n)存储出来
  return memo[n] = fib (n - 2) + fib (n - 1);
}

int
main ()
{
  int i;
  for (i = 0; i <= MAX_N; i++)
    memo[MAX_N + 1] = 0;
  for (i = 0; i < 41; i++)
    {
      printf ("fibonacci(%d)=%d\n", i, fib (i));
    }
  printf("Time used = %f\n",(double)clock()/CLOCKS_PER_SEC);
  return 0;
}
