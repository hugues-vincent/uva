#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int N, M, C, K, best;
vi garment[20];

void recursive_global(int c, int m){
    if (m < 0) return;
    if (c == C && best < M - m) { 
        best = M - m; 
        return;
    }
    for (int k = 0; k < garment[c].size(); ++k)
        recursive_global(c + 1, m - garment[c][k]);
}

int max(int a, int b) { return a >=b ? a: b; }
int recursive_local(int c, int m) {
    if (m < 0) return -(1<<25);
    int local_max = -1;
    if(c == C) return M - m;
    for (int k = 0; k < garment[c].size(); ++k)
    {
        local_max = max(local_max, recursive_local(c +1, m - garment[c][k]));
    }
    return local_max;
}

int table[20][201];
int dp_bottom_up(int c, int m) {
    for (int i = 0; i <= M; ++i)
        for (int k = 0; k < garment[C-1].size(); ++k)
            if(garment[C-1][k] <= i ) table[C-1][i] = max(garment[C-1][k], table[C-1][i]);

    for (int j = C-1; j >= 0; --j)
        for (int i = 0; i <= M; ++i)
            for (int k = 0; k < garment[j].size(); ++k) 
                if(garment[j][k] <= i && table[j+1][i - garment[j][k]] != -1) 
                    table[j][i] = max(garment[j][k] + table[j+1][i - garment[j][k]], table[j][i]);

    return table[c][m];
}

int dp_top_down(int c, int m) {
    if (m < 0) return -(1 << 20);
    if (c == C) return M - m;
    if(table[c][m] != -1) return table[c][m];
    int ans = -1;
    for (int k = 0; k < garment[c].size(); ++k)
        ans = max(ans, dp_top_down(c + 1, m - garment[c][k]));
    return table[c][m] = ans;
}

int dp_top_down_v2(int c, int m) {
    if (m < 0) return -(1 << 20);
    if (c == C) return M - m;
    int &ans = table[c][m];
    if(ans != -1) return ans;
    for (int k = 0; k < garment[c].size(); ++k)
        ans = max(ans, dp_top_down(c + 1, m - garment[c][k]));
    return ans;
}
int main() { 
    int tmp;
    if(scanf("%d", &N)){}
    while(N--){
        if(scanf("%d %d", &M, &C)){}
        for (int i = 0; i < C; ++i){
            if(scanf("%d", &K)){}
            garment[i].clear();
            for (int j = 0; j < K; ++j) {
                if(scanf("%d", &tmp)){}
                garment[i].push_back(tmp);
            }
        }
        memset(table, -1, sizeof table);

        // best = dp_bottom_up(0, M);
        // best = dp_top_down(0, M);
        best = dp_top_down_v2(0, M);
        best == -1 ? printf("no solution\n") : printf("%d\n", best);
    }

    return 0;
}