#include <iostream>
using namespace std;

int main(){
    int size;
    cin >> size;
    int array[size];
    int menor = 0;
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }
    for(int i = 0; i < size - 1; i++){
        menor = i;
        for(int j = i + 1; j < size; j++){
            if(array[j] < array[menor]){
               menor = j;
            }
        }
        swap(array[menor], array[i]);
    }
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}