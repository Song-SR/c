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

    long startTime = 0; // ���� ���� �ð�
    long totalElapsedTime = 0;  // �� ����ð�
    long prevElapsedTime = 0;  // ���� ����ð� (�ֱٿ� ���� �� �ð� ����) <- �پ��� ���� ���� ���� ����ϱ� ���� ����

    int num;  // 
    initData();  // ���ӵ����� �ʱ�ȭ

    cursur = arrayFish;

    startTime = clock();  // ���� �ð��� 1/1000��(millisecond) ������ ��ȯ
    while(1){
        printfFishes();
        printf("�� �� ���׿� ���� �� ������?(1~6) : ");
        scanf("%d", &num);

        if(num < 1 || num > 6){
            printf("�Է� ���� �ʰ�\n");
            continue;
        }

        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;  // ms������ 1000���� ���� �Ͱ� ����. �� �� ������ ��ȯ
        printf("�� ��� �ð� : %ld ��\n", totalElapsedTime);

        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("�ֱ� ��� �ð� : %ld ��\n", prevElapsedTime);

        decreaseWater(prevElapsedTime);  // �� ����

        if(cursur[num-1] <= 0){  // �� ����
            printf("%d �� ����� �̹� ����. �� ���� x\n", num);
        }else if(cursur[num-1] < 100){
            printf("%d �� ���׿� �� ����!\n", num);
            cursur[num-1] += 1;
        }

        if(totalElapsedTime / 20 > level - 1){  // 20�ʿ� �ѹ��� ������
            level++;
            printf(" *** Level Up! Lv.%d -> Lv.%d ***\n\n", level-1, level);

            if (level == 5){
                printf(" *** Level 5�޼�! ������ �����մϴ�. ***\n");
                exit(0);  // ���α׷� ����
            }
        }

        if(checkFishAlive() == 0){
            printf(" *** ��� ����� ����. Gave Over *** \n");
            exit(0);
        }else{
            
        }
        prevElapsedTime = totalElapsedTime;  // ������ ���� �߰� ���� �������� �ð��� �����صα�



    }

    return 0;
}

void initData(){
    level = 1;  // 1~5
    for(int i = 0; i < 6; i++){
        arrayFish[i] = 100;  // ������ 0 ~ 100
    }
}

void printfFishes(){
    printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1,2,3,4,5,6);  // 3ĭ�Ҵ�+'�ѱ�1 = 2ĭ'+����1ĭ = 6ĭ
    for(int i = 0; i < 6; i++){
        printf("  %3d ", arrayFish[i]);  // 3ĭ�Ҵ�+���� 3ĭ = 6ĭ
    }
    printf("\n\n");
}

void decreaseWater(long time){
    for(int i = 0; i < 6; i++){
        arrayFish[i] -= (level * 3 * (int)time);  // ���̵� ������ ���� 3��� �� ����
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