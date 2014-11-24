#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 100
//即使有重复的元素也会生成所有的排列
//那我要看看有重复语言时，给出的排列具体是怎样的？
//ｎｅｘｔ＿ｐｅｒｍｕｔａｔｉｏｎ是按照字典序来生成下一个排列的
int perm2[MAX_N];
void
permutation2 (int n)
{
  //这是给予一个初始的排序！
  for (int i = 0; i < n; i++)
    {
      perm2[i] = i;
    }
  do
    {
      /*
       * 这里编写需要对ｐｅｒｍ2进行的操作
       */
      //最基本的操作就是打印出这个排列
      for (int i = 0; i < n; i++)
	{
	  printf ("%d", perm2[i]);
	}
      printf ("\n");
    }
  while (next_permutation (perm2, perm2 + n));
  //所有的排列都生成后，应该是字典序的最后一个生成后，ｎｅｘｔ＿ｐｅｒｍｕｔａｔｉｏｎ会返回ｆａｌｓｅ
  //如何验证我的想法，直接把ｐｅｒｍ２设置为中间某种排序然后看ｎｅｘｔ＿ｐｅｒｍｕｔａｔｉｏｎ是生成全部排序还是部分排序？
  return;
}

int
main ()
{
  int n;
  printf
    ("请输入一个数字Ｎ，我们将给出｛０，１，２，．．．，Ｎ－１｝的Ｎ！中排列\n");
  scanf ("%d", &n);
  //看一下刚开始ｐｅｒｍ［ｎ］与ｕｓｅｄ［ｎ］被赋予的初始值是什么？
  permutation2 (n);
  return 0;
}
