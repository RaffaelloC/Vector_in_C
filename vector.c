#include <stdlib.h>
#include <stdio.h>

typedef int* vector;

vector create(int temp[], int length){
    vector array = malloc(sizeof(vector)*length);
    for(int i=0; i<length; i++){
        array[i] = temp[i]; 
    }
    array[length] = length;
    return array;
}

void push(vector array,int num){
    int i = 0;
    while((array[i+1] != 0)){
        i++;
    }
    array[i] = num;
    array[i+1] = i+1;
}

void delete(vector array, int n){
    int j = 0;
    while((array[j+1] != 0)){
        j++;
    }
    array[j]--;
    for(int i=(n+1); i<=j; i++){
        array[i-1] = array[i];
    }
    array[j] = 0;
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    size_t length = sizeof(array)/sizeof(array[0]);
    vector vec = create(array, length);
    for(int i=0; i<12; i++){
        printf("%d \t", vec[i]);
    }
    printf("\n");
    push(vec, 11);
    push(vec, 30);
    for(int i=0; i<13; i++){
        printf("%d \t", vec[i]);
    }
     printf("\n");
    delete(vec, 4);
    for(int i=0; i<13; i++){
        printf("%d \t", vec[i]);
    }
    return 0;
}
