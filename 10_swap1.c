#include <stdio.h>

void swap(int a, int b);
int main(){

    int a = 10;
    int b = 20;
    printf("a와 b의 값 : %d, %d\n", a, b);
    printf("a와 b 스왑 중(함수 밖) : %d, %d\n", &a, &b);
    swap(a, b);
    printf("a와 b 스왑 후 : %d, %d\n", a, b);
    printf("a와 b 스왑 중(함수 밖) : %d, %d\n", &a, &b);

    return 0;
}

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    printf("a와 b 스왑 중(함수 내) : %d, %d\n", a, b);
    printf("a와 b 스왑 중(함수 내) : %d, %d\n", &a, &b);
    // main과 swap함수내의 변수 a, b의 주소가 서로 다르기 때문에 함수밖으로 빠져나왔을때 적용이 안 됨!
}