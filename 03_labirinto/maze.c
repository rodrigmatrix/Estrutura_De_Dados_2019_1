#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const char wall = 'H';
const char path = '#';

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
    if(maze[l][c] != wall){
        return;
    }
    int qtd = 0;
    
    if(maze[l][c-1] == path){ 
        qtd++;
    }
    if(maze[l-1][c] == path){
        qtd++;
    }
    if(maze[l][c+1] == path){
        qtd++;
    }
    if(maze[l+1][c] == path){
        qtd++;
    }
    
    if(qtd > 3){
        return;
    }
    maze[l][c] = path;
    drill_maze(nl, nc, maze, l, c-1);
    drill_maze(nl, nc, maze, l-1, c);
    drill_maze(nl, nc, maze, l, c+1);
    drill_maze(nl, nc, maze, l+1, c);
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