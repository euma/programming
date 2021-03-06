#include<queue>
#include<cstdio>
using namespace std;
typedef pair<int, int> P;
void
printqueue (queue < P >que)
{
  printf ("(%d,%d) ", que.front ().first,que.front().second);
  que.pop ();
  printf ("(%d,%d) ", que.front ().first,que.front().second);
  que.pop ();			
  printf ("(%d,%d) ", que.front ().first,que.front().second);
  que.pop ();		
  printf ("\n");

}

void
printqueue2 (queue < P >que)
{
  while (que.size ())
    {
  printf ("(%d,%d) ", que.front ().first,que.front().second);
      que.pop ();
    }
  printf ("\n");

}


int
main ()
{
  queue < P >que;		//声明存储int类型数据的队列
  que.push (P(1,2));			//{}->{1}
  que.push (P(2,3));			//{1}->{1,2}
  que.push (P(3,4));			//{1,2}->{1,2,3}
  printf ("queue size is %d\n", (int) que.size ());
  printqueue (que);
  printqueue2 (que);
  printf ("queue size is %d\n", (int) que.size ());
  //两者相同，可以看出，这是复制过去的，而不是传递过去的！
  return 0;
}
