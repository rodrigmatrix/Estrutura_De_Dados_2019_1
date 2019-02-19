#include <stdio.h>
#include <stdlib.h>

typedef struct head * nodeHead;
struct head {
    nodeHead previous;
    nodeHead next;
    int element;
};

typedef struct list * nodeList;
struct list {
    nodeHead first;
    nodeHead last;
};

nodeList new_list(){
    nodeList list;
    list->first = NULL;
    list->last = NULL;
    return list;
}

nodeHead new_head(int element){
    nodeHead h;
    h->element = element;
    h->next = NULL;
    return h;
}
void print_array(nodeList list, int size);
void fill_list(nodeList list, int size);
void print_array(nodeList list, int size);

int main(){
    int size,selected;
    scanf("%d",&size);
    scanf("%d",&selected);
    nodeList list;
    list = new_list();

    fill_list(list, size);
    print_array(list, size);

    
}

void fill_list(nodeList list, int size){
    int i=1;
    nodeHead current;
    current = new_head(1);
    list->first = current;
    list->last = current;
    while(size != i){
        nodeHead newHead;
        newHead = new_head(i+1);
        newHead->previous = list->last;
        list->last->next = newHead;
        list->last = newHead;
        i++;  
    }
}

void print_array(nodeList list, int size){
    int i=1;
    nodeHead current;
    current = list->first;
    printf("%s","[ ");
    while(size != i){
        printf("%d ",current->element);
        current = current->next;
        i++;
    }
    printf("%s","]\n");
}