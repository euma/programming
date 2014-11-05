/*这个程序只是让Thedraw.cpp结构分得更清,添加了一个函数solve！*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 1000;
//输入，需要从标准输入中得到的数据,标准输入可能来自键盘，也可能来自文件的重新定向,对数据的这种划分是好的！
//以后可以专门把标准输入的数据，单独声明！
int n, m, k[MAX_N];
//保存2个数的和的数列
int kk[MAX_N * MAX_N];

bool
binary_search (int x)
{
  //x的存在范围是kk[l],kk[l+1],...,kk[r-1]
  int l = 0, r = n * n;		//l 表示left，r表示right
  //反复操作直到存在范围为空
  while (r - l >= 1)
    {
      int i = (l + r) / 2;
      if (kk[i] == x)
	return true;		//找到x
      else if (kk[i] < x)
	l = i + 1;
      else
	r = i;
    }
  //没找到x
  return false;
}

void
solve ()
{
//枚举k[c]+k[d]的和
  for (int c = 0; c < n; c++)
    {
      for (int d = 0; d < n; d++)
	{
	  kk[c * n + d] = k[c] + k[d];	//这个技巧，我忘了使用，以前知道。
	}
    }
  //排序以便进行二分搜索
  sort (kk, kk + n * n);

//是否找到和为m的组合的标记
  bool f = false;

  for (int a = 0; a < n; a++)
    {
      for (int b = 0; b < n; b++)
	{
	  //将内侧的两个循环替换程二分搜索
	  if (binary_search (m - k[a] - k[b]))
	    {
	      f = true;
	      printf ("%d+%d+%d=%d\n", k[a], k[b], m - k[a] - k[b], m);
	    }
	}
    }

//输出到标准输出
  if (f)
    puts ("Yes");
  else
    puts ("No");
}

void
input ()
{
//从标准输入读入
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &k[i]);
    }

}

int
main ()
{
  //main函数里结构更简单了！
  input ();
  solve ();

  return 0;
}
