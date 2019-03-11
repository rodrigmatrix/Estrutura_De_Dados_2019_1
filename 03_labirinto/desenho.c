#include "../xpaint/xpaint.h"

int linha(int x, int y, float ang, int size){
    int xf = x + size * xm_cos(ang);
    int yf = y - size * xm_sin(ang);
   // xd_thick_line(x, y, ang, 4);
}

int main(){
    int largura = 600, altura = 500;
    /* cria um bitmap de 600x600 */
    x_open(largura, altura);
    xd_thick_line(50, 50, 200, 200, 3);
    x_save("embua");
    /* libera os recursos alocados */
    x_close();
    return 0;
}