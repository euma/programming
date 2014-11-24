#include<queue>
#include<cstdio>
using namespace std;
void
printqueue (queue < int >que)
{
  printf ("%d ", que.front ());	//1
  que.pop ();			//从队尾移除{1,2,3}->{2,3}
  printf ("%d ", que.front ());	//2
  que.pop ();			//{2,3}->{3}
  printf ("%d ", que.front ());	//3
  que.pop ();			//{3}->{}
  printf ("\n");

}

void
printqueue2 (queue < int >que)
{
  while (que.size ())
    {
      printf ("%d ", que.front ());
      que.pop ();
    }
  printf ("\n");

}


int
main ()
{
  queue < int >que;		//声明存储int类型数据的队列
  que.push (1);			//{}->{1}
  que.push (2);			//{1}->{1,2}
  que.push (3);			//{1,2}->{1,2,3}
  printf ("queue size is %d\n", (int) que.size ());
  printqueue (que);
  printqueue2 (que);
  printf ("queue size is %d\n", (int) que.size ());
  //两者相同，可以看出，这是复制过去的，而不是传递过去的！
  return 0;
}
