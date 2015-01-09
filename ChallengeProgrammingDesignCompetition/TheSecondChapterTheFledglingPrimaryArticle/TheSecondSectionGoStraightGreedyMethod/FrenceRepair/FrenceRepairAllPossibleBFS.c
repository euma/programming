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
//int 这里书上说，不用到达终点就停止程序，可以全部搜索完，直到ｑｕｅｕｅ为空
//我们可以得到所有从起点出发到达任何一个位置的最短距离！这些数据都存储在ｄ［ｘ］［ｙ］数组中！所以我的想法是，让程序全部搜索完，我只需要打印ｄ［ｇｘ］［ｇｙ］就可以！
void
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
      //全部搜索完！
      //if (p.first == gx && p.second == gy)
	//break;
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
  //return d[gx][gy];
}

//思考为什么是最短距离，因为我们是一层一层往下走的，不可能跳过一层来到达，所以我们的距离是最短的！

void
solve ()
{
  //int res = bfs ();
  bfs ();
  printf ("%d\n", d[gx][gy]);
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
/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: FrenceRepairAllPossible.c
 * 创建日期: 2014年12月28日 星期日 06时38分01秒
 * 程序想法：先实现给定一个排列，我找出所有分割下的花销！ 
 */
#include<stdio.h>
#define MAX_N 20000
//输入数据
int N;
int L[MAX_N];
//内部数据

void swap(int *Aj, int *Aj1) {
    int originAj = (*Aj);
    *Aj = (*Aj1);
    *Aj1 = originAj;
}
void printarray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
	printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int n) {
    int swapped;
    do {
	swapped = 0;
	int i;
	//这里依然是每一次都从头开始比较，调换次序
	for (i = 1; i <= n - 1; i++) {
	    //printarray(A, n);
	    if (A[i - 1] > A[i]) {
		swap(&A[i - 1], &A[i]);
		swapped = 1;
	    }
	    //printarray(A, n);
	}
	//这里调换一次就让ｎ减一，这是一个我没有见过的处理办法！
	n = n - 1;
	//printf("a round end n=%d\n", n);
    } while (swapped);
}
void input() {
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++) {
	scanf("%d", &L[i]);
    }
}
void test_input() {
    printf("N=%d\n", N);
    int i;
    for (i = 0; i < N; i++) {
	printf("L[%d]=%d\n", i, L[i]);
    }
}
int cutting(int start, int end) {
    if (start > end) {
	return 0;
    }
    if (start == end) {
	return L[start];
    }
    if (start + 1 == end) {
	return L[start] + L[end];
    }

    int cuttingPoint;
    for (cuttingPoint = start ; cuttingPoint < end; cuttingPoint++) {

	printf("cutting(%d-|%d|-%d)\n", start, cuttingPoint, end);
	return cutting(start, cuttingPoint) + cutting(cuttingPoint+1, end);

    }
    //这里感觉用队列，广度优先搜索比较好可以写一个广度优先搜索的版本
    //

}

void test_cutting() {
    int start = 0, end = N - 1;
    printf("spending = %d\n", cutting(start, end));
}
void solve() {
    int i;
    int spending = 0;
    bubbleSort(L, N);
    for (i = 0; i < N; i++) {
	spending += L[i] * (N - i);
    }
    spending -= L[0];
    //printf("spending = %d\n", spending);
    printf("%d\n", spending);
}

int main() {
    input();
    test_input();
    //solve();
    test_cutting();
    return 0;
}
