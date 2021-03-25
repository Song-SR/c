#include <stdio.h>
#include <conio.h>  // getch()
#include <string.h>  // strcmp()
#define MAX 10000

int main(void){

    char line[MAX];  // 파일에서 불러온 내용 저장
    char contents[MAX];  // 입력할 내용
    char password[20];
    char c;  // 마스킹 용도

    printf("비밀번호 입력 : ");

    int i = 0;
    while(1){
        c = getch();  // 키 입력시 바로 동작    cf) getchar()은 엔터를 입력받아야 동작
        if(c == 13){  // enter
            password[i] = '\0';
            break;
        }else{
            printf("*");
            password[i] = c;
        }
        i++;
    }

    printf("\n==password check==\n");
    if(strcmp(password, "1234") == 0){  // stringcompare 일치하면 0
        printf("login success!\n");
        char *fileName = "c:\\dev\\c\\data.txt";
        FILE *file = fopen(fileName, "a+b");  // 파일이 없으면 생성, 있으면 append
        if(file == NULL){
            printf("파일 열기 실패\n");
        }
        while(fgets(line, MAX, file) != NULL){
            printf("%s", line);
        }
        printf("내용 작성 (종료하려면 EXIT) : \n");

        while(1){
            scanf("%[^\n]", contents);  // \n을 만날때까지 읽어들임
            getchar();  // Enter 입력 - (Flush처리)

            if(strcmp(contents, "EXIT") == 0){
                printf("입력 종료\n");
                break;
            }
            fputs(contents, file);
            fputs("\n", file);  // Flush처리로 엔터를 무시해버렸으므로 임의로 추기
        }
        fclose(file);
    }else{
        printf("login fail..\n");
    }

    return 0;
}