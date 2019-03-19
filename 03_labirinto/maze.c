#include <stdio.h>
#include <stdlib.h>

const char wall = 'H';
const char path = '#';

void print_maze(char maze[15][15]){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
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
    maze[l][c] = path;
    int qtd = 0;
    for(int i = 0; i < 4; i++){
        if(maze[l][c] == path){
            qtd++;
        }
    }
    if(qtd < 3){
        return;
    }
    drill_maze(nl, nc, maze, l, c-1); 
    drill_maze(nl, nc, maze, l-1, c); 
    drill_maze(nl, nc, maze, l, c+1); 
    drill_maze(nl, nc, maze, l+1, c); 
         
}

int main(){
    char maze[15][15];
    int l;
    int c;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            maze[i][j] = wall;
        }
    }
    drill_maze(15, 15, maze, 1, 1);
    print_maze(maze);
}