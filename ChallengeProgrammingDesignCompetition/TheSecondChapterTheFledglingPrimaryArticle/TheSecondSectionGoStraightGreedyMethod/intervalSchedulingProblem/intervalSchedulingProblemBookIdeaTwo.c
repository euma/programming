#include<stdio.h>
#include<stdlib.h>

#define MAXN 100000

int n;
int s[MAXN], t[MAXN];

int used[MAXN];

void
input ()
{
  scanf ("%d", &n);
  int i;
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &s[i]);
      printf ("%d\t", s[i]);
    }

  printf ("\n");
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &t[i]);
      printf ("%d\t", t[i]);
    }

  printf ("\n");
}



void
solve ()
{
  int current_i = 0;
  int next_i = 1;		//只要给ｎｅｘｔ＿ｉ一个非ｃｕｒｒｅｎｔ＿ｉ的值就可以，但不能不给！不给会造成段错误！
  int find;
  int maxwork = 1;
  while (1)
    {
      printf ("current is %d\n", current_i);
      find = 0;
      //不必从头开始搜索，而是从ｃｕｒｒｅｎｔ＿ｉ＋１开始
      int i;
      for (i = current_i + 1; i < n; i++)
	{
	  if (t[current_i] < s[i])//看出了思维的差别，我是由当前的来在比较中寻找下一个，作者的思路是保存上一个，然后拿它和当前的这个进行比较！
	//而且可以从当前的自然找出，下一次循环所使用的上一个！
	//这是两个不同方法的不同思维的体现！
	    {

	      find = 1;
	      next_i = i;
	      break;
	      //找到最早出现的那一个就停止查找！
	      //不然程序不仅找到最早出现的，而且还要一直找下去，直到找到最后一个这样以来，不符合我的设想！程序的测试结果也将出错！
	    }
	}
      current_i = next_i;

      if (!find)
	break;
      else
	{
	  maxwork++;
	}
    }

  printf ("max work is %d\n", maxwork);

}

void
sort ()
{
  int i, j;
  for (i = 0; i < n; i++)
    {
      for (j = i + 1; j < n; j++)
	{
	  if (t[j] < t[i])
	    {
	      int ti_origin = t[i];
	      t[i] = t[j];
	      t[j] = ti_origin;
	      int si_origin = s[i];
	      s[i] = s[j];
	      s[j] = si_origin;

	    }
	}
    }
}

void
printarray ()
{
  int i;
  for (i = 0; i < n; i++)
    {
      printf ("(%d,%d)\t", s[i], t[i]);
    }
  printf ("\n");
}


int
main ()
{
  //我想到了，可以以结束时间的早晚来排序，然后我们只需要从第一个开始找不连续的时间段了！
  //这里实践的是，一有想法就独立实现，因为在实现的过程中，最大程度地，发展着自己编写代码的能力！形成自己的代码风格，自己的代码思维！
  input ();
  if (n > MAXN)
    {
      exit (1);
    }

  printarray ();
  sort ();
  printarray ();
  solve ();
  return 0;
}
