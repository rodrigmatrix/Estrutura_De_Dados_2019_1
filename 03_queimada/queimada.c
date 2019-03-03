#include <stdio.h>
#include <stdlib.h>
const char tree = '#';
const char empty = '.';
const char burned = 'o';

void burn(){
    
}

void show_forest(int nl, int nc, char forest[nl][nc]){
    system("clear");
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            printf("%c", forest[i][j]);
        }
        puts("");
    }
}

int main(){
    int nl;
    int nc;
    int l;
    int c;

    scanf("%d %d %d %d", &nl, &nc, &l, &c);
    char forest[nl][nc];
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            scanf(" %c", &forest[i][j]);
        }
    }
    show_forest(nl, nc, forest);


}