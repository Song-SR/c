#include <stdio.h>

int main(){

    char c = 'A';
    char str[7] = "coding"; // 문자열의 끝을 의미하는 NULL 문자 '\0'이 자동으로 포함된다!
    printf("%s\n", str);

    char str1[] = "coding";
    printf("%s\n", str1);
    printf("%d\n", sizeof(str1));

    char str2[] = "코딩";
    printf("%d\n", sizeof(str2));

    return 0;
}