#include <iostream>
#include <cmath>

using namespace std;

long money, S[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long dp(long n, long m) {
    long table[30001][11];
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
    long a, b;
    char c;
    while(scanf("%ld %c %ld", &a, &c, &b) != EOF && (a != 0 || b != 0)){
        money = a * 100 + b;
        printf("%6.2f %16ld\n", (float)money/100,dp(money, 11));
    }
    return 0;
}