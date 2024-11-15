#include "ripes_system.h"

#define BLUE_COLOR 0xFFFFFF

void set_pixel(unsigned int x, unsigned int y, unsigned int color);
void create_snake(unsigned int x, unsigned int y);
void move_snake(unsigned int x, unsigned int y);
void draw_game_over();

void main(){
    unsigned int *up = D_PAD_0_UP;
    unsigned int *down = D_PAD_0_DOWN;
    unsigned int *left = D_PAD_0_LEFT;
    unsigned int *right = D_PAD_0_RIGHT;
    
    
    unsigned int kup = 0;
    unsigned int kdp = 0;
    unsigned int klp = 0;
    unsigned int krp = 0;
    
    unsigned int x = 17;
    unsigned int y = 12;
    
    create_snake(x,y);
    draw_game_over();
    while(1){
        if (*up == 1 && kup == 0){
            y -= 1;
            kup = 1;
            move_snake(x,y);
        }
        else if (*down == 1 && kdp == 0){
            y += 1;
            kdp = 1;
            move_snake(x,y);
        }
        else if (*left == 1 && klp == 0){
            x -= 1;
            klp = 1;
            move_snake(x,y);
        }
        else if (*right == 1 && krp == 0){
            x += 1;
            krp = 1;
            move_snake(x,y);
        }
        
        if (*up == 0){
            kup = 0;
        }
        if (*down == 0){
            kdp = 0;
        }
        if (*left == 0){
            klp = 0;
        }
        if (*right == 0){
            krp = 0;
        }
    }
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

void move_snake(unsigned int x, unsigned int y){
    create_snake(x,y);
    }
void draw_game_over() {
    // Coordenadas ajustadas para cada letra en "Game over"

    // G
    int g_coords[][2] = {{7,9}, {8,9}, {9,9}, {10,9}, {11,9},
                         {7,10}, {7,11}, {7,12}, {7,13}, {7,14},
                         {8,14}, {9,14}, {10,14}, {10,13}, {10,12}};
    
    // A
    int a_coords[][2] = {{13,9}, {14,9}, {15,9}, {16,9}, {17,9},
                         {13,10}, {13,11}, {13,12}, {13,13}, {13,14},
                         {15,11}, {15,12}, {15,13},
                         {17,10}, {17,11}, {17,12}, {17,13}, {17,14}};
    
    // M
    int m_coords[][2] = {{19,9}, {20,9}, {21,9}, {22,9}, {23,9},
                         {19,10}, {19,11}, {21,11}, {23,10}, {23,11},
                         {19,12}, {19,13}, {19,14}, {20,13}, {21,14}, {22,13}, {23,12}};
    
    // E
    int e_coords[][2] = {{25,9}, {26,9}, {27,9}, {28,9}, {29,9},
                         {25,10}, {25,11}, {25,12}, {25,13}, {25,14},
                         {26,12}, {27,12}, {28,12}};

    // O
    int o_coords[][2] = {{7,17}, {8,17}, {9,17}, {10,17}, {11,17},
                         {7,18}, {7,19}, {7,20}, {7,21}, {7,22},
                         {8,22}, {9,22}, {10,22}, {11,22}};

    // V
    int v_coords[][2] = {{13,17}, {14,17}, {15,17}, {16,17}, {17,17},
                         {13,18}, {13,19}, {13,20}, {15,20}, {17,18},
                         {17,19}, {17,20}, {17,21}, {17,22}};
    
    // E
    int e2_coords[][2] = {{19,17}, {20,17}, {21,17}, {22,17}, {23,17},
                          {19,18}, {19,19}, {19,20}, {19,21}, {19,22},
                          {20,20}, {21,20}, {22,20}};

    // R
    int r_coords[][2] = {{25,17}, {26,17}, {27,17}, {28,17}, {29,17},
                         {25,18}, {25,19}, {25,20}, {25,21}, {25,22},
                         {26,20}, {27,21}, {29,20}};

    // Dibujar cada letra usando set_pixel
    int i;
    for (i = 0; i < sizeof(g_coords) / (2 * sizeof(int)); i++) {
        set_pixel(g_coords[i][0], g_coords[i][1], BLUE_COLOR);
    }
    for (i = 0; i < sizeof(a_coords) / (2 * sizeof(int)); i++) {
        set_pixel(a_coords[i][0], a_coords[i][1], BLUE_COLOR);
    }
    for (i = 0; i < sizeof(m_coords) / (2 * sizeof(int)); i++) {
        set_pixel(m_coords[i][0], m_coords[i][1], BLUE_COLOR);
    }
    for (i = 0; i < sizeof(e_coords) / (2 * sizeof(int)); i++) {
        set_pixel(e_coords[i][0], e_coords[i][1], BLUE_COLOR);
    }
    for (i = 0; i < sizeof(o_coords) / (2 * sizeof(int)); i++) {
        set_pixel(o_coords[i][0], o_coords[i][1], BLUE_COLOR);
    }
    for (i = 0; i < sizeof(v_coords) / (2 * sizeof(int)); i++) {
        set_pixel(v_coords[i][0], v_coords[i][1], BLUE_COLOR);
    }
    for (i = 0; i < sizeof(e2_coords) / (2 * sizeof(int)); i++) {
        set_pixel(e2_coords[i][0], e2_coords[i][1], BLUE_COLOR);
    }
    for (i = 0; i < sizeof(r_coords) / (2 * sizeof(int)); i++) {
        set_pixel(r_coords[i][0], r_coords[i][1], BLUE_COLOR);
    }
}