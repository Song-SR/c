#include <stdio.h>

void change(int *arr);
int main(){

    int arr[] = {1,2,3};
    for(int i = 0; i < 3; i++){
        printf("%d ", *(arr+i));
    }
    change(arr);  // == change(&(arr[0]))
    for(int i = 0; i < 3; i++){
        printf("%d ", *(arr+i));
    }
    
    return 0;
}

void change(int *arr){
    arr[2] = 50;
}