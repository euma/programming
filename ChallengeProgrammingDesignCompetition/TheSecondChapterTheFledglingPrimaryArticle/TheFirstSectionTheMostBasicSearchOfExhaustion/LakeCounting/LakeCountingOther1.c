#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXMN 110

char atlas[MAXMN][MAXMN];	//atlas　是at lakes?
//因为这个二维数组比较小，所以可以直接写出，如果太大，还是用一个双重循环比较好！
int d[8][2] =
  { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
int used[MAXMN][MAXMN];		//把我的想法全部写下来，有思考才有进步
//这里用了１１０，其实用#define MAXMN 110比较好！
//把我的改进全部写下来
int n, m;

void
dfs (int i, int j)
{
  int k;
  used[i][j] = 1;
  for (k = 0; k < 8; ++k)
    {
      int nexti, nextj;
      nexti = i + d[k][0];
      nextj = j + d[k][1];
      //作者不是说可以用四个方向的搜索也可以，但这里展示的是８个方向的！
      //这里使用ｕｓｅｄ数组与把ｗ变为．原理是相同的，只不过实现方式不同！
      if (nexti >= 0 && nexti < n && nextj < m
	  && nextj >= 0 && atlas[nexti][nextj] == 'W' && !used[nexti][nextj])
	dfs (nexti, nextj);
    }
}

void
printatlas ()
{
  int i;
  for (i = 0; i < n; ++i)
    printf ("%s\n", atlas[i]);
  printf ("\n");
}

void
printused ()
{
  int i, j;
  for (i = 0; i < n; ++i)
    {
      for (j = 0; j < m; ++j)
	printf ("%d", used[i][j]);
      printf ("\n");
    }
  printf ("\n");
}

int
main ()
{
  int i, j;
  scanf ("%d%d", &n, &m);
  //我用的是scanf ("%s", &atlas[i][0]);看来我的添加是多余的，编译器可以很智慧的处理！
  for (i = 0; i < n; ++i)
    scanf ("%s", atlas[i]);
  int ans = 0;
  memset (used, 0, sizeof used);
  //printatlas ();
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j)
      if (atlas[i][j] == 'W' && !used[i][j])
	{
	  //printused ();
	  ans++, dfs (i, j);
	  //printused ();
	}
  printf ("%d\n", ans);
  return 0;
}
