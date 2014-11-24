#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char atlas[110][110];
int d[8][2] =
  { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
int used[110][110];
int n, m;

void
dfs (int i, int j)
{
  int k;
  used[i][j] = 1;
  for (k = 0; k < 8; ++k)
    if (i + d[k][0] >= 0 && i + d[k][0] < n && j + d[k][1] < m
	&& j + d[k][1] >= 0 && atlas[i + d[k][0]][j + d[k][1]] == 'W'
	&& !used[i + d[k][0]][j + d[k][1]])
      dfs (i + d[k][0], j + d[k][1]);
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
  for (i = 0; i < n; ++i)
    scanf ("%s", atlas[i]);

  //printatlas ();
  int ans = 0;
  memset (used, 0, sizeof used);
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