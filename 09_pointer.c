#include <stdio.h>

int main(){

    int a  = 1;

    printf("���� a �� �޸� ���� �ּ� : %d\n", &a);
    printf("���� a�� ����ִ� ���� : %d\n", a);

    int *b;  // �����ͺ���
    b = &a;
    printf("�����Ͱ� ã�ư��� �ּ� : %d, ������ : %d\n", b, *b);

    *b *= 3;
    printf("�����Ͱ� ���� �ٲ� �ּ� : %d, ������ : %d\n", b, *b);
    printf("a�� ���� �ٲ����? %d\n", a);


    // �迭�� ������
    int arr[3] = {1,2,3};
    printf("%d", arr);
    
    for(int i = 0; i < 3; i++){
        printf("arr[%d]�� ���� : %d\n", i, arr[i]);
    }
    for(int i = 0; i < 3; i++){
        printf("arr[%d]�� ���� : %d\n", i, *(arr+i));
        // arr�� �迭�� �����ϴ� �ּҸ� ��� ����
        // �� arr[i] == *(arr+i)
    }

    return 0;
}