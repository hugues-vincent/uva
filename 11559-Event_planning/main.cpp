#include <iostream>

using namespace std;

int min(int a, int b) { return a <= b ? a : b; }
int main() {
    int N, B, H, W, beds, price;
    int min_price;
    while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
        min_price = 2000001;
        for (int i = 0; i < H; ++i)
        {
            if (scanf("%d", &price)){}
            for (int j = 0; j < W; ++j) if(scanf("%d", &beds)){
                int cur_price = price * N;
                if(N <= beds && cur_price < min_price && cur_price <= B) min_price = price * N;
            }
        }
        if (min_price == 2000001) printf("stay home\n");
        else printf("%d\n", min_price);
    }

    return 0;
}