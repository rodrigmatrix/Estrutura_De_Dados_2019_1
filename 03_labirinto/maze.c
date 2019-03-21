#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
const char wall = 'H';
const char path = '#';
typedef struct _Pos{
    int l;
    int c;
} Pos;

#define get_neibs(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}

void shuffle(Pos vet[], int size){
    for(int i = 0; i < size; i++){
        int pos = rand() % size;
        Pos aux = vet[i];
        vet[i] = vet[pos];
        vet[pos] = aux;
    }
}
void print_maze(int nl, int nc, char maze[nl][nc]){
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            if(maze[i][j] == wall){
                printf("█");
            }
            else{
                printf(" ");
            }
        }
        puts("");
    }
}

bool equals(int nl, int nc, char maze[nl][nc], int l, int c, char value){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return false;
    return maze[l][c] == value;
}

bool find_exit(int nl, int nc, char maze[nl][nc], int lexit, int cexit){
    if(!equals(nl, nc, maze, lexit, cexit, path)){
        return false;
    }
    if(maze_visited[lexit][cexit] == path){
        return false;
    }
    maze_visited[lexit][cexit] = path;
    if((nl == lexit) && (nc == cexit)){
        return true;
    }
    for(){
        
    }
}

void drill_maze(int nl, int nc, char maze[nl][nc], int l, int c){
    if(!equals(nl, nc, maze, l, c, wall)){
        return;
    }
    Pos neibs[] = get_neibs(l, c);
    shuffle(neibs, 4);
    int qtd = 0;
    for(int i = 0; i < 4; i++){
        if(equals(nl, nc, maze, neibs[i].l, neibs[i].c, wall)){
            qtd++;
        }
    }
    if(qtd < 3){
        return;
    }
    maze[l][c] = path;
    for(int i = 0; i < 4; i++){
        drill_maze(nl, nc, maze, neibs[i].l, neibs[i].c); 
    }  
}

int main(){
    srand(time(NULL));
    int nl = 8;
    int nc = 60;
    char maze[nl][nc];
    int l = 1;
    int c = 1;
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            maze[i][j] = wall;
        }
    }
    drill_maze(nl, nc, maze, l, c);
    print_maze(nl, nc, maze);
}