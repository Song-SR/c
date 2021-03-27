#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct {
    char *name;
    int level;
    char *type;
} MON;

int collection[5] = {0,0,0,0,0};  // 보유

MON mons[5];  // 전체 종류

void initMons();
void printMon(int selected);
int checkCollection();

int main(void){
    
    srand(time(NULL));
    int gamble = 0;
    initMons();

    while(1){
        printf("포켓몬 뽑기! 아무키나 누르세요!");
        getchar();
        system("cls");
        gamble++;

        int selected = rand() % 5;
        printMon(selected);
        collection[selected] += 1;

        int collectAll = checkCollection();
        printf("지금까지 뽑은 횟수 : %d\n", gamble);
        if(collectAll == 1){
            break;
        }
    }
    
    return 0;
}

void initMons(){
    mons[0].name = "이상해씨";
    mons[0].level = 5;
    mons[0].type = "풀";

    mons[1].name = "파이리";
    mons[1].level = 5;
    mons[1].type = "불";

    mons[2].name = "꼬부기";
    mons[2].level = 5;
    mons[2].type = "물";

    mons[3].name = "피카츄";
    mons[3].level = 5;
    mons[3].type = "전기";

    mons[4].name = "이브이";
    mons[4].level = 5;
    mons[4].type = "노말";
}

void printMon(int selected){

    printf("========뽑기 결과========\n");
    printf("이름 : %s\n", mons[selected].name);
    printf("레벨 : %d\n", mons[selected].level);
    printf("속성 : %s\n", mons[selected].type);
}

int checkCollection(){

    int collectAll = 1;

    printf("========보유 목록========\n");
    for(int i = 0; i < 5; i++){
        if(collection[i] == 0){
            printf("%11s", "(미수집)");
            collectAll = 0;
        }else{
            printf("%9sx%d", mons[i].name, collection[i]);
        }
    }
    printf("\n=========================\n");

    if(collectAll){
        printf("5종류 포켓몬 수집 달성!\n");
    }

    return collectAll;
}