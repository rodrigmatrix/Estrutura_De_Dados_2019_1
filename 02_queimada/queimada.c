#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char tree = '#';
const char empty = '.';
const char burned = 'o';

void show_forest(int nl, int nc, char forest[nl][nc]){
    system("clear");
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            printf("%c", forest[i][j]);
        }
        printf("\n");
    }
}

void burn(int nl, int nc, int l, int c, char forest[nl][nc]){
    if(forest[l][c] == tree){
        forest[l][c] = burned;
    }
    else{
        return;
    }
    show_forest(nl, nc, forest);
    usleep(700000);
    burn(nl, nc, l, c-1, forest);
    burn(nl, nc, l-1, c, forest);
    burn(nl, nc, l, c+1, forest);
    burn(nl, nc, l+1, c, forest);
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
    burn(nl, nc, l, c, forest);

}