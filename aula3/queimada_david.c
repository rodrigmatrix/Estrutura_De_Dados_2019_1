#include <stdio.h>
#include <stdlib.h> //srand, rand
#include <time.h> // time()

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.';

//left, up, right, down
int deltaL[] = {0, -1, 0, 1};
int deltaC[] = {-1, 0, 1, 0};
int lados = sizeof(deltaL)/sizeof(int); 
//int delta[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            printf("%c", mat[l][c]);
        }
        puts("");
    }
}

int tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return 0;
    if(mat[l][c] != TREE)
        return 0;
    mat[l][c] = FIRE;
    int cont = 1;
    for(int i = 0; i <lados; i++){
        cont += tocar_fogo(nl, nc ,mat, l+  deltaL[i], c + deltaC[i]);
    }
    
    return cont;
}

int main(){
    srand(time(NULL));
    int nl = 0;
    int nc = 0;
    puts("Digite dimensoes da matriz");
    scanf("%d %d", &nl, &nc);
    puts("Digite a porcentagem de arvores 0-100");
    int porc_tree = 0;
    scanf("%d", &porc_tree);
    char mat[nl][nc];
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(rand() % 101 <= porc_tree)
                mat[l][c] = TREE;
            else
                mat[l][c] = EMPTY;
        }
    }
    show(nl, nc, mat);
    puts("Onde queres incendiar?");
    int l = 0;
    int c = 0;
    scanf("%d %d", &l, &c);
    
    
    int total = tocar_fogo(nl, nc, mat, l, c);
    show(nl, nc, mat);
    printf("total do estrago: %d\n", total);
}
