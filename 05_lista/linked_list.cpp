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
    void kill(int selected){
        if(this->size == 1){
            return;
        }
        this->show_list(selected);
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
            node->next = node_kill->next;
            selected = node->next->element;
            this->size--;
            free(node_kill);
        }
        else{
            Node * node_kill = node->previous;
            if(node_kill == this->first){
                this->first = node_kill->next;
            }
            if(node_kill == this->last){
                this->last = node_kill->previous;
            }
            node->previous = node_kill->previous;
            selected = node->previous->element;
            this->size--;
            free(node_kill);
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
    List list(size);
    list.fill_list(s);
    list.kill(selected);
}