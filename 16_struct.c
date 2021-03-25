#include <stdio.h>

struct GameInfo {
    char *name;
    int year;
    int price;
    char *company;

    struct GameInfo *friendGame;
};

typedef struct {
    char *name;
    int year;
    int price;
    char *company;

    struct GameInfo *friendGame;
} GAME_INFO;

int main(void){

    struct GameInfo gameInfo1;
    gameInfo1.name = "game1";
    gameInfo1.year = 2021;
    gameInfo1.price = 100;
    gameInfo1.company = "company1";
    
    printf("%s\n", gameInfo1.name);

    struct GameInfo gameInfo2 = {"game2", 2021, 200, "company2"};

    struct GameInfo gamearray[2] = {
        {"game3", 2021, 300, "company3"},
        {"game4", 2021, 400, "company4"}
    };

    struct GameInfo *gamePtr;
    gamePtr = &gameInfo1;
    printf("%s\n", (*gamePtr).name);
    printf("%s\n", gamePtr->name);  // gamePtr.name으로 써도 자동완성 되네

    gameInfo1.friendGame = &gameInfo2;
    printf("%s\n", gameInfo1.friendGame->name);

    int i = 1;
    typedef int hihi;  // typedef 자료형에 별명 지정
    hihi a = 3;
    printf("%d", a);

    typedef struct GameInfo info;
    info game1;
    game1.name = "game5";

    GAME_INFO game2;
    game2.name = "game6";

    return 0;
}