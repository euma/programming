#include<stdio.h>
#define MAX_N 20
int n, a[MAX_N], k;
//我先根据这个状态转移的样子，利用函数递归来实现一下，能实现多少是多少！
int countPrintf = 0;
int find = 0;
int
state (int i, int sum)
{
  countPrintf++;
  printf ("%d:state(%d,%d)\n", countPrintf, i, sum);
  //我们可以让程序找到一个后返回1,每找到返回0,这样我们可以从state函数的最终返回值判断有几个满足要求的答案！
  //或者单独写一个find变量，来记录找到了几个！
  //如果只是找到一种结果，那么判断中间状态中是否出现需要的结果是可以的
  //如果需要所有结果，那么必须走到最末端的结果状态再做判断!
  if (i >= n)
    {
      if (sum == k)
	{
	  find++;
	}

      return 0;
    }

  return state (i + 1, sum + a[i]) + state (i + 1, sum);
}

int
main ()
{
  scanf ("%d", &n);
  int i;
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  scanf ("%d", &k);
  state (0, 0);
  if (find)
    printf ("Yes find %d\n", find);
  else
    printf ("No\n");
  return 0;
}
