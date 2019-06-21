#include <iostream>
using namespace std;

int main(){
    int size;
    int j = 0;
    cin >> size;
    int array[size];
    int elem = 0;
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }
    for(int i = 1; i < size; i++){
        elem = array[i];
        j = i-1;
        while (j >= 0 && array[j] > elem){  
            array[j+1] = array[j];  
            j = j-1;  
        }
        array[j+1] = elem; 
    }
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}