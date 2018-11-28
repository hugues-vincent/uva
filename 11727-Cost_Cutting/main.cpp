#include <iostream>

using namespace std;

int main() {
    int T, a, b, c;

    if(scanf("%d", &T)){}
    
    for (int i = 1; i <= T; ++i) {
        if(scanf("%d %d %d", &a, &b, &c)){}
        if((b >= a && a >= c) || (c >= a && a >= b)) printf("Case %d: %d\n", i, a);
        else if((a >= b && b >= c) || (c >= b && b >= a)) printf("Case %d: %d\n", i, b);
        else if((a >= c && c >= b) || (b >= c && c >= a)) printf("Case %d: %d\n", i, c);
    }
    return 0;
}