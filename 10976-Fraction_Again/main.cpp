// find all pairs (x, y) such that 1/k = 1/x + 1/y
// with x >= y
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int k, cpt;
    std::vector<int> v;
    while (scanf("%d", &k) != EOF) {
        v.clear();
        for (int y = k + 1; y <= 2*k; ++y) if(y*k % (y-k) == 0) v.push_back(y);
        printf("%ld\n", v.size());
        for (int y : v) printf("1/%d = 1/%d + 1/%d\n", k, y*k/(y-k),y);
    }
    return 0;
}