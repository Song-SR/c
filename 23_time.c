#include<stdio.h>
#include<time.h>

void main()
{
	struct tm *t;
	time_t timer; // �ð�����

	timer = time(NULL);    // ���� �ð��� �� ������ ���
	t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�

	printf("���� �ð��� ");
	printf("%d�� %d�� %d�� %d�� %d�� %d���Դϴ�.\n",t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
}