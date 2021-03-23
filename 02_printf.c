#include <stdio.h>

int main(void){

     int a, b, c = 0;
     const int d = 1;

     printf("정수 3개 입력 : ");
     scanf("%d %d %d",&a, &b, &c);
     printf("a, b, c : %d, %d, %d\n", a, b, c);

    return 0;
}