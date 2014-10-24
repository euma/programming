/*在标准C/C++中，我们可通过tm结构来获得日期和时间，tm结构在time.h中的定义如下：
#ifndef _TM_DEFINED
struct tm {
int tm_sec; * 秒–取值区间为[0,59] /
int tm_min; * 分 - 取值区间为[0,59] /
int tm_hour; * 时 - 取值区间为[0,23] /
int tm_mday; * 一个月中的日期 - 取值区间为[1,31] /
int tm_mon; * 月份（从一月开始，0代表一月） - 取值区间为[0,11] /
int tm_year; * 年份，其值从1900开始 /
int tm_wday; * 星期–取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 /
int tm_yday; * 从每年的1月1日开始的天数–取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 /
int tm_isdst; * 夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。/
long int tm_gmtoff; *指定了日期变更线东面时区中UTC东部时区正秒数或UTC西部时区的负秒数/
const char *tm_zone; *当前时区的名字(与环境变量TZ有关)/
};
#define _TM_DEFINED
#endif
ANSI C标准称使用tm结构的这种时间表示为分解时间(broken-down time)。
2格式转换编辑
可以使用的函数是gmtime()和localtime()将time()获得的日历时间time_t结构体转换成tm结构体。
其中gmtime()函数是将日历时间转化为世界标准时间（即格林尼治时间），并返回一个tm结构体来保存这个时间，而localtime()函数是将日历时间转化为本地时间。*/
#include <stdio.h>
#include <time.h>
int main(void)
{
	struct tm *ptr;
	time_t lt;
	lt =time(NULL);
	ptr=localtime(&lt);
	printf("second:%d\n",ptr->tm_sec);
	printf("minute:%d\n",ptr->tm_min);
	printf("hour:%d\n",ptr->tm_hour);
	printf("mday:%d\n",ptr->tm_mday);
	printf("month:%d\n",ptr->tm_mon+1);
	printf("year:%d\n",ptr->tm_year+1900);
	return 0;
}
