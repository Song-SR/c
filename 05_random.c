#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));  // 매 시작시 다르게 동작하게끔
    rand(); rand(); rand();
    int i = rand();
    printf("%d\n", i);

    return 0;
}