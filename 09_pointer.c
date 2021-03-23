#include <stdio.h>

int main(){

    int a  = 1;

    printf("변수 a 의 메모리 공간 주소 : %d\n", &a);
    printf("변수 a에 담겨있는 값은 : %d\n", a);

    int *b;  // 포인터변수
    b = &a;
    printf("포인터가 찾아가는 주소 : %d, 변수값 : %d\n", b, *b);

    *b *= 3;
    printf("포인터가 값을 바꾼 주소 : %d, 변수값 : %d\n", b, *b);
    printf("a가 정말 바뀌었나? %d\n", a);


    // 배열과 포인터
    int arr[3] = {1,2,3};
    printf("%d", arr);
    
    for(int i = 0; i < 3; i++){
        printf("arr[%d]의 값은 : %d\n", i, arr[i]);
    }
    for(int i = 0; i < 3; i++){
        printf("arr[%d]의 값은 : %d\n", i, *(arr+i));
        // arr은 배열이 시작하는 주소를 담고 있음
        // 즉 arr[i] == *(arr+i)
    }

    return 0;
}