#include <iostream>

using namespace std;
int width, height, dir, cpt[5], occurrence[102][102];
bool maze[102][102];

// 0: up ; 1: right ; 2: down; 3: left;
const int front_pos[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} },
    front_right_pos[4][2] = { {-1, 1}, {1, 1}, {1, -1}, {-1, -1} };

void initialize() {
    for (int i = 0; i < height + 2; ++i)
        for (int j = 0; j < width + 2; ++j)
            maze[i][j] = 0;
    for (int i = 0; i < height + 2; ++i)
        for (int j = 0; j < width + 2; ++j)
            occurrence[i][j] = 0;
    for (int i = 0; i < 5; ++i)
        cpt[i] = 0;
}
void read_maze() {
    char cell;
    for (int i = 0; i < height; ++i)
    {
        if(scanf("%c", &cell)) {}
        for (int j = 0; j < width; ++j)
        {
            if(scanf("%c", &cell)) {}
            maze[i+1][j+1] = cell=='1' ? false : true;
        }
    }
}
void cross_the_maze() {
    int x = height, y = 1, f_x, f_y, fr_x, fr_y;
    bool has_moved = false;
    dir = 1;
    while (!has_moved || x != height || y != 1) {
        f_x = x + front_pos[dir][0];
        f_y = y + front_pos[dir][1];
        if(maze[f_x][f_y]){
            fr_x = x + front_right_pos[dir][0];
            fr_y = y + front_right_pos[dir][1];
            x = f_x;
            y = f_y;
            occurrence[x][y]++;
            has_moved = true;
            if(maze[fr_x][fr_y]) dir = (dir + 1) % 4;
        }
        else dir = dir == 0 ? 3 : dir - 1;
    }
}
void count() {
    for (int i = 0; i < height + 2; ++i)
        for (int j = 0; j < width + 2; ++j)
            if(maze[i][j]) cpt[occurrence[i][j]]++;
}
int main() {
    while(scanf("%d %d", &height, &width) != EOF && (height != 0 || width != 0)) {
        initialize();
        read_maze();
        cross_the_maze();
        count();
        for (int i = 0; i < 5; ++i)
            printf("%3d", cpt[i]);
        printf("\n");
    }
    return 0;
}