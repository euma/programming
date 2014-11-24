#include<stdio.h>
#include<math.h>
int main(){
  const double pi = acos(-1.0);//第二版里换了函数！
  //pi=acos(-1.0) <==> cos(pi)=-1
  //const double pi = 4.0 * atan(1.0);
  //pi=4*atan(1.0) <==> tan(pi/4)=1 <==> sin(pi/4) / cos(pi/4) = 1 <==> sin(pi/4) = cos(pi/4),这在等腰直接三角形里可以直接看出来！//sin(pi/4)=sqrt(2)/2,cos(pi/4)=sqrt(2)/2
  double r, h, s1, s2, s;
  scanf("%lf%lf", &r, &h);
  s1 = pi * r * r;
  s2 = 2 * pi * r * h;
  s = s1 * 2.0 + s2;
  printf("Area = %.3lf\n", s);
  return 0;
}
