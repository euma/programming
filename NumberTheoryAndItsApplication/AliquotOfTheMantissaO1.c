#include<stdio.h>
int
main ()
{
  int a, b;
  int i;
  int t1, t2, t3;
  while (scanf ("%d%d", &a, &b), a != 0 || b != 0)
    {
	    //t1=a mod b
      t1 = a % b;
      //如果b整除a，则后面两位数只能是b的倍数，且不能超过100
      if (t1 == 0)
	{
	  printf ("00");
	  for (i = 1; b * i < 100; i++)
	    printf (" %02d", b * i);
	  //百位以上的余数+百位一下的余数
	  //0+0
	  //100*a*j+b*i
	}
      else
	{
	  t2 = (t1 * 100) % b;//最终还是找到a*100 mod b 是多少！
	  
	  t3 = b - t2; //补上t3余数就会为零！
	  //给百位的余数t2补上t3,就可以实现整除！
	  printf ("%02d", t3);
	  for (i = 1; b * i + t3 < 100; i++)
	    printf (" %02d", b * i + t3);
	  //百位以上的余数+百位一下的余数
	  //t2+t3=b
	  //100*a*j+t2+b*i+b-t2
	}
      printf ("\n");
    }
  return 0;
}
