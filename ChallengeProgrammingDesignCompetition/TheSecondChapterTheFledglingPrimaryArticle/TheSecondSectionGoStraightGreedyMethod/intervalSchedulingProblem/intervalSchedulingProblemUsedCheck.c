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
int unchecked[MAXN];

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
  //if (i == (n - 1))//这个结束有点提前了，我们需要把ｉ＝＝ｎ－１
  //的情况也探索下去！
  if (i >= n)
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
  //使用ｃｈｅｃｋｅｄ就要从头开始查，因为起始时间没有按从小到大排列！
  for (j = 0; j < n; j++)
    {
	    /*
      int k;
  for (k = 0; k < n; k++)
    {
      //unchecked[j]=1;
      printf("%d:%d\t",k,unchecked[k]);
    }
      printf("\n");
      */

      if (unchecked[j] && t[i] < s[j])
	{
	  find++;
	  count++;
	  unchecked[j] = 0;
	  printf ("<%d-%d>", i, j);
	  dfs (j);
	  unchecked[j] = 1;
	  count--;
	}
    }
  if (!find)
    {
	    find=0;
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
      //进入每一个dfs搜索时，应该把ｕｎｃｈｅｃｋｅｄ全部设置为没有检查过！
      //没起作用
      /*
      int j;
  for (j = 0; j < n; j++)
    {
      //unchecked[j]=1;
      printf("%d:%d\t",j,unchecked[j]);
    }
      printf("\n");

      */
      dfs (i);
      printf ("\n");
    }
  printf ("max work is %d\n", maxcount);
}

int
main ()
{
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
  for (i = 0; i < n; i++)
    {
      unchecked[i]=1;
    }

  solve ();
  //这个方法对ｉｎ４ｘ不成功！
  return 0;
}
