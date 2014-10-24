/*在我本机上测试正确，在online judge上却是compile error
 * 这里compile error，可能只是当前编译器不接受的句子！*/

#include<stdio.h>
int
main ()
{
  int a, b;
  scanf ("%d%d", &a, &b);
  while (a != 0 || b != 0)
    {
      int i, j;
      int find = 0;
      int first = 1;
      for (i = 0; i < 10; i++)
	{
	  for (j = 0; j < 10; j++)
	    {
	      int num = a * 100 + i * 10 + j;
	      if (num % b == 0)
		{
		  find = 1;
		  //这样处理有一个问题，最后一个答案后面会先跟一个空格，再跟一个回车，
		  //我的理想情况是不要那个空格，但是去掉那个空格还要添加一些判断代码！
		  //我的处理办法是给前面加空格，第一个的前面不用加空格，这时，我们只需要
		  //判断是不是第一个，如果是第一个不加空格，如果不是第一个，都要在前面加空格！
		  if (!first)
		    printf (" ");
		  first = 0;
		  printf ("%d%d", i, j);
		}
	    }
	}
      if (find)
	printf ("\n");
      scanf ("%d%d", &a, &b);
    }
}
