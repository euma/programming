#include<stdio.h>
#include<math.h>
int
main ()
{
  double pi =2* acos(0.0);
  printf("pi is %lf\n",pi);
  //而且我写代码的风格是，用变量本身的意思来做变量名，
  //形成自己的好的代码风格也是一件重要的事情，它会帮助我把程序写得更好！
  //输入
  double theBottomRadius;
  double high;
  scanf ("%lf%lf", &theBottomRadius, &high);

  //输出
  double theCylinderSurfaceArea;

  //计算过程
  //两个底面，加一个侧面，底面是一个圆，侧面展开后是一个长方形！
  theCylinderSurfaceArea =
    2 * pi * theBottomRadius * theBottomRadius +
    high * 2 * pi * theBottomRadius;
  printf ("Area = %lf\n", theCylinderSurfaceArea);

  //无论多么简单的代码和问题，自己写出来都是对自己的一次锻炼！而且我要在一次次亲自写代码中锻炼自己！直接看书中的代码，让我丢失了锻炼自己的机会！
  return 0;
}
