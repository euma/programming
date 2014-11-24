//基本思路还是，先看最大的需要几个，再看接下来的需要几个，一直到最小的需要几个，按顺序来一次度量
//其实我先写了一种情况，然后写出适用于六种情况的一般情况，让ｆｏｒ循环遍历这六种情况便可！
#include<stdio.h>
int C1, C5, C10, C50, C100, C500;
int A;
void
input ()
{
  scanf ("%d", &C1);
  scanf ("%d", &C5);
  scanf ("%d", &C10);
  scanf ("%d", &C50);
  scanf ("%d", &C100);
  scanf ("%d", &C500);
  scanf ("%d", &A);
}

int
main (void)
{
  input ();
  //其实现在有一个直接的想法就是用数组
  int coin[6] = {
    1, 5, 10, 50, 100, 500
  };
  int coinNumber[6] = {
    C1, C5, C10, C50, C100, C500
  };
  //表示之后，我可以用一个循环来把所有的工作做完，要不然我就需要对六种情况作出一一的处理
  int leastCoins = 0;
  int neededCoins = 0;
  int i;
  for (i = 5; i >= 0; i--)
    {
      neededCoins = A / coin[i];
      if (neededCoins > 0)
	{
	  //需要的硬币数是足够时，ｎｅｅｄｅｄＣｏｉｎｓ不变
	  //需要的硬币数是不够时，只能有几个拿几个了！这是ｎｅｅｄｅｄＣｏｉｎｓ就要作出改变！
	  if (coinNumber[i] < neededCoins)
	    {
	      neededCoins = coinNumber[i];
	    }
	  printf ("%d:(%d) ", neededCoins,coin[i]);
	  leastCoins += neededCoins;
	  A -= (coin[i] * neededCoins);

	}
    }
  printf ("\n%d\n", leastCoins);

  return 0;
}
