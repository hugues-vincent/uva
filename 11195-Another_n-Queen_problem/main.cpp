// How to place 8 queen on a n*n chess board where none of them can attack each other 
// One queen position is given
// Some squares are blocked
#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

char cell;
int n, a, b, cpt;
bool board[15][15];
bitset<30> rw, ld, rd;

void backtrack(int c) {
    if (c == n) {++cpt; return; } 
    for (int r = 0; r < n; ++r)
    {
        if (board[r][c] && !rw[r] && !ld[r - c + n -1] && !rd[r + c]){
            ld[r - c + n -1] = rd[r + c] = rw[r] = true;
            backtrack(c + 1);
            ld[r - c + n -1] = rd[r + c] = rw[r] = false;
        }
    }
}
int main() {
    int nb_case = 0;
    while (scanf("%d", &n) != EOF && n != 0) {
        nb_case ++;
        cpt = 0;
        if(scanf("%c", &cell)){}
        for (int i = 0; i < n*n; ++i)
        {
            if(scanf("%c", &cell))
            board[i/n][i%n] = (cell == '.');
            if(i%n == n-1)if(scanf("%c", &cell)){}
        }
        backtrack(0);
        printf("Case %d: %d\n", nb_case, cpt);
    }
    return 0;
}