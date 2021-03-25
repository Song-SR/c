#include <stdio.h>

#define MAX 10000

int main(void){
    char line[MAX];
    FILE *file = fopen("c:\\dev\\c\\test1.txt", "wb");  // 파일을 여는 방식 read write append (읽기 쓰기 이어쓰기) text binary
    if(file == NULL){
        printf("파일 열기 실패\n");
        return 1;
    }

    fputs("fputs를 사용하여 글을 작성\n", file);
    
    fputs("데이터 손실을 막기 위해 닫는 것까지 항상 체크!\n", file);
    fclose(file);

    return 0;
}