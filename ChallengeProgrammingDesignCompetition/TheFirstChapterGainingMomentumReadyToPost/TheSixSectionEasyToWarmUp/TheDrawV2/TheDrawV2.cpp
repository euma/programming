/*这个程序只是让Thedraw.cpp结构分得更清,添加了一个函数solve！*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 1000;
int n, m, k[MAX_N], tmp[MAX_N];

int
binarySearch (int target, int end)
{
  int start = 0;
  while (start <= end)
    {
      int mid = (start + end) / 2;
      if (tmp[mid] > target)
	{
	  end = mid - 1;
	}
      else if (tmp[mid] < target)
	{
	  start = mid + 1;
	}
      else
	{
	  return mid;
	  //printf("we find! it's at %d\n And it's %d\n",mid,a[mid]);
	  break;
	}
    }
  return -1;
}

void
solve ()
{
//是否找到和为m的组合的标记
  bool f = false;
  int i = 0;
  for (int c = 0; c < n; c++)
    {
      for (int d = 0; d < n; d++)
	{
	  //好像也可以建立一个判断函数，令is_right[k[c]+k[d]]=1;
	  //让其他等于零，也可以建立一个二维数组，令is_right[k[c]][k[d]]=1;
	  //其他等于零，这里不能以is_right[MAX_N],is_right[MAX_N][MAX_N]为标准建立数组，因为MAX_N表示的是个数，我这里要放的是抽签中出现的最大数！
	  //这个程序的不足是，不能方便地给出，四次抽签的数字分别是什么
	  //这里可以直接打印的是前两次以及第三第四次的和！
	  tmp[i] = k[c] + k[d];
	  printf ("%d:%d+%d=%d\n", i, k[c], k[d], tmp[i]);
	  i++;
	}
    }
  sort (tmp, tmp + n * n);
  for (int j = 0; j < i; j++)
    {
      printf ("%d ", tmp[j]);
    }
  printf ("\n");

//通过四重循环枚举所有方案
  for (int a = 0; a < n; a++)
    {
      for (int b = 0; b < n; b++)
	{

	  int target = m - k[a] - k[b];
	  //这里应该可以过滤一下，target小于零，我们就没必要查找，不过这不是程序的主要问题，不过滤二分查找也能应对！

	  if (binarySearch (target, n - 1) >= 0)
	    {
	      f = true;

	      printf ("%d+%d+(%d)=%d\n", k[a], k[b], target, m);
	    }
	}
    }

//输出到标准输出
  if (f)
    puts ("Yes");
  else
    puts ("No");
}

int
main ()
{
//从标准输入读入
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &k[i]);
    }
  solve ();

  return 0;
}
