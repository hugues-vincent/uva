#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, x[1000001];
    x[0] = 1;
    for (int i = 1; i < 1000001; ++i)
        x[i] = (x[(int)(i - sqrt(i))] + x[(int)log(i)] + x[(int)(i*sin(i)*sin(i))]) % 1000000;
    while(scanf("%d", &n) != EOF && n != -1){
        printf("%d\n", (x[n]));
    }
    return 0;
}