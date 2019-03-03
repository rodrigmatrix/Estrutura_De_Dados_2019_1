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
    nodeList l = malloc(sizeof(struct list));
    l->first = NULL;
    l->last = NULL;
    return l;
}

void new_head(nodeList list, int number){
    nodeHead h = malloc(sizeof(struct head));
    h->element = number;
    if(list->first == NULL){
        h->next = h;
        h->previous = h;
        list->first = h;
        list->last = h;
    }
    else{
        h->next = list->first;
        h->previous = list->last;
        list->last->next = h;
        list->first->previous = h;
        list->last = h;
    }
}

void fill_list(nodeList list, int size){
    for(int i = 1; i <= size; i++){
        new_head(list, i);
    }
}

void print_array(nodeList list, int size){
    int i = 0;
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

void kill(nodeList list, nodeHead head){
    if(head == list->first){
        list->first = head->next;
    }
    else if(head == list->last){
        list->last= head->previous;
    }
    head->previous->next = head->next;
    head->next->previous = head->previous;
    free(head);
}

int kill_and_select(nodeList list, int selected){
    nodeHead current  = list->first;
    int select = 0;
    while(current->element != selected){
        current = current->next;
    }
    select = current->next->next->element;
    kill(list, current->next);
    return select;
}

int main(){
    int size, selected;
    scanf("%d",&size);
    scanf("%d",&selected);
    nodeList list;
    list = new_list();
    fill_list(list, size);
    printf("Selecionado: %d\n",selected);
    print_array(list, size);
    while(size != 1){
        selected = kill_and_select(list, selected);
        size--;
        printf("Selecionado: %d\n",selected);
        print_array(list, size);
    }
}

