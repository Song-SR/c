#include <stdio.h>
#include <conio.h>  // getch()
#include <string.h>  // strcmp()
#define MAX 10000

int main(void){

    char line[MAX];  // ���Ͽ��� �ҷ��� ���� ����
    char contents[MAX];  // �Է��� ����
    char password[20];
    char c;  // ����ŷ �뵵

    printf("��й�ȣ �Է� : ");

    int i = 0;
    while(1){
        c = getch();  // Ű �Է½� �ٷ� ����    cf) getchar()�� ���͸� �Է¹޾ƾ� ����
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
    if(strcmp(password, "1234") == 0){  // stringcompare ��ġ�ϸ� 0
        printf("login success!\n");
        char *fileName = "c:\\dev\\c\\data.txt";
        FILE *file = fopen(fileName, "a+b");  // ������ ������ ����, ������ append
        if(file == NULL){
            printf("���� ���� ����\n");
        }
        while(fgets(line, MAX, file) != NULL){
            printf("%s", line);
        }
        printf("���� �ۼ� (�����Ϸ��� EXIT) : \n");

        while(1){
            scanf("%[^\n]", contents);  // \n�� ���������� �о����
            getchar();  // Enter �Է� - (Flushó��)

            if(strcmp(contents, "EXIT") == 0){
                printf("�Է� ����\n");
                break;
            }
            fputs(contents, file);
            fputs("\n", file);  // Flushó���� ���͸� �����ع������Ƿ� ���Ƿ� �߱�
        }
        fclose(file);
    }else{
        printf("login fail..\n");
    }

    return 0;
}