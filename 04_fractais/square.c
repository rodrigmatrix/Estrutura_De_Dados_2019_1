#include "../xpaint.h"
const int end = 10;

void square(int x, int y, int size){
    xs_color((XColor){xm_rand(0,255),xm_rand(0,255),xm_rand(0,255)});
    if(size < end){
        return;
    }
    else{
        xd_filled_rect(x, y, x, y);
    }
    square(x , y, size/2);
    square(x, y, size/2);
}
int main(){
    int l = 500;
    int a = 500;
    x_open(l, a);
    x_clear(BLACK);
    float ang = 200;
    int x = l/2;
    int y = a/2;
    float size = 180;
    circle(x, y, size);
    x_save("square");
    x_close();
}