/*直接在别人的代码基础上修改有好处，也有坏处，可是我觉得最重要的还是自己的掌控！*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 100;
int n, a[MAX_N];

void
solve ()
{
  int ans = 0;
  for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
	{
	  for (int k = j + 1; k < n; k++)
	    {
	      int len = a[i] + a[j] + a[k];
	      //这里使用ma的原因是不与max同名，变量名不能和函数名同名，好多时候我们并不知道系统函数名，
	      //但是我们却用了相同的名字来命名变量，这可能引起编译错误吗？
	      int ma = max (a[i], max (a[j], a[k]));
	      int rest = len - ma;
	      if (ma < rest)
		{
		  ans = max (ans, len);	//以我以前的代码习惯，我会写一个if语句来判断，然后给ans一个比较后
		  //的最大值，现在看到，直接用一个函数，用最少的字母找到最大值就可以，这是好的，值得学习
		}
	    }
	}
    }
  printf ("%d\n", ans);
}

int
main ()
{
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  solve ();

  return 0;
}
