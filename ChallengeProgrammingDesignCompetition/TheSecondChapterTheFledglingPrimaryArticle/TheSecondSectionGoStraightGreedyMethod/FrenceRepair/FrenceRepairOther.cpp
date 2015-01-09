/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: FrenceRepairOther.cpp
 * 创建日期: 2015年01月03日 星期六 06时52分30秒
 * 程序想法： 
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
 
//#define __int64 long long
 
class Node
{
public:
	__int64 w;
	Node(__int64 weight = 0) : w(weight) {}
	bool operator<(const Node& rhs) const
	{
		return this->w > rhs.w;
	}
};
 
int main(int argc, char **argv)
{
	int n, i;
	while (EOF != scanf("%I64d", &n))
	{
		priority_queue<Node> q;
		__int64 tmp, res = 0;
		for (i = 0; i < n; ++i)
		{
			scanf("%I64d", &tmp);
			q.push(tmp);
		}
		Node na, nb;
		while (q.size() > 1)
		{
			na = q.top();
			q.pop();
			nb = q.top();
			q.pop();
			na.w += nb.w;
			res += na.w;
			q.push(na);
		}
		q.pop();
		printf ("%I64d\n", res);
	}
 
	return 0;
}
我需要改造为ｇ＋＋上可以运行的代码！
http://www.programlife.net/poj-3253-fence-repair.html
 */
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

class Node {
  public:
    long long w;
   Node(long long weight = 0):w(weight) {
    } bool operator<(const Node & rhs) const {
	return this->w > rhs.w;
}};
//c++引入的一些语法让我看不懂，这些语法的结构感觉不合理！

//int main(int argc, char **argv)
int main() {
    int n, i;
    //我能做的工作就是打印一下中间过程，看看内部发生了什么？！
    while (EOF != scanf("%I64d", &n)) {
	priority_queue < Node > q;
	long long tmp, res = 0;
	for (i = 0; i < n; ++i) {
	    scanf("%I64lld", &tmp);
	    q.push(tmp);
	}
	Node na, nb;
	while (q.size() > 1) {
	    na = q.top();
	    q.pop();
	    nb = q.top();
	    q.pop();
	    na.w += nb.w;
	    res += na.w;
	    q.push(na);
	}
	q.pop();
	printf("%I64lld\n", res);
    }

    return 0;
}
