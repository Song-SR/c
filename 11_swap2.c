#include <stdio.h>

void swap(int *a, int *b);
int main(){

    int a = 10;
    int b = 20;
    printf("a�� b�� �� : %d, %d\n", a, b);
    swap(&a, &b);  // ���� a,b�� �ּҰ��� �Լ��� �Ѱ��ֱ�!
    printf("a�� b ���� �� : %d, %d\n", a, b);
    
    return 0;
}

void swap(int *a, int *b){  // ������ �ʿ��� �� �������̴ϱ� *���
    int temp = *a;
    *a = *b;
    *b = temp;
}