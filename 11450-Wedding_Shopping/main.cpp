#include <iostream>
#include <vector>

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
        best = recursive_local(0, M);
        best == -1 ? printf("no solution\n") : printf("%d\n", best);
    }

    return 0;
}