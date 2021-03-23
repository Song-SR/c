#include <stdio.h>

int main(void){
    
    char e = 'A';
    printf("%c\n", e);
    char str[256];
    printf("문자열 입력 : ");
    scanf("%s", str, sizeof(str));
    printf("입력한 문자 : %s\n", str);

}