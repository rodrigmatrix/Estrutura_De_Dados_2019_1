#include <stdio.h>
#include <stdlib.h>
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
            if(maze[i][j] == path){
                printf("█");
            }
            else{
                printf("%c", maze[i][j]);
            }
        }
        puts("");
    }
}

void drill_maze(int nl, int nc, char maze[nl][nc], int l, int c){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc)){
        return;
    }
    if(maze[l][c] == path){
        return;
    }
    Pos neibs[] = get_neibs(l, c);
    int qtd = 0;
    int line;
    int col;
    for(int i = 0; i < 4; i++){
        line = neibs[i].l;
        col = neibs[i].c;
        if(maze[line][col] == path){
            qtd++;
        }
    }
    if(qtd > 3){
        return;
    }
    maze[l][c] = path;
    shuffle(neibs, 4);
    for(int i = 0; i < 4; i++)
        drill_maze(nl, nc, maze, neibs[i].l, neibs[i].c);  
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