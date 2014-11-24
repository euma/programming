#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 10000000;
const int MAX_N = 100;
const int MAX_M = 100;

//使用pair表示状态时，使用typedef会更加方便一些
typedef pair < int, int >P;
//输入
char maze[MAX_N][MAX_M + 1];	//表示迷宫的字符串的数组
int N, M;
int sx, sy;			//起点坐标start x, start y
int gx, gy;			//终点坐标goal x, goal y
int d[MAX_N][MAX_M];		//到各个位置的最短距离的数组，这里统计的很全面？
//4个方向移动的向量
int dx[4] = { 1, 0, -1, 0 }, dy[4] =

{
0, 1, 0, -1};
//(1,0)向右
//(0,1)向上
//(-1,0)向左
//(0,-1)向下
//逆时针从右开始寻找！

void
input ()
{
  int i, j;
  scanf ("%d %d", &N, &M);
  for (i = 0; i < N; i++)
    {
      scanf ("%s", maze[i]);
    }
  //找到起点的坐标
  int find = 0;
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{
	  if (maze[i][j] == 'S')
	    {
	      sx = i;
	      sy = j;
	      find = 1;
	      break;
	    }
	}
      if (find)
	break;
    }
  //找到终点的坐标
  find = 0;
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{
	  if (maze[i][j] == 'G')
	    {
	      gx = i;
	      gy = j;
	      find = 1;
	      break;
	    }
	}
      if (find)
	break;
    }


}

void
printfqueue (queue < P > que)
{
  while (que.size ())
    {
      P p = que.front ();
      printf (" (%d,%d)", p.first, p.second);
      que.pop ();
    }
  printf ("\n");

}

//求从（ｓｘ，ｓｙ)到（ｇｘ，ｇｙ）的最短距离
//如果无法到达，则是ＩＮＦ
//这里的搜索，没有记录最短距离经过哪些点！
int
bfs ()
{
  queue < P > que;
  //把所有的位置都初始化为ＩＮＦ
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      d[i][j] = INF;
  //将起点加入队列，并把这一地点的距离设置为０
  que.push (P (sx, sy));
  d[sx][sy] = 0;
  //不断循环直到队列的长度为０
  while (que.size ())
    {

      printfqueue (que);
      //从队列的最前端取出元素
      P p = que.front ();
      que.pop ();
      //如果取出的状态已经是终点，则结束搜索
      if (p.first == gx && p.second == gy)
	break;
      //四个方向的循环
      for (int i = 0; i < 4; i++)
	{
	  //移动之后的位置记为（ｎｘ，ｎｙ）
	  int nx = p.first + dx[i], ny = p.second + dy[i];
	  //判断是否可以移动以及是否已经访问过（ｄ［ｎｘ］［ｎｙ］！＝ＩＮＦ即为已经访问过）
	  //这里判断的可否移动，其实就是是不是超过了边界,以及是不是碰到了墙
	  if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#'
	      && d[nx][ny] == INF)
	    {
	      //可以移动的话，则加入到队列，并且到该位置的距离确定为到ｐ的距离＋１
	      que.push (P (nx, ny));
	      d[nx][ny] = d[p.first][p.second] + 1;
	    }
	}
    }
  return d[gx][gy];
}

//思考为什么是最短距离，因为我们是一层一层往下走的，不可能跳过一层来到达，所以我们的距离是最短的！

void
solve ()
{
  int res = bfs ();
  printf ("%d\n", res);
}

void
printmaze ()
{
  int i;
  for (i = 0; i < N; i++)
    {
      printf ("%s\n", maze[i]);
    }
}



void
printd ()
{
  int i, j;
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < M; j++)
	{
	  if (d[i][j] == INF)
	    //printf ("INF ");
	    printf ("%3c ",'x');
	  else
	    printf ("%3d ", d[i][j]);
	}
      printf ("\n");
    }

  printf ("\n");
}

int
main ()
{
  input ();
  printf ("start point position:(%d,%d)\n", sx, sy);
  printf ("end point position:(%d,%d)\n", gx, gy);

  printmaze ();
  solve ();
  printd ();
  return 0;
}
