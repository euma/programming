/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: ThreeIntegerSortingMinMidMax.c
 * 创建日期: 2014年12月06日 星期六 06时17分40秒
 */
#include<stdio.h>
int a,b,c;
#define min(X,Y) ((X) < (Y) ? (X) : (Y))
#define max(X,Y) ((X) < (Y) ? (X) : (Y))

void
input ()
{
}

void
solve ()
{

minabc=min(min(a,b),c)
maxabc=max(max(a,b),c)
midabc=a+b+c-minabc-maxabc
printf("%d %d %d\n",minabc,midabc,maxabc);
}

int
main ()
{
   
  input ();
  solve ();
  return 0;
}

