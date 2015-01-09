/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: systemV2.c
 * 创建日期: 2014年12月04日 星期四 22时01分06秒
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input() {
}

void solve() {
    int status;
    char cmdstring[50];
    strcpy(cmdstring, "ifconfig eth0");
    if (NULL == cmdstring)	//如果cmdstring为空趁早闪退吧，尽管system()函数也能处理空指针
    {
	return ;
    }
    status = system(cmdstring);
    if (status < 0) {
	printf("cmd: %s\t error: %s", cmdstring, strerror(errno));	// 这里务必要把errno信息输出或记入Log
	return ;
    }

    if (WIFEXITED(status)) {
	printf("normal termination, exit status = %d\n", WEXITSTATUS(status));	//取得cmdstring执行结果
    } else if (WIFSIGNALED(status)) {
	printf("abnormal termination,signal number =%d\n", WTERMSIG(status));	//如果cmdstring被信号中断，取得信号值
    } else if (WIFSTOPPED(status)) {
	printf("process stopped, signal number =%d\n", WSTOPSIG(status));	//如果cmdstring被信号暂停执行，取得信号值
    }
}

int main() {

    input();
    solve();
    return 0;
}
