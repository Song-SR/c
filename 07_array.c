#include <stdio.h>

int main(){

    char c = 'A';
    char str[7] = "coding"; // ���ڿ��� ���� �ǹ��ϴ� NULL ���� '\0'�� �ڵ����� ���Եȴ�!
    printf("%s\n", str);

    char str1[] = "coding";
    printf("%s\n", str1);
    printf("%d\n", sizeof(str1));

    char str2[] = "�ڵ�";
    printf("%d\n", sizeof(str2));

    return 0;
}