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
  //从第一项开始就选结束时间最早的！
  int i;
  for (i = 0; i < n; i++)
    {
      used[i] = 0;
    }
  int first_i = 0;
  for (i = 0; i < n; i++)
    {
	  //这里好像不用关心开始时间的早晚？
	  if (t[i] < t[first_i])
	    {
	      first_i = i;
	    }
    }				//以上先找到第一个
  printf ("first is %d\n", first_i);
  used[first_i] = 1;

  int current_i = first_i;
  int next_i = first_i + 1;	//只要给ｎｅｘｔ＿ｉ一个非ｃｕｒｒｅｎｔ＿ｉ的值就可以，但不能不给！不给会造成段错误！
  int find, first;
  int maxcount = 1;
  while (1)
    {
      printf ("current is %d\n", current_i);
      first = 1; find = 0;
      for (i = 0; i < n; i++)
	{
	  if (!used[i]) {
		  if( t[current_i] < s[i])
	    {

	      find=1;
	      if (first)
		{
		  next_i = i;
		  first = 0;
		}
	      else
		{

		  if (t[i] < t[next_i])
		    {
		      next_i = i;
		    }
		}
	    }
	  }
	}
	  used[next_i] = 1;
	  current_i = next_i;

      if (!find)
	break;
      else
	{
	  maxcount++;
	}
    }
  printf ("max work is %d\n", maxcount);

}

int
main ()
{
  //写的有点复杂，但是我基本按我的思路把作者的想法实现了，接下来就是测试代码的正确性了！
  input ();
  int i;
  for (i = 0; i < n; i++)
    {
      printf ("(%d,%d)\t", s[i], t[i]);
    }
  printf ("\n");
  if (n > MAXN)
    {
      exit (1);
    }
  solve ();
  return 0;
}
