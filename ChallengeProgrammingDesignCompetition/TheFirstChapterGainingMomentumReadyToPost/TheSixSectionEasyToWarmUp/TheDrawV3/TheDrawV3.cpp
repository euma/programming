/*程序测试的结果是：内存占用太多？1000×1000×1000个int大概是10^9个4byte，1k=1000byte,1m=10^6byte,1g=10^byte,4g=4*10^9byte,光一个数组就要占用4g的内存，是太多了！*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 1000;
//输入，需要从标准输入中得到的数据,标准输入可能来自键盘，也可能来自文件的重新定向,对数据的这种划分是好的！
//以后可以专门把标准输入的数据，单独声明！
int n, m, k[MAX_N];
//保存3个数的和的数列
int kkk[MAX_N * MAX_N * MAX_N];

bool
binary_search (int x)
{
  //x的存在范围是kkk[l],kkk[l+1],...,kkk[r-1]
  int l = 0, r = n * n;		//l 表示left，r表示right
  //反复操作直到存在范围为空
  while (r - l >= 1)
    {
      int i = (l + r) / 2;
      if (kkk[i] == x)
	return true;		//找到x
      else if (kkk[i] < x)
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
//枚举k[b]+k[c]+k[d]的和
  for (int b = 0; b < n; b++)
    {
      for (int c = 0; c < n; c++)
	{
	  for (int d = 0; d < n; d++)
	    {
	      kkk[b * n * n + c * n + d] = k[b] + k[c] + k[d];
	    }
	}
    }
  //排序以便进行二分搜索
  sort (kkk, kkk + n * n * n);

//是否找到和为m的组合的标记
  bool f = false;

  for (int a = 0; a < n; a++)
    {
      if (binary_search (m - k[a]))
	{
	  f = true;
	  printf ("%d+%d=%d\n", k[a], m - k[a], m);
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
