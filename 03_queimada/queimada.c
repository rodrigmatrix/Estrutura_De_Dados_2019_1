#include <stdio.h>
#include <stdlib.h>
const char tree = '#';
const char empty = '.';
const char burned = 'o';

void burn(){
    
}


int main(){
    int nl;
    int nc;
    int l;
    int c;

    puts("Número de linhas:");
    scanf("%d",&nl);
    puts("Número de colunas:");
    scanf("%d",&nl);
    char array[nl][nc];
    puts("Floresta:");
    for(int i = 0; i<nl; i++){
        for(int j = 0; j<nc; j++){
            scanf("%c",&array[i][j]);
        }
    }
    puts("Linha para queimar:");
    scanf("%d",&nl);
    puts("Coluna para queimar:");
    scanf("%d",&nl);


}