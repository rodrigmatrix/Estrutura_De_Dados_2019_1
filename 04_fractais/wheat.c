#include "../xpaint.h"
const int end = 1;

void wheat(int x, int y, float ang, int size){
    if(size < end){
        return;
    }
    for(int i = 0; i < 4; i++){
        int xf = x + size * xm_cos(ang)/3;
        int yf = y - size * xm_sin(ang)/3;
        xd_thick_line(x, y, xf, yf, 1);
        wheat(xf, yf, ang - xm_rand(20, 40), size/3);
        wheat(xf, yf, ang + xm_rand(20, 40), size/3);
        x = xf;
        y = yf;
    }
}
int main(){
    int l = 500;
    int a = 500;
    x_open(l, a);
    x_clear(BLACK);
    float ang = 90;
    int x = l/2;
    int y = a-10;
    float size = 200;
    xs_color((XColor){224,109,16});
    wheat(x, y, ang, size);
    x_save("wheat");
    x_close();
}