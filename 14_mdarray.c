#include <stdio.h>

int main(){

    // Multidimensional Array
    int arr[2][5];
    int arr2[2][5] = {{1,2,3,4,5},{1,2,3,4,5}};
    int arr3[2][5] = {
        {1,2,3,4,5},
        {1,2,3,4,5}
    };

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            printf("2차원 배열 (%d, %d) 의 값 : %d\n", i, j, arr3[i][j]);
        }
    }

    return 0;

}