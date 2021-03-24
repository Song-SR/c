#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int level;
int arrayFish[6];
int *cursur;

void initData();
void printfFishes();
void decreaseWater(long time);
int checkFishAlive();

int main(){

    long startTime = 0; // 게임 시작 시간
    long totalElapsedTime = 0;  // 총 경과시간
    long prevElapsedTime = 0;  // 직전 경과시간 (최근에 물을 준 시간 간격) <- 줄어드는 물의 양을 쉽게 계산하기 위한 목적

    int num;  // 
    initData();  // 게임데이터 초기화

    cursur = arrayFish;

    startTime = clock();  // 현재 시간을 1/1000초(millisecond) 단위로 반환
    while(1){
        printfFishes();
        printf("몇 번 어항에 물을 줄 것인지?(1~6) : ");
        scanf("%d", &num);

        if(num < 1 || num > 6){
            printf("입력 범위 초과\n");
            continue;
        }

        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;  // ms단위를 1000으로 나눈 것과 동일. 즉 초 단위로 전환
        printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

        decreaseWater(prevElapsedTime);  // 물 감소

        if(cursur[num-1] <= 0){  // 물 공급
            printf("%d 번 물고기 이미 죽음. 물 공급 x\n", num);
        }else if(cursur[num-1] < 100){
            printf("%d 번 어항에 물 공급!\n", num);
            cursur[num-1] += 1;
        }

        if(totalElapsedTime / 20 > level - 1){  // 20초에 한번씩 레벨업
            level++;
            printf(" *** Level Up! Lv.%d -> Lv.%d ***\n\n", level-1, level);

            if (level == 5){
                printf(" *** Level 5달성! 게임을 종료합니다. ***\n");
                exit(0);  // 프로그램 종료
            }
        }

        if(checkFishAlive() == 0){
            printf(" *** 모든 물고기 죽음. Gave Over *** \n");
            exit(0);
        }else{
            
        }
        prevElapsedTime = totalElapsedTime;  // 별도의 변수 추가 없이 물공급한 시간을 저장해두기



    }

    return 0;
}

void initData(){
    level = 1;  // 1~5
    for(int i = 0; i < 6; i++){
        arrayFish[i] = 100;  // 물높이 0 ~ 100
    }
}

void printfFishes(){
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1,2,3,4,5,6);  // 3칸할당+'한글1 = 2칸'+띄어쓰기1칸 = 6칸
    for(int i = 0; i < 6; i++){
        printf("  %3d ", arrayFish[i]);  // 3칸할당+띄어쓰기 3칸 = 6칸
    }
    printf("\n\n");
}

void decreaseWater(long time){
    for(int i = 0; i < 6; i++){
        arrayFish[i] -= (level * 3 * (int)time);  // 난이도 조절을 위해 3배로 값 설정
        if(arrayFish[i] < 0){
            arrayFish[i] = 0;
        }

    }
}

int checkFishAlive(){
    for(int i = 0; i < 6; i++){
        if(arrayFish[i] > 0)
            return 1;
    }
    return 0;
}