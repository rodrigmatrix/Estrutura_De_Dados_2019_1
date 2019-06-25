struct Node{
    int value;
    Node* next;
};

struct List{
    Node* head;
    void remove(Node* node, int value){
        if(node == nullptr){
            return;
        }
        else if(node == head && node->value == value){
            head == nullptr;
        }
        else if(node->next->value == value){
            node->next = node->next->next;
            return;
        }
        return remove(node->next, value);
    }
};