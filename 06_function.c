#include <stdio.h>

void function(int num);  // ����
int function2(int num);

int main(){
    function(3);
    printf("\n");
    printf("%d", function2(3));
    return 0;
}

void function(int num){  // ����
    printf("num : %d", num);
}

int function2(int num){
    return num+3;
}