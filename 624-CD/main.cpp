#include <iostream>
#include <utility>

using namespace std;
typedef pair<int, int> p2i;

int N, n, tracks[20];


// version with void and global variables
int best_sum, best_tracks; 
void count_void(int i, int sum, int cur_tracks) {
    if (sum > N) return;
    if (sum > best_sum) {
        best_sum = sum;
        best_tracks = cur_tracks;
    }
    if (i >= n) return;
    count_void(i + 1, sum + tracks[i], cur_tracks | (1 << i));
    count_void(i + 1, sum, cur_tracks);
}

// version with returned data and recursively copied variables 
p2i count(int i, int sum, int cur_tracks){
    p2i c1 = {0, 0}, c2 = {0, 0};
    if(i >= n) return {sum, cur_tracks};
    if(sum + tracks[i] <= N)
        c1 = count(i + 1, sum + tracks[i], cur_tracks | (1 << i));
    c2 = count(i + 1, sum, cur_tracks);
    if (c1.first >= c2.first)
        return c1;
    return c2;
}
int main() {
    p2i p;
    while(scanf("%d %d", &N, &n) != EOF){
        for (int i = 0; i < n; ++i)
            if(scanf("%d", &tracks[i])){}

        // p = count(0, 0, 0);
        // int used_tracks = p.second, sum = p.first;
        // for (int i = 0; i < n; ++i)
        //     if (used_tracks & (1 << i))
        //         printf("%d ", tracks[i]);
        // printf("sum:%d\n", sum);

        best_sum = -1;
        best_tracks = -1;
        count_void(0, 0, 0);
        for (int i = 0; i < n; ++i)
            if (best_tracks & (1 << i))
                printf("%d ", tracks[i]);
        printf("sum:%d\n", best_sum);
    }

    return 0;
}