#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct {
    char *name;
    int level;
    char *type;
} MON;

int collection[5] = {0,0,0,0,0};  // ����

MON mons[5];  // ��ü ����

void initMons();
void printMon(int selected);
int checkCollection();

int main(void){
    
    srand(time(NULL));
    int gamble = 0;
    initMons();

    while(1){
        printf("���ϸ� �̱�! �ƹ�Ű�� ��������!");
        getchar();
        system("cls");
        gamble++;

        int selected = rand() % 5;
        printMon(selected);
        collection[selected] += 1;

        int collectAll = checkCollection();
        printf("���ݱ��� ���� Ƚ�� : %d\n", gamble);
        if(collectAll == 1){
            break;
        }
    }
    
    return 0;
}

void initMons(){
    mons[0].name = "�̻��ؾ�";
    mons[0].level = 5;
    mons[0].type = "Ǯ";

    mons[1].name = "���̸�";
    mons[1].level = 5;
    mons[1].type = "��";

    mons[2].name = "���α�";
    mons[2].level = 5;
    mons[2].type = "��";

    mons[3].name = "��ī��";
    mons[3].level = 5;
    mons[3].type = "����";

    mons[4].name = "�̺���";
    mons[4].level = 5;
    mons[4].type = "�븻";
}

void printMon(int selected){

    printf("========�̱� ���========\n");
    printf("�̸� : %s\n", mons[selected].name);
    printf("���� : %d\n", mons[selected].level);
    printf("�Ӽ� : %s\n", mons[selected].type);
}

int checkCollection(){

    int collectAll = 1;

    printf("========���� ���========\n");
    for(int i = 0; i < 5; i++){
        if(collection[i] == 0){
            printf("%11s", "(�̼���)");
            collectAll = 0;
        }else{
            printf("%9sx%d", mons[i].name, collection[i]);
        }
    }
    printf("\n=========================\n");

    if(collectAll){
        printf("5���� ���ϸ� ���� �޼�!\n");
    }

    return collectAll;
}