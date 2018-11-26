#include <iostream>

using namespace std;
int money, S[] = {25, 50, 10, 1, 5};
// Time limit exceeded
void iterative() {
    int cpt = 0, remaining = money;
    for (int i = 0; i <= money/50; ++i)
    {
        remaining -= i*50;
        for (int j = 0; j <= remaining/25; ++j)
        {
            remaining -= j*25;
            for (int k = 0; k <= remaining/10; ++k)
            {
                remaining -= k*10;
                for (int l = 0; l <= remaining/5; ++l) cpt++;
                remaining += k*10;
            }
            remaining += j*25;
        }
        remaining += i*50;
    }
    printf("%d\n", cpt);
}

// time limit exceeded
int recursive(int N, int m) {
    if (N < 0 || m < 0) return 0;
    else if (N == 0) return 1;
    return recursive(N - S[m], m) + recursive(N, m -1);
}

// accepted: rank 11756
int dp(int n, int m) {
    int table[n+1][m];
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0) table[i][j] = 1;
            else if (j == 0) {
                if (i % S[j] == 0) table[i][j] = 1;
                else table[i][j] = 0;
            }
            else if (i < S[j]) table[i][j] = table[i][j-1];
            else table[i][j] = table[i - S[j]][j] + table[i][j-1];
        }
    }
    return table[n][m-1];
}
int main() {
    while(scanf("%d", &money) != EOF) {
        printf("%d\n", dp(money, 5));
    }
    return 0;
}