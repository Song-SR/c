#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));  // �� ���۽� �ٸ��� �����ϰԲ�
    rand(); rand(); rand();
    int i = rand();
    printf("%d\n", i);

    return 0;
}