#include <iostream>
using namespace std;
typedef struct Node{
        Node * next;
        int value;
};
typedef struct List{
    Node * first;
    List(){
        this->first = nullptr;
    }

    List * clone(List &other){
        List * newList = new List();
        Node * node = other.first;
        newList->first = node;
        do{
            if(node == nullptr){
                return newList;
            }
            newList->insert(node);
            // Método para inserir um elemento em uma lista
        }while(newList->first != node);
        return newList;
    }
};
    