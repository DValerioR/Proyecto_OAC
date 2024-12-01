#include "ripes_system.h"
#include <stdio.h>
#include <stdbool.h>

#define BLUE_COLOR 0x000000FF
#define MAX_QUEUE_SIZE 1000 // Tamaño máximo de la cola
#define SNAKE_COLOR = 0x0000ff00 // hay que usar estos para faciliatar cutomizaciones alrato o talvez ponerlos en main o algo asi
#define APPLE_COLOR = 0x00ff0000

typedef struct {
    int data[MAX_QUEUE_SIZE]; // Arreglo fijo para almacenar los elementos
    int front;                // Índice del frente de la cola
    int back;                 // Índice del final de la cola
    int size;                 // Cantidad de elementos en la cola
} Queue;

unsigned int apple_x, apple_y;

void set_pixel(unsigned int x, unsigned int y, unsigned int color);
void create_snake(unsigned int x, unsigned int y);
void move_snake(unsigned int x, unsigned int y);
unsigned int lfsr_generate(unsigned int *seed);
void Create_apple(unsigned int *seed);
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
    
    unsigned int x = 16;
    unsigned int y = 11;
    
    Queue q;
    initializeQueue(&q);

    create_snake(x,y);
    unsigned int seed = 0x56;
    Create_apple(&seed);
    while(1){
        if (*up == 1 && kup == 0){
            y -= 1;
            kup = 1;
            move_snake(x,y,&q);
        }
        else if (*down == 1 && kdp == 0){
            y += 1;
            kdp = 1;
            move_snake(x,y,&q);
        }
        else if (*left == 1 && klp == 0){
            x -= 1;
            klp = 1;
            move_snake(x,y,&q);
        }
        else if (*right == 1 && krp == 0){
            x += 1;
            krp = 1;
            move_snake(x,y,&q);
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
    // antes de pitar la casiila hay que ver si el color de esta es la de color manzazna 
    unsigned int *led_base = LED_MATRIX_0_BASE;
    unsigned int *address = 0;
    unsigned int offset = 0;
    offset = x + y*LED_MATRIX_0_WIDTH;
    address = led_base + offset;
    
    *(address) = color;
}

void create_snake(unsigned int x, unsigned int y){
    /*
    int hastouchaplle = set_pixel(x, y, 0x0000ff00); y queiro que me diga set pixel si algun pixel es manzana
    */
   x+=1;
   y+=1;
    set_pixel(x, y, 0x0000ff00);
    set_pixel(x + 1, y, 0x0000ff00);
    set_pixel(x, y + 1, 0x0000ff00);
    set_pixel(x + 1, y + 1, 0x0000ff00);
}

void delete_snake(unsigned int x, unsigned int y){
    set_pixel(x, y, 0x00000000);
    set_pixel(x + 1, y, 0x00000000);
    set_pixel(x, y + 1, 0x00000000);
    set_pixel(x + 1, y + 1, 0x00000000);
}

unsigned int lfsr_generate(unsigned int *seed) {
    // taps: 6 5; feedback polynomial: x^6 + x^5 + 1
    unsigned int bit = ((*seed >> 1) ^ (*seed >> 2)) & 1;
    *seed = (*seed >> 1) | (bit << 7); // Avanzamos el registro de desplazamiento
    return *seed;
}

void Create_apple(unsigned int *seed) {
    unsigned int max_x = 33;
    unsigned int max_y = 23;

    apple_x = lfsr_generate(seed) % (max_x + 1);
    apple_y = lfsr_generate(seed) % (max_y + 1);

    set_pixel(apple_x, apple_y, 0x00FF0000);
    set_pixel(apple_x + 1, apple_y, 0x00FF0000);
    set_pixel(apple_x, apple_y + 1, 0x00FF0000);
    set_pixel(apple_x + 1, apple_y + 1, 0x00FF0000);
}

void Delete_apple() {
    set_pixel(apple_x, apple_y, 0x00000000);
    set_pixel(apple_x + 1, apple_y, 0x00000000);
    set_pixel(apple_x, apple_y + 1, 0x00000000);
    set_pixel(apple_x + 1, apple_y + 1, 0x00000000);
}

void move_snake(unsigned int x, unsigned int y,Queue *q){
    //int grow = create_snake(x,y); quiero que create snake me diga si toco la manzana
    create_snake(x,y);
    enQueue(q,x);
    enQueue(q,y);
    if (false){
    x=deQueue(q);
    y=deQueue(q);
    delete_snake(x,y);
    }

    }

void draw_game_over() {
    // G
    int g_coords[][2] = {{3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1},
                         {8, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5},
                         {3, 6}, {3, 7}, {3, 8}, {4, 8}, {5, 8},
                         {6, 8}, {7, 8}, {8, 8}, {8, 7}, {8, 6},
                         {8, 5}, {7, 5}, {6, 5}, {5, 5}};

    // A
    int a_coords[][2] = {{10, 1}, {11, 1}, {12, 1}, {13, 1}, {14, 1},
                         {10, 2}, {10, 3}, {10, 4}, {10, 5}, {10, 6},
                         {10, 7}, {10, 8}, {11, 4}, {12, 4}, {13, 4},
                         {14, 4}, {14, 2}, {14, 3}, {14, 5}, {14, 6},
                         {14, 7}, {14, 8}};

    // M
    int m_coords[][2] = {{16, 1}, {22, 1}, {16, 2}, {16, 3}, {16, 4},
                         {16, 5}, {16, 6}, {16, 7}, {16, 8},
                         {17, 2}, {18, 3}, {19, 4}, {20, 3},
                         {21, 2}, {22, 2}, {22, 3}, {22, 4},
                         {22, 5}, {22, 6}, {22, 7}, {22, 8}};

    // E
    int e_coords[][2] = {{24, 1}, {25, 1}, {26, 1}, {27, 1}, {28, 1},
                         {24, 2}, {24, 3}, {24, 4}, {24, 5}, {24, 6},
                         {24, 7}, {24, 8}, {25, 4}, {26, 4},
                         {25, 8}, {26, 8}, {27, 8}, {28, 8}};

    // O
    int o_coords[][2] = {{1, 11}, {2, 11}, {3, 11}, {4, 11}, {5, 11},
                         {6, 11}, {7, 11}, {8, 11}, {1, 12}, {1, 13},
                         {1, 14}, {1, 15}, {1, 16}, {1, 17}, {1, 18},
                         {1, 19}, {1, 20}, {1, 21}, {1, 22}, {2, 22},
                         {3, 22}, {4, 22}, {5, 22}, {6, 22}, {7, 22},
                         {8, 22}, {8, 12}, {8, 13},
                         {8, 14}, {8, 15}, {8, 16}, {8, 17}, {8, 18},
                         {8, 19}, {8, 20}, {8, 21}, {8, 22}};

    // V
    int v_coords[][2] = {{10, 11}, {10, 12}, {10, 13}, {10, 14}, {16, 11}, 
                         {16, 12}, {16, 13}, {16, 14}, {11, 15}, {11, 16},
                         {11, 17}, {11, 18}, {11, 19}, {12, 20}, {12, 21}, 
                         {13, 22}, {15, 15}, {15, 16}, {15, 17}, {15, 18},
                         {15, 19}, {14, 20}, {14, 21},};
              
    // E
    int e2_coords[][2] = {{18, 11}, {19, 11}, {20, 11}, {21, 11}, {22, 11},
                          {23, 11}, {24, 11}, {18, 12}, {18, 13}, {18, 14}, 
                          {18, 15}, {18, 16}, {18, 17}, {18, 18}, {18, 19}, 
                          {18, 20}, {18, 21}, {18, 22}, {19, 22}, {20, 22},
                          {21, 22}, {22, 22}, {23, 22}, {24, 22}, {19, 16},
                          {20, 16}, {21, 16}};

    // R
    int r_coords[][2] = {{26, 11}, {27, 11}, {28, 11}, {29, 11}, {30, 11}, 
                         {26, 12}, {30, 12}, {26, 13}, {30, 13}, {26, 14},
                         {30, 14}, {26, 15}, {30, 15}, {26, 16}, {30, 16},
                         {26, 17}, {27, 17}, {28, 17}, {29, 17}, {26, 18},
                         {26, 19}, {26, 20}, {26, 21}, {26, 22}, {27, 18},
                         {28, 19}, {29, 20}, {30, 21}, {31, 22}};

    // Dibujar cada letra
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

void initializeQueue(Queue *q) {
    q->front = 0;
    q->back = -1;
    q->size = 0;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}

bool isFull(Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

void enQueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Error: La cola está llena\n");
        return;
    }
    q->back = (q->back + 1) % MAX_QUEUE_SIZE; // Movimiento circular
    q->data[q->back] = value;
    q->size++;
}

int deQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: La cola está vacía\n");
        return -1; // Indica error
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; // Movimiento circular
    q->size--;
    return value;
}
