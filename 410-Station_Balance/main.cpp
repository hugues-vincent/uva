#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int C, S, species[10], case_i = 0, chambers[5][2];
    while(scanf("%d %d", &C, &S) != EOF) {
        for (int i = 0; i < S; ++i)
            if(scanf("%d", &species[i])){}

        for (int i = S ; i < 2*C; ++i)
            species[i] = 0;
        sort(species, species + 2*C,  greater<int>());
        for (int i = 0; i < C; ++i){
            chambers[i][0] = species[i];
            chambers[i][1] = species[2*C-i - 1];
        }
        double mean = 0, imbalance = 0;
        for (int i = 0; i < S; ++i) mean += species[i];
        mean /= C;
        for (int i = 0; i < C; ++i) imbalance += fabs(chambers[i][0] + chambers[i][1] - mean);

        printf("Set #%d\n", ++case_i);
        for (int i = 0; i < C; ++i)
        {
            printf(" %d:", i);
            int ci0 = chambers[i][0], ci1 = chambers[i][1];
            if(ci0) printf(" %d", ci0);
            if(ci1) printf(" %d", ci1);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }
    return 0;
}