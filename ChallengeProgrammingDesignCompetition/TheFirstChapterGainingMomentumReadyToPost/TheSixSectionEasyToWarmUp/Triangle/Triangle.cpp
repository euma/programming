/*直接在别人的代码基础上修改有好处，也有坏处，可是我觉得最重要的还是自己的掌控！*/
#include<cstdio>
const int MAX_N = 100;
int n, a[MAX_N];
int ThePerimeterOfTheLargest = 0;

void
solve ()
{
  for (int i = 0; i < n; i++)
    {
      for (int j = i+1; j < n; j++)
	{
	  for (int k = j+1; k < n; k++)
	    {
	      int ThePerimeter;
	      if (a[i] + a[j] > a[k])
		{
		  ThePerimeter = a[i] + a[j] + a[k];
		}
	      else
		{
		  ThePerimeter = 0;
		}

	      if (ThePerimeter > ThePerimeterOfTheLargest)
		{
		  ThePerimeterOfTheLargest = ThePerimeter;
		}
	    }
	}
    }
  printf("%d\n",ThePerimeterOfTheLargest);
}

int
main ()
{
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  solve ();

  return 0;
}
