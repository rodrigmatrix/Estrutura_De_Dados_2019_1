#include <map> //tree
#include <set> //tree
#include <unordered_map>
#include <unordered_set> //hash
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

pair<bool, int> binary_search(vector<int>& vet, int value, int menor, int maior){
    int meio = menor + (maior - menor)/2;
    if (maior < menor){
        auto pair = make_pair(false, 0);
        return pair;
    }
    if (value < vet[meio]){
        return binary_search(vet, menor, meio-1, value);
    }
    else if (value > vet[meio]){
        return binary_search(vet, meio+1, maior, value);
    }
    else{
        auto pair = make_pair(true, meio);
        return pair; 
    }
}

int main(){
    vector<int> data;
    bool sorted = false;
    int sucessos = 0;
    char op;
    while(cin >> op){
        int value;
        cin >> value;
        auto pair_return = binary_search(data, value, 0, data.size());
        if(op == 'i'){
            if(!pair_return.first){
                data.push_back(value);
                sorted = false;
                sucessos++;
            }
        }
        if(op == 's'){
            if(!sorted){
                std::sort(data.begin(), data.end());
                sorted = true;
            }
            if(pair_return.first)
                sucessos++;
        }
        if(op == 'r'){
            auto it = std::find(data.begin(), data.end(), value);
            if(data[pair_return.second] != data.end()){
                data.erase(it);
                sucessos++;
            }
        }
    }
    cout << sucessos << endl;
}