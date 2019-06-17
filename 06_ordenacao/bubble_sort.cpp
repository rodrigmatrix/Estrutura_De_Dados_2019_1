#include <iostream>
using namespace std;

int main(){
    int size;
    cin >> size;
    int array[size];
    int maior = 0;
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }
    for(int i = 0; i < size; i++){
        maior = array[1];
        for(int j = 0; j < size; j++){
            if(array[i] < array[j]){
                maior = array[i];
                swap(array[i], array[j]);
            }
        }
    }
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}