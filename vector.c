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

vector push(vector array,int num){
    int i = 0;
    while((array[i+1] != 0)){
        i++;
    }
    array[i] = num;
    array[i+1] = i+1;
    return array;
}

vector delete(vector array, int n){
    int j = 0;
    vector temp = malloc(sizeof(array));
    for(int i=0; i<n; i++){
        temp[i] = array[i];
    }

    while((array[j+1] != 0)){
        j++;
    }
    array[j]--;
    for(int i=(n+1); i<=j; i++){
        temp[i-1] = array[i];
    }
    return temp;
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    char fra = 'a';
    size_t length = sizeof(array)/sizeof(array[0]);
    vector vec = create(array, length);
    for(int i=0; i<12; i++){
        printf("%d \t", vec[i]);
    }
    printf("\n");
    vec = push(vec, 11);
    vec = push(vec, 30);
    for(int i=0; i<13; i++){
        printf("%d \t", vec[i]);
    }
     printf("\n");
    vec = delete(vec, 4);
    for(int i=0; i<13; i++){
        printf("%d \t", vec[i]);
    }
    return 0;
}