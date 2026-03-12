#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct pen {
    int x;
    int y;
    int is_draw;
} t_pen;

char **new_tab(int width, int height);
void free_tab(char **tab, int height);
void iter_map(char **tab, int width, int height);
int count_neighbors(char **tab, int x, int y, int width, int height);
void print_tab(char **tab, int width, int height);

char** new_tab(int width, int height){
    char** tab = malloc(sizeof(char*) * height);
    for(int yy = 0; yy < height; yy++){
        tab[yy] = malloc(sizeof(char) * width);
        for(int xx = 0; xx < width; xx++){
            tab[yy][xx] = ' ';
        }
    }
    return tab;
}

void free_tab(char** tab, int height){
    for(int y = 0; y < height; y++){
        free(tab[y]);
    }
    free(tab);
}

void print_tab(char** tab, int height, int width){
    for(int yy = 0; yy < height; yy++){
        for(int xx = 0; xx < width; xx++){
            putchar(tab[yy][xx]);
        }
        putchar('\n');
    }
}

int count_neighbors(char** tab, int y, int x, int width, int height){
    int count = 0;

    for (int yy = -1; yy <= 1; yy++){
        for(int xx = -1; xx <= 1; xx++){

            if(xx == 0 && yy == 0)
                continue;

            int new_y = yy + y;
            int new_x = xx + x;

            if(new_y >= 0 && new_y < height && new_x >= 0 && new_x < width){
                if(tab[new_y][new_x] == 'O')
                    count++;
            }
        }
    }
    return count;
}

void iter_map(char** tab, int width, int height){

    int count;
    char** new_tab_ptr = new_tab(width, height);
    for(int yy = 0; yy < height; yy++){
        for(int xx = 0; xx < width; xx++){
            count = count_neighbors(tab, yy, xx, width, height);

            if(tab[yy][xx] == 'O')
            {
                if(count == 2 || count == 3)
                    new_tab_ptr[yy][xx] = 'O';
            }
            else {
                if(count == 3) {
                    new_tab_ptr[yy][xx] = 'O';
                }
            }
        }
    }

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            tab[y][x] = new_tab_ptr[y][x];
        }
    }

    free_tab(new_tab_ptr, height);
}

int main(int ac, char *av[]){

    if(ac != 4){
        return 1;
    }

    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int iterations = atoi(av[3]);

    t_pen pen = {0,0,0};
    char** tab = new_tab(width, height);
    char command;

    while(read(0, &command, 1) > 0){
        switch(command){
            case 'w':
                if(pen.y > 0)
                    pen.y--;
                if(pen.is_draw)
                    tab[pen.y][pen.x] = 'O';
                break;
            case 's':
                if(pen.y < height - 1)
                    pen.y++;
                if(pen.is_draw)
                    tab[pen.y][pen.x] = 'O';
                break;
            case 'a':
                if(pen.x > 0)
                    pen.x--;
                if(pen.is_draw)
                    tab[pen.y][pen.x] = 'O';
                break;
            case 'd':
                if(pen.x < width - 1)
                    pen.x++;
                if(pen.is_draw)
                    tab[pen.y][pen.x] = 'O';
                break;
            case 'x':
                pen.is_draw = ! pen.is_draw;
                if(pen.is_draw)
                    tab[pen.y][pen.x] = 'O';
                break;
        }
    }

    for (int i = 0; i < iterations; i++) {
        iter_map(tab, width, height);
    }

    print_tab(tab, height, width);
    free_tab(tab, height);
}