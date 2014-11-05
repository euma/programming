#include<stdio.h>
int
main ()
{
  int n;
  scanf("%d",&n);
  int i,j,k;

  for (i = 0; i < n; i++)
    {
      for (j = i + 1; j < n; j++)
	{
	  for (k = j + 1; k < n; k++)
	    printf ("%d %d %d\n", i, j, k);
	}
    }
  return 0;
}
