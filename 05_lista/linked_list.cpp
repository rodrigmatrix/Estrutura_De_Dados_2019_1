#include <iostream>
using namespace std;

struct Node{
    int element;
    Node * next;
    Node * previous;
};

struct List{
    Node * first;
    Node * last;
    int size;
    List(int size = 2){
        this->size = size;
        fill_list();
    }

    void new_node(int element){
        if(this->first == nullptr){
            Node * node = new Node();
            node->previous = node;
            node->next = node;
            this->first = node;
            this->last = node;
        }
        else{
            Node * node = new Node();
            node->previous = this->last;
            node->next = this->first;
            this->last = node;
        }
        
    }
    void fill_list(){
        for(int i = 0; i < this->size; i++){
            new_node(i+1);
        }
    }
    void show_list(){
        Node * node = this->first->next; 
        cout << "[ ";
        while(node != this->first){
            cout << node->element;
            node = node->next;
        }
        cout << "]";
    }
    

};

int main(){
    List list(10);
    list.show_list();
}