#include <stdio.h>

void swap(int a, int b);
int main(){

    int a = 10;
    int b = 20;
    printf("a�� b�� �� : %d, %d\n", a, b);
    printf("a�� b ���� ��(�Լ� ��) : %d, %d\n", &a, &b);
    swap(a, b);
    printf("a�� b ���� �� : %d, %d\n", a, b);
    printf("a�� b ���� ��(�Լ� ��) : %d, %d\n", &a, &b);

    return 0;
}

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    printf("a�� b ���� ��(�Լ� ��) : %d, %d\n", a, b);
    printf("a�� b ���� ��(�Լ� ��) : %d, %d\n", &a, &b);
    // main�� swap�Լ����� ���� a, b�� �ּҰ� ���� �ٸ��� ������ �Լ������� ������������ ������ �� ��!
}