#include <iostream>

using namespace std;

int main() {
    int T, n, speed, c;
    if(scanf("%d", &T)){}
    T = 0;
    while(scanf("%d", &n) != EOF) {
        T++;
        speed = 0;
        for (int i = 0; i < n; ++i) {
            if(scanf("%d", &c)){}
            if (c > speed) speed = c;
        }
        printf("Case %d: %d\n", T, speed);
    }
    return 0;
}