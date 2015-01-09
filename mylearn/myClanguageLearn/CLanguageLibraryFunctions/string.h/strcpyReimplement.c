/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: strcpyReimplement.c
 * 创建日期: 2014年12月13日 星期六 07时58分42秒
 * 程序想法：把ｓｔｒｃｐｙ重新实现一下啊
 */
#include<stdio.h>

void cpystr(char *pss, char *pds) {
    while ((*pds = (*pss)) != '\0') {
	pds++;
	pss++;
    }
}
void cpystr2(char *pss, char *pds) {
    //while (*pds++ = (*pss++));
    //while (*pds++ = ((*pss)++));//出现段错误！
    while ((*(pds++)) = (*(pss++)));
}
void test_cpystr() {
    char *pa = "CHINA", b[10], *pb;
    pb = b;
    //cpystr(pa, pb);
    cpystr2(pa, pb);
    printf("string a=%s\nstring b=%s\n", pa, pb);
}
void input() {
}

void solve() {
}

int main() {
    input();
    solve();
    test_cpystr();
    return 0;
}
