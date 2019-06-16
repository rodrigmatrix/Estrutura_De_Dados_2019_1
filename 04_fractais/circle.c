#include "../xpaint.h"
const int end = 1;

void circle(int x, int y, int size){
    xs_color((XColor){xm_rand(20,50),xm_rand(0,200),xm_rand(0,255)});
    if(size < end){
        return;
    }
    float ang = 145;
    for(int i = 0; i < 6; i++){
        int xf = x + size * xm_cos(ang);
        int yf = y - size * xm_sin(ang);
        xd_circle(xf, yf, size/3);
        circle(xf , yf, size/3);
        ang += (360/6);
    }
}
int main(){
    int l = 500;
    int a = 500;
    x_open(l, a);
    x_clear(BLACK);
    int x = l/2;
    int y = a/2;
    float size = 180;
    xd_circle(x, y, size);
    circle(x, y, size);
    x_save("circle");
    x_close();
}