#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
const char wall = 'H';
const char path = '#';
const char point = '.';
const char target = 'x';
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
            else if(maze[i][j] == point){
                printf(".");
            }
            else if(maze[i][j] == target){
                printf("x");
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

bool find_exit(int nl, int nc, char maze[nl][nc], bool maze_visited[nl][nc], int l, int c, int lexit, int cexit){
    if(maze[l][c] != path){
        return false;
    }
    if(maze_visited[l][c]){
        return false;
    }
    maze_visited[l][c] = true;
    maze[l][c] = point;
    if((l == lexit) && (c == cexit)){
        return true;
    }
    Pos neibs[] = get_neibs(l, c);
    shuffle(neibs, 4);
    bool find = false;
    for(int i = 0; i < 4; i++){
        find = find_exit(nl, nc, maze, maze_visited,  neibs[i].l, neibs[i].c, lexit, cexit);
        if(find){
            break;
        }
    }
    if(find){
        return true;
    }
    else{
        maze[l][c] = path;
        return false;
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
    int nl = 10;
    int nc = 30;
    char maze[nl][nc];
    int l = 1;
    int c = 1;
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            maze[i][j] = wall;
        }
    }
    bool maze_visited[nl][nc];
    drill_maze(nl, nc, maze, l, c);
    print_maze(nl, nc, maze);
    find_exit(nl, nc, maze, maze_visited, 1, 1, 8, 1);
    maze[1][1] = target;
    maze[8][1] = target;
    print_maze(nl, nc, maze);
}