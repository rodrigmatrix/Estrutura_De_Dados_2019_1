#include <iostream>
#include <list>
#include <queue>
using namespace std;

struct Customer{
    string id;
    int docs;
    int pac; 
};

struct Bank{
    vector<Customer*> caixas;
    list<Customer*> fila_entrada;
    queue<Customer*> fila_saida;
};

int main(){

}