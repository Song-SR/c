#include <stdio.h>

#define MAX 10000

int main(void){
    char line[MAX];
    FILE *file = fopen("c:\\dev\\c\\test1.txt", "rb");
    if(file == NULL){
        printf("���� ���� ����\n");
        return 1;
    }

    while(fgets(line, MAX, file) != NULL){
        printf("%s", line);
    }


    fclose(file);

    return 0;
}