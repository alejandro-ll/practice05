#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_pen {
    int x;
    int y;
    int is_draw;
} t_pen;

char **new_tab(int width, int height);
void free_tab(char **tab, int height);
void iter_map(char **tab, int width, int height);
int count_neighbors(char **tab, int x, int y, int width, int height);
void print_tab(char **tab, int width, int height);

int count_neighbors(char** tab, int x, int y, int width, int height){
    int count = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j<=1; j++){
            if (i == 0 && j == 0)
                continue;

            int new_x = x + j;
            int new_y = y + i;

            if(new_x < width && new_x >= 0 && new_y >= 0 && new_y < height)
                if (tab[new_y][new_x] == 'O')
                    count++;
        }
    }
    return count;
}

void free_tab(char** tab, int height) {
    for (int i = 0; i < height; i++){
        free(tab[i]);
    }
    free(tab);
}

void print_tab(char** tab, int width, int height){
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(tab[y][x]);
        }
        putchar('\n');
    }
}

char** new_tab(int width, int height){

    char** tab = malloc(sizeof(char*) * height);

    for (int i = 0; i < height; i++) {
        tab[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++){
            tab[i][j] = ' ';
        }
    }
    return tab; 
}

void iter_map(char** tab, int width, int height) {

    char** new_tab_ptr = new_tab(width, height);

    for (int yy = 0; yy < height; yy++){
        for (int xx = 0; xx < width; xx++){
            int count = count_neighbors(tab, xx, yy, width, height);

            if (tab[yy][xx] == 'O') {
                if (count == 2 || count == 3)
                    new_tab_ptr[yy][xx] = 'O';
            } else {
                if (count == 3)
                    new_tab_ptr[yy][xx] = 'O';
            }
        }
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            tab[i][j] = new_tab_ptr[i][j];
        }
    }

    free_tab(new_tab_ptr, height);
}

int main(int argc, char *av[]) {
    if (argc != 4){
        return 1;
    }

    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int iterations = atoi(av[3]);
    
    char** tab = new_tab(width, height);
    t_pen pen = {0, 0, 0};

    char command;

    while(read(0, &command, 1) > 0) {
        switch(command){
            case 'w':
                if (pen.y > 0)
                    pen.y = pen.y - 1;
                if (pen.is_draw)
                    tab[pen.y][pen.x] = 'O';
                break;
            case 's':
                if (pen.y < height - 1)
                    pen.y = pen.y + 1;
                if (pen.is_draw)
                    tab[pen.y][pen.x] = 'O';
                break;
            case 'a':
                if (pen.x > 0)
                    pen.x = pen.x - 1;
                if (pen.is_draw)
                    tab[pen.y][pen.x] = 'O';
                break;                
            case 'd':
                if (pen.x < width - 1)
                    pen.x = pen.x + 1;
                if (pen.is_draw)
                    tab[pen.y][pen.x] = 'O';
                break;
            case 'x':
                pen.is_draw = !pen.is_draw;
                if (pen.is_draw)
                    tab[pen.y][pen.x] = 'O';
                break;

        }
    }

    for ( int i = 0; i < iterations; i++) {
        iter_map(tab, width, height);
    }

    print_tab(tab, width, height);

    free_tab(tab, height);

    return 0;
}