/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: FindTheSmallest_re-exchange.c
 * 创建日期: 2014年11月24日 星期一 08时50分08秒
 */
#include<stdio.h>
#define MAXN 50
int test[MAXN];

int actual_n;
void
printarray ()
{
  int i;
  for (i = 0; i < actual_n; i++)
    printf ("%d\t", test[i]);
  printf ("\n");

}

int
main ()
{
  actual_n = 5;
  test[0] = 2;
  test[1] = 8;
  test[2] = 4;
  test[3] = 7;
  test[4] = 0;
printarray ();
  int i, j;
  for (i = 0; i < actual_n; i++)
    {
      int smallest = test[i];
      int smallest_i = i;
      //通过比较找到最小的！
      for (j = i + 1; j < actual_n; j++)
	{
	  if (test[j] < smallest)
	    {
	      smallest = test[j];
	      smallest_i = j;
	    }
	}
      //把最小的与当前值交换！
      int testi_origin = test[i];
      test[i] = smallest;
      test[smallest_i] = testi_origin;

printarray ();
    }
  return 0;
}
