#include <stdio.h>

#define MAX 10000

int main(void){

    int num[6] = {0,0,0,0,0,0};
    int bonus = 0;
    char str1[MAX];
    char str2[MAX];

    FILE *file = fopen("c:\\dev\\c\\test3.txt", "wb");
    if(file == NULL){
        printf("���� ���� ����\n");
        return 1;
    }
    
    fprintf(file, "%s %d %d %d %d %d %d\n", "��÷��ȣ", 1,2,3,4,5,6);
    fprintf(file, "%s %d\n", "���ʽ���ȣ", 7);


    fclose(file);

    return 0;
}