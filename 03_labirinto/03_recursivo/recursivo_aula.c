#include <stdio.h>
#include <stdlib.h>

void show(int array, int size){
    if(size == 0){
        return;
    }
    printf("%d ", array[0]);
    return show(array + 1, size-1);

}

void inverter(int array[], int size){
    if(size < 2){
        return;
    }

}

int main(){
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array)/sizeof(int);
    show(array, size);
}