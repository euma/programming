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
  return memo[n] = fib (n - 1) + fib (n - 2);
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
