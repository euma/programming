/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: 35Other2.c
 * 创建日期: 2015年01月04日 星期日 07时18分04秒
 * 程序想法： 
Sun, 24 Oct 2004, 14:59 
tilex 
Canada	
   Quote   Report    63
Ok, here's mine.. nothing really clever nor complicated:
	
Hide Code


#include "iostream" // less than and greater than are disabled
int main(int argc, char** argv)
{
    unsigned int sum = 0;
    for(int i = 1; i < 1001; ++i)
        if(!(i % 3) && !(i % 5))
            sum += i;
    std::cout << i;
    return 0;
}

PS: I wrote it from memory but I think it's pretty much what I did
 */
#include <iostream>		// less than and greater than are disabled
//int main(int argc, char **argv) {
int main() {
    unsigned int sum = 0;
    for (int i = 1; i < 1000; ++i)
	if (!(i % 3) || !(i % 5))
	    sum += i;
    std::cout << sum << "\n";
    return 0;
}
