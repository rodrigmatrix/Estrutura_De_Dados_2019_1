#include <iostream>
#include <cstdio>
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
    List(int size){
        this->size = size;
    }

    void new_node(int element){
        if(this->first == nullptr){
            Node * node = new Node();
            node->element = element;
            node->previous = node;
            node->next = node;
            this->first = node;
            this->last = node;
        }
        else{
            Node * node = new Node();
            node->element = element;
            node->previous = this->last;
            node->next = this->first;
            this->last->next = node;
            this->last = node;
            this->first->previous = this->last;
        }
        
    }
    
    void fill_list(int s){
        for(int i = 0; i < this->size; i++){
            new_node((i+1) * (s));
            s *= -1;
        }
    }

    void show_list(int selected){
        Node * node = this->first;
        cout << "[ ";
        do{
            if(node->element == selected){
                if(selected > 0){
                    cout << node->element << "> ";
                }
                else{
                    cout << "<" << node->element << " ";
                }
            }
            else{
                cout << node->element << " ";
            }
            node = node->next;
        }
        while(node != this->first);
        cout << "]" << endl;
    }

    int change_selected(Node * node){
        int size = node->element;
        if(node->element > 0){
            for(int i = 0; i < size; i++){
                node = node->next;
            }
            return node->element;
        }
        else{
            for(int i = 0; i < size * (-1); i++){
                node = node->previous;
            }
            return node->element;
        }
    }

    void pop_node(Node * node){
        node->previous->next = node->next;
        node->next->previous = node->previous;
        this->size--;
        free(node);
    }

    void kill(int selected){
        this->show_list(selected);
        if(this->size == 1){
            return;
        }
        Node * node = this->first;
        while(true){
            if(node->element == selected){
                break;
            }
            node = node->next;
        } // [1 -2 3 -4]
        if(node->element > 0){
            Node * node_kill = node->next;
            if(node_kill == this->first){
                this->first = node_kill->next;
            }
            if(node_kill == this->last){
                this->last = node_kill->next;
            }
            pop_node(node_kill);
            selected = change_selected(node_kill->previous);
        }
        else{
            Node * node_kill = node->previous;
            if(node_kill == this->first){
                this->first = node;
            }
            if(node_kill == this->last){
                this->last = node_kill->previous;
            }
            pop_node(node_kill);
            selected = change_selected(node_kill->next);
        }
        kill(selected);
    }
};

int main(){
    int size = 1;
    int selected = 1;
    int s = 1;
    cin >> size;
    cin >> selected;
    cin >> s;
    if((s < 0 ) && ((selected%2) != 0)){
        selected *= -1;
    }
    else if((s > 0 ) && ((selected%2) == 0)){
        selected *= -1;
    }
    List list(size);
    list.fill_list(s);
    list.kill(selected);
}