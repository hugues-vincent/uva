// How to place 8 queen on a chess board where none of them can attack each other 
// One queen position is given
#include <iostream>
#include <cmath>

using namespace std;

int N, a, b, cpt, row[] = {0, 1, 2, 3, 4, 5, 6, 7};

bool is_position_correct(int s, int r) {
    for (int i = 0; i < s; ++i)
        if((row[i] == r )|| (abs(row[i] - r) ==  abs(i - s)))
            return false;
    return true;
}
void backtrack(int s) {
    if (s == 8 && row[a] == b) { 
        printf("%2d     ", ++cpt);
        for (int i = 0; i < 8; ++i) printf(" %d", row[i] + 1);
        printf("\n");
    }
    for (int r = 0; r < 8; ++r)
    {
        if (is_position_correct(s, r)) {
            row[s] = r;
            backtrack(s + 1);
        }
    }
}
int main() {
    if(scanf("%d", &N)){}
    while (N--) {
        if(scanf("%d %d", &b, &a)){} a--; b--; 
        cpt = 0;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if(N) printf("\n");
    }
    return 0;
}