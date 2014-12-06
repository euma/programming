/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: 
 * 创建日期: 2014年11月24日 星期一 08时50分08秒
 */
//我的想法是初步实现一个可以从第一个开始统计经过了多少不连续的工作区间的
//之后，我可以推广到从第二个开始统计，
//一直推广到从最后一个开始统计，
//然后找到最大统计数便可以！
#include<stdio.h>
#include<stdlib.h>

#define MAXN 100000

int n;
int s[MAXN], t[MAXN];

int count = 1;
int maxcount = 0;
int find = 0;

void
input ()
{
  //这里的读入数据有误！
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
dfs (int i)
{
  if (i == (n - 1))
    {
      printf ("%d\n", count);
      if (count > maxcount)
	{
	  maxcount = count;
	}

      return;
    }
  int j;
  //我这里是按次序找的，可以改进为不按次序找！
  //其实只要按开始时间排列好次序，我的办法就是好的！
  //因为我所有的测试代码都是按照开始时间排序的，所以我暂时不改进，除非这个问题是一个ｏｎｌｉｎｅ　ｊｕｄｇｅ问题，我为了通过，我可能需要改一下我的代码，现阶段代码写成这样是可以的
  //改进的办法有两个，一个是读入ｓ［ｉ］与ｔ［ｉ］，后重新排序
  //另一个是，在ｄｆｓ中使用ｕｓｅｄ［ｉ］＝１来记录！
  //这需要ｕｓｅｄ［ｉ］＝１；ｄｆｓ（ｊ）;used[i]=0;式地去写代码！
  find = 0;
  for (j = i + 1; j < n; j++)
    {
      if (t[i] < s[j])
	{
	  find++;
	  count++;
	  printf ("<%d-%d>", i, j);
	  dfs (j);
	  count--;
	}
    }
  if (!find)
    {
      printf ("%d\n", count);
      if (count > maxcount)
	{
	  maxcount = count;
	}

      return;
    }

}

void
solve ()
{
  int i;
  for (i = 0; i < n; i++)
    {
//这里来一个深度优先搜索，来获得我举出的反例的正确答案？
//这里的想法是，无论书上的想法有多么好，我都不可以看，无论我的想法有多么笨，我都要实现，而且我要实现的是彻底解决问题的方法！
//因为只有当我用我的方法独立解决了问题之后，我才可以去看书中的想法，向书中的想法学习，当然我的一个目标就是让自己的想法更优秀！
      printf ("<%d>", i);
      dfs (i);
      printf ("\n");
    }
  printf ("max work is %d\n", maxcount);
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
  input ();
  printarray ();
  int i, j;
  for (i = 0; i < n; i++)
    {
      for (j = i + 1; j < n; j++)
	{
	  if (s[j] < s[i])
	    {
	      int si_origin = s[i];
	      s[i] = s[j];
	      s[j] = si_origin;
	      int ti_origin = t[i];
	      t[i] = t[j];
	      t[j] = ti_origin;

	    }
	}
    }

  printarray ();
  if (n > MAXN)
    {
      exit (1);
    }
  solve ();
  return 0;
}
