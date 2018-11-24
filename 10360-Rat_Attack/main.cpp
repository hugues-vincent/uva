#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#define WIDTH 1025

using namespace std;

typedef tuple<int, int, int> t3i;
typedef vector<t3i> vt3i;

int max(int a, int b) { return a > b ? a: b; }
int main() {
    int N, n, d, best, best_x, best_y, kill[WIDTH][WIDTH];
    vt3i rats;
    if(scanf("%d", &N)){}
    while (N--) {
        if(scanf("%d %d", &d, &n)){}
        best = best_x = best_y = 0;
        for (int i = 0; i < WIDTH; ++i)
            for (int j = 0; j < WIDTH; ++j)
                kill[i][j] = 0;
        rats.clear();
        rats.assign(n, t3i{0, 0, 0});
        for (int i = 0; i < n; ++i)
            if(scanf("%d %d %d", &get<0>(rats[i]), &get<1>(rats[i]), &get<2>(rats[i]))){}
        for (int ri = 0; ri < n; ++ri)
            for (int i = get<0>(rats[ri]) - d; i <= d + get<0>(rats[ri]); ++i)
                for (int j = get<1>(rats[ri]) - d; j <= d + get<1>(rats[ri]); ++j)
                    if (i >=0 && j >=0 && i < WIDTH && j < WIDTH && abs(get<0>(rats[ri]) - i) <= d && abs(get<1>(rats[ri]) - j) <= d)
                        kill[i][j] += get<2>(rats[ri]);
        
        for (int i = 0; i < WIDTH; ++i)
            for (int j = 0; j < WIDTH; ++j)
                if (kill[i][j] > best) {
                    best = kill[i][j];
                    best_x = i;
                    best_y = j;
                }
        printf("%d %d %d\n", best_x, best_y, best);                    
    }
    return 0;
}