#include <stdio.h>
#include <stdlib.h>

const char wall = 'H';
const char path = '#';

void fill_maze(char maze[15][15], int l, int c){
    if(l > 15 || c > 15){
        return;
    }
    else if(maze[l][c] == wall){
        return;
    }
    
}

void print_maze(char maze[15][15]){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            printf("%c", maze[i][j]);
        }
        puts("");
    }
}
int main(){
    char maze[15][15];
    int l;
    int c;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if((i == 0 || j == 0) || (i == 14 || j == 14)){
                maze[i][j] = wall;
            }
            else{
                maze[i][j] = path;
            }
        }
    }
    print_maze(maze);
}