#include <stdio.h>

int main(){

    int a = 0;
    while(a < 10){
        printf("%d ", a);
        a++;
    }
    printf("\n");
    for(int i = 0; i < 5; i++){
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(j <= i){
            printf("*");
            }
        }
        printf("\n");
    }

    // 조건문, break, continue, &&, ||, switch - case, 

}