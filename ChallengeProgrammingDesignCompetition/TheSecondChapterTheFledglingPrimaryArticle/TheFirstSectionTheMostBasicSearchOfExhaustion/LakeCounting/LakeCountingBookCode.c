#include<stdio.h>
#define MAX_N 100
#define MAX_M 100
//输入
int N, M;
char field[MAX_N][MAX_M + 1];	//园子
//这里为什么加一？是因为如果读取一个字符串，那么就会多一个\0，这个加一，就是为多出来的\0留的？
//这里我可以试一下直接读取一个字符串
void
input ()
{
  scanf ("%d %d", &N, &M);
  int i;
  for (i = 0; i < N; i++)
    {
      scanf ("%s", &field[i][0]);
    }
}

void
printfield ()
{
  int i;
  for (i = 0; i < N; i++)
    {
      printf ("%s\n", &field[i][0]);
    }
      printf ("\n");

}

//现在位置(x,y)
void
dfs (int x, int y)
{
  //将现在所在位置替换为.
  field[x][y] = '.';

  //循环遍历移动的８个方向
  int dx, dy;
  for (dx = (-1); dx <= 1; dx++)
    {
      for (dy = (-1); dy <= 1; dy++)
	{
	  //向ｘ方向移动dx，向ｙ方向移动ｄｙ，移动的结果为（ｎｘ，ｎｙ）
	  int nx = x + dx, ny = y + dy;	//这里使用ｄｘ，ｄｙ与微积分所使用的符号系统是相同的！
	  //判断(nx,ny)是不是在园子内，以及是否有积水
	  //积极解决程序中出现的问题，也是编程乐趣的来源之一，没有问题，我们无法看到和感受到一个奇异的编程世界！
	  //这里全部用ａｎｄ逻辑判断符号分割，这样在哪里中断，就在哪里停止,我用括号分割，思路更清晰，从这里看，我的那个括号可以去掉！
	  if (0 <= nx && nx < N && 0 <= ny && ny <= M && field[nx][ny] == 'W')
	    {

	      dfs (nx, ny);
	    }
	}
    }
  return;
}

void
solve ()
{
  int res = 0;			//res result的前三个字母
  int i, j;
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{
	  if (field[i][j] == 'W')
	    {
	      //从有Ｗ的地方开始ｄｆｓ
	      //printfield ();
	      dfs (i, j);
	      res++;
	    }
	}
    }
  printf ("%d\n", res);
}

int
main ()
{
  input ();
  solve ();
  return 0;
}
