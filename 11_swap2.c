#include <stdio.h>

void swap(int *a, int *b);
int main(){

    int a = 10;
    int b = 20;
    printf("a와 b의 값 : %d, %d\n", a, b);
    swap(&a, &b);  // 변수 a,b의 주소값을 함수로 넘겨주기!
    printf("a와 b 스왑 후 : %d, %d\n", a, b);
    
    return 0;
}

void swap(int *a, int *b){  // 실제로 필요한 건 변수값이니까 *사용
    int temp = *a;
    *a = *b;
    *b = temp;
}