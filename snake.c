#include "ripes_system.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//constantes 
#define MAX_QUEUE_SIZE 1000
#define SNAKE_COLOR 0x0000FF00
#define APPLE_COLOR 0x00FF0000
#define BLUE_COLOR 0x000000FF

typedef struct {
    int data[MAX_QUEUE_SIZE]; // Arreglo fijo para almacenar los elementos
    int front;                // Índice del frente de la cola
    int back;                 // Índice del final de la cola
    int size;                 // Cantidad de elementos en la cola
} Queue;

unsigned int apple_x, apple_y;

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
<<<<<<< HEAD
        printf("Error: La cola está llena\n");
=======
        printf("Error: La cola estÃ¡ llena\n");
>>>>>>> 577800186bf575cce059538bc220909662adea8d
        return;
    }
    q->back = (q->back + 1) % MAX_QUEUE_SIZE; // Movimiento circular
    q->data[q->back] = value;
    q->size++;
}

int deQueue(Queue *q) {
    if (isEmpty(q)) {
<<<<<<< HEAD
        printf("Error: La cola está vacía\n");
=======
        printf("Error: La cola estÃ¡ vacÃ­a\n");
>>>>>>> 577800186bf575cce059538bc220909662adea8d
        return -1; // Indica error
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE; // Movimiento circular
    q->size--;
    return value;
}

int set_pixel(unsigned int x, unsigned int y, unsigned int color) {
    unsigned int *led_base = LED_MATRIX_0_BASE;
    unsigned int offset = x + y * LED_MATRIX_0_WIDTH;
    unsigned int *address = led_base + offset;
    *address = color;
}

void apple_create(unsigned int seed) {
<<<<<<< HEAD
    unsigned int max_x = 34;  // El rango debe ser múltiplo de 2 para mantener pares
    unsigned int max_y = 24;  // Ajuste para mantener dentro del rango válido
=======
    unsigned int max_x = 34;  // El rango debe ser mÃºltiplo de 2 para mantener pares
    unsigned int max_y = 24;  // Ajuste para mantener dentro del rango vÃ¡lido
>>>>>>> 577800186bf575cce059538bc220909662adea8d
    unsigned int apple_x, apple_y;
    unsigned int *led_base = LED_MATRIX_0_BASE;
    unsigned int offset;
    unsigned int *address;

    srand(seed);  // Inicializa la semilla de rand()

<<<<<<< HEAD
    // Generar una nueva posición para la manzana
=======
    // Generar una nueva posiciÃ³n para la manzana
>>>>>>> 577800186bf575cce059538bc220909662adea8d
    do {
        apple_x = (rand() % ((max_x / 2) + 1)) * 2;  // Genera posiciones pares para apple_x
        apple_y = (rand() % ((max_y / 2) + 1)) * 2;  // Genera posiciones pares para apple_y

<<<<<<< HEAD
        // Calcular la dirección de memoria correspondiente a la posición
=======
        // Calcular la direcciÃ³n de memoria correspondiente a la posiciÃ³n
>>>>>>> 577800186bf575cce059538bc220909662adea8d
        offset = apple_x + apple_y * LED_MATRIX_0_WIDTH;
        address = led_base + offset;
    } while (*address == SNAKE_COLOR);  // Evitar que la manzana aparezca sobre la serpiente

<<<<<<< HEAD
    // Poner la manzana en la nueva posición
=======
    // Poner la manzana en la nueva posiciÃ³n
>>>>>>> 577800186bf575cce059538bc220909662adea8d
    set_pixel(apple_x, apple_y, APPLE_COLOR);
    set_pixel(apple_x + 1, apple_y, APPLE_COLOR);
    set_pixel(apple_x, apple_y + 1, APPLE_COLOR);
    set_pixel(apple_x + 1, apple_y + 1, APPLE_COLOR);
}

<<<<<<< HEAD
// Función para eliminar una parte de la serpiente
=======
// FunciÃ³n para eliminar una parte de la serpiente
>>>>>>> 577800186bf575cce059538bc220909662adea8d
void apple_delete(unsigned int x, unsigned int y) {
    // Borra la parte de la serpiente
    set_pixel(x, y, 0x00000000);
    set_pixel(x + 1, y, 0x00000000);
    set_pixel(x, y + 1, 0x00000000);
    set_pixel(x + 1, y + 1, 0x00000000);

<<<<<<< HEAD
    // Crear una nueva manzana en una nueva posición
=======
    // Crear una nueva manzana en una nueva posiciÃ³n
>>>>>>> 577800186bf575cce059538bc220909662adea8d
    apple_create(rand());  // Usa rand() para generar la semilla
}

int snake_create(unsigned int x, unsigned int y) {
    set_pixel(x, y, SNAKE_COLOR);
    set_pixel(x + 1, y, SNAKE_COLOR);
    set_pixel(x, y + 1, SNAKE_COLOR);
    set_pixel(x + 1, y + 1, SNAKE_COLOR);
}

void snake_delete(unsigned int x, unsigned int y) {
    set_pixel(x, y, 0x00000000);
    set_pixel(x + 1, y, 0x00000000);
    set_pixel(x, y + 1, 0x00000000);
    set_pixel(x + 1, y + 1, 0x00000000);
}

void snake_move(unsigned int x, unsigned int y, Queue *q) {
    int grow = 1;
    int colition = 0;
    unsigned int *led_base = LED_MATRIX_0_BASE;
    unsigned int offset = x + y * LED_MATRIX_0_WIDTH;
    unsigned int *address = led_base + offset;
     if (*address == APPLE_COLOR){
             grow = 0;
           apple_delete(x,y);
         }
     if (*address == SNAKE_COLOR){
              draw_game_over();exit(0);
         }
    snake_create(x, y);
    enQueue(q, x);
    enQueue(q, y);
    if (grow)
    {
    unsigned int old_x = deQueue(q);
    unsigned int old_y = deQueue(q);
    snake_delete(old_x, old_y);
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


void main() {
    unsigned int *up = (unsigned int *)D_PAD_0_UP;
    unsigned int *down = (unsigned int *)D_PAD_0_DOWN;
    unsigned int *left = (unsigned int *)D_PAD_0_LEFT;
    unsigned int *right = (unsigned int *)D_PAD_0_RIGHT;

    unsigned int kup = 0, kdp = 0, klp = 0, krp = 0;

    unsigned int x = 16, y = 12;
    Queue q;
    initializeQueue(&q);
<<<<<<< HEAD
    enQueue(&q, x - 2);
    enQueue(&q, y);
    enQueue(&q, x);
    enQueue(&q, y);
    snake_create(x - 2, y);
=======
    enQueue(&q, x-2);
    enQueue(&q, y);
    enQueue(&q, x);
    enQueue(&q, y);
    snake_create(x-2, y);
>>>>>>> 577800186bf575cce059538bc220909662adea8d
    snake_create(x, y);

    unsigned int seed = 0x48;
    apple_create(seed);

<<<<<<< HEAD
    // Configurar dirección inicial (derecha)
    krp = 1;

    while (1) {
        // Detectar entrada del jugador para cambiar dirección
        if (*up && !kup && kdp == 0) {
            kup = 1;
            kdp = klp = krp = 0;
        } else if (*down && !kdp && kup == 0) {
            kdp = 1;
            kup = klp = krp = 0;
        } else if (*left && !klp && krp == 0) {
            klp = 1;
            kup = kdp = krp = 0;
        } else if (*right && !krp && klp == 0) {
            krp = 1;
            kup = kdp = klp = 0;
        }

        // Mover la serpiente automáticamente según la dirección
        if (kup) {
            if (y == 0) {
                draw_game_over();
                exit(0);
            }
            y -= 2;
        } else if (kdp) {
            if (y > 24) {
                draw_game_over();
                exit(0);
            }
            y += 2;
        } else if (klp) {
            if (x == 0) {
                draw_game_over();
                exit(0);
            }
            x -= 2;
        } else if (krp) {
            if (x > 34) {
                draw_game_over();
                exit(0);
            }
            x += 2;
        }

        // Mover la serpiente y manejar colisiones
        snake_move(x, y, &q);

        // Introducir un retraso para controlar la velocidad de movimiento
        for (volatile int delay = 0; delay < 5000; delay++);
=======
    while (1) {
        int moved = 0;

        // Detectar entrada del jugador
        if (*up && !kup) {
         kup = 1;
         if(y==0){
            draw_game_over();exit(0);}
         y=y-2;
         snake_move(x, y, &q);
        }if (*down && !kdp) {
           kdp = 1; 
           y=y+2;
           if(y>24){
            draw_game_over();
            exit(0);}
           snake_move(x, y, &q);
        }if (*left && !klp) {
            klp = 1;
            if(x==0){
            draw_game_over();
            exit(0);}
            x=x-2;
            snake_move(x, y, &q);
        }if (*right && !krp) {
            krp = 1;
            x=x+2;
            if(x>34){
            draw_game_over();
            exit(0);}
            snake_move(x, y, &q);
        }
        // Resetear los estados de los botones
       if (*up == 0) kup = 0;
        if (*down == 0) kdp = 0;
        if (*left == 0) klp = 0;
        if (*right == 0) krp = 0;
>>>>>>> 577800186bf575cce059538bc220909662adea8d
    }
}
