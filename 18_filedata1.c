#include <stdio.h>

#define MAX 10000

int main(void){
    char line[MAX];
    FILE *file = fopen("c:\\dev\\c\\test1.txt", "wb");  // ������ ���� ��� read write append (�б� ���� �̾��) text binary
    if(file == NULL){
        printf("���� ���� ����\n");
        return 1;
    }

    fputs("fputs�� ����Ͽ� ���� �ۼ�\n", file);
    
    fputs("������ �ս��� ���� ���� �ݴ� �ͱ��� �׻� üũ!\n", file);
    fclose(file);

    return 0;
}