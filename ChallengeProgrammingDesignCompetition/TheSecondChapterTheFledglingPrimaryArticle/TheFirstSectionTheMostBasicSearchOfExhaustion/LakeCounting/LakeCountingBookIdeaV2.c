//测试了一下，书中的思路是很好的！处理得不错！
//整个程序分三步走，第一步先读取数据
//第二步找到一个连通的水哇
//第三步找到所有连通的水哇
#include<stdio.h>
#include<stdlib.h>
#define MAXMN 100		//这里直接给出变量M和N的最大值
//#define MAXMN 20              //这里直接给出变量M和N的最大值
//很感谢网上的朋友指出了我的错误，让我自己发现将是一个浪费时间的问题！
//这里N代表行，M代表列
int N, M;
char field[MAXMN][MAXMN];	//这里给出的是最大二维数组，而不是刚好的二维数组
//刚好的二维数组field[N][M]是动态的，无法通过编译器的编译

void
input ()
{
  scanf ("%d %d", &N, &M);
  int i, j;
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{
	  //直接读取一个字符串是好的，但是，我还是先坚持自己的，发展自己的再去吸收其他人的，如果没有自己的，一味地吸收其他人的，那是不利于自己发展的！
	  //如果读到的不是W或.那么我们就要重新读取,直到读到W和.
	  char w;
	  //这个读取问题比较大，会使程序陷入无限循环！
	  while (scanf ("%c", &w) != EOF)
	    {
	      if (w == 'W')
		{
		  field[i][j] = 'W';
		  break;
		}
	      else if (w == '.')
		{

		  field[i][j] = '.';
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
  //if (times>10) { exit(1); }
  if ((i >= 0 && i < N) && (j >= 0 && j < M))
    {
      //如果field[i][j]不等于W那么，我们就要进行深度搜索！
      if (field[i][j] == 'W')
	{
	  field[i][j] = '.';

	  int nexti, nextj;
	  //to right
	  //行不变，列加一
	  nexti = i, nextj = j + 1;
	  if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	    {
	      //先把W变为.
	      //这里好像每必要关心field[nexti][nextj]是啥，只需要把当前的field[i][j]有W变为.，然后进行接下来的搜索就可以！或者说进行接下来的改变
	      //从书上的方法看，不仅判断是否在界内，而且判断下一个点是不是W，这样可以减少一点递归，我这里没有判断，就直接进行下一个，就多了一次对(nexti,nextj)=.的处理,这里就不用添加了，书中的代码超级优秀！
	      onePond (nexti, nextj);
	    }
	  //to left
	  //行不变，列加一
	  nexti = i, nextj = j - 1;
	  if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	    {
	      onePond (nexti, nextj);
	    }

	  //to down
	  //行加一，列不变
	  nexti = i + 1, nextj = j;
	  if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	    {

	      onePond (nexti, nextj);
	    }
	  //to up
	  //行减一，列不变
	  nexti = i - 1, nextj = j;
	  if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	    {

	      onePond (nexti, nextj);
	    }

	  //to lower right
	  //行加一，列加一
	  nexti = i + 1, nextj = j + 1;
	  if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	    {

	      onePond (nexti, nextj);
	    }
	  //to left up
	  //行减一，列减一
	  nexti = i - 1, nextj = j - 1;
	  if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	    {

	      onePond (nexti, nextj);
	    }

	  //to left down
	  //行加一，列减一
	  nexti = i + 1, nextj = j - 1;
	  if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	    {

	      onePond (nexti, nextj);
	    }
	  //to right up
	  //行减一，列加一
	  nexti = i - 1, nextj = j + 1;
	  if ((nexti >= 0 && nexti < N) && (nextj >= 0 && nextj < M))
	    {

	      onePond (nexti, nextj);
	    }
	  //最终我还是把8个方向都给全了！

	}
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
	  printf ("%2c", field[i][j]);
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

int count = 0;
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{

	  //这里onePond（i，j）就是一个测试连通和建立连通的函数！
	  //这里onePand函数的作用就是把连通的W给消失掉！
	  if (field[i][j] == 'W')
	    {
	      //printf ("(%d,%d)\n", i, j);
  //printfield ();
	      onePond (i, j);
  //printfield ();
	      //onePond之后，连通的W都变为了.
	      //下一个找到的W将是另一个连通的水哇的开始
	      count++;
	    }
	}
    }
  //printf ("we find %d ponds\n", count);
  printf ("%d\n", count);
  return 0;

}
