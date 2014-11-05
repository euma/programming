//整个程序分三步走，第一步先读取数据
//第二步找到一个连通的水哇
//第三步找到所有连通的水哇
#include<stdio.h>
#include<stdlib.h>
#define MAXMN 100		//这里直接给出变量M和N的最大值
//#define MAXMN 20		//这里直接给出变量M和N的最大值
//很感谢网上的朋友指出了我的错误，让我自己发现将是一个浪费时间的问题！
//这里N代表行，M代表列
int N, M;
int field[MAXMN][MAXMN];	//这里给出的是最大二维数组，而不是刚好的二维数组
//刚好的二维数组field[N][M]是动态的，无法通过编译器的编译
int times;
int visitfield[MAXMN][MAXMN];

void
input ()
{
  scanf ("%d %d", &N, &M);
  int i, j;
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{
	  //如果读到的不是W或.那么我们就要重新读取,直到读到W和.
	  char w;
	  //这个读取问题比较大，会使程序陷入无限循环！
	  while (scanf ("%c", &w) != EOF)
	    {
	      if (w == 'W')
		{
		  field[i][j] = 1;
		  break;
		}
	      else if (w == '.')
		{

		  field[i][j] = 0;
		  break;
		}

	      else
		continue;
	    }
	}
    }

}

void
onePond (int i, int j)
{

  //printf ("onePond(%d,%d)\n", i, j);
  //times++;
  //if (times>10) { exit(1); }
  if ((i >= 0 && i < N) && (j >= 0 && j < M))
    {

      int nexti, nextj;
      //to right
      //行不变，列加一
      nexti = i, nextj = j + 1;
      if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	{
		//(visitfield[nexti][nextj]>=2)说明(nexti,nextj)点已经被访问过了！没有访问过的点还是1
	  if (!(visitfield[nexti][nextj]>=2) && (field[i][j] == 1) && (field[nexti][nextj] == 1))
	    {
	      visitfield[i][j]++;
	      onePond (nexti, nextj);
	    }
	  if ((visitfield[nexti][nextj]>=2) && (field[i][j] == 1) && (field[nexti][nextj] == 1)){
	      visitfield[i][j]++;
	  }
	}
    //to left
      //行不变，列加一
      nexti = i, nextj = j - 1;
      if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	{
		//(visitfield[nexti][nextj]>=2)说明(nexti,nextj)点已经被访问过了！没有访问过的点还是1
	  if (!(visitfield[nexti][nextj]>=2) && (field[i][j] == 1) && (field[nexti][nextj] == 1))
	    {
	      visitfield[i][j]++;
	      onePond (nexti, nextj);
	    }
	  if ((visitfield[nexti][nextj]>=2) && (field[i][j] == 1) && (field[nexti][nextj] == 1)){
	      visitfield[i][j]++;
	  }
	}

      //to down
      //行加一，列不变
      nexti = i + 1, nextj = j;
      if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	{

	  if (!(visitfield[nexti][nextj]>=2) &&(field[i][j] == 1) && (field[nexti][nextj] == 1))
	    {
	      visitfield[i][j]++;
	      onePond (nexti, nextj);
	    }
	  if ((visitfield[nexti][nextj]>=2) && (field[i][j] == 1) && (field[nexti][nextj] == 1)){
	      visitfield[i][j]++;
	  }
	}
      //to up
      //行减一，列不变
      nexti = i - 1, nextj = j;
      if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	{

	  if (!(visitfield[nexti][nextj]>=2) &&(field[i][j] == 1) && (field[nexti][nextj] == 1))
	    {
	      visitfield[i][j]++;
	      onePond (nexti, nextj);
	    }
	  if ((visitfield[nexti][nextj]>=2) && (field[i][j] == 1) && (field[nexti][nextj] == 1)){
	      visitfield[i][j]++;
	  }
	}

      //to lower right
      //行加一，列加一
      nexti = i + 1, nextj = j + 1;
      if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	{

	  if (!(visitfield[nexti][nextj]>=2) &&(field[i][j] == 1) && (field[nexti][nextj] == 1))
	    {
	      visitfield[i][j]++;
	      onePond (nexti, nextj);
	    }
	  if ((visitfield[nexti][nextj]>=2) && (field[i][j] == 1) && (field[nexti][nextj] == 1)){
	      visitfield[i][j]++;
	  }
	}
      //to left up
      //行减一，列减一
      nexti = i - 1, nextj = j - 1;
      if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	{

	  if (!(visitfield[nexti][nextj]>=2) &&(field[i][j] == 1) && (field[nexti][nextj] == 1))
	    {
	      visitfield[i][j]++;
	      onePond (nexti, nextj);
	    }
	  if ((visitfield[nexti][nextj]>=2) && (field[i][j] == 1) && (field[nexti][nextj] == 1)){
	      visitfield[i][j]++;
	  }
	}

      //to left down
      //行加一，列减一
      nexti = i + 1, nextj = j - 1;
      if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	{

	  if (!(visitfield[nexti][nextj]>=2) &&(field[i][j] == 1) && (field[nexti][nextj] == 1))
	    {
	      visitfield[i][j]++;
	      onePond (nexti, nextj);
	    }
	  if ((visitfield[nexti][nextj]>=2) && (field[i][j] == 1) && (field[nexti][nextj] == 1)){
	      visitfield[i][j]++;
	  }
	}
      //to right up
      //行减一，列加一
      nexti = i - 1, nextj = j + 1;
      if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	{

	  if (!(visitfield[nexti][nextj]>=2) &&(field[i][j] == 1) && (field[nexti][nextj] == 1))
	    {
	      visitfield[i][j]++;
	      onePond (nexti, nextj);
	    }
	  if ((visitfield[nexti][nextj]>=2) && (field[i][j] == 1) && (field[nexti][nextj] == 1)){
	      visitfield[i][j]++;
	  }
	}
      //最终我还是把8个方向都给全了！

    }
  return;
}

void
printfield ()
{
  int i, j;
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{
	  printf ("%2d", field[i][j]);
	}
      printf ("\n");
    }
  printf ("\n");

}
void
printvisitfield ()
{
  int i, j;
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{
	  printf ("%2d", visitfield[i][j]);
	}
      printf ("\n");
    }
  printf ("\n");

}
int
main ()
{
  input ();
  //printf ("%d %d\n", N, M);
  int i, j;
  //onePond (0, 0);
  //printfield ();

  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{
	  visitfield[i][j] = field[i][j];
	}
    }

  int count = 0;
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{

	  //当tmpfield[i][j]==1时，说明field[i][j]还没有被搜索过，如果搜索过，那么我会让field[i][j]++,同时也让field[nexti][nextj]++只要他们是连通的！
	  //这里onePond（i，j）就是一个测试连通和建立连通的函数！
	  if (visitfield[i][j] == 1)
	    {
	      //printf ("(%d,%d)\n", i, j);
	      //printvisitfield ();
	      onePond (i, j);
	      //printvisitfield ();
	      count++;
	    }
	}
    }
  //printf ("we find %d ponds\n", count);
  printf ("%d\n", count);
  return 0;

}
