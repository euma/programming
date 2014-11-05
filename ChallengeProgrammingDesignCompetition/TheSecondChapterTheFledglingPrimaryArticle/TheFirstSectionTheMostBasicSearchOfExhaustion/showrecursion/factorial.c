#include<stdio.h>
int space = 0;
int
fact (int n)
{
  printf ("fact(%d)=%d*fact(%d)\n", n, n, n - 1);
  int i;
  for (i = 0; i <= space; i++)
    {
      printf (" ");
    }
  space++;


  if (n == 0)
    return 1;
  return n * fact (n - 1);
}

int
main ()
{
  printf ("factorial(%d)=%d\n", 4, fact (4));
  return 0;
}
