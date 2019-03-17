#include "../xpaint.h"
const int end = 10;

void tree(int x, int y, float ang, int size){
    int xf = x + size * xm_cos(ang);
    int yf = y - size * xm_sin(ang);
    if(size < end){
        xs_color((XColor){70,164,108});
        xd_thick_line(x, y, xf, yf, 5);
        return;
    }
    else if(size > end && size < 20){
        xs_color((XColor){70,164,108}); 
        xd_thick_line(x, y, xf, yf, 5);
        // xs_color((XColor){39,109,155});
        // xd_thick_line(10, 40, xf, yf, 5);
    }
    else{
        xs_color((XColor){91,44,6});
        xd_thick_line(x, y, xf, yf, 5);
    }
    //x_step("tree");
    tree(xf, yf, ang - xm_rand(27, 30), size - xm_rand(5, 15));
    tree(xf, yf, ang + xm_rand(27, 30), size - xm_rand(5, 15));
}
int main(){
    int l = 500;
    int a = 500;
    x_open(l, a);
    x_clear(BLACK);
    float ang = 90;
    int x = l/2;
    int y = a-10;
    float size = 90; 
    tree(x, y, ang, size);
    x_save("tree");
    x_close();
}