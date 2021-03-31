#include<stdio.h>
#include<time.h>

void main()
{
	struct tm *t;
	time_t timer; // 시간측정

	timer = time(NULL);    // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

	printf("현재 시간은 ");
	printf("%d년 %d월 %d일 %d시 %d분 %d초입니다.\n",t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
}