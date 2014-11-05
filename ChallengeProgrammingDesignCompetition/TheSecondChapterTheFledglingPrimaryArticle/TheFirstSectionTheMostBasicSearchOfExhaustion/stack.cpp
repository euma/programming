#include<stack>
#include<cstdio>
using namespace std;
int main() {
	stack<int> s;//声明存储int类型数据的栈
	s.push(1);//{}->{1}
	s.push(2);//{1}->{1,2}
	s.push(3);//{1,2}->{1,2,3}
	printf("%d\n",s.top());//3
	s.pop();//从栈顶移除{1,2,3}->{1,2}
	printf("%d\n",s.top());//2
	s.pop();//{1,2}->{1}
	printf("%d\n",s.top());//1
	s.pop();//{1}->{}
	return 0;
}
