#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int arrayAnimal[4][5];  // 동물카드 20장 중에서 일치하는 것 뒤집기
int checkAnimal[4][5];

char *strAnimal[10];

void initAnimalArray();
void initAnimalName();
void shuffleCard();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();

int main(void){

    srand(time(NULL));

    initAnimalArray();
    initAnimalName();
    
    shuffleCard();

    int failCount = 0;

    while(1){
        int select1 = 0;
        int select2 = 0;
        
        // printAnimals(); 정답
        printQuestion();
        printf("뒤집을 카드 2개 선택 : ");
        scanf("%d %d", &select1, &select2);

        system("cls");

        if(select1 == select2){
            continue;
        }

        int firstSelect_x = conv_pos_x(select1-1);
        int firstSelect_y = conv_pos_y(select1-1);

        int secondSelect_x = conv_pos_x(select2-1);
        int secondSelect_y = conv_pos_y(select2-1);

        if((checkAnimal[firstSelect_x][firstSelect_y] == 0
           && checkAnimal[secondSelect_x][secondSelect_y] == 0)
           
           &&

           arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]){
               
               printf("\n%s success!\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
               checkAnimal[firstSelect_x][firstSelect_y] = 1;
               checkAnimal[secondSelect_x][secondSelect_y] = 1;

        }else{

            printf("\nfail..\n");
            printf("%d %s", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d %s", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            failCount++;

        }

        if(foundAllAnimals() == 1){
            printf("Game Clear!!\n");
            printf("총 실수 횟수 : %d", failCount);
            break;
        }
    
    }


    return 0;
}

void initAnimalArray(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            arrayAnimal[i][j] = -1;
        }
    }
}

void initAnimalName(){
    strAnimal[0] = "쥐";
    strAnimal[1] = "소";
    strAnimal[2] = "호랑이";
    strAnimal[3] = "토끼";
    strAnimal[4] = "용";
    strAnimal[5] = "뱀";
    strAnimal[6] = "말";
    strAnimal[7] = "양";
    strAnimal[8] = "원숭이";
    strAnimal[9] = "닭";
}

void shuffleCard(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 2; j++){
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition(){  // 빈공간 찾고 0~19의 숫자를 x,y좌표로! ex) 19 -> (3,4)
    while(1){
        int randPos = rand() % 20; // 0 ~ 19
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);

        if(arrayAnimal[x][y] == -1){
            return randPos;
        }
    }
    return 0;
}

int conv_pos_x(int x){
    return x/5;
}

int conv_pos_y(int y){
    return y%5;
}

void printAnimals(){
    printf("\n=============테스트 정답============\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            printf("%8s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("====================================\n");
}

void printQuestion(){
    printf("\n\n(문제)\n");
    int seq = 1;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            if(checkAnimal[i][j] != 0){
                printf("%8s", strAnimal[arrayAnimal[i][j]]);
                seq++;
            }else{
                printf("%8d", seq++);
            }
        }
        printf("\n");
    }
}

int foundAllAnimals(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            if(checkAnimal[i][j] == 0){
                return 0;
            }
        }
    }
    return 1;
}