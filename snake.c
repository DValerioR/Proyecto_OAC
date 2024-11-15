#include "ripes_system.h"

void set_pixel(unsigned int x, unsigned int y, unsigned int color);
void create_snake(unsigned int x, unsigned int y);

void main(){
    unsigned int x = 17;
    unsigned int y = 12;
    
    create_snake(x,y);
    create_snake(x + 5, y + 5);
    while(1);
    }
    
void set_pixel(unsigned int x, unsigned int y, unsigned int color){
    unsigned int *led_base = LED_MATRIX_0_BASE;
    unsigned int *address = 0;
    unsigned int offset = 0;
    offset = x + y*LED_MATRIX_0_WIDTH;
    address = led_base + offset;
    *(address) = color;
}

void create_snake(unsigned int x, unsigned int y){
    set_pixel(x, y, 0x0000ff00);
    set_pixel(x + 1, y, 0x0000ff00);
    set_pixel(x, y + 1, 0x0000ff00);
    set_pixel(x + 1, y + 1, 0x0000ff00);
}