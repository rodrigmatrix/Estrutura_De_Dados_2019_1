#include <stdio.h>

void fill_maze(char maze[15][15]){

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
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if((i == 0 || j == 0) || (i == 14 || j == 14)){
                maze[i][j] = 'D';
            }
            else{
                maze[i][j] = '#';
            }
        }
    }
    print_maze(maze);
}