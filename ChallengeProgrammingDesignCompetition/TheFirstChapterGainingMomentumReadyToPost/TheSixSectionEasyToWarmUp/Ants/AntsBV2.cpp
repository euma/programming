#include<cstdio>
#include<algorithm>
#define MAX_N 1000000
using namespace std;

int L, n;
int x[MAX_N];

void
solve ()
{
  scanf ("%d%d", &L, &n);
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &x[i]);
    }
  //计算最短时间
  int minT = 0;
  for (int i = 0; i < n; i++)
    {
      minT = max (minT, min (x[i], L - x[i]));
    }
  //计算最长时间
  int maxT = 0;
  for (int i = 0; i < n; i++)
    {
      maxT = max (maxT, max (x[i], L - x[i]));
    }
  printf ("%d %d\n", minT, maxT);
}

int
main ()
{
  int num;
  scanf ("%d", &num);
  for (int i; i < num; i++)
    {
      solve ();
    }
  return 0;
}
